#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{//creating a structure for stack
    char parts[6][10];
    char top;
};
struct queue{//creating a structure for queue
    char parts[6][10];
    char f,r;
};
struct snode{//creating a structure for a single linked list node and circular linked list node
    char data;
    struct snode *next;
};
struct dnode{//creating a structure for double linked list node
    char data;
    struct snode *next,*prev;
};
void initialize_stack(struct stack *s)//function to initialize a stack that is setting the top value to -1
{
    s->top=-1;
}
void initialize_queue(struct queue *q)//function to initialize a queue that is setting the front and rear value to -1
{
    q->f=-1;
    q->r=-1;
}
void insert_dll(struct dnode** head, int data) {//function to insert a node in the end of a doubly linked list
    struct dnode* newNode = (struct dnode*)malloc(sizeof(struct dnode));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct dnode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}
void insert_sll(struct snode** head, int newData) {//function to insert a node in the end of a singly linked list
    struct snode* newNode = (struct snode*)malloc(sizeof(struct snode));
    struct snode* temp = *head;
    newNode->data = newData;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
}

void deleteNode(struct snode** head, int key)//function to delete a node based on the data present in the node
{
    struct snode *temp = *head, *prev = NULL;
    if (temp != NULL && (temp->data) == key) {
        *head = temp->next;
        free(temp);
        return;
    }
}
void enqueue(struct queue *q, char c[10]) {//function to insert a data value inside a queue
    if (q->r == 5) {
        printf("Queue is full\n");
        return;
    }

    if (q->f == -1) { // First enqueue
        //q->f = 0;
    }

    int x = ++q->r;
    strcpy(q->parts[x], c);
    printf("%s has arrived via conveyor belt\n", c);
}

char *dequeue(struct queue *q)//function to remove a value from the queue
{
    if(q->r==-1)
    {
        printf("queue is empty");
        return '\0';
    }
    if (q->r==5)
    {
        printf("queue is full");
    }
    if(q->f==q->r)
    {
        initialize_queue(q);
    }
    q->f++;
    printf("Robotic arm picked up %s\n",q->parts[q->f]);
    return (q->parts[q->f]);
    
}
void push (struct stack *s,char p[10])//function to insert a value to stack
{
    if(s->top==5)
    {
        printf("stack is full");
    }
    s->top++;
    strcpy(s->parts[s->top],p);
    printf("Robotic arm assembled %s \n",p);
    return;
}
void pop_assembly(struct stack *s)//reccursive to function to empty the given stack
{
    if(s->top==-1)
    {
        return;
    }
    printf("%s\n",s->parts[s->top--]);
    pop_assembly(s);
}
void main()
{
    struct stack s1,*s;//declaring and using pointer for queue and stack
    struct queue q1,*q;
    s=&s1;
    q=&q1;
    //question part a
    initialize_queue(q);//initializing the queue
    initialize_stack(s);//initializing the stack
    //getting the part from the coveyor belt
    printf(" This assignment Key objective are:\nimplementations of queue stack arrays singly linkedlist doubly linked list and circular linked list\n\n\n");
    enqueue(q,"Engine");
    enqueue(q,"chassis");
    enqueue(q,"Wheels"); 
    enqueue(q,"Battery");
    enqueue(q,"Hood");
    //using the robotic arm to assemble the given parts in proper order
    for(int i=0;i<5;i++)
    {
        push(s,dequeue(q));
    }
    printf("assembly order of the robotic arm to give better energy efficiency in manufacturing :\n");
    //function to show the order of part assembled by the robotic arm
    pop_assembly(s);
    printf("assembly of the car is done!!");
    //question part b
    int garage[8];//a garage which stores the model number of the vehicle
    int x=2025001;//model number of the very first vehicle consists of manufacturing year followed the number of car manufactured
    printf("\nNow adding the prototype to the garage:\n");
    for(int i=0;i<8;i++)//function to add the prototype into the garage
    {
        garage[i]=x;
        x++;
        printf("Added Model number:%d in garage slot %d\n",garage[i],i+1);
    }
    //condition for overflow that is when the garage is full
    printf("garage is currently full \n");
    printf("model number:2025001 is sent back to the factory due to engine malfunctioning now garage slot 1 is empty\n");
    garage[0]= x;
    printf("Added Model number:%d in garage slot 1\n",x++);
    printf("garage is currently full \n");
    printf("model number:2025002 is sold  now garage slot 2 is empty\n");
    garage[1]= x;
    printf("Added Model number:%d in garage slot 2\n",x++);
//question part c
printf("finding the defective prototypes in the gararge:\n");
struct snode *head=NULL;
//using the loop to traverse through each prototype to identify the defective one
for(int i=0;i<8;i++)
{
    if((i==(2)||i==(5)))
    {
        printf("Model number:%d is defective\n",garage[i]);
        insert_sll(&head,garage[i]);//added the defective prototype to the linked list that is sending them to the factory
        printf("Sent to factory for repairs\n");
        
    }
    else
    {
            printf("Mode number:%d is not defective\n",garage[i]);
    }
}
printf("repairs of Model number:%d has been done now sending it to repainting as the painting layer was removed for repairs\n",garage[2]);//sending one of the prototype to doubly linked list
struct dnode **dhead=NULL;
insert_dll(&dhead,garage[2]);
deleteNode(&head,garage[2]);//removing that prototype from the singly linked list
//question part d
printf("for VIP clients Model number : %d & %d are given to upgrade checks\n",garage[0],garage[4]);
struct snode *chead=NULL;
struct snode *check=NULL;
int y;
insert_sll(&chead,garage[0]);
insert_sll(&chead,garage[4]);
chead->next->next=chead;
check=chead;
//traversing through the prototype multiple times to verify the functionality of the upgrades
for(int i=0;i<6;i++)
{

    printf("Upgrade check round %d\n",(i/2)+1);
    y=check->data;
    check=check->next;
    printf("checked model number:%d\n",y);
}
//brief description of the upgraded given to the VIP clients
printf("model number:%d has been given hydrogen cylinder and can be fueled by hydrogen gas\n",garage[0]);
printf("mode number :%d has been upgraded with nitro booster and now has a top speed of 450 mph",garage[4]);
//Name and ROll number
printf("\n\n\n\n\t\t\t\t\t\tassignment done by \n\t\t\t\t\t\t\t\tName:kaarthick\n\t\t\t\t\t\t\t\tRoll number:me24b1056");
}