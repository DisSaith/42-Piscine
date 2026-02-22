/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:55:57 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/18 08:23:44 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	c;
	char	*hexa;

	i = 0;
	hexa = "0123456789abcdef";
	while (str[i])
	{
		c = (unsigned char)str[i];
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			ft_putchar(hexa[c / 16]);
			ft_putchar(hexa[c % 16]);
		}
		i++;
	}
}

#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello¬How are you ?";
	printf("(avant) str = %s\n", str);
	ft_putstr_non_printable(str);
	return (0);
}
