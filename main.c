/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:44:16 by jwoo              #+#    #+#             */
/*   Updated: 2021/05/30 18:57:50 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_stack	*stack;
	int		*sort;
	int		arg_num;

	arg_num = argument_number(argc, argv);
	stack = init_stack_struct();
	stack->a = init_stack_a(argc, argv, arg_num);
	sort = init_sort(arg_num, stack->a);
	stack->b = init_stack_b(arg_num);
	push_swap(stack, sort);
	free_stack(stack, sort);
	return (0);
}
