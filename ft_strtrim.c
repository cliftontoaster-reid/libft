/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:19:17 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/07 18:28:27 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcontain(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && ft_strcontain(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strcontain(s1[end - 1], set))
		end--;
	trimmed_str = (char *)malloc(end - start + 1);
	if (!trimmed_str)
		return (NULL);
	ft_memcpy(trimmed_str, &s1[start], end - start);
	trimmed_str[end - start] = '\0';
	return (trimmed_str);
}
