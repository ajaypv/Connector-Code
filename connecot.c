#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct Student
{
    char conntercode[20];
    char name[100];
    char phone[100];
    char mailid[100];
    char wlink[100];

    struct Student *next;

}* head=NULL;


void view()
{
  printf("do you want to display it");
}


void insert()
{
  char name[100];
    char phone[100];
    char conntercode[20];
    char mailid[100];
    char wlink[300];
int n,i;
   
    struct Student * temp = head,*ptr;

    printf("create connter code for this group: ");
    scanf("%s",conntercode);
    printf("\npaste your whatsapp group link\n");
scanf("%s",wlink);

	while(temp!=NULL)
{
 if(temp->conntercode==conntercode)
    {
    printf("oops CC CODE is not strong   %s !!!\n", conntercode);
    return;
     }
    temp = temp->next;
  }
printf("enter the number of people is there in your community\n");
scanf("%d",&n);
  printf("Enter maid id : ");
              
              getchar();
              fgets(mailid,100,stdin);
  for(i=0;i<n;i++)
 { struct Student * student = (struct Student *) malloc(sizeof(struct Student));
  
    printf("Enter name: ");
               
               fgets(name,100,stdin);
                printf("Enter phone number: ");
                fgets(phone,100,stdin);
              


 // student->conntercode =conntercode;
  strcpy(student->conntercode, conntercode);
	strcpy(student->name, name);
	strcpy(student->phone, phone);
	strcpy(student->mailid, mailid);
  strcpy(student->wlink, wlink);
	student->next = NULL;

	if(head==NULL){

		head = student;
	}
	else{
ptr=head;
while(ptr->next!=NULL)
{
  ptr=ptr->next;

}



ptr->next=student;

	}

}
}

void search(char conntercode[20])
{
    struct Student * temp = head; int count=0;
	while(temp!=NULL){
		if(temp->conntercode==conntercode)

    { count++;
		
	if(count==1)
   {
     printf("maild: %s\n", temp->mailid);
    printf("whatsup link\n %s\n", temp->wlink);

  }
  
    	printf("Name: %s\n", temp->name);
			printf("Phone: %s\n", temp->phone);
		
		}
		temp = temp->next;
   
	}
  if  (count==0)
	printf("Student with roll number %d is not found !!!\n", conntercode);
}

void update(char conntercode[20])
{

    struct Student * temp = head;
	while(temp!=NULL){

		if(temp->next=conntercode){
			printf("Record with connter coded  number %d Found !!!\n", conntercode);
			printf("Enter new name: ");
			printf("%s",temp->name);
			scanf("%s", temp->name);
			printf("Enter new phone number: %s ",temp->phone);
			scanf("%s", temp->phone);
			printf("Enter new percentage: ");
			scanf("%s",temp->mailid);
			printf("Updation Successful!!!\n");
			return;
		}
		temp = temp->next;

	}
	printf("Student with roll number %s is not found !!!\n",conntercode);

}

void Delete(char conntercode[20])
{

    struct Student * temp1 = head;
	struct Student * temp2 = head;
	while(temp1!=NULL){

		if(temp1->conntercode==conntercode){

			printf("Record with roll number %s Found !!!\n",conntercode);

			if(temp1==temp2){
				
				head = head->next;
				free(temp1);
			}
			else{
				
				temp2->next = temp1->next;
				free(temp1);
			}

			printf("Record Successfully Deleted !!!\n");
			return;

		}
		temp2 = temp1;
		temp1 = temp1->next;

	}
	printf("Student with roll number %s is not found !!!\n", conntercode);

}

void display()
{
    struct Student * temp = head;
	while(temp!=NULL){

		printf("Roll Number: %s\n", temp->conntercode);
		printf("Name: %s\n", temp->name);
		printf("Phone: %s\n", temp->phone);
		printf("maild: %s\n\n", temp->mailid);
		temp = temp->next;

	}
}

int main()
{
    head = NULL;
    int choice,i;
    char name[100];
    char phone[100];
    char conntercode[20];
    char mailid[100] ;

    printf("1 create a connter group\n2 to search for student details\n3 to delete student details\n4 to update student details\n5 to display all student details");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:


                insert();
                break;
            case 2:
                printf("Enter roll number to search: ");
                scanf("%s", conntercode);
                search(conntercode);
                break;
            case 3:
                printf("Enter roll number to delete: ");
                scanf("%s", conntercode);
                Delete(conntercode);
                break;
            case 4:
                printf("Enter roll number to update: ");
                scanf("%s",conntercode);
                update(conntercode);
                break;
            case 5:
                display();
                break;
        }

    } while (choice != 0);

}


