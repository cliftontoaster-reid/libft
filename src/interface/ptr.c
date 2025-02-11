/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:50:09 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/14 18:53:02 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/text.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define HEX_LOWER "0123456789abcdef"
#define HEX_UPPER "0123456789ABCDEF"

static void	handle_hex(unsigned long long n, char *res, int len, int upper)
{
	char	*hex_base;

	if (upper)
		hex_base = HEX_UPPER;
	else
		hex_base = HEX_LOWER;
	while (n != 0 && len > 0)
	{
		res[--len] = hex_base[n % 16];
		n /= 16;
	}
}

char	*ft_ptrtoa(unsigned long long n, int upper)
{
	unsigned long long	nb;
	int					len;
	char				*res;

	nb = n;
	len = 0;
	if (n == 0)
		return ("0");
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	handle_hex(n, res, len, upper);
	return (res);
}

int	ft_putptr(unsigned long long ptr)
{
	char	*res;
	int		len;

	if (ptr == 0)
		return (ft_putstr("(nil)"));
	res = ft_ptrtoa(ptr, 0);
	if (res == NULL)
	{
		free(res);
		len = ft_putstr("(nil)");
		return (len);
	}
	len = ft_putstr("0x");
	len += ft_putstr(res);
	free(res);
	return (len);
}
