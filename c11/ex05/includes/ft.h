/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:40:10 by acohaut           #+#    #+#             */
/*   Updated: 2025/10/01 17:59:30 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int		add(int a, int b);
int		sous(int a, int b);
int		divi(int a, int b);
int		mul(int a, int b);
int		mod(int a, int b);
int		ft_atoi(char *str);
int		errors(int argc, char *str, int a, int b);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	zero_intmin(int nb);
void	init_tab(int (*f[5])(int, int));

#endif
