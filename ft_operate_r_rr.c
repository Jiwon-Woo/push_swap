/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate_r_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:41:12 by jwoo              #+#    #+#             */
/*   Updated: 2021/05/30 16:41:49 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ra_rb(int *stack)
{
	int	top;
	int	idx;

	if (stack[0] <= 1)
		return (0);
	top = stack[1];
	idx = 0;
	while (++idx < stack[0])
	{
		stack[idx] = stack[idx + 1];
	}
	stack[stack[0]] = top;
	return (1);
}

int		rr(int *stack_a, int *stack_b)
{
	int	ra;
	int	rb;

	ra = ra_rb(stack_a);
	rb = ra_rb(stack_b);
	if (ra == 0 && rb == 0)
		return (0);
	else if (rb == 0)
		return ('a');
	else if (ra == 0)
		return ('b');
	else
		return (1);
}

int		rra_rrb(int *stack)
{
	int	bottom;
	int	idx;

	if (stack[0] <= 1)
		return (0);
	bottom = stack[stack[0]];
	idx = stack[0] + 1;
	while (--idx > 1)
	{
		stack[idx] = stack[idx - 1];
	}
	stack[1] = bottom;
	return (1);
}

int		rrr(int *stack_a, int *stack_b)
{
	int	rra;
	int	rrb;

	rra = rra_rrb(stack_a);
	rrb = rra_rrb(stack_b);
	if (rra == 0 && rrb == 0)
		return (0);
	else if (rrb == 0)
		return ('a');
	else if (rra == 0)
		return ('b');
	else
		return (1);
}
