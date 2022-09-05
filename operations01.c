/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:46:00 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/05 22:51:31 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_dlist **lst)
{
	//if -> sa sb でやってもいいかも
	if ((*lst)->value == NULL || (*lst)->next->value == NULL)
		return ;
	swap_rotate(lst, SWAP);
}

void	ss(t_dlist **a, t_dlist **b)
{
	sa_sb(a);
	sa_sb(b);
}
