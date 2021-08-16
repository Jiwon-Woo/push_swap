/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:34:42 by jwoo              #+#    #+#             */
/*   Updated: 2021/05/30 16:34:43 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_swap(int *arr, int root, int idx)
{
	int	temp;

	temp = arr[root];
	arr[root] = arr[idx];
	arr[idx] = temp;
}

void	heapify(int *arr, int num)
{
	int	root;

	root = 1;
	arr_swap(arr, root, num);
	while (root <= (num - 1) / 2)
	{
		if ((root * 2 + 1 == num) || (arr[root * 2] > arr[root * 2 + 1]))
		{
			if (arr[root] < arr[root * 2])
			{
				arr_swap(arr, root, root * 2);
				root = root * 2;
			}
			else
				break ;
		}
		else if (arr[root] < arr[root * 2 + 1])
		{
			arr_swap(arr, root, root * 2 + 1);
			root = root * 2 + 1;
		}
		else
			break ;
	}
}

void	heap_sort(int *arr, int num)
{
	if (num <= 1)
		return ;
	heapify(arr, num);
	heap_sort(arr, num - 1);
}

void	insert_heap(int *sort, int idx)
{
	int	parent;

	parent = idx;
	while (parent > 1)
	{
		if (sort[parent] > sort[parent / 2])
		{
			arr_swap(sort, parent, parent / 2);
			parent /= 2;
		}
		else
			break ;
	}
}
