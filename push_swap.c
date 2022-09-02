/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:08:38 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/02 23:18:13 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char *argv[])
{
	t_dlist	*a;
	int		flag;

	if (argc == 1)
		return ;
	a = NULL;
	flag = prepare_a(argc, argv, &a);
	if (flag == SUCCESS)
	{
		// while (a->value != NULL)
		// {
		// 	printf("%d\n", (*a->value));
		// 	a = a->next;
		// }
		a = a->prev->prev;
		while(a->value != NULL)
		{
			printf("%d\n", *(a->value));
			a = a->prev;
		}
	}
	else
	{
		ft_printf("ERROR\n");
		return ;//error
	}
}

static int	prepare_a(int len, char *argv[], t_dlist **a)
{
	unsigned int	i;
	long long		n;

	i = 0;
	while (++i < len)
	{
		n = to_int(argv[i]);
		if (n == NOT_INT)
		{
			return (FAIL);
		}
		else
		{
			ft_dlstadd_back(a, ft_dlstnew((int)n));
		}
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

// void	free_and_exit(int *stack)
// {
// 	ft_putendl_fd("Error", 2);
// 	free(stack);
// 	stack = NULL;
// 	exit(1);
// }
