/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:33:09 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/15 16:23:52 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interface/ptr.h>
#include <interface/text.h>
#include <stddef.h>
#include <stdlib.h>

int	ft_puthex(unsigned int n, int upper)
{
	char	*res;
	int		len;

	if (n == 0)
		return (ft_putstr("0"));
	res = ft_ptrtoa(n, upper);
	if (res == NULL)
	{
		free(res);
		len = ft_putstr("(nil)");
		return (len);
	}
	len = ft_putstr(res);
	free(res);
	return (len);
}
