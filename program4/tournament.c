#include"tournament.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

Player * draftPlayers(char * filename, int team, int num_players)
{
	Player *playerArray = malloc(sizeof(Player) * num_players);
	int playerCounter = 0;
	FILE *fp = fopen(filename, "r");
	char arr[255];
	char *token;

	//Read the contents of the file line by line
	while(fgets(arr, 255, fp) != NULL)
	{
		//Read the team number from the line
		token = strtok(arr, ",");
		if(team == atoi(token))
		{
			int tempCounter = 0;
			//Set the Team no
			playerArray[playerCounter].team = atoi(token);

			//Read the remaining fields from the line
			while(token != NULL)
			{
				tempCounter++;
				token = strtok(NULL, ",");
				switch(tempCounter)
				{
					case 1:
					{
						//Assign memory for first name on the heap
						playerArray[playerCounter].first = malloc(strlen(token) + 1);
						strcpy(playerArray[playerCounter].first, token);
						break;
					}
					case 2:
					{
						//Assign memory for second name on the heap
						playerArray[playerCounter].last = malloc(strlen(token) + 1);
						strcpy(playerArray[playerCounter].last, token);
                                                break;
					}
                                        case 3:
                                        {
						playerArray[playerCounter].number = atoi(token);
                                                break;
                                        }
                                        case 4:
                                        {
						playerArray[playerCounter].offensive = atoi(token);
                                                break;
                                        }
                                        case 5:
                                        {
						playerArray[playerCounter].defensive = atoi(token);
                                                break;
                                        }

				}
			}
			//Increment the index
			playerCounter++;
		}

	}

	fclose(fp);
	return playerArray;
}

Team * initializeTeam(char * name, Player * players) 
{
	Team *team = malloc(sizeof(Team));
	team->name = malloc(strlen(name) + 1);
	strcpy(team->name, name);
	team->players = players;

	return team;
}

Team * game(Team *team1, Team *team2)
{
	Team *winner = NULL;

	//Check if the teams are not null
	if(team1 != NULL && team2 != NULL)
	{
		//Total offense and defense of each teams
		int t1TotalOffense = 0, t1TotalDefense = 0, t2TotalOffense = 0, t2TotalDefense = 0;
		//Total scores of both teams
		int t1Score = 0, t2Score = 0;
		//Summation of total sum and defense of every team
	        for(int i = 0; i < 10; i++)
        	{
			t1TotalOffense += team1->players[i].offensive;
			t1TotalDefense += team1->players[i].defensive;

                        t2TotalOffense += team2->players[i].offensive;
                        t2TotalDefense += team2->players[i].defensive;
       		}

		//Checking team1's offense with team2's defense
		for(int i = 0; i < 9; i ++)
		{
			int random = rand()%t1TotalOffense;
			if(random > t2TotalDefense)
				t1Score++;
			else
				t2Score++;
		}

		//Checking team2's offense with team1's defense
                for(int i = 0; i < 9; i ++)
                {
                        int random = rand()%t2TotalOffense;
                        if(random > t1TotalDefense)
                                t2Score++;
                        else
                                t1Score++;
                }

		//Deciding the winner
		if(t1Score > t2Score)
			winner = team1;
		else
			winner = team2;
	}

	return winner;
}

Team * tournament(Team **teams, int teamCount) 
{
	Team *winner = NULL;
	int teamCount2 = teamCount;
	int teamCount3 = teamCount;

        Team ** winnerArray1 = malloc(sizeof(Team*) * teamCount);

        //Copying contents of Team array to winner array 1
	memcpy(winnerArray1, teams, sizeof(*teams) * teamCount);

	//Check if the number of teams is greater than 0
	if(teamCount > 0)
	{
		int countOf1 = 0;
		//Right shift and count the number of one's in the number passed,
		//if count is 1 then the number is power of 2
		for(int i = 0; i <= 5; i++, teamCount >>= 1)
		{
			if((teamCount & 1) == 1)
			{
				countOf1++;
			}
		}

		if(countOf1 == 1)
		{
			//printf("\nThe number of teams passed is a power of 2\n");

			int noOfRounds = 0;
		        for(; noOfRounds <= 5; noOfRounds++, teamCount2 >>= 1)
		        {
		                if((teamCount2 & 1) == 1)
                		{
                		        break;
		                }
        		}

			//Reduce the size of team in half
			teamCount3 = teamCount3/2;

			Team ** winnerArray2;
			for(int i = 0; i <noOfRounds; i++)
			{
				int locPointer = 0;
				winnerArray2 = malloc(sizeof(Team*) * (teamCount3));
				int ptr2 = 0;

                                for(int j = 0; j < teamCount3; j++, locPointer+= 2)
				{
                                        winnerArray2[ptr2] = game(winnerArray1[locPointer], winnerArray1[locPointer + 1]);
					ptr2++;

				}
				free(winnerArray1);
				winnerArray1 = malloc(sizeof(*teams) * teamCount3);
				memcpy(winnerArray1, winnerArray2, sizeof(*teams) * teamCount3);
				if(i != (noOfRounds - 1))
					free(winnerArray2);
				teamCount3 = teamCount3/2;
			}

			free(winnerArray1);
			//if()
			//free(winnerArray2);
			//winner = teams[0];
			winner = winnerArray2[0];
		}
		else
		{
			printf("\nInvalid number of teams have been passed, the number of teams should be a power of 2");
		}
	}
	return winner;
}

void deleteTeam(Team *team)
{
	//Free the memory allocated for team name
	free(team->name);

	//Free the players first name, last name
	for(int i = 0; i <= 9; i++)
	{
		free(team->players[i].first);
		free(team->players[i].last);
	}
	//Freeing the memory allocated for the players array
	free(team->players);
	//Free the memory allocated for the team
	free(team);
}
