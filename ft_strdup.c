/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:11:54 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/07 10:12:04 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		l;
	char	*res;

	l = ft_strlen(s);
	res = ft_calloc(sizeof(char), l + 1);
	ft_memcpy(res, (void *)s, l);
	return (res);
}
