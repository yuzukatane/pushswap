/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:03:58 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/18 15:27:09 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_label(t_dlist **lst)
{
	(*lst)->label = SORTED;
	(*lst)->next->label = SORTED;
	(*lst)->next->next->label = SORTED;
}

void	sort_three(t_dlist **lst, char stack)
{
	if ((*lst)->next->next->value == NULL)
		sort_two(lst, stack);
	else if (*((*lst)->next->value) < *((*lst)->value)
		&&*((*lst)->value) < *((*lst)->next->next->value))
		sa_sb(lst, stack);
	else if (*((*lst)->next->next->value) < *((*lst)->next->value)
		&& *((*lst)->next->value) < *((*lst)->value))
	{
		sa_sb(lst, stack);
		rra_rrb(lst, stack);
	}
	else if (*((*lst)->next->value) < *((*lst)->next->next->value)
		&& *((*lst)->next->next->value) < *((*lst)->value))
		ra_rb(lst, stack);
	else if (*((*lst)->value) < *((*lst)->next->next->value)
		&& *((*lst)->next->next->value) < *((*lst)->next->value))
	{
		sa_sb(lst, stack);
		ra_rb(lst, stack);
	}
	else if (*((*lst)->next->next->value) < *((*lst)->value)
		&& *((*lst)->value) < *((*lst)->next->value))
		rra_rrb(lst, stack);
	change_label(lst);
}

void	sort_two(t_dlist **lst, char stack)
{
	if ((*lst)->value == NULL || (*lst)->next->value == NULL)
		return ;
	else if (*((*lst)->value) > *((*lst)->next->value))
		sa_sb(lst, stack);
	(*lst)->label = SORTED;
	(*lst)->next->label = SORTED;
}

void	sort_three_reverse(t_dlist **lst, char stack)
{
	if ((*lst)->next->next->value == NULL)
		sort_two_reverse(lst, stack);
	else if (*((*lst)->next->value) > *((*lst)->value)
		&& *((*lst)->value) > *((*lst)->next->next->value))
		sa_sb(lst, stack);
	else if (*((*lst)->next->next->value) > *((*lst)->next->value)
		&& *((*lst)->next->value) > *((*lst)->value))
	{
		sa_sb(lst, stack);
		rra_rrb(lst, stack);
	}
	else if (*((*lst)->next->value) > *((*lst)->next->next->value)
		&& *((*lst)->next->next->value) > *((*lst)->value))
		ra_rb(lst, stack);
	else if (*((*lst)->value) > *((*lst)->next->next->value)
		&& *((*lst)->next->next->value) > *((*lst)->next->value))
	{
		sa_sb(lst, stack);
		ra_rb(lst, stack);
	}
	else if (*((*lst)->next->next->value) > *((*lst)->value)
		&& *((*lst)->value) > *((*lst)->next->value))
		rra_rrb(lst, stack);
	change_label(lst);
}

void	sort_two_reverse(t_dlist **lst, char stack)
{
	if ((*lst)->value == NULL || (*lst)->next->value == NULL)
		return ;
	else if (*((*lst)->value) < *((*lst)->next->value))
		sa_sb(lst, stack);
	(*lst)->label = SORTED;
	(*lst)->next->label = SORTED;
}
