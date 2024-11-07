/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:16:51 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/07 18:29:36 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*substr;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		return (ft_calloc(1, 1));
	}
	if (len > slen - start)
		len = slen - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
	{
		return (NULL);
	}
	if (ft_memcpy(substr, s + start, len) == NULL)
	{
		free(substr);
		return (NULL);
	}
	substr[len] = '\0';
	return (substr);
}
