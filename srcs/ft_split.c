/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolivar <ybolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:21:03 by ybolivar          #+#    #+#             */
/*   Updated: 2024/01/02 18:49:56 by ybolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int static	ft_cntwrd(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

void static	ft_freelst(char **lst, int n)
{
	while (n > 0)
	{
		free(lst[n]);
		n--;
	}
	free(lst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}

char static	*ft_instr(char const *s, char c)
{
	int		i;
	char	*lst;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	lst = (char *)malloc(sizeof(char) * (i + 1));
	if (!lst)
		return (NULL);
	ft_strlcpy(lst, s, i + 1);
	return (lst);
}

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		n_str;
	char	**lst;

	if (!s)
		return (NULL);
	n_str = ft_cntwrd(s, c);
	lst = (char **)malloc(sizeof(char *) * (n_str + 1));
	if (!lst)
		return (NULL);
	i = 0;
	while (i < n_str)
	{
		while (s[0] == c)
			s++;
		lst[i] = ft_instr(s, c);
		if (!lst[i])
		{
			ft_freelst(lst, i);
		}
		s = s + ft_strlen(lst[i]);
		i++;
	}
	lst[i] = 0;
	return (lst);
}