/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:59:12 by acohaut           #+#    #+#             */
/*   Updated: 2025/10/01 14:48:18 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	process_file(int fd, int *total_offset)
{
	unsigned char	buffer[16];
	int				bytes_read;

	bytes_read = read(fd, buffer, 16);
	while (bytes_read > 0)
	{
		print_line(buffer, bytes_read, *total_offset);
		*total_offset += bytes_read;
		bytes_read = read(fd, buffer, 16);
	}
	return (0);
}

int	read_buffer(char *filename, int *total_offset)
{
	int	fd;
	int	result;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror("hexdump: ");
		ft_puterror(filename);
		ft_puterror(": No such file or directory\n");
		return (-1);
	}
	result = process_file(fd, total_offset);
	close(fd);
	return (result);
}

void	process_lotof_files(int argc, char **argv, int *total_offset)
{
	int	i;

	i = 2;
	while (i < argc)
	{
		read_buffer(argv[i], total_offset);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	total_offset;

	total_offset = 0;
	if (argc < 2 || ft_strcmp(argv[1], "-C") != 0)
	{
		ft_puterror("hexdump: invalid option\n");
		return (1);
	}
	if (argc == 2)
		process_file(0, &total_offset);
	else
		process_lotof_files(argc, argv, &total_offset);
	print_offset(total_offset);
	ft_putchar('\n');
	return (0);
}
