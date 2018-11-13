#ifndef TOURNAMENT_H
#define TOURNAMENT_H
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>

typedef struct Player
{
        int offensive;
        int defensive;
        int number;
        int team;
        char *first;
        char *last;
} Player;

typedef struct Team
{
	char *name;
	Player *players;
} Team;

Player * draftPlayers(char * filename, int team, int num_players);

Team * initializeTeam(char * name, Player * players);

Team * game(Team *team1, Team *team2);

Team * tournament(Team **, int);

void deleteTeam(Team *team);
#endif
