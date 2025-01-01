#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>

#ifndef p
#define p ft_printf
#endif

# include "printf/ft_printf.h"
#include <stdlib.h>

typedef struct s_stack
{
    int     number;
    struct s_stack *target;
    struct s_stack *next;
    struct s_stack *prev;
}   t_stack;

t_stack	*ft_lstnew(int number);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst);
char	**ft_split(char const *s, char c);
int is_valid(char **argv);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *c);
char	*ft_strchr(const char *s, int c);
int	ft_atoi(const char *str);
int	ft_lstsize(t_stack *lst);
int is_duplicate(char **argv);
int	ft_strcmp(const char *s1, const char *s2);
void	ft_free(char **ptr);
void    sa(t_stack *a, int flag);
void    ra(t_stack *a, int flag);
void    rra(t_stack *a, int flag);
void    sb(t_stack *b, int flag);
void    rb(t_stack *b, int flag);
void    rrb(t_stack *b, int flag);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);

#endif