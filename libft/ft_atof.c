/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:30:26 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/25 22:05:37 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_skip_ws(const char *s)
{
	while (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\r' || *s == '\f' || *s == '\v')
		s++;
	return (s);
}

static double	ft_extract_sign(const char **ps)
{
	double	sign;

	sign = 1.0;
	if (**ps == '+' || **ps == '-')
	{
		if (**ps == '-')
			sign = -1.0;
		(*ps)++;
	}
	return (sign);
}

static int	ft_parse_integer(const char **ps, double *res)
{
	int	found;

	found = 0;
	while (**ps >= '0' && **ps <= '9')
	{
		*res = *res * 10.0 + (**ps - '0');
		found = 1;
		(*ps)++;
	}
	return (found);
}

static int	ft_parse_fraction(const char **ps, double *res)
{
	double	place;
	int		found;

	if (**ps != '.')
		return (0);
	(*ps)++;
	place = 0.1;
	found = 0;
	while (**ps >= '0' && **ps <= '9')
	{
		*res += (**ps - '0') * place;
		place *= 0.1;
		found = 1;
		(*ps)++;
	}
	return (found);
}

int	ft_atof(const char *s, double *out)
{
	const char	*p;
	double		val;
	double		sign;
	int			has_int;
	int			has_frac;

	if (!s || !out)
		return (-1);
	p = ft_skip_ws(s);
	sign = ft_extract_sign(&p);
	val = 0.0;
	has_int = ft_parse_integer(&p, &val);
	has_frac = ft_parse_fraction(&p, &val);
	if (!has_int && !has_frac)
		return (-1);
	*out = sign * val;
	return (0);
}
