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
            write(2, "Error\n", 6);
            return (1);
        }
        ptr = ft_lstnew(ft_atoi(s[i]));
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
            return (1);
        }
        i++;
    }
    return (i);
}

void sort_3(t_stack **a)
{
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
    char * t;
    int i;
    char **s;
    char *j = NULL;

    i = 1;
    if (argc == 1)
        return (0);
    while (argv[i])
    {
        t = j;
        j = ft_strjoin(j , argv[i++]);
        free(t);
    }
    i = 1;
    s = ft_split(j, ' ');
    free(j);
    if (is_valid(s) == 0 || is_duplicate(s) == 0)
    {
        ft_free(s);
        write(2, "Error\n", 6);
        return (1);
    }
    if (ft_arrlen(s) == 1)
        return (0);
    stack_init(&a, s);
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
    // while (a){
    //     printf("%d\n", a->number);
    //     a = a->next;
    // }
    // fix_index(a);
    // up_or_down(a);
    // ptr = small_number(a);
    // if (ptr->above_line ==  1)
    //     while (a->number != ptr->number)
    //         ra(a, 1);
    // else
    //     while (a->number != ptr->number)
    //         rra(a, 1);
    // ptr = a;
    // while (ptr)
    // {
    //     printf("%d\n", ptr->number);
    //     ptr = ptr->next;
    // }
    ft_lstclear(&a);
    ft_free(s);
    free(j);
    return (0);
}