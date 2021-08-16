/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:34:25 by jwoo              #+#    #+#             */
/*   Updated: 2021/05/30 16:52:12 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_idx(int *stack, int range, int *sort, int sort_idx)
{
	int	idx;
	int	flag;

	if (sort_idx > sort[0] || sort_idx <= 0)
		return (0);
	idx = 0;
	flag = 0;
	while (++idx < range)
	{
		if (stack[idx] == sort[sort_idx])
		{
			flag = 1;
			break ;
		}
	}
	if (flag == 1)
		return (idx);
	return (0);
}

int	find_idx_reverse(int *stack, int range, int *sort, int sort_idx)
{
	int	idx;
	int	flag;

	if (sort_idx > sort[0])
		return (stack[0] + 1);
	idx = stack[0] + 1;
	flag = 0;
	while (--idx > range)
	{
		if (stack[idx] == sort[sort_idx])
		{
			flag = 1;
			break ;
		}
	}
	if (flag == 1)
		return (idx);
	return (stack[0] + 1);
}

int	reverse_rotate_b(t_stack *stack, int *sort, int max_idx, int sort_idx)
{
	int	next_max;
	int	diff;
	int	ret;

	next_max = stack->b[0] + 1;
	ret = 1;
	if (sort_idx > 1)
		next_max = find_idx_reverse(stack->b, max_idx, sort, sort_idx - 1);
	if (next_max <= stack->b[0])
		ret = 2;
	diff = stack->b[0] + 1 - max_idx;
	while (--diff >= 0)
	{
		operate(stack, RRB);
		if (stack->b[1] == sort[sort_idx])
			operate(stack, PA);
		else if (ret == 2 && stack->b[1] == sort[sort_idx - 1])
			operate(stack, PA);
	}
	if (ret == 2)
		operate(stack, SA);
	return (ret);
}

int	rotate_b(t_stack *stack, int *sort, int max_idx, int sort_idx)
{
	int	next_max;
	int	diff;
	int	ret;

	next_max = 0;
	ret = 1;
	if (sort_idx > 1)
		next_max = find_idx(stack->b, max_idx, sort, sort_idx - 1);
	if (next_max > 0)
		ret = 2;
	diff = max_idx;
	while (--diff >= 0)
	{
		if (stack->b[1] == sort[sort_idx])
			operate(stack, PA);
		else if (ret == 2 && stack->b[1] == sort[sort_idx - 1])
			operate(stack, PA);
		else
			operate(stack, RB);
	}
	if (ret == 2)
		operate(stack, SA);
	return (ret);
}
