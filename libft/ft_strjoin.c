/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 02:07:59 by bchagas-          #+#    #+#             */
/*   Updated: 2025/08/07 02:40:02 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	total;

	if (!s1 || !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	s3 = ft_calloc((total + 1), sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, total + 1);
	ft_strlcat(s3, s2, total + 1);
	return (s3);
}
