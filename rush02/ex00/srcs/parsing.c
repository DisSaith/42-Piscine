/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:13:02 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/28 14:40:50 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*read_dictionary(char *file_dico)
{
	int		fd;
	int		line_loc;
	char	line[256];
	t_list	*dico;

	dico = NULL;
	line_loc = 0;
	fd = open(file_dico, O_RDONLY);
	if (fd == -1)
		return (NULL);
	read_buffer(fd, line, &line_loc, &dico);
	close(fd);
	return (dico);
}

void	read_buffer(int fd, char *line, int *line_loc, t_list **dico)
{
	char	buffer[1024];
	int		size;
	int		i;

	size = 0;
	while (1)
	{
		size = read(fd, buffer, 1023);
		if (size <= 0)
			break ;
		buffer[size] = '\0';
		i = 0;
		while (i < size)
		{
			if (buffer[i] == '\n')
			{
				line[*line_loc] = '\0';
				parse_line(line, dico);
				*line_loc = 0;
			}
			else if (*line_loc < 255)
				line[(*line_loc)++] = buffer[i];
			i++;
		}
	}
}

void	parse_line(char *line, t_list **dico)
{
	char	*key;
	char	*value;
	int		loc;

	loc = 0;
	key = extract_key(line, &loc);
	if (!key)
		return ;
	value = extract_value(line, loc);
	if (!value)
		return ;
	add_to_dico(dico, key, value);
	free(key);
	free(value);
}

char	*extract_key(char *line, int *loc)
{
	char	*key;
	int		i;

	i = 0;
	key = malloc(sizeof(char) * 256);
	if (!key)
		return (NULL);
	while (line[(*loc)] && line[(*loc)] != ':')
	{
		if (is_integer(line[(*loc)]))
		{
			key[i] = line[(*loc)];
			i++;
		}
		(*loc)++;
	}
	key[i] = '\0';
	return (key);
}

char	*extract_value(char *line, int loc)
{
	char	*value;
	int		i;

	i = 0;
	value = malloc(sizeof(char) * 256);
	if (!value)
		return (NULL);
	while ((line[loc] && is_space(line[loc])) || line[loc] == ':')
		loc++;
	while (line[loc] && line[loc] != '\n' && line[loc] != '\0')
	{
		if (is_print_char(line[loc]))
		{
			value[i] = line[loc];
			i++;
		}
		loc++;
	}
	value[i] = ' ';
	value[i + 1] = '\0';
	return (value);
}

/*
int	main(void)
{
	t_list *dico;

	dico = read_dictionary("numbers.dict");
	t_list	*current;
	current = dico;
	int	i = 0;
	while (current)
	{
		printf("liste[%d] : key = %s\n", i, current->key);
		printf("liste[%d] : value = %s\n", i, current->value);
		i++;
		current = current->next;
	}
}*/
