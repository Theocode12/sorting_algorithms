#include "sort.h"

/**
 * insertion_sort_list - Insertion Algorithm.
 * @list: doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *start, *rev;

	if (!list)
		return;

    for(start = (*list); start; start = start->next)
    {
        while(start->next && start->next->n < start->n)
        {
            rev = start->next;
            start->next = rev->next;
            rev->prev = start->prev;

            if (rev->next != NULL)
                rev->next->prev = start;

            if (start->prev != NULL)
                start->prev->next = rev;

            rev->next = start;
			start->prev = rev;
			if (rev->prev == NULL)
				*list = rev;
			else
				start = rev->prev;
			print_list(*list);
        }
    }
}
