/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 20:41:51 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/29 14:30:17 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset))
		{
			if (in_word == 0)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !(is_charset(str[i], charset)))
		i++;
	return (i);
}

char	*ft_filltab(char *str, char *charset)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char) * (ft_strlen(str, charset) + 1));
	if (!tab)
		return (NULL);
	while (str[i] && !(is_charset(str[i], charset)))
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		if (str[i] && !is_charset(str[i], charset))
		{
			tab[j] = ft_filltab(&str[i], charset);
			j++;
			while (str[i] && !is_charset(str[i], charset))
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

#include <stdio.h>

int	main(void)
{
	char *str = "Salut, le monde : hehe ; Aix-en-Provence";
	char *charset = " \t";
	int count = ft_count_words(str, charset);
	printf("count = %d\n", count);
	char **tab = ft_split(str, charset);
	for (int i = 0 ; i < 8 ; i++)
		printf("tab[%d] = %s\n", i, tab[i]);
	free (tab);
	return (0);
}
