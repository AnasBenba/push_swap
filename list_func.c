// #include "push_swap.h"

// int	ft_strcmp(const char *s1, const char *s2)
// {
// 	size_t	i;

// 	i = 0;
// 	while ((s1[i] || s2[i]))
// 	{
// 		if ((unsigned char)s1[i] != (unsigned char)s2[i])
// 			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_lstsize(t_stack *lst)
// {
// 	int	count;

// 	count = 0;
// 	if (lst)
// 	{
// 		while (lst)
// 		{
// 			lst = lst->next;
// 			count++;
// 		}
// 	}
// 	return (count);
// }

// long	ft_atoi(const char *str)
// {
// 	long	i;
// 	long	sign;
// 	long	result;

// 	i = 0;
// 	sign = 1;
// 	result = 0;
// 	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
// 		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
// 		i++;
// 	if (str[i] == '-')
// 	{
// 		sign *= -1;
// 		i++;
// 	}
// 	else if (str[i] == '+')
// 		i++;
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = (result * 10) + (str[i] - '0');
// 		i++;
// 	}
// 	return (result * sign);
// }

// void	ft_lstadd_back(t_stack **lst, t_stack *new)
// {
// 	t_stack	*ptr;
// 	int		i;

// 	i = 1;
// 	if (new)
// 	{
// 		if (!*lst)
// 		{
// 			*lst = new;
// 			return ;
// 		}
// 		ptr = *lst;
// 		while (ptr->next)
// 		{
// 			ptr = ptr->next;
// 			i++;
// 		}
// 		ptr->next = new;
// 		ptr->next->prev = ptr;
// 		ptr = ptr->next;
// 		ptr->index = i;
// 	}
// }

// t_stack	*ft_lstnew(int number)
// {
// 	t_stack	*ptr;

// 	ptr = malloc(sizeof(t_stack));
// 	if (!ptr)
// 		return (NULL);
// 	ptr->number = number;
// 	ptr->next = NULL;
// 	ptr->prev = NULL;
// 	ptr->target = NULL;
// 	ptr->index = 0;
// 	return (ptr);
// }

// void	ft_lstclear(t_stack **lst)
// {
// 	t_stack	*ptr1;

// 	if (lst && *lst)
// 	{
// 		while ((*lst))
// 		{
// 			ptr1 = (*lst)->next;
// 			free((*lst));
// 			(*lst) = ptr1;
// 		}
// 		*lst = NULL;
// 	}
// }

// int	ft_isprint(int c)
// {
// 	if (c >= 32 && c <= 126)
// 		return (1);
// 	return (0);
// }

// static char	*ft_word(char const *s, char c, size_t *i)
// {
// 	size_t	word;
// 	size_t	y;
// 	char	*ptr;

// 	word = 0;
// 	while (s[(*i)] && s[(*i)] != c)
// 	{
// 		word++;
// 		(*i)++;
// 	}
// 	*i = *i - word;
// 	y = 0;
// 	ptr = (char *)malloc(word + 1);
// 	if (!ptr)
// 		return (NULL);
// 	while (s[(*i)] && s[(*i)] != c)
// 	{
// 		ptr[y] = s[(*i)];
// 		(*i)++;
// 		y++;
// 	}
// 	ptr[y] = '\0';
// 	(*i)++;
// 	return (ptr);
// }

// static size_t	ft_count_word(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	count;

// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		while (s[i] == c)
// 			i++;
// 		if (ft_isprint(s[i]))
// 			count++;
// 		while (ft_isprint(s[i]) && s[i] != c)
// 			i++;
// 	}
// 	return (count);
// }

// void	ft_free(char **ptr)
// {
// 	size_t	i;

// 	if (ptr == NULL)
// 		return ;
// 	i = 0;
// 	while (ptr[i])
// 	{
// 		free(ptr[i]);
// 		i++;
// 	}
// 	free(ptr);
// }

// static char	**ft_make(char const *s, char c, char **ptr, size_t len)
// {
// 	size_t	y;
// 	size_t	i;

// 	y = 0;
// 	i = 0;
// 	while (y < len)
// 	{
// 		while (s[i] == c)
// 			i++;
// 		ptr[y] = ft_word(s, c, &i);
// 		if (ptr[y] == NULL)
// 		{
// 			ft_free(ptr);
// 			return (NULL);
// 		}
// 		y++;
// 	}
// 	ptr[y] = NULL;
// 	return (ptr);
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t	len;
// 	char	**ptr;

// 	if (!s)
// 		return (NULL);
// 	len = ft_count_word(s, c);
// 	ptr = (char **)malloc(sizeof(char *) * (len + 1));
// 	if (!ptr)
// 		return (NULL);
// 	return (ft_make(s, c, ptr, len));
// }

// int	ft_isdigit(int c)
// {
// 	if (c >= 48 && c <= 57)
// 		return (1);
// 	return (0);
// }

// int is_valid(char **argv)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		j = 0;
// 		while (argv[i][j])
// 		{
// 			if (argv[i][j] == '-' || argv[i][j] == '+')
// 				j++;
// 			if (ft_isdigit(argv[i][j]) == 0)
// 				return (0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int is_duplicate(char **argv)
// {
// 	int i;
// 	int	j;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		j = 1 + i;
// 		while (argv[j])
// 		{
// 			if (ft_strcmp(argv[i], argv[j]) == 0)
// 				return (0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// size_t	ft_strlen(const char *c)
// {
// 	size_t	len;

// 	len = 0;
// 	while (c && c[len])
// 		len++;
// 	return (len);
// }

// static char	*ft_join(char *ptr, const char *s1, const char *s2)
// {
// 	int	i;
// 	int	y;

// 	i = 0;
// 	y = 0;
// 	while (s1 && s1[i])
// 	{
// 		ptr[i] = s1[i];
// 		i++;
// 	}
// 	ptr[i] = ' ';
// 	i++;
// 	while (s2 && s2[y])
// 	{
// 		ptr[i + y] = s2[y];
// 		y++;
// 	}
// 	ptr[i + y] = '\0';
// 	return (ptr);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*ptr;
// 	size_t	ptr_len;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	ptr_len = ft_strlen(s1) + ft_strlen(s2);
// 	ptr = (char *)malloc(ptr_len + 2);
// 	if (!ptr)
// 		return (NULL);
// 	if (ptr_len == 0)
// 	{
// 		ptr[0] = '\0';
// 		return (ptr);
// 	}
// 	return (ft_join(ptr, s1, s2));
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	str = (char *)s;
// 	while (str[i])
// 	{
// 		if (str[i] == (char)c)
// 			return (&str[i]);
// 		i++;
// 	}
// 	if ((char)c == '\0')
// 		return (&str[i]);
// 	return (NULL);
// }

// void push_to_b(t_stack **a, t_stack **b)
// {
// 	while (ft_lstsize(*a) > 3)
// 	{
// 		pb(a, b);
// 	}
// 	fix_index(*b);
// 	sort_3(a);
// }

// t_stack *small_number(t_stack *a)
// {
// 	t_stack *ptr;
// 	int tmp;

// 	ptr = a;
// 	tmp = a->number;
// 	while (a)
// 	{
// 		if (tmp > a->number)
// 		{
// 			tmp = a->number;
// 			ptr = a;
// 		}
// 		a = a->next;
// 	}
// 	return (ptr);
// }

// void take_targets(t_stack *a, t_stack *b)
// {
// 	int highest;
// 	t_stack *current;
// 	t_stack *ptr;

// 	highest = INT_MAX;
// 	ptr = b;
// 	while (ptr)
// 	{
// 		current = a;
// 		while (current)
// 		{
// 			if (current->number > ptr->number && current->number < highest)
// 			{
// 				ptr->target = current;
// 				highest = current->number;
// 			}
// 			current = current->next;
// 		}
// 		if (highest == INT_MAX)
// 			ptr->target = small_number(a);
// 		else
// 			highest = INT_MAX;
// 		ptr = ptr->next;
// 	}
// }

// void fix_index(t_stack *a)
// {
// 	int		i;

// 	i = 0;
// 	while (a)
// 	{
// 		a->index = i;
// 		a = a->next;
// 		i++;
// 	}
// }

// void up_or_down(t_stack *stack)
// {
// 	int line;

// 	if (stack == NULL)
// 		return ;
// 	line = ft_lstsize(stack) / 2;
// 	while (stack)
// 	{
// 		if (stack->index <= line)
// 			stack->above_line = 1;
// 		else
// 			stack->above_line = 0;
// 		stack = stack->next;
// 	}
// }

// void cost(t_stack *a, t_stack *b)
// {
// 	int length_a;
// 	int length_b;

// 	length_a = ft_lstsize(a);
// 	length_b = ft_lstsize(b);
// 	while (b)
// 	{
// 		b->cost_num = b->index;
// 		if (b->above_line == 0)
// 			b->cost_num = length_b - b->index;
// 		if (b->target->above_line == 1)
// 			b->cost_num += b->target->index;
// 		else
// 			b->cost_num += length_a - b->target->index;
// 		b = b->next;
// 	}
// }

// void perfect_to_push(t_stack *b)
// {
// 	int best;
// 	t_stack *best_node;

// 	best = INT_MAX;
// 	if (b == NULL)
// 		return ;
// 	while (b)
// 	{
// 		if (b->cost_num < best)
// 		{
// 			best = b->cost_num;
// 			best_node = b;
// 		}
// 		b = b->next;
// 	}
// 	best_node->to_push = 1;
// }

// void last_rb(t_stack **b, t_stack *stack)
// {
// 	while ((*b) != stack)
// 	{
// 		if (stack->above_line == 1)
// 			rb(b, 0);
// 		else
// 			rrb(*b, 0);
// 	}
// }

// void last_ra(t_stack **a, t_stack *stack)
// {
// 	while ((*a) != stack)
// 	{
// 		if (stack->above_line == 1)
// 			ra(a, 0);
// 		else
// 			rra(a, 0);
// 	}
// }

// void rr_both(t_stack **a, t_stack **b, t_stack *stack)
// {
// 	while ((*a) != stack->target &&
// 		(*b) != stack)
// 			rr(a, b);
// 	fix_index(*a);
// 	fix_index(*b);
// 	up_or_down(*a);
// 	up_or_down(*b);
// }

// void rrr_both(t_stack **a, t_stack **b, t_stack *stack)
// {
// 	while ((*a) != stack->target &&
// 		(*b) != stack)
// 			rrr(*a, *b);
// 	fix_index(*a);
// 	fix_index(*b);
// 	up_or_down(*a);
// 	up_or_down(*b);
// }

// void sort(t_stack **a, t_stack **b)
// {
// 	t_stack *best_node;
	
// 	best_node = *b;
// 	while (best_node->to_push != 1)
// 		best_node = best_node->next;
// 	if (best_node->above_line == 1 && best_node->target->above_line == 1)
// 		rr_both(a, b, best_node);
// 	else if (best_node->above_line == 0 && best_node->target->above_line == 0)
// 		rrr_both(a, b, best_node);
// 	last_rb(b, best_node);
// 	last_ra(a, best_node->target);
// 	pa(a, b);
// 	fix_index(*a);
// 	fix_index(*b);
// 	up_or_down(*a);
// 	up_or_down(*b);
// }
#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
    size_t	i;

    i = 0;
    while ((s1[i] || s2[i]))
    {
        if ((unsigned char)s1[i] != (unsigned char)s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return (0);
}

int	ft_lstsize(t_stack *lst)
{
    int	count;

    count = 0;
    while (lst)
    {
        lst = lst->next;
        count++;
    }
    return (count);
}

long	ft_atoi(const char *str)
{
    long	i;
    long	sign;
    long	result;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
        || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-')
    {
        sign *= -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
    t_stack	*ptr;
    int		i;

    i = 1;
    if (new)
    {
        if (!*lst)
        {
            *lst = new;
            return ;
        }
        ptr = *lst;
        while (ptr->next)
        {
            ptr = ptr->next;
            i++;
        }
        ptr->next = new;
        new->prev = ptr;
        new->index = i;
    }
}

t_stack *ft_lstnew(int number)
{
    t_stack *ptr;

    ptr = malloc(sizeof(t_stack));
    if (!ptr)
        return (NULL);
    ptr->number = number;
    ptr->next = NULL;
    ptr->prev = NULL;
    ptr->target = NULL;
    ptr->index = 0;
    ptr->cost_num = 0;
    ptr->above_line = 0;
    ptr->to_push = 0;
    return (ptr);
}

void	ft_lstclear(t_stack **lst)
{
    t_stack	*ptr1;

    if (lst && *lst)
    {
        while ((*lst))
        {
            ptr1 = (*lst)->next;
            free((*lst));
            (*lst) = ptr1;
        }
        *lst = NULL;
    }
}

int	ft_isprint(int c)
{
    return (c >= 32 && c <= 126);
}

static char	*ft_word(char const *s, char c, size_t *i)
{
    size_t	word;
    size_t	y;
    char	*ptr;

    word = 0;
    while (s[(*i)] && s[(*i)] != c)
    {
        word++;
        (*i)++;
    }
    *i = *i - word;
    y = 0;
    ptr = (char *)malloc(word + 1);
    if (!ptr)
        return (NULL);
    while (s[(*i)] && s[(*i)] != c)
    {
        ptr[y] = s[(*i)];
        (*i)++;
        y++;
    }
    ptr[y] = '\0';
    (*i)++;
    return (ptr);
}

static size_t	ft_count_word(char const *s, char c)
{
    size_t	i;
    size_t	count;

    i = 0;
    count = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (ft_isprint(s[i]))
            count++;
        while (ft_isprint(s[i]) && s[i] != c)
            i++;
    }
    return (count);
}

void	ft_free(char **ptr)
{
    size_t	i;

    if (ptr == NULL)
        return ;
    i = 0;
    while (ptr[i])
    {
        free(ptr[i]);
        i++;
    }
    free(ptr);
}

static char	**ft_make(char const *s, char c, char **ptr, size_t len)
{
    size_t	y;
    size_t	i;

    y = 0;
    i = 0;
    while (y < len)
    {
        while (s[i] == c)
            i++;
        ptr[y] = ft_word(s, c, &i);
        if (ptr[y] == NULL)
        {
            ft_free(ptr);
            return (NULL);
        }
        y++;
    }
    ptr[y] = NULL;
    return (ptr);
}

char	**ft_split(char const *s, char c)
{
    size_t	len;
    char	**ptr;

    if (!s)
        return (NULL);
    len = ft_count_word(s, c);
    ptr = (char **)malloc(sizeof(char *) * (len + 1));
    if (!ptr)
        return (NULL);
    return (ft_make(s, c, ptr, len));
}

int	ft_isdigit(int c)
{
    return (c >= 48 && c <= 57);
}

int is_valid(char **argv)
{
    int i;
    int j;

    i = 0;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] == '-' || argv[i][j] == '+')
                j++;
            if (ft_isdigit(argv[i][j]) == 0)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int is_duplicate(char **argv)
{
    int i;
    int	j;

    i = 0;
    while (argv[i])
    {
        j = 1 + i;
        while (argv[j])
        {
            if (ft_strcmp(argv[i], argv[j]) == 0)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

size_t	ft_strlen(const char *c)
{
    size_t	len;

    len = 0;
    while (c && c[len])
        len++;
    return (len);
}

static char	*ft_join(char *ptr, const char *s1, const char *s2)
{
    int	i;
    int	y;

    i = 0;
    y = 0;
    while (s1 && s1[i])
    {
        ptr[i] = s1[i];
        i++;
    }
    ptr[i] = ' ';
    i++;
    while (s2 && s2[y])
    {
        ptr[i + y] = s2[y];
        y++;
    }
    ptr[i + y] = '\0';
    return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    char	*ptr;
    size_t	ptr_len;

    if (!s1 && !s2)
        return (NULL);
    ptr_len = ft_strlen(s1) + ft_strlen(s2);
    ptr = (char *)malloc(ptr_len + 2);
    if (!ptr)
        return (NULL);
    if (ptr_len == 0)
    {
        ptr[0] = '\0';
        return (ptr);
    }
    return (ft_join(ptr, s1, s2));
}

char	*ft_strchr(const char *s, int c)
{
    int		i;
    char	*str;

    i = 0;
    str = (char *)s;
    while (str[i])
    {
        if (str[i] == (char)c)
            return (&str[i]);
        i++;
    }
    if ((char)c == '\0')
        return (&str[i]);
    return (NULL);
}

void push_to_b(t_stack **a, t_stack **b)
{
    while (ft_lstsize(*a) > 3)
    {
        pb(a, b);
    }
    fix_index(*b);
    sort_3(a);
}

t_stack *small_number(t_stack *a)
{
    t_stack *ptr;
    int tmp;

    ptr = a;
    tmp = a->number;
    while (a)
    {
        if (tmp > a->number)
        {
            tmp = a->number;
            ptr = a;
        }
        a = a->next;
    }
    return (ptr);
}

// void take_targets(t_stack *a, t_stack *b)
// {
//     int highest;
//     t_stack *current;
//     t_stack *ptr;

//     highest = INT_MAX;
//     ptr = b;
//     while (ptr)
//     {
//         current = a;
//         while (current)
//         {
//             if (current->number > ptr->number && current->number < highest)
//             {
//                 ptr->target = current;
//                 highest = current->number;
//             }
//             current = current->next;
//         }
//         if (highest == INT_MAX)
//             ptr->target = small_number(a);
//         else
//             highest = INT_MAX;
//         ptr = ptr->next;
//     }
// }
void take_targets(t_stack *a, t_stack *b)
{
    int highest;
    t_stack *current;
    t_stack *ptr;

    highest = INT_MAX;
	current = NULL;
    ptr = b;
    while (ptr)
    {
        current = a;
        ptr->target = small_number(a); // Default target
        while (current)
        {
            if (current->number > ptr->number && current->number < highest)
            {
                ptr->target = current;
                highest = current->number;
            }
            current = current->next;
        }
        highest = INT_MAX; // Reset highest for the next iteration
        ptr = ptr->next;
    }
}

void fix_index(t_stack *a)
{
    int		i;

    i = 0;
    while (a)
    {
        a->index = i;
        a = a->next;
        i++;
    }
}

void up_or_down(t_stack *stack)
{
    int line;

    if (stack == NULL)
        return ;
    line = ft_lstsize(stack) / 2;
    while (stack)
    {
        if (stack->index <= line)
            stack->above_line = 1;
        else
            stack->above_line = 0;
        stack = stack->next;
    }
}

// void cost(t_stack *a, t_stack *b)
// {
//     int length_a;
//     int length_b;

//     length_a = ft_lstsize(a);
//     length_b = ft_lstsize(b);
//     while (b)
//     {
//         b->cost_num = b->index;
//         if (b->above_line == 0)
//             b->cost_num = length_b - b->index;
//         if (b->target->above_line == 1)
//             b->cost_num += b->target->index;
//         else
//             b->cost_num += length_a - b->target->index;
//         b = b->next;
//     }
// }
void cost(t_stack *a, t_stack *b)
{
    int length_a;
    int length_b;

    length_a = ft_lstsize(a);
    length_b = ft_lstsize(b);
    while (b)
    {
        if (b->target)
        {
            b->cost_num = b->index;
            if (b->above_line == 0)
                b->cost_num = length_b - b->index;
            if (b->target->above_line == 1)
                b->cost_num += b->target->index;
            else
                b->cost_num += length_a - b->target->index;
        }
        b = b->next;
    }
}


void perfect_to_push(t_stack *b)
{
    int best;
    t_stack *best_node;

    best = INT_MAX;
	best_node = NULL;
    if (b == NULL)
        return ;
    while (b)
    {
        if (b->cost_num < best)
        {
            best = b->cost_num;
            best_node = b;
        }
        b = b->next;
    }
    best_node->to_push = 1;
}

void last_rb(t_stack **b, t_stack *stack)
{
    while ((*b) != stack)
    {
        if (stack->above_line == 1)
            rb(b, 0);
        else
            rrb(b, 0);
    }
}

void last_ra(t_stack **a, t_stack *stack)
{
    while ((*a) != stack)
    {
        if (stack->above_line == 1)
            ra(a, 0);
        else
            rra(a, 0);
    }
}

void rr_both(t_stack **a, t_stack **b, t_stack *stack)
{
    while ((*a) != stack->target &&
        (*b) != stack)
            rr(a, b);
    fix_index(*a);
    fix_index(*b);
    up_or_down(*a);
    up_or_down(*b);
}

void rrr_both(t_stack **a, t_stack **b, t_stack *stack)
{
    while ((*a) != stack->target &&
        (*b) != stack)
            rrr(a, b);
    fix_index(*a);
    fix_index(*b);
    up_or_down(*a);
    up_or_down(*b);
}

// void sort(t_stack **a, t_stack **b)
// {
//     t_stack *best_node;
    
//     best_node = *b;
//     while (best_node->to_push != 1)
//         best_node = best_node->next;
//     if (best_node->above_line == 1 && best_node->target->above_line == 1)
//         rr_both(a, b, best_node);
//     else if (best_node->above_line == 0 && best_node->target->above_line == 0)
//         rrr_both(a, b, best_node);
//     last_rb(b, best_node);
//     last_ra(a, best_node->target);
//     pa(a, b);
//     fix_index(*a);
//     fix_index(*b);
//     up_or_down(*a);
//     up_or_down(*b);
// }
void sort(t_stack **a, t_stack **b)
{
    t_stack *best_node = NULL; // Initialize to NULL
    int min_cost = INT_MAX;    // Initialize to a large value

    // Find the node with the minimum cost
    t_stack *current = *b;
    while (current)
    {
        if (current->to_push == 1 && current->cost_num < min_cost)
        {
            min_cost = current->cost_num;
            best_node = current;
        }
        current = current->next;
    }

    // Perform sorting operations
    if (best_node && best_node->target)
    {
        if (best_node->above_line == 1 && best_node->target->above_line == 1)
            rr_both(a, b, best_node);
        else if (best_node->above_line == 0 && best_node->target->above_line == 0)
            rrr_both(a, b, best_node);
        last_rb(b, best_node);
        last_ra(a, best_node->target);
        pa(a, b);
    }
}
