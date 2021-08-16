/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:34:55 by jwoo              #+#    #+#             */
/*   Updated: 2021/05/30 16:36:24 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_space(char s)
{
	if (s == 32 || (9 <= s && s <= 13))
		return (1);
	return (0);
}

int		factor_num(char *s)
{
	int	num;
	int	index;

	if (*s == 0)
		return (0);
	num = 0;
	if (is_space(s[0]) == 0)
		num++;
	index = 0;
	while (++index < ft_strlen(s))
	{
		if (is_space(s[index - 1]) == 1 && is_space(s[index]) == 0)
			num++;
	}
	return (num);
}

char	**factor_len(char **factor, char *s, int factor_num)
{
	int	len;
	int	index;
	int	num;

	index = 0;
	num = 0;
	while (num < factor_num && index < ft_strlen(s))
	{
		while (is_space(s[index]) == 1 && index < ft_strlen(s))
			index++;
		len = 0;
		while (is_space(s[index]) == 0 && index < ft_strlen(s))
		{
			len++;
			index++;
		}
		if (len != 0)
		{
			factor[num] = (char *)malloc(sizeof(char) * (len + 1));
			if (factor[num] == 0)
				return (free_two_dimension(factor, num));
			num++;
		}
	}
	return (factor);
}

void	factor_split(char **factor, char *s, int factor_num)
{
	int	len;
	int	index;
	int	num;

	index = 0;
	num = 0;
	len = 0;
	while (num < factor_num && index < ft_strlen(s))
	{
		if (is_space(s[index]) == 1)
		{
			index++;
			continue ;
		}
		len = 0;
		while (is_space(s[index]) == 0 && index < ft_strlen(s))
		{
			factor[num][len] = s[index];
			len++;
			index++;
		}
		factor[num][len] = '\0';
		num++;
	}
	factor[num] = 0;
}

char	**ft_split_space(char *s)
{
	char	**words;
	int		num;

	if (s == 0)
		return (0);
	num = factor_num(s);
	words = (char **)malloc(sizeof(char *) * (num + 1));
	if (words == 0)
		return (0);
	if (num == 0)
	{
		words[0] = NULL;
		return (words);
	}
	if (factor_len(words, s, num) == 0)
		return (0);
	factor_split(words, s, num);
	return (words);
}
