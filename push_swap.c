#include "push_swap.h"

void stack_init(t_stack **a, char **s)
{
    t_stack *ptr;

    int i = 0;
    while (s[i])
    {
        ptr = ft_lstnew(ft_atoi(s[i]));
        ft_lstadd_back(a, ptr);
        i++;
    }
}

size_t ft_arrlen(char **s)
{
    size_t i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    int i;
    char **s;
    char *tmp;
    char *j = NULL;

    i = 1;
    if (argc == 1)
        return (0);
    while (argv[i])
    {
        tmp = j;
        j = ft_strjoin(j , argv[i++]);
        free(tmp);
    }
    i = 1;
    s = ft_split(j, ' ');
    if (is_valid(s) == 0 || is_duplicate(s) == 0)
    {
        ft_free(s);
        free(j);
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
    {
        while (1)
        {
            if ((a->number > a->next->number) && (a->number > a->next->next->number))
                ra(a, 0);
            else if (a->number > a->next->number)
                sa(a, 0);
            else if ((a->next->number > a->number) && (a->next->number > a->next->next->number))
                rra(a, 0);
            else
                break;
        }
    }
    // t_stack *ptr = a;
    // while (ptr)
    // {
    //     ft_printf("%d\n", ptr->number);
    //     ptr = ptr->next;
    // }
    ft_lstclear(&a);
    ft_free(s);
    free(j);
    return (0);
}