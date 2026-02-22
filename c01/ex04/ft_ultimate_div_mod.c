/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:07:47 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/10 20:16:25 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp_div;
	int	temp_mod;

	temp_div = *a / *b;
	temp_mod = *a % *b;
	*a = temp_div;
	*b = temp_mod;
}
/*
int	main(void)
{
	int	a;
	int	b;

	a = 43;
	b = 3;
	printf("avant : a = %d et b = %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("apres : a = %d et b = %d\n", a, b);
	return (0);
}*/
