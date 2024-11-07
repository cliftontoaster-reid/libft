/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:06:30 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/07 10:06:39 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*l == '\0')
		return ((char *)b);
	while (b[i] && i < len)
	{
		if (b[i] == l[0])
		{
			j = 0;
			while (l[j] && b[i + j] && (i + j) < len && b[i + j] == l[j])
				j++;
			if (l[j] == '\0')
				return ((char *)&b[i]);
		}
		i++;
	}
	return (NULL);
}
