/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:09:03 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/07 10:09:21 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_ciswhite(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (ft_ciswhite(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			break ;
	}
	if ((result * sign) > INT_MAX)
		return (INT_MAX);
	if ((result * sign) < INT_MIN)
		return (INT_MIN);
	return ((int)result * sign);
}
