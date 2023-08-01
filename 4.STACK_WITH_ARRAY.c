#include<stdio.h>

int main()
{
	// stack with array
	// push ,pop , display
	int stack[5];
	int top=-1;
	int choice;
	int n;
	do{
	printf("1-push 2-pop 3-display");
	printf("\nenter your choice");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1://push
			if(top==4)
			{
				printf("stack is full");
			}
			else
			{
				printf("\nenter number to push in stack");
				scanf("%d",&n);
				stack[++top]=n;
				printf("\n%d is pushed",n);
			}
			break;
		case 2://pop
			if(top==-1)
			{
				printf("stack is empty");
			}
			else{
			n=stack[top];
			top--;
			printf("\n%d is poped",n);
		}
			
			break;
		case 3://display
			if(top==-1)
				{
					printf("stack is empty");
				}
				else
				{
					for(int i=top;i>=0;i--)
					{
						printf("%d\t",stack[i]);
					}
				}
			break;
		default:
			printf("\ninvalide choice");			
	}
		printf("\ndo you want to continue ");
		scanf("%d",&choice);
	}while(choice==1);
	
	
	
	
	return 0;
}
