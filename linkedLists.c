#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int ll_data_t;
struct list;

void print(struct list *list);
struct list *list_create(void);
void push_back(struct list *list, ll_data_t item_data);
void pop_back(struct list *list);
void push_front(struct list *list, ll_data_t item_data);
void pop_front(struct list *list);
void erase(struct list *list, ll_data_t data);
void clear(struct list *list);
static struct list_node *node_create(ll_data_t item_data);

struct list_node
{
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list
{
   struct list_node *first, *last;
};


int main()
{
    int i, num;
    ll_data_t data;
    struct list *list = list_create();
    char cad[11];
    //printf ("Numero de funciones que se realizaran: ");
    scanf("%d", &num);
    for (i=0; i<num; i++)
    {
        scanf("%s ", cad);
        scanf("%d", &data);
        if(strcmp(cad,"push_front") == 0)
        {
            push_front(list, data);
        }
        if(strcmp(cad,"pop_front") == 0)
        {
            pop_front(list);
        }
        if(strcmp(cad,"push_back") == 0)
        {
            push_back(list, data);
        }
        if(strcmp(cad,"pop_back") == 0)
        {
            pop_back(list);
        }
        if(strcmp(cad,"erase") == 0)
        {
            erase(list, data);
        }
        if(strcmp(cad,"clear") == 0)
        {
            clear(list);
        }
    }
    print(list);
    free(list);
}

struct list_node *node_create(ll_data_t item_data)
{
   struct list_node *new = (struct list_node*)malloc(sizeof(struct list_node));
   if (new == NULL)
   {
      printf("Memory allocation failed");
      exit(EXIT_FAILURE);
   }
   new->data = item_data;
   new->next = new->prev = NULL;
   return new;
}

struct list *list_create(void)
{
   struct list *list = (struct list*)malloc(sizeof(struct list));
   if (list == NULL)
   {
      printf("Memory allocation failed");
      exit(EXIT_FAILURE);
   }
   list->first = list->last = NULL;
   return list;
}


void push_front(struct list *list, ll_data_t item_data)
{
   struct list_node *new = node_create(item_data);
   if (list->first == NULL)
   {
      list->first = list->last = new;
      return;
   }
   list->first->prev = new;
   new->next = list->first;
   list->first = new;
}

void push_back(struct list *list, ll_data_t item_data)
{
   struct list_node *new = node_create(item_data);
   if (list->first == NULL)
   {
      list->first = list->last = new;
      return;
   }
   new->prev = list->last;
   list->last->next = new;
   list->last = new;
}

void pop_front(struct list *list)
{
   if (list->first == NULL)
   {
      return ;
   }
   if (list->first->next ==NULL)
   {
      free (list->first);
      list->first = list->last = NULL;
      return ;
   }
   struct list_node *aux = list->first;
   list->first = aux->next;
   list->first->prev = NULL;
   free (aux);
   return ;
}

void pop_back(struct list *list)
{
   if (list->first == NULL)
   {
      return;
   }
   if (list->first->next == NULL)
   {
      free (list->first);
      list->first = list->last = NULL;
      return;
   }
   struct list_node *aux = list->last;
   list -> last = aux->prev;
   list -> last->next = NULL;
   free (aux);
   return;
}

void erase(struct list *list, ll_data_t data)
{
   struct list_node *aux = list->first;
   while(aux != NULL)
   {
      if (aux->data == data)
      {
         // Item in first position
         if (aux->prev != NULL)
         {
            aux->prev->next = aux->next;
         }
         else
         {
            list->first = aux->next;
         }
         //Item in last position
         if (aux->next != NULL)
         {
            aux->next->prev = aux->prev;
         }
         else
         {
            list->last = aux->prev;
         }
         free (aux);
         return;
      }
      aux = aux->next;
   }
   return;
}

void print(struct list *list)
{
    struct list_node *aux = list->first;
    while(aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    return;
}

void clear(struct list *list)
{
   struct list_node *aux= list->first;
   while(aux != NULL)
   {
      pop_front(list);
      aux = aux->next;
   }
   return;
}