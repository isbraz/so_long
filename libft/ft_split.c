/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:09:52 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/04/20 23:37:14 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static char	*ft_new_str(char const *s, char *str, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**allstr;

	allstr = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (allstr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			allstr[j] = ft_new_str(&s[i], allstr[j], c);
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	allstr[j] = NULL;
	return (allstr);
}
