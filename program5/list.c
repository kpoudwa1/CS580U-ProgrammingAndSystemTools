#include"list.h"
#include<stdio.h>
#include<stdlib.h>

List * newList()
{
	List *list = malloc(sizeof(List));
	list->head = list->tail = NULL;

	//Init functin pointers
	list->insert = insertList;
	list->read = readList;
	list->remove = removeList;
	list->delete = deleteList;
	return list;
}

void insertList(struct List * list, int index, Data data)
{
	Node *datanode = (Node *)malloc(sizeof(Node));
	datanode->data=data;
	datanode->prev=NULL;
	datanode->next=NULL;

	int length=0;
	Node *temp=list->head;
	while(temp!=NULL)
	{
		length=length+1;
		temp=temp->next;
	}
	if(length==0)
	{
		list->head=datanode;
		list->tail=datanode;
		return;
	}
	if(index>=length)
	{
		list->tail->next=datanode;
		datanode->prev=list->tail;
		list->tail=datanode;
		return;
	}
	if(index==0)
	{
		datanode->next=list->head;
		list->head->prev=datanode;
		list->head=datanode;
		return;
	}
	int ctr=0;
	temp=list->head;
	while(ctr!=index)
	{
		ctr++;
		temp=temp->next;
	}
	datanode->next=temp;
	datanode->prev=temp->prev;
	temp->prev->next=datanode;
	temp->prev=datanode;
}

Data * readList(struct List * list, int index)
{
	Data *dataPtr = NULL;
	Node *temp=list->head;
	int i = 0;
	while(temp != NULL)
	{
		if(i == index)
		{
			dataPtr = &temp->data;
			return dataPtr;
		}
		temp = temp->next;
		i++;
	}
	return dataPtr;
}

void removeList(struct List * list, int index)
{
	int length = 0;
	Node *tempNode = list->head;

	//Getting the length of the list
	while(tempNode != NULL)
	{
		length++;
		tempNode = tempNode->next;
	}

	//Check if the length is greater than zero
	if(length > 0)
	{
		//Check if head and tail point to the same node
		if(list->head == list->tail)
		{
			free(list->head);
			list->head = NULL;
			list->tail = NULL;
		}
		else if(index == 0)
		{
			tempNode = list->head;
			list->head = list->head->next;
			list->head->prev = NULL;
			free(tempNode);
		}
		else if(index == (length - 1))
		{
			tempNode = list->tail;
			list->tail = list->tail->prev;
			list->tail->next = NULL;
			free(tempNode);
		}
		else if(index < (length - 1))
		{
			tempNode = list->head;
			int i = 0;
			while(tempNode != NULL)
			{
				tempNode = tempNode->next;
				i++;
				if(index == (i - 1))
				{
					break;
				}
			}
			tempNode->prev->next = tempNode->next;
			tempNode->next->prev = tempNode->prev;
			free(tempNode);
		}
	}
}

void deleteList(struct List * list)
{
	//Check if the list is empty or not
	if(list->head != NULL)
	{
		Node *tempNode = list->head;
		int length = 0;
		while(tempNode->next != NULL)
		{
			length++;
			tempNode = tempNode->next;
		}

		//Deleting the nodes of the list
		while(list->head != NULL)
		{
			Node *temp = list->head;
			list->head = list->head->next;
			if(list->head != NULL)
				list->head->prev = NULL;
			free(temp);
		}
	}

	//Free the memory allocated to list variable
	free(list);
}
