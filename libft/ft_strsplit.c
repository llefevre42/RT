/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:02:11 by rpinault          #+#    #+#             */
/*   Updated: 2018/05/30 14:20:27 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			word_count(char const *str, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		if (str[i] != '\0')
			i++;
	}
	return (word);
}

static int			len_count(char const *str, int number, char c)
{
	int		i;
	int		word;
	int		letter;

	i = 0;
	word = 0;
	letter = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
			{
				if (word == number)
					letter++;
				i++;
			}
		}
		if (str[i] != '\0')
			i++;
	}
	return (letter);
}

static char			**ft_print(char const *str, char **tab, char c)
{
	int		i;
	int		j;
	int		word;

	i = 0;
	j = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i] != '\0')
			{
				tab[word][j] = str[i++];
				j++;
			}
			tab[word][j] = '\0';
			j = 0;
			word++;
		}
		if (str[i] != '\0')
			i++;
	}
	tab[word] = 0;
	return (tab);
}

char				**ft_strsplit(char const *str, char c)
{
	int		i;
	char	**tab;

	if (str == NULL)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (word_count(str, c) + 1))))
		return (NULL);
	i = 0;
	while (i < word_count(str, c))
	{
		tab[i] = (char *)malloc(sizeof(char) * (len_count(str, i + 1, c) + 1));
		i++;
	}
	if (!(tab[word_count(str, c)] = (char *)malloc(sizeof(char) + 1)))
		return (NULL);
	tab = ft_print(str, tab, c);
	tab[word_count(str, c)] = 0;
	return (tab);
}
