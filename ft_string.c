/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:35:06 by jwoo              #+#    #+#             */
/*   Updated: 2021/05/30 16:35:06 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (str == 0)
		return (-1);
	while (str[len])
		len++;
	return (len);
}

void	ft_memset(int *arr, int c, int len)
{
	int	i;

	i = 0;
	while (i < len)
		arr[i++] = c;
	return ;
}

int		atoi_sign(char *str)
{
	int	sign;
	int	idx;

	idx = 0;
	sign = 1;
	if (str == 0)
		return (0);
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	if (!('0' <= str[idx] && str[idx] <= '9'))
		return (0);
	return (sign);
}

int		ft_atoi(char *str, int *integer)
{
	int	index;
	int	num;
	int	sign;

	sign = atoi_sign(str);
	if (sign == 0 || ft_strlen(str) > 11)
		return (-1);
	index = 0;
	if (str[index] == '+' || str[index] == '-')
		index++;
	num = 0;
	while (str[index])
	{
		if (num < 214748364 && '0' <= str[index] && str[index] <= '9')
			num = num * 10 + (str[index] - '0');
		else if (num == 214748364 && '0' <= str[index] && str[index] <= '7')
			num = num * 10 + (str[index] - '0');
		else if (num == 214748364 && str[index] == '8' && sign == -1)
			num = num * (-10) - (str[index] - '0');
		else
			return (-1);
		index++;
	}
	*integer = sign * num;
	return (1);
}
