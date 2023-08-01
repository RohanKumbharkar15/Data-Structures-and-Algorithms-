#include<stdio.h>
//linkedlist single
// 	int n = nums.length;
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *addrnext;
	struct Node *addrprev;	
}*start,*curr,*newnode,*last,*prev;
 
struct Node * create(int);
void display();
void addnext(int);
void insertBeg(int);
void insertMiddle(int ,int);
int deleteBeg();
int searchNode(int );
int  deleteMiddle(int);
int main()
{
	start=NULL;
	int choice;
	do{
	
	int n;
	int pos,search,flag=0;
	printf("\n1-create a linked list\n-2add next node\n3-display\n4-insert begin\n5-insert middle\n6-delete begin\n7s-search element\n8-delelet middle");
	printf("\nenter your choice");	
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("enter number to create  linkedlist");
			scanf("%d",&n);
			create(n);
			break;
		case 2:
			printf("enter next node");
			scanf("%d",&n);
			addnext(n);
			display();
			
			
			break;	
		case 3:
			printf("\nlinked list is \n");
			display();
			break;
		case 4:
			printf("\nenter number to insert in begin");
			scanf("%d",&n);
			insertBeg(n);
			
			break;
		case 5:
			printf("\nenter number and position to insert element in middle");
			scanf("%d%d",&n,&pos);
			insertMiddle(n,pos);
			break;
		case 6:
			n=deleteBeg();
			printf("%d is deleted ",n);
			break;
		case 7:
			printf("\nenter number to search in linked list");
			scanf("%d",&search);
			flag=searchNode(search);
			if(flag>0)
			{
				printf("\n%d is found at %d location",search,flag);
			}
			else
			{
				printf("search not found");
			}
			break;
		case 8:
			printf("enter position to delete element");
			scanf("%d",&pos);
			n=deleteMiddle(pos);
			printf("%d is deleted ",n);
			
			break;		
		default :
			printf("wrong choice");				
		}
		printf("\ndo you want to continue press 1");
		scanf("%d",&choice);
	}while(choice==1);
	
	printf("\nthank you");
	
	return 0;
}
// create a linked list
 struct Node * create(int n)
{
	newnode=(struct Node *)malloc(sizeof(struct Node));
	newnode->data=n;
	newnode->addrnext=NULL;
	newnode->addrprev=NULL;
	
	if(start==NULL)
	{
		start=newnode;
		last=newnode;
	}

	return newnode;
	
}
//2- add next node--useful for insert beg,insert middle 
// malloc will be declared only once
void addnext(int n)
{
	newnode=create(n);
	last->addrnext=newnode;
	newnode->addrprev=last;
	last=last->addrnext;
}
//3 - display
void display()
{
	if(start==NULL)
	{
		printf("\nlinked list is empty");
	}
	else
	{
		curr=start;
		while(curr !=NULL)
		{
			printf("| %u | %d | %u |--->",curr->addrprev,curr->data,curr->addrnext);
			curr=curr->addrnext;
		}
		
	}
}
//4-insert begin
void insertBeg(int n)
{
	newnode=create(n);
	newnode->addrnext=start;
	start->addrprev=newnode;

	start=newnode;
	
}
// 5-insert middle
void insertMiddle(int n,int pos)
{
	prev=NULL;
	curr=start;
	int cnt=1;
	while(cnt<pos)
	{
		prev=curr;
		curr=curr->addrnext;
		cnt++;	
	}	
	newnode=create(n);
	newnode->addrprev=prev;
	prev->addrnext=newnode;
	newnode->addrnext=curr;
	curr->addrprev=newnode;
}

// delete begin node
int deleteBeg()
{
	int n;
	curr=start;
	start=start->addrnext;
	start->addrprev=NULL;
	curr->addrnext=NULL;
	n=curr->data;
	free(curr);
	return n;
}
//searching for element
int searchNode(int search)
{
	int flag=0;
	if(start==NULL)
	{
		printf("linkedlist is empty");
	}
	else
	{
		curr=start;
		int cnt=1;
		while(curr !=NULL)
		{
			if(curr->data==search)
			{
				flag=cnt;
				break;
			}
			cnt++;
			curr=curr->addrnext;
		}
	}
	return flag;
}
//8-deleete element using position
int  deleteMiddle(int pos)
{
	int n;
	curr=start;
	prev=NULL;
	int cnt=1;
	while(cnt<pos)
	{
		prev=curr;
		curr=curr->addrnext;
		cnt++;
	}
	prev->addrnext=curr->addrnext;
	curr->addrnext->addrprev=prev;
	n=curr->data;
	free(curr);
	return n;
	
	
}


























