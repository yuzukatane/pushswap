/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:08:38 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/17 17:33:33 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char *argv[])
{
	t_dlist	*a;
	t_dlist	*b;
	int		len;
	int		flag;
	// t_buf	*buffer;

	if (argc == 1)
		return ;
	// buffer = malloc(sizeof(t_buf));
	// if (buffer == NULL)
		// return ;
	// buffer->index = 0;
	a = dlstempty();
	b = dlstempty();
	len = argc - 1;
	flag = check_args(len, argv, &a);
	if (flag == SUCCESS)
	{
		set_index(len, &a);
		// printlst(&a, 1);
		// printf("\n");

		solution(len, &a, &b);

		// printlst(&a, 1);
	}
	else
		ft_putendl_fd("ERROR", 2);
	dlstclear(&a);
	dlstclear(&b);
	// free(buffer);
}

int	check_args(int len, char *argv[], t_dlist **a)
{
	long long	i;
	long long	n;

	i = 1;
	while (i <= len)
	{
		n = to_int(argv[i]);
		if (n == NOT_INT)
			return (FAIL);
		else
		{
			if (i == 1)
				dlstadd_front(a, dlstnew((int)n));
			else
			{
				while ((*a)->value != NULL)
				{
					if ((int)n == (*(*a)->value))
						return (FAIL);
					*a = (*a)->next;
				}
				*a = (*a)->next;
				dlstadd_back(a, dlstnew((int)n));
			}
		}
		i++;
	}
	return (SUCCESS);
}

long long	to_int(const char *str)
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
	if (*str == '\0')
		return (NOT_INT);
	number = 0;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (NOT_INT);
		number *= 10;
		number += (*str - '0');

		if (!(number == INT_MAX + 1ll && sign == -1) && (INT_MAX < number))
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
				printf("%d (%d) (%d)\n", (*(*a)->value), (*a)->index, (*a)->label);
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