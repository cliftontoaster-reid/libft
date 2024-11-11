/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliftontr <cliftontr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:11:54 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/11 17:48:59 by cliftontr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		l;
	char	*res;

	l = ft_strlen(s);
	res = ft_calloc(sizeof(char), l + 1);
	if (res <= 0)
		return (NULL);
	ft_memcpy(res, (void *)s, l);
	return (res);
}
