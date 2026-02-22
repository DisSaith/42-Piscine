/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ascii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 12:53:29 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/28 10:35:07 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	is_integer(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_print_char(char c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}
