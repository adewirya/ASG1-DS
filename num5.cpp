#include<stdio.h>
#include<stdlib.h>

struct Node 
{ 
    int angka; 
    struct Node* next; 
} *head = NULL , *tail = NULL;

Node *createNode ( int angka )
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->angka = angka;
    newNode->next=NULL;
    return newNode;
}

void ans( int angka)
{
    int count = 0;
    struct Node* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if(angka>count) return;

    temp = head;
    for (int i = 1; i < count - angka; i++) 
    temp = temp->next;
  
    printf("%d", temp->angka);
}

void pushTail(int angka)
{
    Node *temp = createNode(angka);
    if(!head)
        head=tail=temp;
    else 
    {
        tail -> next = temp;
        tail = temp; 
    }
}

int main()
{
  for (int i = 10; i<101; i+= 10)
  pushTail(i);

  int  n;
  scanf("%d", &n);
  ans(n);
}