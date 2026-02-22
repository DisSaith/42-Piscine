/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:41:20 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/25 18:07:07 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (base[i] < 32 || base[i] > 126)
			return (1);
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	tab[42];
	int		i;
	long	nb;

	i = 0;
	nb = nbr;
	if (nb == 0)
		ft_putchar(base[0]);
	if (!ft_verif_base(base))
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		while (nb > 0)
		{
			tab[i] = base[nb % ft_strlen(base)];
			nb = nb / ft_strlen(base);
			i++;
		}
		while (i-- > 0)
			ft_putchar(tab[i]);
	}
	return ;
}

#include <stdio.h>

int	main(void)
{
	ft_putnbr_base(42, "fmustrlena");
	return (0);
}
