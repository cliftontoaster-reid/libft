/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliftontr <cliftontr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:59:29 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/11 17:35:14 by cliftontr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = s;
	while (*last)
		last++;
	if ((char)c == '\0')
		return ((char *)last);
	while (last >= s)
	{
		if (*last == (char)c)
			return ((char *)last);
		last--;
	}
	return (NULL);
}
