/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:34:48 by jwoo              #+#    #+#             */
/*   Updated: 2021/05/30 16:41:07 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_command(int command)
{
	if (command == SA)
		write(1, "sa\n", 3);
	else if (command == SB)
		write(1, "sb\n", 3);
	else if (command == SS)
		write(1, "ss\n", 3);
	else if (command == PA)
		write(1, "pa\n", 3);
	else if (command == PB)
		write(1, "pb\n", 3);
	else if (command == RA)
		write(1, "ra\n", 3);
	else if (command == RB)
		write(1, "rb\n", 3);
	else if (command == RR)
		write(1, "rr\n", 3);
	else if (command == RRA)
		write(1, "rra\n", 4);
	else if (command == RRB)
		write(1, "rrb\n", 4);
	else if (command == RRR)
		write(1, "rrr\n", 4);
}

int		is_vaild_operate(t_stack *stack, int command)
{
	if (command == SA)
		return (sa_sb(stack->a));
	else if (command == SB)
		return (sa_sb(stack->b));
	else if (command == SS)
		return (ss(stack->a, stack->b));
	else if (command == PA)
		return (pa(stack->a, stack->b));
	else if (command == PB)
		return (pb(stack->a, stack->b));
	else if (command == RA)
		return (ra_rb(stack->a));
	else if (command == RB)
		return (ra_rb(stack->b));
	else if (command == RR)
		return (rr(stack->a, stack->b));
	else if (command == RRA)
		return (rra_rrb(stack->a));
	else if (command == RRB)
		return (rra_rrb(stack->b));
	else if (command == RRR)
		return (rrr(stack->a, stack->b));
	return (0);
}

void	operate(t_stack *stack, int command)
{
	int	valid;

	valid = is_vaild_operate(stack, command);
	if (valid == 0)
		return ;
	else if (valid == 1)
		write_command(command);
	else if (valid == 'a')
	{
		if (command == SS)
			write_command(SA);
		else if (command == RR)
			write_command(RA);
		else if (command == RRR)
			write_command(RRA);
	}
	else if (valid == 'b')
	{
		if (command == SS)
			write_command(SB);
		else if (command == RR)
			write_command(RB);
		else if (command == RRR)
			write_command(RRB);
	}
}
