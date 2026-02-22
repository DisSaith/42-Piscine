/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:59:12 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/29 15:37:00 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_puterror(char *str)
{
	write(2, str, ft_strlen(str));
}

void	read_buffer(int fd, char *buffer)
{
	int	read_bytes;

	read_bytes = 0;
	while (1)
	{
		read_bytes = read(fd, buffer, SIZE);
		if (read_bytes == -1)
		{
			ft_puterror(strerror(errno));
			return ;
		}
		buffer[read_bytes] = '\0';
		if (read_bytes == 0)
			break ;
		write(1, buffer, read_bytes);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	buffer[SIZE];

	if (argc == 1)
		read_buffer(0, buffer);
	i = 1;
	while (argv[i])
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_puterror("cat: ");
			ft_puterror(argv[i]);
			ft_puterror(": ");
			ft_puterror(strerror(errno));
			ft_puterror("\n");
			i++;
			continue ;
		}
		read_buffer(fd, buffer);
		close(fd);
		i++;
	}
	return (0);
}
