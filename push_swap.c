/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:08:38 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/05 22:22:34 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char *argv[])
{
	t_dlist	*a;
	t_dlist	*b;
	int		flag;

	if (argc == 1)
		return ;
	a = NULL;
	b = dlstempty();
	flag = check_args(argc, argv, &a);
	if (flag == SUCCESS)
	{
		set_index(argc - 1, &a);
		printlst(&a, 1);
		printf("\n");

		swap_rotate(&a, SWAP);
		printf("swap\n");
		printlst(&a, 1);
		printf("\n");
		
		swap_rotate(&a, ROTATE);
		printf("rotate\n");
		printlst(&(a), 1);
		printf("\n");

		push(&b, &a);
		printf("push\na\n");
		printlst(&(a), 1);
		printf("\nb\n");
		printlst(&(b), 1);
		printf("\n");
		
		swap_rotate(&a, REVERSE_ROTATE);
		printf("reverse rotate\n");
		printlst(&(a), 1);
		printf("\n");
	}
	else
	{
		ft_putendl_fd("ERROR", 2);
		dlstclear(&a);
		return ;
	}
}

static int	check_args(int len, char *argv[], t_dlist **a)
{
	unsigned int	i;
	long long		n;

	i = 0;
	while (++i < len)
	{
		n = to_int(argv[i]);
		if (n == NOT_INT)
			return (FAIL);
		else
		{
			if (*a != NULL)
			{
				while ((*a)->value != NULL)
				{
					if ((int)n == (*(*a)->value))
						return (FAIL);
					*a = (*a)->next;
				}
				*a = (*a)->next;
			}
			dlstadd_back(a, dlstnew((int)n));
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

void	set_index(int len, t_dlist **a)
{
	t_dlist	*min;
	int		index;

	index = 0;
	while (index < len)
	{
		while ((*a)->index != -1)
			*a = (*a)->next;
		min = *a;
		*a = (*a)->next;
		while ((*a)->value != NULL)
		{
			if (((*a)->index == -1) && (*(min->value) > *((*a)->value)))
				min = *a;
			*a = (*a)->next;
		}
		*a = (*a)->next;
		min->index = index;
		index++;
	}
}

///////
void	printlst(t_dlist **a, int n)
{
	switch (n)
	{
		case 1:
			while ((*a)->value != NULL)
			{
				printf("%d (%d)\n", (*(*a)->value), (*a)->index);
				*a = (*a)->next;
			}
			*a = (*a)->next;
			break ;
		case 2:
			*a = (*a)->prev->prev;
			while((*a)->value != NULL)
			{
				printf("%d (%d)\n", (*(*a)->value), (*a)->index);
				*a = (*a)->prev;
			}
			*a = (*a)->next;
			break ;
		default:
			break;
	}
}
//////