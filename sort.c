/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:03:58 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/10 14:15:21 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_dlist **lst, char stack)
{
	if ((*lst)->next->next->value == NULL)
		sort_two(lst, stack);
	else if (*((*lst)->next->value) < *((*lst)->value) && *((*lst)->value) < *((*lst)->next->next->value))
	{
		sa_sb(lst);
		ft_printf("s%c\n", stack);
	}
	else if (*((*lst)->next->next->value) < *((*lst)->next->value) && *((*lst)->next->value) < *((*lst)->value))
	{
		sa_sb(lst);
		ft_printf("s%c\n", stack);
		rra_rrb(lst);
		ft_printf("rr%c\n", stack);
	}
	else if (*((*lst)->next->value) < *((*lst)->next->next->value) && *((*lst)->next->next->value) < *((*lst)->value))
	{
		ra_rb(lst);
		ft_printf("r%c\n", stack);
	}
	else if (*((*lst)->value) < *((*lst)->next->next->value) && *((*lst)->next->next->value) < *((*lst)->next->value))
	{
		sa_sb(lst);
		ft_printf("s%c\n", stack);
		ra_rb(lst);
		ft_printf("r%c\n", stack);
	}
	else if (*((*lst)->next->next->value) < *((*lst)->value) && *((*lst)->value) < *((*lst)->next->value))
	{
		rra_rrb(lst);
		ft_printf("rr%c\n", stack);
	}
	(*lst)->label = SORTED;
	(*lst)->next->label = SORTED;
	(*lst)->next->next->label = SORTED;
}

void	sort_two(t_dlist **lst, char stack)
{
	if ((*lst)->value == NULL || (*lst)->next->value == NULL)
		return ;
	else if (*((*lst)->value) > *((*lst)->next->value))
	{
		sa_sb(lst);
		ft_printf("s%c\n", stack);
	}
	(*lst)->label = SORTED;
	(*lst)->next->label = SORTED;
}

void	sort_three_reverse(t_dlist **lst, char stack)
{
	if ((*lst)->next->next->value == NULL)
		sort_two_reverse(lst, stack);
	else if (*((*lst)->next->value) > *((*lst)->value) && *((*lst)->value) > *((*lst)->next->next->value))
	{
		sa_sb(lst);
		ft_printf("s%c\n", stack);
	}
	else if (*((*lst)->next->next->value) > *((*lst)->next->value) && *((*lst)->next->value) > *((*lst)->value))
	{
		sa_sb(lst);
		ft_printf("s%c\n", stack);
		rra_rrb(lst);
		ft_printf("rr%c\n", stack);
	}
	else if (*((*lst)->next->value) > *((*lst)->next->next->value) && *((*lst)->next->next->value) > *((*lst)->value))
	{
		ra_rb(lst);
		ft_printf("r%c\n", stack);
	}
	else if (*((*lst)->value) > *((*lst)->next->next->value) && *((*lst)->next->next->value) > *((*lst)->next->value))
	{
		sa_sb(lst);
		ft_printf("s%c\n", stack);
		ra_rb(lst);
		ft_printf("r%c\n", stack);
	}
	else if (*((*lst)->next->next->value) > *((*lst)->value) && *((*lst)->value) > *((*lst)->next->value))
	{
		rra_rrb(lst);
		ft_printf("rr%c\n", stack);
	}
	(*lst)->label = SORTED;
	(*lst)->next->label = SORTED;
	(*lst)->next->next->label = SORTED;
}

void	sort_two_reverse(t_dlist **lst, char stack)
{
	if ((*lst)->value == NULL || (*lst)->next->value == NULL)
		return ;
	else if (*((*lst)->value) < *((*lst)->next->value))
	{
		sa_sb(lst);
		ft_printf("s%c\n", stack);
	}
	(*lst)->label = SORTED;
	(*lst)->next->label = SORTED;
}

void	sort_up_to_six(int len, t_dlist **a, t_dlist **b)
{
	int	i;

	if (len <= 3)
		sort_three(a, 'a');
	else
	{
		send_half_small(len, b, a);
		sort_three(a, 'a');
		sort_three_reverse(b, 'b');
		i = 0;
		while (i < ((len / 2) + (len % 2)))
		{
			pa_pb(a, b);
			ft_printf("pa\n");
			i++;
		}
	}
}
