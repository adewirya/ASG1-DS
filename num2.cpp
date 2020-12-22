#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int angka;
    Node *next;
}*head  = NULL, *tail = NULL;

Node *createNode(int angka)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->angka=angka;
    newNode->next=NULL;

    return newNode;
}

void pushTail(int angka)
{
    Node *newNode = createNode(angka);
    if(!head)
        head = tail = newNode;
    else 
    {
        tail->next=newNode;
        tail = newNode;
    }
}

int checkCycle()
{
    Node *curr = head;
    Node *temp = head;
    while(curr && temp && curr->next)
    {
        temp = temp->next;
        curr = curr->next->next;

        if(curr==temp)
            return 1;
    }
    return 0;
}

void print()
{
    struct Node* curr = head;
    while (curr)
    {
        printf("%d ", curr->angka);
        curr = curr->next;
    }
    puts("");
}

int main()
{
    for (int i = 10; i<51; i+= 10)
    pushTail(i);
    head->next->next = head;
    // print();
    (checkCycle()) ? puts("There's a Cycle") : puts("No Cycle");
    return 0;
}