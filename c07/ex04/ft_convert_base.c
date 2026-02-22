/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:01:06 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/22 18:48:06 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_verif_base(char *base);
char	*ft_fill_tab(int size, char *tab, int is_negative);

char	*ft_putnbr_base(int nbr, char *base)
{
	char	tab[42];
	char	*result;
	int		i;
	long	nb;

	i = 0;
	nb = nbr;
	if (!ft_verif_base(base))
	{
		if (nb == 0)
			tab[i++] = base[0];
		if (nb < 0)
			nb *= -1;
		while (nb > 0)
		{
			tab[i++] = base[nb % ft_strlen(base)];
			nb = nb / ft_strlen(base);
		}
		result = ft_fill_tab(i, tab, (nbr < 0));
		return (result);
	}
	return (NULL);
}

int	ft_base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{	
	int	atoi;
	int	sign;
	int	i;

	sign = 1;
	atoi = 0;
	i = 0;
	if (ft_verif_base(base))
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_base_index(str[i], base) != -1)
	{
		atoi *= ft_strlen(base);
		atoi += ft_base_index(str[i], base);
		i++;
	}
	return (atoi * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result_char;
	int		result_int;

	if (ft_verif_base(base_from) || ft_verif_base(base_to))
		return (NULL);
	result_int = ft_atoi_base(nbr, base_from);
	result_char = ft_putnbr_base(result_int, base_to);
	return (result_char);
}
/*
#include <stdio.h>

int	main(void)
{
	char *nbr = "-2147483648";
	char *base_from = "0123456789";
	char *base_to = "01";
	char *result = ft_convert_base(nbr, base_from, base_to);
	printf("result = %s\n", result);
	free(result);
}*/
