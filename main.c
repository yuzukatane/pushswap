/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:08:40 by kyuzu             #+#    #+#             */
/*   Updated: 2022/06/29 16:15:57 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int main(int argc, char *argv[])
{
	int	*stack;		//mallocとポインタ？ダブル？

	stack = malloc(STACK_SIZE * sizeof(int));
	if (stack == NULL)
		return (1);
	
	prepare_stack(argc, argv, stack);
	ft_printf("%d %d %d", stack[0], stack[1], stack[2]);


	
	return (0);
}
