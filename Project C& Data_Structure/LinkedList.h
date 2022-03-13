typedef struct node
{
	u8 name[20];
	u8 age;
	u8 gender;
	u8 iD;
	struct node * next;
	
}Node;

typedef struct slot
{
	u32 iD;
	u32 Num_slot; 
	struct slot * next;
	
}Slot;

typedef enum MODE
{
	USER=0,
	ADMIN=1,
}mode;


typedef enum Error
{
	false,
	true
}error;

typedef enum ADMIN_Options
{
	option1=1,
	option2=2,
	option3=3,
	option4=4,
} Admin_options;

typedef enum USER_Options
{
	Option1=1,
	Option2=2,
} User_options;

typedef enum Slots
{
	slot1=1,
	slot2=2,
	slot3=3,
	slot4=4,
	slot5=5,
	
} slots;

// prototypes functions in linkedlist.c
Node * LL_create(u8 * name,u8 age,u8 gender,u8 iD);
void LL_append(Node * head,u8 * name,u8 age,u8 gender,u8 iD);
Node * LL_search(Node * head, int key);
void LL_print(Node *head);
void LL_printReservations(Slot *head);
Slot * LL_SLOTS(u8 Num_slot);
void LL_voidNewSlot(Slot * head,u8 slot);
Slot * LL_searchSlotAvailable(Slot * head, u8 slot);
Slot * LL_searchIDNotAvailable(Slot * head, u32 id);
	
// prototypes functions in clinic.c
mode Clinic_ChooseMode(void);
User_options USER_optionsChoose(void);
void USER_voidViewPatientRecord(Node * list);
void USER_voidViewreservations(Slot * Local_Slot);
error ADMIN_errorUserPass(void);
void ADMIN_voidAddNewPat(Node * list);
Admin_options ADMIN_optionsChoose(void);
void ADMIN_voidEditPatRecord(Node * list);
void ADMIN_voidReserveSlot(Node * list, Slot * Local_Slot);
void ADMIN_voidCancleReserve(Node * list,Slot * Local_Slot);

void SWAP(int *a ,int *b);