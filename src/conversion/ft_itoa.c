/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:33:39 by lfiorell          #+#    #+#             */
/*   Updated: 2025/04/02 11:22:54 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	handle_nbr(int n, char *res, int len, int sign)
{
	while (n != 0)
	{
		if (n < 0)
			res[--len] = ((char)n % 10) * -1 + '0';
		else
			res[--len] = (char)n % 10 + '0';
		n /= 10;
	}
	if (sign == -1)
		res[0] = '-';
}

static int	get_len(int n)
{
	long long	nb;
	int			sign;
	int			len;

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
	return (len);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*res;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == INT_MAX)
		return (ft_strdup("2147483647"));
	sign = 1;
	if (n < 0)
		sign = -1;
	len = get_len(n);
	res = (char *)malloc(sizeof(char) * (unsigned long)(len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	handle_nbr(n, res, len, sign);
	return (res);
}
