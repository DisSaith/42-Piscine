/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:11:02 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/26 11:20:24 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

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

void	write_buffer(char *argv)
{
	int		fd;
	int		size;
	char	buffer[124];

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror("Cannot read file.\n");
		close(fd);
		return ;
	}
	while (1)
	{
		size = read(fd, buffer, sizeof(buffer));
		if (size <= 0)
			break ;
		write(1, buffer, size);
	}
	if (size == -1)
	{
		ft_puterror("Cannot read file.\n");
		close(fd);
		return ;
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_puterror("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_puterror("Too many arguments.\n");
		return (1);
	}
	write_buffer(argv[1]);
	return (0);
}
