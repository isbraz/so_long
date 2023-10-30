/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:51:23 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/04/17 17:25:47 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	lendest;
	size_t	lensrc;

	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	index = 0;
	if (size <= lendest)
	{
		return (lensrc + size);
	}
	while ((index < size - lendest - 1) && src[index] != '\0')
	{
		dest[lendest + index] = src[index];
		index++;
	}
	dest[lendest + index] = '\0';
	return (lendest + lensrc);
}

/*int	main(void)
{
	char	dest[20] = "avanti";
	char	src[] = " palestra";

	printf("%s\n", src);
	//ft_strlcat(dest, src, 2);
	printf("%s\n", dest);
	printf("%d\n", ft_strlcat((void *)0, src, 9));
	printf("After: %s\n", src);
	printf("After: %s\n", dest);
}*/