/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:22:34 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/23 20:43:04 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;

	if (fd < 0)
		return ;
	i = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = -n;
	}
	if (i >= 10)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd((i % 10) + '0', fd);
}

int	ft_putnbr(long long n)
{
	unsigned long long	i;
	int					count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		i = (unsigned long long)(-n);
	}
	else
		i = (unsigned long long)n;
	if (i >= 10)
		count += ft_putnbr(i / 10);
	count += ft_putchar((i % 10) + '0');
	return (count);
}
