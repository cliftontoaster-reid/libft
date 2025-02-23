/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:11:54 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/10 22:40:49 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		l;
	char	*res;

	l = ft_strlen(s);
	res = ft_calloc(sizeof(char), (unsigned long)l + 1);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, (void *)s, l);
	return (res);
}
