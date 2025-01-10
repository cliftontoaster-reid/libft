/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:44:52 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/14 14:55:39 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Converts an unsigned integer into a hexadecimal string and prints it.
///
/// It converts the unsigned integer into a hexadecimal string, and prints it.
/// If the boolean value is true,
/// the hexadecimal string is printed in uppercase.
/// Otherwise, it is printed in lowercase.
///
/// @param n The unsigned integer to convert into a hexadecimal string.
/// @param upper A boolean value that determines whether the hexadecimal string
///              should be printed in uppercase (if true) or
///              lowercase (if false).
/// @return Returns the number of characters printed.
int	ft_puthex(unsigned int n, int upper);
