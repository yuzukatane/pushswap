/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:08:35 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/19 13:55:17 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

# define SUCCESS 1
# define FAIL 0
# define NOT_INT INT_MAX + 1ll
# define ROTATE 0
# define REVERSE_ROTATE 1
# define SWAP 2
# define SORTED -1

typedef struct s_dlist
{
	int				*value;
	int				index;
	int				label;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

void	push_swap(int argc, char *argv[]);
int		check_args(int len, char *argv[], t_dlist **a);
void	set_index(int len, t_dlist **a);

void	dlstadd_back(t_dlist **lst, t_dlist *new);
void	dlstadd_front(t_dlist **lst, t_dlist *new);
t_dlist	*dlstnew(int value);
t_dlist	*dlstempty(void);
void	dlstclear(t_dlist **lst);
void	dlstdelone(t_dlist *lst);

void	pa_pb(t_dlist **dst, t_dlist **src, char stack);
void	swap_rotate(t_dlist **lst, int flag);
void	sa_sb(t_dlist **lst, char stack);
void	ss(t_dlist **a, t_dlist **b);
void	ra_rb(t_dlist **lst, char stack);
void	rr(t_dlist **a, t_dlist **b);
void	rra_rrb(t_dlist **lst, char stack);
void	rrr(t_dlist **a, t_dlist **b);

void	solution(int len, t_dlist **a, t_dlist **b);
void	find_three(int len, t_dlist **a, t_dlist **b);
int		send_half_small(int len, t_dlist **dst, t_dlist **src);
int		send_half_large(int len, t_dlist **dst, t_dlist **src);
void	sort_up_to_six(int len, t_dlist **a, t_dlist **b);
int		is_sorted(t_dlist **lst);
void	small_or_large(int median, t_dlist **lst);
void	rotate_to_sort(t_dlist **a);
void	is_larger(int len, int median, t_dlist **dst, t_dlist**src);

void	sort_three(t_dlist **lst, char stack);
void	sort_two(t_dlist **lst, char stack);
void	sort_three_reverse(t_dlist **lst, char stack);
void	sort_two_reverse(t_dlist **lst, char stack);

#endif
