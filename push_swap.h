/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:08:35 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/02 22:03:09 by kyuzu            ###   ########.fr       */
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
	// int				index;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

void	push_swap(int argc, char *argv[]);
static int	prepare_a(int len, char *argv[], t_dlist **a);
static long long	to_int(const char *str);

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
t_dlist	*ft_dlstnew(int value);

#endif
