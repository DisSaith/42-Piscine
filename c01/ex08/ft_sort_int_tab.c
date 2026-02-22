/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:58:08 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/11 14:36:44 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_test_size_int(int a, int b)
{
	if (a > b)
		return (1);
	return (0);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	switchi;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_test_size_int(tab[i], tab[j]))
			{
				switchi = tab[i];
				tab[i] = tab[j];
				tab[j] = switchi;
			}
			j++;
		}
		i++;
	}
}
/*
int     main(void)
{
        int     tab[11] = {42, 19, 6, 50, 0, 15, -2, 12, 14, 4, 1};

        for (int i = 0 ; i < 9 ; i++)
                printf("avant  : tab[%d] = %d\n", i, tab[i]);
        ft_sort_int_tab(tab, 9);
        printf("\n");
        for (int i = 0 ; i < 9 ; i++)
                printf("apres  : tab[%d] = %d\n", i, tab[i]);
        return (0);
}*/
