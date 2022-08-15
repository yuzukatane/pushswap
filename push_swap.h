/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:08:35 by kyuzu             #+#    #+#             */
/*   Updated: 2022/08/15 17:09:37 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
//# include <limits.h> libftにもう入ってる

#include <stdio.h> //////

# define STACK_SIZE 1000
# define SUCCESS 1
# define FAIL 0
# define NOT_INT INT_MAX + 1ll


void	push_swap(int argc, char *argv[]);
static int	prepare_a(int len, char *argv[], t_list *a);
static long long	to_int(const char *str);

#endif
