/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_under_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:35:10 by jwoo              #+#    #+#             */
/*   Updated: 2021/05/30 16:36:42 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_arg_in_a(t_stack *stack)
{
	if (stack->a[1] > stack->a[2])
		operate(stack, SA);
}

void	sort_three_arg_in_a(t_stack *stack)
{
	if (stack->a[1] > stack->a[2] && stack->a[2] > stack->a[3])
	{
		operate(stack, RA);
		operate(stack, SA);
	}
	else if (stack->a[2] > stack->a[3] && stack->a[3] > stack->a[1])
	{
		operate(stack, RRA);
		operate(stack, SA);
	}
	else if (stack->a[3] > stack->a[1] && stack->a[1] > stack->a[2])
		operate(stack, SA);
	else if (stack->a[2] > stack->a[1] && stack->a[1] > stack->a[3])
		operate(stack, RRA);
	else if (stack->a[1] > stack->a[3] && stack->a[3] > stack->a[2])
		operate(stack, RA);
}

void	sort_four_arg_in_a(t_stack *stack, int *sort)
{
	int	idx;
	int	mid;

	mid = sort[(sort[0] - stack->a[0] + sort[0]) / 2];
	idx = stack->a[0];
	while (--idx >= 0)
	{
		if (stack->a[1] <= mid)
			operate(stack, PB);
		else
			operate(stack, RA);
	}
	if (stack->a[1] > stack->a[2] && stack->b[1] < stack->b[2])
		operate(stack, SS);
	else if (stack->a[1] > stack->a[2])
		operate(stack, SA);
	else if (stack->b[1] < stack->b[2])
		operate(stack, SB);
	operate(stack, PA);
	operate(stack, PA);
}

void	sort_five_arg_in_a(t_stack *stack, int *sort)
{
	int	idx;
	int	mid;

	mid = sort[(sort[0] - stack->a[0] + sort[0]) / 2];
	idx = stack->a[0];
	while (--idx >= 0)
	{
		if (stack->a[1] <= mid)
			operate(stack, PB);
		else
			operate(stack, RA);
	}
	sort_three_arg_in_a(stack);
	if (stack->b[1] < stack->b[2])
		operate(stack, SB);
	operate(stack, PA);
	operate(stack, PA);
}
