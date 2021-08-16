/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:34:37 by jwoo              #+#    #+#             */
/*   Updated: 2021/05/30 16:34:38 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_two_dimension(char **word, int num)
{
	int	n;

	n = -1;
	while (++n <= num)
	{
		free(word[n]);
		word[n] = 0;
	}
	free(word);
	word = 0;
	return (NULL);
}

void	free_stack(t_stack *stack, int *sort)
{
	free(stack->a);
	stack->a = 0;
	free(stack->b);
	stack->b = 0;
	free(stack);
	stack = 0;
	free(sort);
	sort = 0;
}
