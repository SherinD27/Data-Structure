#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void push(int);
void pop();
void display();
int stack [SIZE],top=-1;
void main()
{
  int value, choice;
  while(1) {
  printf("\n\n*****MENU*****\n");
  printf("1.push\n2.pop\n3.Display\n4.exit");
  printf("\nEnter your Choice: ");
  scanf("%d",&choice);
  switch(choice){
      case 1:
           printf("Enter the value to be insert: ");
           scanf("%d",&value);
           push(value);
           break;
      case 2:
          pop();
          break;
      case 3:
           display();
           break;
      case 4:
          exit(0);
          default: printf("\nWrong selection!!! Try again!!!");
  }
  }
}
void push(int value)
{
    if(top==SIZE-1)
        printf("\n Stack is full!!! Insertion is not possible!!!");
    else
    {
        top++;
        stack[top]=value;
        printf("\n Insertion success!!!");
    }
}
void pop()
{
    if (top==-1)
        printf("\n stack is empty!!!Deletion is not possible!!!");
    else
    {
        printf("\nDeleted :%d", stack[top]);
        top--;
    }
}
void display()
{
    if(top==-1)
        printf("\n Stack is empty!!!");
    else
    {
        int i;
        printf("\n Stack elements are:\n");
        for(i=top; i>=0; i--)
            printf("%d\n",stack[i]);
    }
}




