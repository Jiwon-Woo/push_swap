/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:34:51 by jwoo              #+#    #+#             */
/*   Updated: 2021/05/30 19:00:46 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	slice_three_part(t_stack *stack, int *sort, int start, int end)
{
	int	one_third;
	int	two_third;
	int	idx;

	one_third = sort[start + (end - start) / 3];
	two_third = sort[start + ((end - start) * 2) / 3];
	idx = stack->a[0];
	while (--idx >= 0)
	{
		if (stack->a[1] > two_third)
			operate(stack, RA);
		else
		{
			operate(stack, PB);
			if (stack->b[1] <= one_third && stack->a[1] > two_third)
			{
				operate(stack, RR);
				--idx;
			}
			else if (stack->b[1] <= one_third)
				operate(stack, RB);
		}
	}
}

void	sort_remain_stack_b(t_stack *stack, int *sort, int sort_idx)
{
	int	max_idx;
	int	sort_start;

	if (stack->b[0] <= 0)
		return ;
	sort_start = sort_idx;
	while (sort_start >= 1 && stack->b[0] > 0)
	{
		max_idx = find_idx(stack->b, stack->b[0] + 1, sort, sort_start);
		if (max_idx > stack->b[0] / 2 + 1)
			sort_start -= reverse_rotate_b(stack, sort, max_idx, sort_start);
		else
			sort_start -= rotate_b(stack, sort, max_idx, sort_start);
	}
}

void	sort_remain_stack_a(t_stack *stack, int *sort)
{
	if (stack->a[0] <= 1)
		return ;
	else if (stack->a[0] == 2)
		return (sort_two_arg_in_a(stack));
	else if (stack->a[0] == 3)
		return (sort_three_arg_in_a(stack));
	else if (stack->a[0] == 4)
		return (sort_four_arg_in_a(stack, sort));
	else if (stack->a[0] == 5)
		return (sort_five_arg_in_a(stack, sort));
}

void	push_swap(t_stack *stack, int *sort)
{
	int		start;

	start = 0;
	while (stack->a[0] > 5)
	{
		slice_three_part(stack, sort, start, sort[0]);
		start += (sort[0] - start) * 2 / 3;
	}
	sort_remain_stack_a(stack, sort);
	sort_remain_stack_b(stack, sort, sort[0] - stack->a[0]);
}
