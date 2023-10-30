/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:05:46 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/04/18 18:05:34 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int main(void)
{
	char *s1 = "Bruna ";
	char *s2 = "Braz";
	char *result = ft_strjoin(s1, s2);
	
	if (result == NULL)
	{
		printf("Error: failed to allocate memory.\n");
		return (1);
	}
	printf("%p\n", s1);
	printf("%p\n", s2);
	//printf("%s\n", result);
	free(result);
	return (0);
}*/