/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 09:09:49 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/23 12:52:08 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*
#include <stdio.h>

int	main(void)
{
	char	*strs[] = {"Salut", "Pierre", "Feuille", "Puit", "OK ?", NULL};
	t_stock_str *tab;
	tab = ft_strs_to_tab(5, strs);
	for (int i = 0 ; i < 6 ; i++)
	{
		printf("struc[%d].size = %d\n", i, tab[i].size);
		printf("struc[%d].str = %s\n", i, tab[i].str);
		printf("struc[%d].copy = %s\n", i, tab[i].copy);
	}
	free (tab);
	return (0);
}

#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

typedef struct s_stock_str
{
	int	size;
	char	*str;
	char	*copy;
}		t_stock_str;

#endif
*/
