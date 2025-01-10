/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:45:42 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/14 12:39:14 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct	s_flags
{
	int	precision;

}		t_flags;

/// @brief Prints a formatted string to the standard output stream.
/// @param * the string to print
/// @param ... the arguments to print
/// @return the number of characters printed
int		ft_printf(const char *format, ...);
