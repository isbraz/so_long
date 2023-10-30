/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:32:49 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/04/26 16:58:29 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_on_set(char c, char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	begin;
	size_t	end;
	size_t	i;

	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] && ft_is_on_set(s1[begin], set))
		begin++;
	while (end > begin && ft_is_on_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - begin + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (begin < end)
	{
		str[i] = s1[begin];
		i++;
		begin++;
	}
	str[i] = '\0';
	return (str);
}

/*
#include <stdio.h>
int	main(void)
{
	char const *s1 = "hello world my friend";
	char const *set = "hello friend";
	
	printf("%s\n",ft_strtrim(s1, set));
}
*/