/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 09:14:34 by acohaut           #+#    #+#             */
/*   Updated: 2025/10/01 14:48:43 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_offset(int offset)
{
	char	*hex;
	char	buffer[9];
	int		i;

	hex = "0123456789abcdef";
	i = 7;
	while (i >= 0)
	{
		buffer[i] = hex[offset % 16];
		offset /= 16;
		i--;
	}
	buffer[8] = '\0';
	ft_putstr(buffer);
}

void	print_ascii(unsigned char *buf, int size)
{
	int	i;

	ft_putchar('|');
	i = 0;
	while (i < size)
	{
		if (is_printable(buf[i]))
			ft_putchar(buf[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('|');
}

void	print_hex_line(unsigned char *buf, int size)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
			print_hex_byte(buf[i]);
		else
			ft_putstr("  ");
		ft_putchar(' ');
		if (i == 7)
			ft_putchar(' ');
		i++;
	}
	ft_putstr(" ");
}

void	print_line(unsigned char *buf, int size, int offset)
{
	print_offset(offset);
	ft_putstr("  ");
	print_hex_line(buf, size);
	print_ascii(buf, size);
	ft_putchar('\n');
}
