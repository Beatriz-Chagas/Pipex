/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 02:23:30 by bchagas-          #+#    #+#             */
/*   Updated: 2025/08/11 19:39:53 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	word;

	word = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			word++;
		s++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**splitt;
	const char	*start;
	int			i;

	if (!s)
		return (NULL);
	splitt = (char **)malloc((count_word((char *)s, c) + 1) * sizeof(char *));
	if (!splitt)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		if (s > start)
			splitt[i++] = ft_substr(start, 0, s - start);
	}
	splitt[i] = NULL;
	return (splitt);
}
