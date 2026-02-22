/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [ls-phabm] <[ls-phabm@student.42.fr]>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:18:39 by [ls-phabm]        #+#    #+#             */
/*   Updated: 2025/09/27 15:18:43 by [ls-phabm]       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

char    *trans_key(char *str)
{
    int i;
    char    *str0;

    i = 1;
    str0 = str;
    while (str0[i])
    {
        str0[i] = '0';
        i++;
    }
    return (str0);
}

char    *trans_h(char *str)
{
    return (ft_strndup(str, 1));
}

char    *convert_unit(char *str, t_list *dict)
{
    return (ft_strdup(find_value(dict, str)));
}

char    *convert_ten(char *str, t_list *dict)
{
    char    *t;
    char    *u;
    //char    n;
    
    if (str[0] == '1') // unique values
        return (ft_strdup(find_value(dict, str)));
    else // combination of ten + unit
    {        
        u = find_value(dict, &str[1]); // unit
        t = find_value(dict, trans_key(str)); // ten
        return(ft_strcat(ft_strdup(t), ft_strdup(u)));
    }
}

char    *convert_hundred(char *str, t_list *dict)
{
    char    *h;
    char    *t;
    char    *u;
    
    if (str[2] == '0') // nada
    {
        u = "";
        t = "";
    }
    else if (str[1] == '0') // units only
    {
        u = convert_unit(str+2, dict);
        t = "";
    }
    else if (str[1] == '1') // unique values
    {
        u = "";
        t = convert_ten(str+1, dict);
    }
    else // combination of ten + unit
    {
        u = find_value(dict, &str[2]); // unit
        t = find_value(dict, trans_key(&str[1])); // ten
    }
    h = ft_strcat(ft_strdup(find_value(dict, trans_h(str))), ft_strdup(find_value(dict, "100"))); // hundred
    return(ft_strcat(ft_strdup(h), ft_strcat(ft_strdup(t), ft_strdup(u))));
}

int     block_len(char *str)
{
    int nd;

    if (ft_strlen(str) % 3 == 0)
        nd = 3;
    else
        nd = ft_strlen(str) % 3;
    return (nd);
}

char     *multiplier(char *str, t_list *dict)
{
    int     nz;
    char    *key;

    nz = ft_strlen(str) - (ft_strlen(str) % 3);
    key = malloc(sizeof(char) * (nz + 1 + 1));
    key[0] = '1';
    key[nz + 2] = '\0';
    while (nz > 0)
    {
        key[nz] = '0';
        nz--;
    }        
    return (ft_strdup(find_value(dict, key)));
}

char    *convert_block(char *str, t_list *dict)
{
    int n;
    char *block_str;

    n = ft_strlen(str);
    block_str = malloc(sizeof(char) * (11 * 5 + 4 + 1));
    if (n == 1) // one single digit
        block_str = convert_unit(str, dict); // easy
    if (n == 2) // two digits = ten
        block_str = convert_ten(str, dict);
    if (n == 3)
        block_str = convert_hundred(str, dict);
    return (block_str);
}

char    *convert(char *word, char *str, t_list *dict)
{
    int n;
    char    *block;
    char    *str_b;
    int     b_len;
    char     *m;

    n = ft_strlen(str);
//    str_f = malloc(sizeof(char) * 1000);
    str_b = malloc(sizeof(char) * 1000);
    b_len = 0;

    n = ft_strlen(str); // max base_ten
    block = malloc(sizeof(char) * (3 + 1));
    m = malloc(sizeof(char) * 38);
    
    if (n == 1) // one single digit // base case
        return(convert_unit(str, dict)); // easy
    else if (n == 2) // two digits = ten
        return (convert_ten(str, dict));
    else if (n == 3)
        return (convert_hundred(str, dict));
    /*
    // recursive - read block of 3 digits
    while (n > 4)
    {
        printf("%d\n", n);
        m = multiplier(str, dict);
        //printf("multiplier = %s\n", m);
        block = ft_strndup(str, n % 3);
        b_len = block_len(block);
        //printf("block = %s\n", block);
        str_b = ft_strdup(convert_block(block, dict));
        str_b = ft_strcat(str_b, m);
        word = ft_strcat(word, str_b);
        //str = &str[b_len]; // next iteration
        printf("word = %s\n", word);
        printf("next block = %s\n", &str[b_len]);
        convert(word, &str[b_len], dict);
        //return (convert(word, &str[b_len], dict));
    }*/
    return (word);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
    (void)argc;
    t_list *dict;
    char    word[1000] = "";

    dict = read_dictionary("numbers.dict");
    printf("%s\n", convert(word, argv[1], dict));
    return(0);
}
*/