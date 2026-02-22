/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:41:20 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/17 22:17:12 by acohaut          ###   ########.fr       */
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
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (base[0] == '\0' || base[1] == '\0')
			return (1);
		if (base[i] <= 32 || base[i] == 127)
			return (1);
		while (base[j])
		{
			if (base[i] == base[j] && !(base[j] == '\0'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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
/*
#include <stdio.h>

int	main(void)
{
	printf("val_atoi_base = %d\n", ft_atoi_base("-20000000000", "01234567"));
	return (0);
}*/
