#include "sort.h"

/**
 * cocktail_sort_list - Implementation of cocktail sort algorithm
 * @list: doubly linked list 
 */
listint_t *front_sweep(listint_t **list, listint_t *head);
int back_sweep(listint_t **list, listint_t *head);

listint_t *front_sweep(listint_t **list, listint_t *head)
{
    listint_t *tmp;

    while (list && head->next)
        {
            if (head->n > head->next->n)
            {
                tmp = head->next;
                head->next = tmp->next;
                tmp->prev = head->prev;

                if (tmp->next != NULL)
                    tmp->next->prev = head;

                if (head->prev != NULL)
                    head->prev->next = tmp;

                head->prev = tmp;
                tmp->next = head;

                if (tmp->prev == NULL)
                    *list = tmp;
                print_list(*list);
            }
            else
                head = head->next;
        }
        return (head);
}

int back_sweep(listint_t **list, listint_t *head)
{
    listint_t *tmp;
    int swap = 0;

    while (head->prev)
        {
            if (head->n < head->prev->n)
            {
                tmp = head->prev;
                head->prev = tmp->prev;
                tmp->next = head->next;

                if (head->next != NULL)
                {
                    head->next->prev = tmp;
                } 

                if (tmp->prev != NULL)
                {
                    tmp->prev->next = head;
                }

                head->next = tmp;
                tmp->prev = head;

                if (head->prev == NULL)
                    *list = head;
                swap = 1;
                print_list(*list);
            }
            else
                head = head->prev;
        }
        return (swap);
}
void cocktail_sort_list(listint_t **list)
{
    int swap;
    listint_t *head;

    swap = 1;
    while (swap)
    {
        head = *list;
        head = front_sweep(list, head);
        
        swap = 0;
        swap = back_sweep(list, head);
        
    }
}
