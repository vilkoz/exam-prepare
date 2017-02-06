/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:52:51 by exam              #+#    #+#             */
/*   Updated: 2017/01/24 13:10:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	if (str == NULL)
		return (i);
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int		ft_strstr(char *s1, char *s2)
{
	int	i;
	int	j;
	int	k;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return (1);
	while (s1[i] != '\0')
	{
		j = 0;
		k = i;
		while (s2[j] != '\0' && s1[k] != '\0')
		{
			if (s1[k++] != s2[j])
				break;
			else
				j++;
		}
		if (j == ft_strlen(s2))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strsub(char *str, int len)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new[len] = '\0';
	while (*str && i < len)
	{
		new[i] = *str;
		str++;
		i++;
	}
	return (new);
}

char	**str_maxlenoc(int argc, char **argv)
{
	int		i;
	char	*sub;
	int		j;
	char	**arr;
	int		counter;

	i = 1;
	arr = (char**)malloc(sizeof(char*) * 500);
	arr[500] = NULL;
	counter = 0;
	while (*argv[1] != '\0')
	{
		sub = ft_strsub(argv[1], i);
		j = 2;
		while (j < argc)
		{
			if (ft_strstr(argv[j], sub) == 1)
				j++;
			else
				break ;
		}
		if (j == argc)
			arr[counter++] = sub;
		if (i == ft_strlen(argv[1]))
		{
			i = 1;
			argv[1]++;
		}
		else
			i++;
	}
	return (arr);
}

int		main(int argc, char **argv)
{
	char	**arr;
	int		max_len;
	int		counter;
	
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		arr = str_maxlenoc(argc, argv);
		max_len = 0;
		counter = -1;
		while (counter++ < 500)
			if (ft_strlen(arr[counter]) > max_len)
				max_len = ft_strlen(arr[counter]);
		counter = -1;
		while (counter++ < 500)
		{
			if (ft_strlen(arr[counter]) == max_len)
			{
				write(1, arr[counter], max_len);
				write(1, "\n", 1);
				break ;
			}
		}
	}
	return (0);
}
