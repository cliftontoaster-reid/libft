/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:39:25 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/14 12:46:52 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TOKENS "\%cspdiuxX"
#define FLAGS "#0-+. "

int	is_flag(char c)
{
	int	i;

	i = 0;
	while (FLAGS[i])
	{
		if (FLAGS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_token(char c)
{
	int	i;

	i = 0;
	while (TOKENS[i])
		if (TOKENS[i++] == c)
			return (1);
	return (0);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
