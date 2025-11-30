/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:29:55 by bchagas-          #+#    #+#             */
/*   Updated: 2025/08/09 00:20:45 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
		return (ft_strdup(""));
	i -= start;
	if (len < i)
		i = len;
	sub = (char *)malloc(i + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, i);
	sub[i] = '\0';
	return (sub);
}
