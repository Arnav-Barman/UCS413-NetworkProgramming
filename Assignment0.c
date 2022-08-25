#include<stdio.h>
#include<stdlib.h>

struct QNode{
 int key;
 struct QNode*next;
};

typedef struct QNode node;

struct QStructure{
 node *front,*rear;
};

typedef struct QStructure Queue;

node* createNode(){
int a=0;
printf("Enter the number\n");
scanf("%d",&a);
node *temp = malloc(sizeof(node));
temp->key=a;
return temp;
}

Queue *createQueue(){
Queue *temp = malloc(sizeof(Queue));
 return temp;
}

Queue *equeue(Queue *q,node *newnode){
 if(q->front==NULL)
  q->front=newnode;
 else
  q->rear->next = newnode;
 q->rear=newnode;
 return q;
}

Queue *dqueue(Queue *q){
 if(q->front!=NULL){
  node *temp=q->front;
  q->front=q->front->next;
  if(q->front==NULL){
   q->rear=NULL;
  }
 }
 return q;
}


void displayQueue(Queue *q){
 node* ptr=q->front;
 while(ptr!=NULL){
  printf("%d ",ptr->key);
  ptr=ptr->next;
 }
 printf("\n");
}

int countQueue(Queue *q){
 node* ptr=q->front;
 int ans=0;
 while(ptr!=NULL){
  ans+=1;
  ptr=ptr->next;
 }
 return ans;
}

void main()
{
  Queue* a = createQueue();
  a=equeue(a,createNode());
  a=equeue(a,createNode());
  printf("There are a total of %d elements in the queue\n",countQueue(a));
  displayQueue(a);
  a=dqueue(a);
  a=dqueue(a);
  printf("There are a total of %d elements in the queue\n",countQueue(a));
  displayQueue(a);
}
