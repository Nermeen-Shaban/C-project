#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "STD_TYPES.h"
#include "LinkedList.h"

Node * LL_create(u8 * name,u8 age,u8 gender,u8 iD)
{
	Node * head=(Node *)malloc(sizeof(Node));
		if(head!=NULL)
		{
			strcpy(head->name,name);
			head->age=age;
			head->gender=gender;
			head->iD=iD;
			head->next=NULL;
		}
	return head;
}

Slot * LL_SLOTS(u8 Num_slot)
{
	Slot * head=(Slot *)malloc(sizeof(Slot));
		if(head!=NULL)
		{
			head->iD=0;
			head->Num_slot=Num_slot;
			head->next=NULL;
		}
	return head;
}
void LL_voidNewSlot(Slot * head,u8 slot)
{
	Slot *iterate=head;
	while(iterate->next != NULL)
	{
		iterate=iterate->next;
	}
	Slot * NewNode=(Slot *)malloc(sizeof(Slot));
	if (NewNode!=NULL)
	{
		iterate->next=NewNode;
		NewNode->Num_slot=slot;
		NewNode->iD=0;
		NewNode->next=NULL;
	}
	
	
}

void LL_append(Node * head,u8 *name,u8 age,u8 gender,u8 iD)
{
	Node *iterate=head;
	while(iterate->next != NULL)
	{
		iterate=iterate->next;
	}
	Node * NewNode=(Node *)malloc(sizeof(Node));
	if (NewNode!=NULL)
	{
		iterate->next=NewNode;
		printf("\n\nEnter NAME of this patient :");
		scanf("%s",NewNode->name);
		NewNode->age=age;
		NewNode->gender=gender;
		NewNode->iD=iD;
		NewNode->next=NULL;
	}
	
	
}

Node * LL_search(Node * head, int key)
{
	Node * iterate=head;
	while(iterate !=NULL && iterate->iD != key)
	{
		iterate=iterate->next;
	}
	if (iterate==NULL)
	{
		
	}

	return iterate;

}

Slot * LL_searchSlotAvailable(Slot * head, u8 slot)
{
	Slot * iterate=head;
	while(iterate !=NULL && iterate->Num_slot != slot)
	{
		iterate=iterate->next;
	}
	if (iterate==NULL)
	{
		printf(" NOT FOUND");
		
	}

	return iterate;

}

Slot * LL_searchIDNotAvailable(Slot * head, u32 id)
{
	Slot * iterate=head;
	while(iterate !=NULL && iterate->iD != id)
	{
		iterate=iterate->next;
	}
	return iterate;
}


void LL_print(Node *head)
{
	Node *iterate;
	iterate=head;
	while(iterate != NULL)
	{
		printf("ID     : %d\n",iterate->iD);
		printf("age    : %d\n",iterate->age);
		printf("gender : %c\n",iterate->gender);
		printf("name   : %s\n",iterate->name);
		
		iterate=iterate->next;
		printf("\n");
	}
}

void LL_printReservations(Slot *head)
{
	Slot *iterate;
	iterate=head;
	while(iterate != NULL)
	{
		printf("ID                      : %d",iterate->iD);
		switch(iterate->Num_slot)
		{
			case slot1: printf("\nThe reserved slot is    : 2   pm    to    2:30pm\n");break;
			case slot2 :printf("\nThe reserved slot is    : 2:30pm    to    3   pm\n");break;
			case slot3 :printf("\nThe reserved slot is    : 3   pm    to    3:30pm\n");break;
			case slot4 :printf("\nThe reserved slot is    : 4   pm    to    4:30pm\n");break;
			case slot5 :printf("\nThe reserved slot is    : 4:30pm    to    5   pm\n");break;
		}
		iterate=iterate->next;
		printf("\n");
	}
}

