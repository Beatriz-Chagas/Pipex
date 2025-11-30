/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 22:02:26 by bchagas-          #+#    #+#             */
/*   Updated: 2025/08/09 00:03:40 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (src == NULL && dest == NULL)
		return (NULL);
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	i = 0;
	if (d < s)
	{
		while (i < len)
		{
		d[i] = s[i];
		i++;
		}
	}
	else
	{
		while (len--)
			d[len] = s[len];
	}
	return (dest);
}
