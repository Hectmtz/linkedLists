#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct list_node
{
   struct list_node *prev, *next;
   int coeff;
   int exp;
};

struct list
{
   struct list_node *first, *last;
};

int calculate(struct list *list, int var);
struct list *list_create(void);
struct list_node *node_create(int coeff, int exp);
void print_list(struct list *list);
void push_front(struct list *list, int coeff, int exp);

int main()
{
    int i, res, num, exp, coeff, var;
    struct list *list = list_create();
    scanf("%d", &num);
    for(i=0; i<num; i++)
    {
        scanf("%d", &coeff);
        scanf("%d", &exp);
        push_front(list, coeff, exp);
    }
    scanf("%d", &var);
    res=calculate(list, var);
    printf("%d", res);
    free(list);
}

struct list_node *node_create(int coeff, int exp)
{
   struct list_node *new = (struct list_node*)malloc(sizeof(struct list_node));
   if (new == NULL)
   {
      printf("Memory allocation failed");
      exit(EXIT_FAILURE);
   }
   new->coeff = coeff;
   new->exp = exp;
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

int calculate(struct list *list, int var)
{
    int sum=0;
    struct list_node *aux = list->first;
    while(aux != NULL)
    {
        sum += (aux->coeff *(pow(var, aux->exp)));
        aux = aux->next;
    }
    free(aux);
    return sum;
}

void print_list(struct list *list)
{
    struct list_node *aux = list->first;
    while(aux != NULL)
    {
        printf("%d %d", aux->coeff, aux->exp);
        aux = aux->next;
    }
    free(aux);
    return;
}

void push_front(struct list *list, int coeff, int exp)
{
    struct list_node *new = node_create(coeff, exp);
    if (list -> first == NULL)
    {
        list -> first = new;
        list -> last = new;
        return;
    }
    list -> first -> prev = new;
    new -> next = list -> first;
    list -> first = new;
}