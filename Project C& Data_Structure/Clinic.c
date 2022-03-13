#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "STD_TYPES.h"
#include "LinkedList.h"

u8 Global_u8Flag1=0;
u8 Global_u8Flag2=0;
u8 Global_u8Flag3=0;
u8 Global_u8Flag4=0;
u8 Global_u8Flag5=0;


int main()
{
	u8 Local_u8Option;
	Node *list;
	
	// data base 
	list=LL_create("Nermeen",23,'f',1);
	Slot *ReserveSlot= LL_SLOTS(slot1);
	LL_voidNewSlot(ReserveSlot,slot2);
	LL_voidNewSlot(ReserveSlot,slot3);
	LL_voidNewSlot(ReserveSlot,slot4);
	LL_voidNewSlot(ReserveSlot,slot5);
	u32 cls;
	u32 mode ;
	while (1)
	{
		mode=Clinic_ChooseMode();
		if (mode == USER)
		{
			cls=system("cls");
			printf("            YOU NOW in USER MODE        ");
			while(1)
			{
				Local_u8Option= USER_optionsChoose();
				switch(Local_u8Option)
				{
					case Option1 : 
						cls=system("cls");
						USER_voidViewPatientRecord(list); 
						break;
					case Option2 :
						cls=system("cls");
						USER_voidViewreservations(ReserveSlot);
						break;
					default : 
						if (Local_u8Option != 3)
						{
							cls=system("cls");
							printf("This optins is not available ");
							break;
						}
						
				}
				if (Local_u8Option==3)
				{
					cls=system("cls");
					break;
				}
			}
		
		}
		else if (mode == ADMIN)
		{
			cls=system("cls");
			printf("            YOU NOW in ADMIN MODE        ");
			u8 Local_u8Pass=ADMIN_errorUserPass();
			if (Local_u8Pass==true)
			{
				while(1)
				{
					Local_u8Option= ADMIN_optionsChoose();
					switch(Local_u8Option)
					{
					case option1 : 
						cls=system("cls");
						ADMIN_voidAddNewPat(list); 
						break;
					case option2 : 
						cls=system("cls");
						ADMIN_voidEditPatRecord(list);
						break;
					case option3 :
						cls=system("cls");
						ADMIN_voidReserveSlot(list,ReserveSlot);
						break;
					case option4 :
						cls=system("cls");
						ADMIN_voidCancleReserve(list ,ReserveSlot);
						break;
					default : 
						if (Local_u8Option != 5)
						{
							cls=system("cls");
							printf("This optins is not available ");
							break;
						}
						
					}
					if (Local_u8Option==5)
					{
						cls=system("cls");
						break;
					}
				}
			}
		
		}
		else if(mode == 3)
		{
			break;
		}
		else 
		{
			printf("This Mode Not Valid");
		}
	
	}
	

	
}

mode Clinic_ChooseMode(void)
{
	u32 mode;
	u32 flag;
	printf("           Enter Mode (User OR ADMIN)                    \n");
	printf("-------------OPTIONS----------------------\n");
	printf("|      0. USER                           |\n");
	printf("|      1. ADMIN                          |\n");
	printf("|      3. EXIT                           |\n");
	printf("------------------------------------------\n");
	scanf("%d", &mode);
	if(mode==0)
	{
		flag=USER;
	}
	else if (mode == 1)
	{
		flag=ADMIN;
	}
	else if(mode ==3)
	{
		flag=3;
	}
	else 
	{
		flag=5;
	}
	return flag;
}

error ADMIN_errorUserPass(void)
{
	u8 Local_u8Flag=0;
	u16 Local_u8Pass=0;
	u8 Local_u8_Return=0;
	printf("\nEnter Password :");
	scanf("%d",&Local_u8Pass);
	for(u8 i=0;i<2;i++)
	{
		if (Local_u8Pass==1234)
		{
			Local_u8_Return=true;
			break;
		}
		else
		{
			if (Local_u8Flag==2)
			{
				printf("No more Tries\n");
				Local_u8_Return=false;
				break;
			}
			printf("incorrect password ,try again : ");
			scanf("%d",&Local_u8Pass);
			Local_u8Flag++;
			
		}
	}
	
	return Local_u8_Return;
}


void ADMIN_voidAddNewPat(Node *list)
{
	u8 name[20];
	u8 age;
	u8 gender;
	u32 iD;
	printf("\n            ADDING NEW PATIENT           \n");;
	printf("\n\nEnter ID of this patient :");
	scanf("%d",&iD);
	Node *local_patient=LL_search(list,iD);
	if (local_patient==NULL)
	{
		printf("\nEnter AGE of this patient :");
		scanf("%d",&age);
		printf("\nEnter GENDER of gender patient (f or m) :");
		gender=getch();
		if(gender == 'f' || gender=='m') 
		{
			LL_append(list,name,age,gender,iD);
		    LL_print(list);
		}
		else 
		{
			
			printf("\nThis char that you Entered Not Define ");
			printf("Must Enter f or m ");
		}
	}
	else 
	{
		printf("\nThis ID already exist\n");
	}
	
	
}

Admin_options ADMIN_optionsChoose(void)
{
	u32 Local_u32Option;
	printf("\n");
	printf("-------------OPTIONS----------------------\n");
	printf("|      1. Add new patient record         |\n");
	printf("|      2. Edit patient record            |\n");
	printf("|      3. Reserve a slot with the doctor |\n");
	printf("|      4. Cancel reservation             |\n");
	printf("|      5. EXIT                           |\n");
	printf("------------------------------------------\n");
	printf("\nEnter Number of Option You Need  : ");
	scanf("%d",&Local_u32Option);
	return Local_u32Option;
}

User_options USER_optionsChoose(void)
{
	u32 Local_u32Option;
	printf("\n");
	printf("-------------OPTIONS----------------------\n");
	printf("|      1. View patient record            |\n");
	printf("|      2. View today reservations.       |\n");
	printf("|      3. EXIT                           |\n");
	printf("------------------------------------------\n");
	printf("\nEnter Number of Option You Need  : ");
	scanf("%d",&Local_u32Option);
	return Local_u32Option;
}
void USER_voidViewPatientRecord(Node * list)
{
	u8 local_u8Id;
	Node * local_patient;
	printf("Enter ID to this patient :");
	scanf("%d",&local_u8Id);
	local_patient=LL_search(list,local_u8Id);
	if (local_patient !=NULL)
	{
		printf("ID     : %d\n",local_patient->iD);
		printf("age    : %d\n",local_patient->age);
		printf("gender : %c\n",local_patient->gender);
		printf("name   : %s\n",local_patient->name);
	}
	else 
	{
		printf("This iD NOT exist");
	}
}
void ADMIN_voidEditPatRecord(Node * list)
{
	u8 local_u8Id;
	Node * local_patient;
	printf("Enter ID to this patient :");
	scanf("%d",&local_u8Id);
	local_patient=LL_search(list,local_u8Id);
	if (local_patient !=NULL)
	{
		printf("Enter new age to update it :");
		u8 age;
		scanf("%d",&age);
		printf("Gender :");
		u8 g=getch();
		if(g == 'f' || g =='m')
		{
			local_patient->gender=g;
			local_patient->age=age;
			printf("\nEnter name you need to update for this patient :");
			scanf("%s",local_patient->name);
		}
		else 
		{
			printf("\nThis char that you Entered Not Define ");
			printf("Must Enter f or m ");
		}
		local_patient->iD=local_u8Id;
		
	}
	else 
	{
		printf("This iD NOT exist");
	}
	
}


void ADMIN_voidReserveSlot(Node * list,Slot * Local_Slot)
{
	
	u32 local_u8Id;
	u32 Local_u32Slot;
	Node * local_patient;
	
	
	printf("\nhere slots that available now \n");
	printf("\n");
	printf("--------------SLOTS--------------\n");
	
	if (Global_u8Flag1==0)
	{
		printf("| 1-   2   pm    to    2:30pm   |\n");
	}
	if (Global_u8Flag2==0)
	{
		printf("| 2-   2:30pm    to    3   pm   |\n");
	}
	if (Global_u8Flag3==0)
	{
		printf("| 3-   3   pm    to    3:30pm   |\n");
	}
	if (Global_u8Flag4==0)
	{
		printf("| 4-   4   pm    to    4:30pm   |\n");
	}
	if (Global_u8Flag5==0)
	{
		printf("| 5-   4:30pm    to    5   pm   |\n");
	}
	printf("---------------------------------\n");
	printf("\nEnter ID to reserve a slot:");
	scanf("%d",&local_u8Id);
	local_patient=LL_search(list,local_u8Id);
	Slot * ReserveSlot =LL_searchIDNotAvailable(Local_Slot,local_u8Id);
	if (local_patient !=NULL && (Global_u8Flag1 ==0 || Global_u8Flag2 ==0 || Global_u8Flag3==0 || Global_u8Flag4==0 || Global_u8Flag5 ==0 ) && ReserveSlot==NULL )
	{
		printf("\nEnter Number of Slot You Need to reserve it : ");
		scanf("%d",&Local_u32Slot);	
		switch(Local_u32Slot)
		{
			case slot1: 
				Local_Slot = LL_searchSlotAvailable(Local_Slot,slot1);
				if (Local_Slot->iD==0)
				{
					Local_Slot->iD=local_u8Id;
					Global_u8Flag1=1;
				}
				else 
				{
					printf("this Slot Not Available Now ");
				}
				break;
				
			case slot2:
				Local_Slot = LL_searchSlotAvailable(Local_Slot,slot2);
				if (Local_Slot->iD==0)
				{
					Local_Slot->iD=local_u8Id;
					Global_u8Flag2=1;
				}
				else 
				{
					printf("this Slot Not Available Now ");
				}
				break;
				
			case slot3: 
				Local_Slot = LL_searchSlotAvailable(Local_Slot,slot3);
				if (Local_Slot->iD==0)
				{
					Local_Slot->iD=local_u8Id;
					Global_u8Flag3=1;
				}
				else 
				{
					printf("this Slot Not Available Now ");
				}
				break;
				
			case slot4: 
				Local_Slot = LL_searchSlotAvailable(Local_Slot,slot4);
				if (Local_Slot->iD==0)
				{
					Local_Slot->iD=local_u8Id;
					Global_u8Flag4=1;
				}
				else 
				{
					printf("this Slot Not Available Now ");
				}
				break;
				
			case slot5:
				Local_Slot = LL_searchSlotAvailable(Local_Slot,slot5);
				if (Local_Slot->iD==0)
				{
					Local_Slot->iD=local_u8Id;
					Global_u8Flag5=1;
				}
				else 
				{
					printf("this Slot Not Available Now ");
				}
				break;
				
			default:
				printf(" This Slot Not Valid ");
				break;
			
		}
		printf("             DONE            \n");
	} 
	else if (local_patient ==NULL)
	{
		printf("This iD NOT exist");
	}
	else if (ReserveSlot!=NULL)
	{
		printf("This ID already Reserved\n");
	}
}

void ADMIN_voidCancleReserve(Node * list,Slot * Local_Slot)
{
	u8 local_u8Id;
	Node * local_patient;	
	printf("\nEnter ID to Cancel reservation:");
	scanf("%d",&local_u8Id);
	local_patient=LL_search(list,local_u8Id);
	Slot *ReserveSlot = LL_searchIDNotAvailable(Local_Slot,local_u8Id);
	if (local_patient != NULL && ReserveSlot!= NULL )
	{
		switch(ReserveSlot->Num_slot)
		{
			case slot1:
				Global_u8Flag1=0;
				ReserveSlot->iD=0;
				break;
			case slot2:
				Global_u8Flag2=0;
				ReserveSlot->iD=0;
				break;
			case slot3:
				Global_u8Flag3=0;
				ReserveSlot->iD=0;
				break;
			case slot4:
				Global_u8Flag4=0;
				ReserveSlot->iD=0;
				break;
			case slot5:
				Global_u8Flag5=0;
				ReserveSlot->iD=0;
				break;
			
		}
		printf("       DONE         ");
	}
	else if (local_patient==NULL || ReserveSlot ==NULL)
	{
		printf("This iD NOT exist");
	}


}


void USER_voidViewreservations(Slot * Local_Slot)
{
	printf(" 0 means that this slot is not reserved \n");
	LL_printReservations(Local_Slot);
}