/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:00:32 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/07 10:00:44 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, int n)
{
	int					i;
	const unsigned char	*f;

	f = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (f[i] == (unsigned char)c)
			return ((void *)&f[i]);
		i++;
	}
	return (0);
}
