/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconceic <tconceic@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:20:32 by tconceic          #+#    #+#             */
/*   Updated: 2021/10/24 15:13:11 by tconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen( const char *str )
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == '\0')
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	char			*str_end;
	unsigned int	i;
	unsigned int	j;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_end = (char *)malloc(s1_len + s2_len + 1);
	if (str_end == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		str_end[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
		str_end[i++] = s2[j++];
	str_end[i] = '\0';
	return (str_end);
}

char	*ft_strchr(const char *str, int ch)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)ch)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == '\0' && ch == '\0')
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strdup(const char *str1)
{
	char	*str2;
	size_t	str_size;

	str_size = ft_strlen(str1) + 1;
	str2 = (char *)malloc(str_size);
	if (!str2)
		return (NULL);
	ft_strlcpy(str2, str1, str_size);
	return (str2);
}
