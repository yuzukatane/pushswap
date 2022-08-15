/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:08:38 by kyuzu             #+#    #+#             */
/*   Updated: 2022/06/29 16:10:14 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prepare_stack(int len, char *argv[], int *stack)
{
	int	flag;

	flag = check_args(len, argv, stack);
	if (flag == FAIL)
		return (FAIL);
	else
		return (SUCCESS);
}

static int	check_args(int len, char *argv[], int *stack)
{
	int			i;
	int			j;
	long long	n;

	i = 0;
	while (++i < len)
	{
		n = to_int(argv[i]);
		if (n == NOT_INT)
			free_and_exit(stack);
		stack[i - 1] = n;
	}
	i = -1;
	while (++i < len - 1)
	{
		j = i;
		while (++j < len)
			if (stack[i] == stack[j])
				free_and_exit(stack);
	}
	return (SUCCESS);
}

static long long	to_int(const char *str)
{
	long long	number;
	int			sign;

	sign = 1;
	if (*str == '+' && *(str + 1) != '\0')
		str++;
	else if (*str == '-' && *(str + 1) != '\0')
	{
		sign = -1;
		str++;
	}
	number = 0;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (NOT_INT);
		number *= 10;
		number += (*str - '0');
		if (number < INT_MIN || INT_MAX < number)
			return (NOT_INT);
		str++;
	}
	return (number * sign);
}

void	free_and_exit(int *stack)
{
	ft_putendl_fd("Error", 2);
	free(stack);
	stack = NULL;
	exit(1);
}
