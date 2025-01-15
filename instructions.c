// #include "push_swap.h"

// void sa(t_stack *a, int flag)
// {
//     int tmp;

//     tmp = a->number;
//     a->number = a->next->number;
//     a->next->number = tmp;
//     if (flag == 0)
//         write(1, "sa\n", 3);
// }

// void ra(t_stack **a, int flag)
// {
//     t_stack *first;
//     t_stack *last;

//     if (!a || !(*a) || !(*a)->next)
//         return;

//     first = *a;
//     last = *a;

//     while (last->next)
//         last = last->next;

//     *a = first->next;
//     (*a)->prev = NULL;

//     last->next = first;
//     first->prev = last;
//     first->next = NULL;

//     if (flag == 0)
//         write(1, "ra\n", 3);
// }

// t_stack	*find_last(t_stack *stack) //Define a function that returns the pointer to the last node
// {
// 	if (!stack)
// 		return (NULL);
// 	while (stack->next) //Loop until the end of the stack is reached
// 		stack = stack->next;
// 	return (stack);
// }

// static void	rev_rotate(t_stack **stack) //Define a funtion that rotates a stack's bottom node, to the top
// {
// 	t_stack	*last; //To store the pointer to the last node

// 	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
// 		return ;
// 	last = find_last(*stack);
// 	last->prev->next = NULL; //Assign to the `next` attribute of the node before itself, `NULL` effectively setting it as the current last node
// 	last->next = *stack; //Assign to its own `next` attribute as the top node of the stack
// 	last->prev = NULL; //Detach itself from the node before it
// 	*stack = last;  //Complete appending itself to the top of the stack, and now holds the pointer to the top node
// 	last->next->prev = last; //Update the current last node of the stack
// }

// void	rra(t_stack **a, int flag) //Rotate the bottom of `a` to the top of the stack and print the instruction
// {
// 	rev_rotate(a);
// 	if (flag == 0)
// 		write(1, "rra\n", 4);
// }

// // void rra(t_stack *a, int flag)
// // {
// //     int tmp;
// //     t_stack *ptr;

// //     ptr = a;
// //     while (ptr->next)
// //         ptr = ptr->next;
// //     tmp = ptr->number;
// //     while (ptr->prev)
// //     {
// //         ptr->number = ptr->prev->number;
// //         ptr = ptr->prev;
// //     }
// //     ptr->number = tmp;
// //     if (flag == 0)
// //         write(1, "rra\n", 4);
// // }

// void sb(t_stack *b, int flag)
// {
//     int tmp;

//     tmp = b->number;
//     b->number = b->next->number;
//     b->next->number = tmp;
//     if (flag == 0)
//         write(1, "sb\n", 3);
// }

// void rb(t_stack **b, int flag)
// {
//     t_stack *first;
//     t_stack *last;

//     if (!b || !(*b) || !(*b)->next)
//         return;

//     first = *b;
//     last = *b;

//     while (last->next)
//         last = last->next;

//     *b = first->next;
//     (*b)->prev = NULL;

//     last->next = first;
//     first->prev = last;
//     first->next = NULL;

//     if (flag == 0)
//         write(1, "rb\n", 3);
// }

// void rrb(t_stack *b, int flag)
// {
//     int tmp;
//     t_stack *ptr;

//     ptr = b;
//     while (ptr->next)
//         ptr = ptr->next;
//     tmp = ptr->number;
//     while (ptr->prev)
//     {
//         ptr->number = ptr->prev->number;
//         ptr = ptr->prev;
//     }
//     ptr->number = tmp;
//     if (flag == 0)
//         write(1, "rrb\n", 4);
// }

// void ss(t_stack *a, t_stack *b)
// {
//     sa(a, 1);
//     sb(b, 1);
//     write(1, "ss\n", 3);
// }

// void rr(t_stack **a, t_stack **b)
// {
//     ra(a, 1);
//     rb(b, 1);
//     write(1, "rr\n", 3);
// }

// void rrr(t_stack *a, t_stack *b)
// {
//     rra(&a, 1);
//     rrb(b, 1);
//     write(1, "rrr\n", 4);    
// }

// void pa(t_stack **a, t_stack **b)
// {
//     t_stack *ptr;

//     if (!b || !(*b))
//         return;

//     ptr = *b;
//     *b = (*b)->next;
//     if (*b)
//         (*b)->prev = NULL;

//     if (!(*a))
//     {
//         *a = ptr;
//         ptr->next = NULL;
//         ptr->prev = NULL;
//     }
//     else
//     {
//         ptr->next = *a;
//         (*a)->prev = ptr;
//         *a = ptr;
//     }

//     write(1, "pa\n", 3);
// }

// // void pa(t_stack **a, t_stack **b)
// // {
// //     t_stack *ptr = *b;
// //     if (!(*b) || !b)
// //         return ;
// //     if ((*b)->next != NULL)
// //         (*b) = (*b)->next;
// //     if (*b != NULL)
// //         (*b)->prev = NULL;
// //     if (!a)
// //     {
// //         (*a) = ptr;
// //         (*a)->next = NULL;
// //         (*a)->prev = NULL;
// //     }
// //     else
// //     {
// //         ptr->next = (*a);
// //         ptr->prev = NULL;
// //         (*a) = ptr;
// //     }
// //     write(1, "pa\n", 3);
// // }

// void pb(t_stack **a, t_stack **b)
// {
//     t_stack *ptr = *a;
//     if ((*a) == NULL)
//         return ;
//     *a = (*a)->next;
//     if (*a != NULL)
//         (*a)->prev = NULL;
//     fix_index(*a);
//     if (!b)
//     {
//         *b = ptr;
//         (*b)->next = NULL;
//         (*b)->prev = NULL;
//     }
//     else
//     {
//         ptr->next = *b;
//         ptr->prev = NULL;
//         (*b) = ptr;
//     }
//     write(1, "pb\n", 3);
// }

#include "push_swap.h"

void sa(t_stack *a, int flag)
{
    int tmp;

    if (!a || !(a->next))
        return;

    tmp = a->number;
    a->number = a->next->number;
    a->next->number = tmp;
    if (flag == 0)
        write(1, "sa\n", 3);
}

void ra(t_stack **a, int flag)
{
    t_stack *first;
    t_stack *last;

    if (!a || !(*a) || !(*a)->next)
        return;

    first = *a;
    last = *a;

    while (last->next)
        last = last->next;

    *a = first->next;
    (*a)->prev = NULL;

    last->next = first;
    first->prev = last;
    first->next = NULL;

    if (flag == 0)
        write(1, "ra\n", 3);
}

t_stack *find_last(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

static void rev_rotate(t_stack **stack)
{
    t_stack *last;

    if (!*stack || !(*stack)->next)
        return;
    last = find_last(*stack);
    if (last->prev)
        last->prev->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    (*stack)->prev = last;
    *stack = last;
}

void rra(t_stack **a, int flag)
{
    rev_rotate(a);
    if (flag == 0)
        write(1, "rra\n", 4);
}

void sb(t_stack *b, int flag)
{
    int tmp;

    if (!b || !(b->next))
        return;

    tmp = b->number;
    b->number = b->next->number;
    b->next->number = tmp;
    if (flag == 0)
        write(1, "sb\n", 3);
}

void rb(t_stack **b, int flag)
{
    t_stack *first;
    t_stack *last;

    if (!b || !(*b) || !(*b)->next)
        return;

    first = *b;
    last = *b;

    while (last->next)
        last = last->next;

    *b = first->next;
    (*b)->prev = NULL;

    last->next = first;
    first->prev = last;
    first->next = NULL;

    if (flag == 0)
        write(1, "rb\n", 3);
}

void rrb(t_stack **b, int flag)
{
    rev_rotate(b);
    if (flag == 0)
        write(1, "rrb\n", 4);
}

void ss(t_stack *a, t_stack *b)
{
    sa(a, 1);
    sb(b, 1);
    write(1, "ss\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
    ra(a, 1);
    rb(b, 1);
    write(1, "rr\n", 3);
}

void rrr(t_stack **a, t_stack **b)
{
    rra(a, 1);
    rrb(b, 1);
    write(1, "rrr\n", 4);
}

void pa(t_stack **a, t_stack **b)
{
    t_stack *ptr;

    if (!b || !(*b))
        return;

    ptr = *b;
    *b = (*b)->next;
    if (*b)
        (*b)->prev = NULL;

    if (!(*a))
    {
        *a = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
    }
    else
    {
        ptr->next = *a;
        (*a)->prev = ptr;
        *a = ptr;
    }

    write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
    t_stack *ptr;

    if (!a || !(*a))
        return;

    ptr = *a;
    *a = (*a)->next;
    if (*a)
        (*a)->prev = NULL;

    if (!(*b))
    {
        *b = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
    }
    else
    {
        ptr->next = *b;
        (*b)->prev = ptr;
        *b = ptr;
    }

    write(1, "pb\n", 3);
}