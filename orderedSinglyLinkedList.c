#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  node
{
    int data;
    struct node *next;
}TNode;

typedef TNode* TNodeptr;

TNode *create_node(int data);
void insert_in_order(int data, TNodeptr *head);
void print_list(TNode *head);
void release_list(TNode *head);


int main()
{
    int i=0, j=0;
    int cases, elements=0, data=0;
    //printf("Numero de casos pruebas: ");
    scanf("%d", &cases);
    for (i=0; i<cases; i++)
    {
        TNode *head=NULL;
        //printf("Cantidad de elementos de la lista: ");
        scanf("%d", &elements);
        for (j=0; j<elements; j++)
        {
            //printf("Cual es el dato de la lista? ");
            scanf("%d", &data);
            insert_in_order(data, &head);
        }
        print_list(head);
        printf("\n");
    }
}

TNode *create_node(int data)
{
    TNode *newNode = (TNode*)malloc(sizeof(TNode));
    if (newNode==NULL)
    {
        printf("Error al crear el nodo");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert_in_order(int data, TNodeptr *head)
{
    TNode *newNode = create_node(data);
    TNode *aux = *head;
    int count=0;
    //Empty list
    if (aux==NULL)
    {
        newNode->next = *head;
        *head=newNode;
        return;
    }
    //1 node case
    if (aux->next==NULL)
    {
        if(data>=aux->data)
        {
            newNode->next = aux->next;
            aux->next=newNode;
            return;
        }
        else
        {
            newNode->next = aux;
            *head=newNode;
            return;
        }
    }
    //More than 1 node
    while (aux->next != NULL)
    {
        if(count==0 && data<aux->data)
        {
            newNode->next = *head;
            *head = newNode;
            return;
        }
        if (data>=aux->data && data<=aux->next->data)
        {
            newNode->next=aux->next;
            aux->next=newNode;
            return;
        }
        if(data>aux->next->data && aux->next->next ==NULL)
        {
            newNode->next = aux->next->next;
            aux->next->next=newNode;
            return;
        }
        aux=aux->next;
        count++;
    }
    free(aux);
}

void print_list(TNode *head)
{
    TNode *aux = head;
    while(aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    free(aux);
    return;
}