#include "push_swap.h"

void sa(t_stack *a, int flag)
{
    int tmp;

    tmp = a->number;
    a->number = a->next->number;
    a->next->number = tmp;
    if (flag == 0)
        write(1, "sa\n", 3);
}

void ra(t_stack *a, int flag)
{
    int tmp;
    t_stack *ptr;

    ptr = a;
    tmp = a->number;
    while (ptr->next)
    {
        ptr->number = ptr->next->number;
        ptr = ptr->next;
    }
    ptr->number = tmp;
    if (flag == 0)
        write(1, "ra\n", 3);
}

void rra(t_stack *a, int flag)
{
    int tmp;
    t_stack *ptr;

    ptr = a;
    while (ptr->next)
        ptr = ptr->next;
    tmp = ptr->number;
    while (ptr->prev)
    {
        ptr->number = ptr->prev->number;
        ptr = ptr->prev;
    }
    ptr->number = tmp;
    if (flag == 0)
        write(1, "rra\n", 4);
}

void sb(t_stack *b, int flag)
{
    int tmp;

    tmp = b->number;
    b->number = b->next->number;
    b->next->number = tmp;
    if (flag == 0)
        write(1, "sb\n", 3);
}

void rb(t_stack *b, int flag)
{
    int tmp;
    t_stack *ptr;

    ptr = b;
    tmp = b->number;
    while (ptr->next)
    {
        ptr->number = ptr->next->number;
        ptr = ptr->next;
    }
    ptr->number = tmp;
    if (flag == 0)
        write(1, "rb\n", 3);
}

void rrb(t_stack *b, int flag)
{
    int tmp;
    t_stack *ptr;

    ptr = b;
    while (ptr->next)
        ptr = ptr->next;
    tmp = ptr->number;
    while (ptr->prev)
    {
        ptr->number = ptr->prev->number;
        ptr = ptr->prev;
    }
    ptr->number = tmp;
    if (flag == 0)
        write(1, "rrb\n", 4);
}

void ss(t_stack *a, t_stack *b)
{
    sa(a, 1);
    sb(b, 1);
    write(1, "ss\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
    ra(a, 1);
    rb(b, 1);
    write(1, "rr\n", 3);
}

void rrr(t_stack *a, t_stack *b)
{
    rra(a, 1);
    rrb(b, 1);
    write(1, "rrr\n", 4);    
}

void pa(t_stack **a, t_stack **b)
{
    t_stack *ptr = *b;
    (*b) = (*b)->next;
    if (*b != NULL)
        (*b)->prev = NULL;
    if (!a)
    {
        (*a) = ptr;
        (*a)->next = NULL;
        (*a)->prev = NULL;
    }
    else
    {
        ptr->next = (*a);
        ptr->prev = NULL;
        (*a) = ptr;
    }
    write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
    t_stack *ptr = *a;
    *a = (*a)->next;
    if (*a != NULL)
        (*a)->prev = NULL;
    if (!b)
    {
        *b = ptr;
        (*b)->next = NULL;
        (*b)->prev = NULL;
    }
    else
    {
        ptr->next = *b;
        ptr->prev = NULL;
        (*b) = ptr;
    }
    write(1, "pb\n", 3);
}