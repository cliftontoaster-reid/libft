/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:50:11 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/07 09:50:29 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, int n)
{
	unsigned char		*d;
	const unsigned char	*s;
	int					i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (n - i)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
