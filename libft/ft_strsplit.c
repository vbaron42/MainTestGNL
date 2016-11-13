/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:16:58 by vbaron            #+#    #+#             */
/*   Updated: 2016/02/09 21:46:57 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_str(char *s, char c)
{
	char	instr;
	size_t	str;
	size_t	i;

	str = 0;
	instr = 0;
	i = 0;
	while ('\0' != s[i])
	{
		if (s[i] == c)
			instr = 0;
		else if (0 == instr)
		{
			str++;
			instr = 1;
		}
		i++;
	}
	return (str);
}

static char		*ft_fillstr(char **s2, char c)
{
	size_t	len;
	char	*tabstr;
	char	*end;

	len = 0;
	while (**s2 == c)
		(*s2)++;
	end = ft_strchr(*s2, c);
	if (NULL == end)
		len = ft_strlen(*s2);
	else
		len = end - *s2;
	tabstr = ft_strsub(*s2, 0, len);
	*s2 += len;
	return (tabstr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*s2;
	size_t	i;
	size_t	str;

	i = 0;
	s2 = (char *)s;
	str = ft_str(s2, c);
	tab = (char **)malloc((str + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab[str] = NULL;
	while (i < str)
	{
		tab[i] = ft_fillstr(&s2, c);
		i++;
	}
	return (tab);
}
