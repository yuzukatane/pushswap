/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:08:35 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/03 18:14:17 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
//# include <limits.h> libftにもう入ってる

#include <stdio.h> //////

# define SUCCESS 1
# define FAIL 0
# define NOT_INT INT_MAX + 1ll

typedef struct s_dlist
{
	int				*value;
	int				index;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

void	push_swap(int argc, char *argv[]);
static int	check_args(int len, char *argv[], t_dlist **a);
static long long	to_int(const char *str);

void	dlstadd_back(t_dlist **lst, t_dlist *new);
t_dlist	*dlstnew(int value);

void	dlstclear(t_dlist **lst);
void	dlstdelone(t_dlist *lst);

#endif
