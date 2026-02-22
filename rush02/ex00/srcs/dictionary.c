/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:14:54 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/28 14:41:18 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*create_elem(char *key, char *value)
{
	t_list	*elem;

	if (!key || !value)
		return (NULL);
	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->key = ft_strdup(key);
	elem->value = ft_strdup(value);
	if (!elem->key || !elem->value)
	{
		if (elem->key)
			free(elem->key);
		if (elem->value)
			free(elem->value);
		free(elem);
		return (NULL);
	}
	elem->next = NULL;
	return (elem);
}

void	add_to_dico(t_list **dico, char *key, char *value)
{
	t_list	*new_elem;
	t_list	*current;

	new_elem = create_elem(key, value);
	if (!new_elem)
		return ;
	if (!*dico)
	{
		*dico = new_elem;
		return ;
	}
	current = *dico;
	while (current->next)
		current = current->next;
	current->next = new_elem;
}

void	free_dico(t_list *dico)
{
	t_list	*current;
	t_list	*next;

	current = dico;
	while (current)
	{
		next = current->next;
		free(current->key);
		free(current->value);
		free(current);
		current = next;
	}
}

char	*find_value(t_list *dico, char *key)
{
	t_list	*current;

	if (!dico || !key)
		return (NULL);
	current = dico;
	while (current)
	{
		if (ft_strcmp(key, current->key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
