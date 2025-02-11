/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliftontr <cliftontr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:50:11 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/11 17:41:15 by cliftontr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, int n)
{
	unsigned char		*d;
	const unsigned char	*s;
	int					i;

	if (!dest && !src)
		return (NULL);
	if ((n == 0) || ((const void *)dest == src))
		return (dest);
	if (n < 0)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (n - i)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
