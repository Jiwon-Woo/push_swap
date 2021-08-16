/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:34:45 by jwoo              #+#    #+#             */
/*   Updated: 2021/05/30 17:08:11 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack_struct(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == 0)
		error_message("Error\n");
	return (stack);
}

int		*init_stack_a(int argc, char *argv[], int arg_num)
{
	int		arg_idx;
	int		split_idx;
	int		idx;
	char	**split;
	int		*stack_a;

	stack_a = (int *)malloc(sizeof(int) * arg_num + 1);
	if (stack_a == 0)
		error_message("Error\n");
	arg_idx = 0;
	idx = 0;
	while (++arg_idx < argc)
	{
		split = ft_split_space(argv[arg_idx]);
		split_idx = 0;
		while (split[split_idx])
			ft_atoi(split[split_idx++], &stack_a[++idx]);
		free_two_dimension(split, split_idx);
	}
	stack_a[0] = arg_num;
	return (stack_a);
}

int		*init_sort(int arg_num, int *stack_a)
{
	int		idx;
	int		*sort;

	sort = (int *)malloc(sizeof(int) * arg_num + 1);
	if (sort == 0)
		error_message("Error\n");
	idx = 0;
	while (++idx <= arg_num)
	{
		sort[idx] = stack_a[idx];
		insert_heap(sort, idx);
	}
	heap_sort(sort, arg_num);
	sort[0] = arg_num;
	idx = 1;
	while (arg_num > 2 && ++idx <= arg_num)
		if (sort[idx - 1] == sort[idx])
			error_message("Error\n");
	is_sort(arg_num, stack_a, sort);
	return (sort);
}

int		*init_stack_b(int arg_num)
{
	int	*stack_b;

	stack_b = (int *)malloc(sizeof(int) * arg_num + 1);
	if (stack_b == 0)
		error_message("Error\n");
	ft_memset(stack_b, 0, arg_num + 1);
	stack_b[0] = 0;
	return (stack_b);
}
