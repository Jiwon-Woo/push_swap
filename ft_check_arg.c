/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:34:23 by jwoo              #+#    #+#             */
/*   Updated: 2021/05/30 17:07:10 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(char *message)
{
	write(1, message, ft_strlen(message));
	exit(1);
}

int		argument_number(int argc, char *argv[])
{
	int		arg_num;
	int		idx;
	int		atoi_ret;
	char	**split;
	int		i;

	if (argc < 2)
		exit(0);
	arg_num = 0;
	idx = 0;
	while (++idx < argc)
	{
		split = ft_split_space(argv[idx]);
		if (split == 0)
			error_message("Error\n");
		i = -1;
		while (split[++i])
			if (ft_atoi(split[i], &atoi_ret) == -1)
				error_message("Error\n");
		if (i == 0)
			error_message("Error\n");
		arg_num += i;
		free_two_dimension(split, i);
	}
	return (arg_num);
}

void	is_sort(int arg_num, int *stack_a, int *sort)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (++i <= arg_num)
	{
		if (sort[i] != stack_a[i])
			flag++;
	}
	if (flag == 0)
		exit(0);
}
