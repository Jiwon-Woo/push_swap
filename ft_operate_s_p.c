/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate_s_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:38:53 by jwoo              #+#    #+#             */
/*   Updated: 2021/05/30 16:41:51 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sa_sb(int *stack)
{
	if (stack[0] <= 1)
		return (0);
	arr_swap(stack, 1, 2);
	return (1);
}

int		ss(int *stack_a, int *stack_b)
{
	int	sa;
	int	sb;

	sa = sa_sb(stack_a);
	sb = sa_sb(stack_b);
	if (sa == 0 && sb == 0)
		return (0);
	else if (sb == 0)
		return ('a');
	else if (sa == 0)
		return ('b');
	else
		return (1);
}

int		pa(int *stack_a, int *stack_b)
{
	int	b_top;

	if (stack_b[0] <= 0)
		return (0);
	ra_rb(stack_b);
	b_top = stack_b[stack_b[0]];
	stack_b[stack_b[0]] = 0;
	stack_b[0]--;
	rra_rrb(stack_a);
	stack_a[0]++;
	stack_a[stack_a[0]] = stack_a[1];
	stack_a[1] = b_top;
	return (1);
}

int		pb(int *stack_a, int *stack_b)
{
	int	a_top;

	if (stack_a[0] <= 0)
		return (0);
	ra_rb(stack_a);
	a_top = stack_a[stack_a[0]];
	stack_a[stack_a[0]] = 0;
	stack_a[0]--;
	rra_rrb(stack_b);
	stack_b[0]++;
	stack_b[stack_b[0]] = stack_b[1];
	stack_b[1] = a_top;
	return (1);
}
