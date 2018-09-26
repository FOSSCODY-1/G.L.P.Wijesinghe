#include<stdio.h>
#define MAX 10 //length of array
int queue[MAX];
int front = -1, rear = -1;
void insert(void);
int delete_element(void);
int peek(void);
void display(void);
int main()
{
    int option, val;
    do
    {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1. Insert an entry"); //when a car drives in
        printf("\n 2. Delete an entry"); //when a car drives out
        printf("\n 3. Check the first car to drive out"); //peek
        printf("\n 4. Display the car park");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
    switch(option)
        {
        case 1:
        insert();
        break;

        case 2:
        val = delete_element();
        if (val != -1)
        printf("\n The car number droved out is : %d\n\n", val);
        break;

        case 3:
        val = peek();
        if (val != -1)
        printf("\n The first car to drive out next is : %d\n\n", val);
        break;

        case 4:
        display();
        break;
        }
    }
    while(option != 5);
return 0;
}

void insert()
{
    int num;
    printf("\n Enter the car number to drive into the car park : ");
    scanf("%d", &num);
    if(rear == MAX-1)
    printf("\n |||||||||NOT ENOUGH SPACE|||||||||\n\n");
    else if(front == -1 && rear == -1)
    front = rear = 0;
    else
    rear++;
    queue[rear] = num;
}
int delete_element()
{
    int val;
    if(front == -1 || front>rear)
    {
    printf("\n |||||||||CAR PARK IS EMPTY. NO CARS TO LEAVE|||||||||\n\n");
    return -1;
    }
    else
    {
    val = queue[front];
    front++;
    if(front > rear)
    front = rear = -1;
    return val;
    }
}
int peek()
{
    if(front==-1 || front>rear)
    {
    printf("\n |||||||||CAR PARK IS EMPTY|||||||||\n\n");
    return -1;
    }
    else
    {
    return queue[front];
    }
}
void display()
{
    int i;
    //printf("\n");
    if(front == -1 || front > rear)
    printf("\n |||||||||CAR PARK IS EMPTY|||||||||\n\n");
    else
    {
    for(i = front;i <= rear;i++)
    printf("\t %d", queue[i]);
    }
}