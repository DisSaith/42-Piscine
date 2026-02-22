/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:59:12 by acohaut           #+#    #+#             */
/*   Updated: 2025/10/01 14:58:40 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	read_buffer(int fd, int nb_bytes)
{
	char	buffer[SIZE];
	int		read_bytes;
	int		i;

	read_bytes = 0;
	while (1)
	{
		read_bytes = read(fd, buffer, SIZE);
		if (read_bytes == -1)
		{
			ft_puterror("tail: ");
			ft_puterror(strerror(errno));
			ft_puterror("\n");
			return ;
		}
		buffer[read_bytes] = '\0';
		if (read_bytes == 0)
			break ;
		i = read_bytes - nb_bytes;
		while (i < (read_bytes + nb_bytes) && buffer[i] != '\0')
		{
			write(1, &buffer[i], 1);
			i++;
		}
	}
}

void	print_header(char *filename, int add_newline)
{
	if (add_newline)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	write(1, filename, ft_strlen(filename));
	write(1, " <==\n", 5);
}

void	process_file(int argc, char **argv, int nb_bytes)
{
	int	i;
	int	fd;

	i = 3;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_puterror("tail: ");
			ft_puterror(argv[i]);
			ft_puterror(": ");
			ft_puterror(strerror(errno));
			ft_puterror("\n");
		}
		else
		{
			if (argc > 4)
				print_header(argv[i], i > 3);
			read_buffer(fd, nb_bytes);
			close(fd);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	if (ft_strcmp(argv[1], "-c") != 0)
		return (1);
	if (argc == 3)
		read_buffer(0, ft_atoi(argv[2]));
	else
		process_file(argc, argv, ft_atoi(argv[2]));
	return (0);
}
