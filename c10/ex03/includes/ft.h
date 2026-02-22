/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:57:42 by acohaut           #+#    #+#             */
/*   Updated: 2025/10/01 12:54:46 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <libgen.h>

void	print_offset(int offset);
void	print_ascii(unsigned char *buf, int size);
void	print_hex_line(unsigned char *buf, int size);
void	print_line(unsigned char *buf, int size, int offset);

int		process_file(int fd, int *total_offset);
int		read_buffer(char *filename, int *total_offset);
void	process_lotof_files(int argc, char **argv, int *total_offset);

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_puterror(char *str);
void	print_hex_byte(unsigned char c);
int		is_printable(unsigned char c);
int		ft_strcmp(char *s1, char *s2);

#endif
