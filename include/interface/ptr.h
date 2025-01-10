/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:53:51 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/15 16:19:04 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Converts and prints a pointer address to hexadecimal format
/// @param ptr The pointer whose address needs to be printed
/// @return The number of characters printed
int		ft_putptr(long long ptr);

char	*ft_ptrtoa(unsigned long long n, int upper);
