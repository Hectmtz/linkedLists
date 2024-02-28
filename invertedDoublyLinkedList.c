#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  node
{
    int data;
    struct node *next, *prev;
}TNode;


typedef struct list
{
   TNode *first, *last;
}TList;


TNode *create_node(int data);
void print_list(TList *list);
TList *list_create(void);
void push_back(int data, TList *list);
void invertir(TList *list);

int main()
{
    int i=0, j=0;
    int cases, elements=0, data=0;
    //printf("Numero de casos pruebas: ");
    scanf("%d", &cases);
    for (i=0; i<cases; i++)
    {
        TList *list = list_create();
        //printf("Cantidad de elementos de la lista: ");
        scanf("%d", &elements);
        for (j=0; j<elements; j++)
        {
            //printf("Cual es el dato de la lista? ");
            scanf("%d", &data);
            //insert_in_order(data, &list);
            push_back(data, list);
        }
        invertir(list);
        print_list(list);
        printf("\n");
        free(list);
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

TList *list_create(void)
{
   TList *n = (struct list*)malloc(sizeof(TList));
   if (n == NULL)
   {
      exit(EXIT_FAILURE);
   }
   n -> first = n -> last = NULL;
   return n;
}

void push_back(int data, TList *list)
{
   TNode *new = create_node(data);
   if (list -> first == NULL)
   {
      list -> first = new;
      list -> last = new;
      return;
   }
   new -> prev = list -> last;
   list -> last -> next = new;
   list -> last = new;
}

void invertir(TList *list)
{
    TNode *aux = list->first;
    while (list->last != aux)
    {
        TNode *aux2 = aux->next;
        if(aux2 == NULL)
        {
            free(aux);
            return;
        }
        if(aux2->next==NULL)
        {
            aux2->next = list->first;
            aux2->prev = NULL;
            aux->next = NULL;
            list->last = aux;
            list->first = aux2;
        }
        else
        {
            aux->next = aux2->next;
            aux2->next->prev = aux;
            list->first->prev = aux2;
            aux2->next = list->first;
            list->first = aux2;
        }
    }
}

void print_list(TList *list)
{
    TNode *aux = list->first;
    while(aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    free(aux);
    return;
}