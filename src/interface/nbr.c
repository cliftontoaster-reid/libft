/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:18:58 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/15 16:12:16 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/text.h"
#include "utils/itoa.h"
#include <stdlib.h>

int	ft_putnbr(int nb)
{
	char	*str;
	int		len;

	str = ft_ltoa((long)nb);
	if (!str)
		return (-1);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	ft_putunbr(unsigned int nb)
{
	char	*str;
	int		len;

	str = ft_ltoa((long)nb);
	if (!str)
		return (-1);
	len = ft_putstr(str);
	free(str);
	return (len);
}
