/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:09:00 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/23 14:24:18 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	tab[11];
	int		i;
	long	nbr;

	nbr = nb;
	i = 0;
	if (nbr == 0)
		write(1, "0", 1);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	while (nbr > 0)
	{
		tab[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	while (i-- > 0)
		ft_putchar(tab[i]);
}

/*
char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	t_stock_str		*struc;

	struc = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!struc)
		return (NULL);
	i = 0;
	while (i < ac && av[i] != NULL)
	{
		struc[i].size = ft_strlen(av[i]);
		struc[i].str = ft_strdup(av[i]);
		struc[i].copy = struc[i].str;
		i++;
	}
	struc[i].str = 0;
	return (struc);
}
*/

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}

/*
int	main(void)
{
	char	*strs[] = {"Salut", "Pierre", "Feuille", "Puit", "OK ?", NULL};
	t_stock_str *tab;
	tab = ft_strs_to_tab(5, strs);
	ft_show_tab(tab);
	free (tab);
	return (0);
}*/
