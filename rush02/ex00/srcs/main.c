/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 12:36:50 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/27 12:37:10 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char **argv)
{
    (void)argc;
    t_list *dict;
    char    word[1000] = "";

    dict = read_dictionary("numbers.dict");
    ft_putstr(convert(word, argv[1], dict));
    ft_putstr("\n");
    free(dict);
    return(0);
}