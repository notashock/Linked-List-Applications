#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node {
	int data;
	struct node *next;
};
void addnode(struct node *head);
void delnode(struct node *head);
void display(struct node *head);
void MainMenu(struct node *head);
int main()
{
	struct node *head=NULL;
	system("color 3f");
	MainMenu(head);
}
struct node *createnode(int data)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}
int pos()
{
	int i;
	system("cls");
	printf("\t\t\t\t\tLINKED LIST\n\n");
	printf("\t\t\tEnter the position(int only):");
	scanf("%d",&i);
	return i;
}
int data()
{
	int i;
	system("cls");
	printf("\t\t\t\t\tLINKED LIST\n\n");
	printf("\t\t\tEnter an Element(int only):");
	scanf("%d",&i);
	return i;
}
struct node *newnode(int data,struct node *head)
{
	if(head==NULL)
	{
		return createnode(data);
	}
	else
	{
		printf("error!!!");
		getch();
		return NULL;
	}
}
struct node *addfront(int data, struct node *head)
{
	struct node *q=createnode(data);
	q->next=head;
	return q;
}
void addend(int data, struct node *head)
{
    struct node *p=head;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=createnode(data);
}
void addpos(int x,int data,struct node *head)
{
	struct node *p=head;
	struct node *r=head;
	int i;
	if(x==1)
	{
		printf("error");
	}
	for(i=1;i<x;i++)
	{
		if(p->next==NULL)
		{
			printf("error");
			//exit(1);
		}
		else
			p=p->next;
	}
	while(r->next!=p)
		r=r->next;
	struct node *q=createnode(data);
	q->next=p;
	r->next=q;
	addnode(head);
}
struct node *delfront(struct node *head)
{
	struct node *temp=head;
	head=head->next;
	free(temp);
	return head;
}
void delend(struct node *head)
{
	struct node *q=head;
	struct node *p=head;
	while(q->next!=NULL)
		q=q->next;
	while(p->next!=q)
		p=p->next;
	p->next=NULL;
	free(q);
}
void delpos(int data,struct node *head)
{
	struct node *q=head;
	while(q->data!=data)
		q=q->next;
	if(q==NULL)
		printf("error");
    else if(q==head){
        head=delfront(head);
        delnode(head);
    }
    else if(q->next==NULL)
        delend(head);
	else{
		while(head->next!=q)
			head=head->next;
		head->next=q->next;
		free(q);
	}
}
void addnode(struct node *head)
{
	system("cls");
	printf("\t\t\t\t\tADD NODE\n\n");
	if(head==NULL){
        printf("\t\t\t1 - Add New Node\n\t\t\t0 - Go Back\n\n\n");
        display(head);
        switch(getch()){
        case '1':
            head=newnode(data(),head);
			addnode(head);
			break;
        case '0':
            MainMenu(head);
            break;
        default:
            printf("\n\nInvalid choice");
            getch();
            addnode(head);
            break;
        }
	}
	else{
        printf("\t\t\t1 - Add at Beginning\n\t\t\t2 - Add at End\n\t\t\t3 - Add at InBetween\n\t\t\t0 - Go Back\n\n\n");
	display(head);
	switch(getch())
	{
		case '1':
			head=addfront(data(),head);
			addnode(head);
			break;
		case '2':
		    addend(data(),head);
			addnode(head);
			break;
		case '3':
			addpos(pos(),data(),head);
			break;
		case '0':
			MainMenu(head);
			break;
		default:
			printf("Invalid key");
			getch();
			addnode(head);
			break;
	}
	}
}
void delnode(struct node *head)
{
	system("cls");
	printf("\t\t\t\t\tDELETE NODE\n\n");
	printf("\t\t\t1 - Delete First Node\n\t\t\t2 - Delete Last Node\n\t\t\t3 - Delete Node by Data\n\t\t\t0 - Go Back\n\n\n");
	display(head);
	switch(getch())
	{
		case '1':
			head=delfront(head);
			delnode(head);
			break;
		case '2':
			delend(head);
			delnode(head);
			break;
		case '3':
			delpos(data(),head);
			delnode(head);
			break;
		case '0':
			MainMenu(head);
			break;
		default:
			printf("\nInvalid key!!!");
			getch();
			delnode(head);
			break;
	}
}
void search(int data,struct node *head)
{
	int i=1;
	struct node *q=head;
	while(q->data!=data){
            if(q->next!=NULL){
                q=q->next;
                i++;
            }
            else
                break;
	}
	if(q->data==data){
        system("cls");
		printf("\t\t\t\t\tLINKED LIST\n\n");
		printf("\t\t\tElement - %d, Found at node number - %d",data,i);
	}
	else{
	    system("cls");
		printf("\t\t\t\t\tLINKED LIST\n\n");
		printf("\t\t\tElement not found!!");
	}
	getch();
	MainMenu(head);
}
void MainMenu(struct node *head)
{
	system("cls");
	printf("\t\t\t\t\tLINKED LIST\n\n");
	printf("\t\t\t1 - Add a Node\n\t\t\t2 - Delete a Node\n\t\t\t3 - Search an Element\n\t\t\t0 - Exit\n\n\n");
	display(head);
	switch(getch())
	{
		case '1':
			addnode(head);
			break;
		case '2':
			delnode(head);
			break;
		case '3':
			search(data(),head);
			break;
        case '0':
            exit(1);
            break;
		default:
			printf("\n\t\t\tInvalid key!!!");
			getch();
			MainMenu(head);
			break;
	}
}
void display(struct node *head)
{
	printf("Output:");
	if(head!=NULL){
		while(head->next!=NULL){
			printf("%d->",head->data);
			head=head->next;
		}
		printf("%d",head->data);
	}
	else{
		printf("XXXXX");
	}
}
