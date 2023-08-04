/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 13:39:27 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/04 14:17:15 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	word_count(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**free_mem(char **two_d_array)
{
	size_t	i;

	i = 0;
	while (two_d_array[i])
	{
		free(two_d_array[i]);
		i++;
	}
	free(two_d_array);
	return (NULL);
}

static char	**split_word(char const *s, char c, char **str)
{
	const char	*newword;
	size_t		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			newword = s;
			while (*s && *s != c)
				s++;
			str[i] = ft_substr(newword, 0, s - newword);
			if (str[i] == NULL)
				return (free_mem(str));
			i++;
		}
		else
			s++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char		**str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!str)
		return (NULL);
	split_word(s, c, str);
	return (str);
}

/* #include <stdio.h>
int	main(void)
{
	char test[] = "...split...being....a....lil....biiii..";
	char **array;
	int i; 
	
	i = 0;
	array = ft_split(test, '.');
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
} */