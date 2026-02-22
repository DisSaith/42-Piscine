/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:35:39 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/14 15:30:49 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>

void	ft_putchar(char c);

bool	on_edge(int pos, int max)
{
	return (pos == 0 || pos == max - 1);
}

void	display_box(int x, int y)
{
	char	*chars;
	char	*corners;
	char	chr;
	int		j;
	int		i;

	chars = " *X";
	corners = "/\\";
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			chr = chars[on_edge(i, x) + on_edge(j, y)];
			if (chr == 'X')
				chr = corners[(i > 0) ^ (j > 0)];
			ft_putchar(chr);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

void	errorlog(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	rush(int x, int y)
{
	if (x < 0 || y < 0)
	{
		errorlog("negative value supplied\n");
		return ;
	}
	display_box(x, y);
}
