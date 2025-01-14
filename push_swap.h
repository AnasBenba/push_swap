#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

typedef struct s_stack
{
    int     number;
    int     index;
    int     cost_num;
    int     above_line;
    int     to_push;
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
long	ft_atoi(const char *str);
int	ft_lstsize(t_stack *lst);
int is_duplicate(char **argv);
int	ft_strcmp(const char *s1, const char *s2);
void	ft_free(char **ptr);
void    sa(t_stack *a, int flag);
void    ra(t_stack **a, int flag);
void    rra(t_stack **a, int flag);
void    sb(t_stack *b, int flag);
void    rb(t_stack **b, int flag);
void    rrb(t_stack *b, int flag);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void rrr(t_stack *a, t_stack *b);
void rr(t_stack **a, t_stack **b);
void push_to_b(t_stack **a, t_stack **b);
void sort_3(t_stack **a);
void take_targets(t_stack *a, t_stack *b);
void fix_index(t_stack *a);
t_stack *small_number(t_stack *a);
void cost(t_stack *a, t_stack *b);
void up_or_down(t_stack *stack);
void sort(t_stack **a, t_stack **b);
void last_rb(t_stack **b, t_stack *stack);
void last_ra(t_stack **a, t_stack *stack);
void rr_both(t_stack **a, t_stack **b, t_stack *stack);
void rrr_both(t_stack **a, t_stack **b, t_stack *stack);
void perfect_to_push(t_stack *b);

#endif