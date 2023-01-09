/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnieto-j <vnieto-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:22:59 by vnieto-j          #+#    #+#             */
/*   Updated: 2023/01/09 18:25:31 by vnieto-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// fct qui thceck si lke caractere est present dans set
static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		i;
	size_t		start;
	size_t		end;

	if (!s1)
		return (NULL);
	start = 0;
	//compte le nombre d elemn du set present au debut de s1
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	// comnpte le nombre d element de set present a la fin de s1
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	//malloc la taille entre les deux partie du set)
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

// #include <stdio.h>

// int main()
// {
// 	printf("%s\n", ft_strtrim("   xxx   xxx", " x"));
// 	printf("%d\n", ft_char_in_set('t', "toto"));
// 	printf("%s\n", ft_strtrim("atototatatoto", "toto"));
// }	
