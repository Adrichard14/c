#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;
int size;

void offer(int placa)
{
    if (head == NULL)
    {
        head = (Node *)malloc(sizeof(Node));
        head->data = placa;
        tail = head;
    }
    else
    {
        Node *newNode = NULL;
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = placa;
        newNode->next = tail;
        tail->prev = newNode;
        tail = newNode;
    }
    size++;
}

Node *poll()
{
    Node *p = head;
    if (p == NULL)
    {
        return NULL;
    }
    head = head->prev;
    p->next = NULL;
    p->prev = NULL;

    size--;
    return p;
}

int search(int placa)
{
    int count = 1;
    Node *tmp = head;
    Node *node = NULL;
    if (tmp->data == placa)
    {
        return count;
    }
    while ((node = poll()) != NULL)
    {
        if (node->data == placa)
        {
            return count;
        }
        count++;
    }
    return count;
}

void output()
{
    Node *p = head;

    printf("Head");
    Node *node = NULL;
    while ((node = poll()) != NULL)
    {
        printf("%i<-", node->data);
        printf("Tail\n");
    }
}

void dequeue(int value)
{
    Node *p = head;
    Node *temp = p;

    while (p->data != value)
    {
        p = &p->next;
    } 
    if(p->data == value){
        p->data = NULL;
        return;
    }
    return;
}

void freeMemory()
{
    Node *p = head;
    Node *temp = p;

    while (p != NULL)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
}

int main()
{
    offer(100);
    offer(101);
    offer(103);
    offer(104);
    offer(102);
    
    dequeue(104);

    output();
    int number = search(104);
    printf("%i", number);
    freeMemory();

    return 0;
}