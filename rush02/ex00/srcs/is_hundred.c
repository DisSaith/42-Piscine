#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "header.h"

char *ft_strdup(char *src)
{
	char *ptr;
	int i;

	i = 0;
	while (src[i])
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (NULL == ptr)
		return (0);
	i = 0;
	while (src[i])
	{
		ptr[i] = src[i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int t_str(int size, char **str)
{
	int i;
	int total;

	i = 0;
	total = 0;
	while (i < size)
	{
		total = total + ft_strlen(str[i]);
		i++;
	}
	return (total);
}

char *ft_strcat(char *dest, char *src)
{
	char *ptr;

	ptr = dest;
	while (*ptr != '\0')
		ptr++;
	while (*src)
		*ptr++ = *src++;
	return (dest);
}

void strs_write(int size, char **strs, char *sep, char *ptr)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_strcat(ptr, strs[i]);
		ptr += ft_strlen(strs[i]);
		if (i != size - 1)
		{
			ft_strcat(ptr, sep);
			ptr += ft_strlen(sep);
		}
		i++;
	}
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	int tlen;
	char *ptr;
	char *result;

	if (size == 0)
	{
		ptr = (char *)malloc(sizeof(char));
		if (ptr == NULL)
			return (NULL);
		*ptr = '\0';
		return (ptr);
	}
	else
	{
		tlen = t_str(size, strs) + (size - 1) + 1;
		result = (char *)malloc(sizeof(char) * tlen);
		ptr = result;
		if (ptr == NULL)
			return (NULL);
		strs_write(size, strs, sep, ptr);
		return (result);
	}
}

int size_c(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

char *tens_str(char *str)
{
	char *res;
	int j;

	res = (char *)malloc(sizeof(char) * 3);
	res[0] = str[1];
	j = 0;
	if (str[1] != '0')
	{
		while ((str[1] != '1') || (str[1] == '1' && str[2] == '0') && j < 2) // 10 20 24
		{
			res[1] = '0';
			j++;
		}
		if (str[1] == '1' && str[2] != 0) // 12 14
			res[1] = str[2];
		res[j] = '\0';
	}
	return (res);
}

char *res(char *key, t_list *dico)
{
	t_list *current;
	char *value;

	current = dico;

	while (current)
	{
		if (ft_strcmp(key, current->key) == 0)
		{
			value = ft_strdup(current->value);
			break;
		}
		current = current->next;
	}
	return (value);
}

void hun_str(char **result, char *str, int *i)
{
	t_list *dico;
	char digstr[2];

	if (i[0] != 0)
	{
		digstr[0] = str[0];
		digstr[1] = '\0';
		result[0] = res(digstr, dico);
		result[1] = ft_strdup("hundred");
		if (i[1] == 0 && i[2] != 0) // 102
			result[3] = res(digstr, dico);
		if (i[1] != 0 && i[1] != 1 && i[2] == 0) // 120
			result[2] = res(tens_str(str), dico);
		if (i[1] != 0 && i[1] != 1 && i[2] != 0) // 123
		{
			result[2] = res(tens_str(str), dico);
			result[3] = res(digstr, dico);
		}
		if (i[1] == 1) // 110 119 118
		{
			digstr[0] = str[1];
			result[2] = res(digstr, dico);
		}
	}
}

void no_hun(char *str, char **result, int *i)
{
	t_list *dico;
	char digstr[2];

	digstr[0] = str[2];
	digstr[1] = '\0';
	if (i[0] == 0)
	{
		if (i[1] == 0 && i[2] != 0) // 003
		{
			result[0] = res(digstr, dico);
			result[1] = ft_strdup("\0");
		}
		if ((i[1] != 0 && i[2] == 0) || (i[1] == 1)) // 020 040 010 012
		{
			result[0] = res(tens_str(str), dico);
			result[1] = ft_strdup("\0");
		}
		if (i[1] != 0 && i[1] != 1 && i[2] != 0) // 038
		{
			result[0] = res(tens_str(str), dico);
			result[1] = res(digstr, dico);
		}
	}
}

char *put_hundred(char *str)
{
	int size_str;
	int i;
	int digit[3];

	digit[0] = str[0] - '0';
	digit[1] = str[1] - '0';
	digit[2] = str[2] - '0';

	if (digit[0] == 0 && digit[1] == 0 && digit[2] == 0)
		return ("/0");
	char **result = malloc(sizeof(char *) * 4); // result = {"nine", "hundred", "forty", "two"};
	if (result == NULL)
		return (NULL);
	hun_str(result, str, digit);
	hun_str(result, str, digit);
	size_str = size_c(result);
	char *ret = ft_strjoin(size_str, result, " ");
	i = size_str;
	while (i >= 0) // free malloc from tens_str
		free(result[i--]);
	i = 3; // free malloc from result
	free(result);
	return ret;
}

int main(void)
{
	char *str = put_hundred("060");
	printf("%s\n", str);
	free(str); // free malloc from strjoin
}