/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:04:54 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/07 10:05:32 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	i = 0;
	while (n - i)
	{
		if (ptr1[i] != ptr2[i])
			return ((unsigned char)ptr1[i] - (unsigned char)ptr2[i]);
		i++;
	}
	return (0);
}
