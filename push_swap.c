/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:08:38 by kyuzu             #+#    #+#             */
/*   Updated: 2022/08/15 18:05:53 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char *argv[])
{
	t_list	*a;
	int		flag;

	a = NULL;

	if (argc == 1)
		return ;
	flag = prepare_a(argc, argv, a);
	if (flag == SUCCESS)
	{
		ft_printf("OK\n");
	}
	else
		return ;//error
}

// int	prepare_stack(int len, char *argv[], int *stack)
// {
// 	int	flag;

// 	flag = check_args(len, argv, stack);
// 	if (flag == FAIL)
// 		return (FAIL);
// 	else
// 		return (SUCCESS);
// }

static int	prepare_a(int len, char *argv[], t_list *a)
{
	unsigned int	i;
	long long		n;
	unsigned int	*check_double;

	check_double = ft_calloc(UINT_MAX + 1ll, sizeof(char));
	if (check_double == NULL)
		return (FAIL);
	i = 0;
	while (++i < len)
	{
		n = to_int(argv[i]);
		if (n == NOT_INT)
		{
			free(check_double);
			return (FAIL);
		}
		if (check_double[(unsigned int)n] == 0)
			check_double[(unsigned int)n] = 1;
		else
		{
			free(check_double);
			return (FAIL);
		}
		ft_lstadd_back(&a, ft_lstnew(&n));
	}
	free(check_double);
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
