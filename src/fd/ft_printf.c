/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:41:48 by lfiorell          #+#    #+#             */
/*   Updated: 2025/03/25 16:31:20 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/hex.h"
#include "interface/nbr.h"
#include "interface/ptr.h"
#include "interface/text.h"
#include "limits.h"
#include "utils/str.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/// [ ] %c
/// [ ] %s
/// [ ] %p
/// [ ] %d
/// [ ] %i
/// [ ] %u
/// [ ] %x
/// [ ] %X
/// [ ] %%

/// @brief This function handles the token and calls the appropriate
///        function based on the token.
/// @param args The argument list containing the values to be processed.
/// @param format The format string containing the token.
/// @return The number of characters printed.
static int	handle_token(va_list args, const char **format)
{
	int	count;

	count = 0;
	if (*(*format + 1) == '\0')
		return (ft_putchar(**format));
	(*format)++;
	if (**format == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (**format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (**format == 'p')
		count += ft_putptr((long long)va_arg(args, void *));
	else if (**format == 'd' || **format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (**format == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (**format == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (**format == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (**format == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(**format);
	return (count);
}

int	ft_vprintf(va_list args, const char *format)
{
	int	count;

	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += handle_token(args, &format);
		else
			count += ft_putchar(*format);
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	count = ft_vprintf(args, format);
	va_end(args);
	return (count);
}
