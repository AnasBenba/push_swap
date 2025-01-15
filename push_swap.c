// 

#include "push_swap.h"

int stack_init(t_stack **a, char **s)
{
    t_stack *ptr;
    long test;
    int i = 0;

    while (s[i])
    {
        test = ft_atoi(s[i]);
        if (test > INT_MAX || test < INT_MIN)
        {
            ft_free(s);
            ft_lstclear(a); // Free the stack if initialization fails
            write(2, "Error\n", 6);
            exit(1);
        }
        ptr = ft_lstnew((int)test); // Casting test to int
        if (!ptr)
        {
            ft_free(s);
            ft_lstclear(a); // Free the stack if initialization fails
            write(2, "Error\n", 6);
            exit(1);
        }
        ft_lstadd_back(a, ptr);
        i++;
    }
    return (0);
}

size_t ft_arrlen(char **s)
{
    size_t i = 0;
    long test;
    if (!s)
        return (0);
    while (s[i])
    {
        test = ft_atoi(s[i]);
        if (test > INT_MAX || test < INT_MIN)
        {
            ft_free(s);
            write(2, "Error\n", 6);
            exit(1);
        }
        i++;
    }
    return (i);
}

void sort_3(t_stack **a)
{
    if (!a || !(*a) || !(*a)->next || !(*a)->next->next)
        return;

    while (1)
    {
        if (((*a)->number > (*a)->next->number) && ((*a)->number > (*a)->next->next->number))
            ra(a, 0);
        else if ((*a)->number > (*a)->next->number)
            sa((*a), 0);
        else if (((*a)->next->number > (*a)->number) && ((*a)->next->number > (*a)->next->next->number))
            rra(a, 0);
        else
            break;
    }
}

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    t_stack *ptr;
    t_stack *tmp;
    char *t;
    int i;
    char **s;
    char *j = NULL;

    i = 1;
    if (argc == 1)
        return (0);
    while (argv[i])
    {
        t = j;
        j = ft_strjoin(j, argv[i++]);
        if (!j)
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        free(t);
    }
    s = ft_split(j, ' ');
    if (!s || is_valid(s) == 0 || is_duplicate(s) == 0)
    {
        ft_free(s);
        free(j);
        write(2, "Error\n", 6);
        exit(1);
    }
    if (ft_arrlen(s) == 1)
    {
        ft_free(s);
        free(j);
        return (1);
    }
    if (stack_init(&a, s) == 1)
    {
        ft_free(s);
        free(j);
        return (1);
    }
    if (ft_lstsize(a) == 2)
    {
        if (a->number > a->next->number)
            sa(a, 0);
    }
    else if (ft_lstsize(a) == 3)
        sort_3(&a);
    else
    {
        push_to_b(&a, &b);
        up_or_down(a);
        up_or_down(b);
        take_targets(a, b);
        cost(a, b);
        perfect_to_push(b);
    }
    while (b)
    {
        sort(&a, &b);
        up_or_down(a);
        up_or_down(b);
        take_targets(a, b);
        cost(a, b);
        perfect_to_push(b);
    }
    ptr = small_number(a);
    up_or_down(a);
    tmp = a;
    if (ptr->above_line ==  1)
    {
        while (tmp != ptr)
        {
            ra(&a, 0);
            tmp = a;
        }
    }
    else
    {
        while (tmp != ptr)
        {
            rra(&a, 0);
            tmp = a;
        }
    }
    ft_lstclear(&a);
    ft_free(s);
    free(j);
    return (0);
}