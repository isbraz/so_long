/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:40:20 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/04/16 14:05:46 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	lensrc;

	index = 0;
	lensrc = ft_strlen(src);
	if (size <= 0)
		return (lensrc);
	while (src[index] != '\0' && index < size - 1)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (lensrc);
}

/*int	main(void)
{
	char	dest[] = "Hello";
	char	src[] = "World";

	printf("%s\n", dest);
	printf("%ld\n", ft_strlcpy(dest, src, 5));
	printf("%s\n", dest);

}*/
