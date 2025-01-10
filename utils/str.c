/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:20:27 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/14 12:46:37 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/mem.h"
#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;

	len = ft_strlen(s);
	if (len == 0)
		return (NULL);
	dup = (char *)ft_calloc(sizeof(char), (len + 1));
	if (dup == NULL)
		return (NULL);
	while (len)
	{
		dup[len] = s[len];
		len--;
	}
	dup[len] = '\0';
	return (dup);
}
