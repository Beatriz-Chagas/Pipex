/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 05:07:57 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/30 04:53:35 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *ptr)
{
	int	p;

	if (!ptr)
		return (ft_putstr("(nil)"));
	p = ft_putstr("0x") + ft_puthex((unsigned long)ptr, 0);
	return (p);
}
