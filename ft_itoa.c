/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:33:39 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/07 10:34:46 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	get_num_length(int n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static char	*handle_negative_number(int n, char *res)
{
	char	*neg;
	char	*temp;

	neg = ft_itoa(-n);
	if (!neg)
		return (NULL);
	temp = res;
	res = ft_strjoin("-", neg);
	free(temp);
	free(neg);
	return (res);
}

void	inner_itea(char *res, int *i, int *n, int *len)
{
	if (*len >= 2)
	{
		res[(*i)++] = (*n % 100) / 10 + '0';
		res[(*i)++] = (*n % 10) + '0';
		*n /= 100;
		*len -= 2;
	}
	else
	{
		while (*len > 0)
		{
			res[(*i)++] = (*n % 10) + '0';
			*n /= 10;
			(*len)--;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MAX)
		return (ft_strdup("2147483647"));
	i = 0;
	len = get_num_length(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		return (handle_negative_number(n, res));
	}
	inner_itea(res, &i, &n, &len);
	res[i] = '\0';
	return (res);
}
