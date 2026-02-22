/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:15:18 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/23 14:36:25 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(Value) (Value < 0 ? -Value : Value)

#endif

/*
#include <stdio.h>
#include "ft_abs.h"

int	main(void)
{
	int	value = -8;
	ABS(value);
	printf("Valeur absolue de -4 = %d\n", value);
}*/
