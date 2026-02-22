/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 12:37:32 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/28 12:53:38 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
char	*ft_strndup(char *src, int n);
char	*ft_strcat(char *dest, char *src);

int		is_space(char c);
int		is_integer(char c);
int		is_print_char(char c);

typedef struct s_list
{
	char			*key;
	char			*value;
	struct s_list	*next;
}	t_list;

t_list	*create_elem(char *key, char *value);
void	add_to_dico(t_list **dico, char *key, char *value);
void	free_dico(t_list *dico);
char	*find_value(t_list *dico, char *key);

t_list	*read_dictionary(char *file_dico);
void	read_buffer(int fd, char *line, int *line_loc, t_list **dico);
void	parse_line(char *line, t_list **dico);
char	*extract_key(char *line, int *loc);
char	*extract_value(char *line, int loc);

char    *convert(char *word, char *str, t_list *dict);

#endif
