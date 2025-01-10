/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:20:21 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/15 16:14:51 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static void	handle_nbr(long n, char *res, int len, int sign)
{
	while (n != 0)
	{
		if (n < 0)
			res[--len] = (n % 10) * -1 + '0';
		else
			res[--len] = n % 10 + '0';
		n /= 10;
	}
	if (sign == -1)
		res[0] = '-';
}

char	*ft_ltoa(long n)
{
	long long	nb;
	int			sign;
	int			len;
	char		*res;

	nb = n;
	sign = 0;
	if (nb < 0)
		nb *= -1 + 0 * sign--;
	len = 0;
	if (nb == 0)
		len = 1;
	while (nb > 0)
		nb /= 10 + 0 * len++;
	if (sign == -1)
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	handle_nbr(n, res, len, sign);
	return (res);
}
