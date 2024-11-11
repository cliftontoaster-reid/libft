/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliftontr <cliftontr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:07:56 by cliftontr         #+#    #+#             */
/*   Updated: 2024/11/11 18:08:11 by cliftontr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*n;
	int		i;

	n = lst;
	i = 0;
	while (n != NULL)
	{
		n = n->next;
		i++;
	}
	return (i);
}
