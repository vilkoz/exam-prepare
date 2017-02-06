/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 11:40:00 by exam              #+#    #+#             */
/*   Updated: 2017/01/24 12:46:36 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++ ;
	return (i);
}

int main(int argc, char **argv)
{
	char	*res;
	int		i;
	int		j;
	int		k;
	int		tmp;

	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		write(1, "0\n", 2);
		return (0);
	}
	argc = ft_strlen(argv[1]) + ft_strlen(argv[2]);
	res = (char*)malloc(sizeof(char) * (argc + 1));
	if (!res)
		return (0);
	k = 0;
	while (k <= argc)
		res[k++] = 0;
	i = ft_strlen(argv[2]) - 1;
	while (i >= 0 && argv[2][i] != '-')
	{
		k = argc + i - ft_strlen(argv[2]);
		j = ft_strlen(argv[1]) - 1;
		while (j >= 0 && argv[1][j] != '-')
		{
			res[k] += (argv[1][j] - 48) * (argv[2][i] - 48);
			tmp = argc - 1;
			while (tmp >= 0)
			{
				while (res[tmp] > 9)
				{
					res[tmp - 1]++;
					res[tmp] = res[tmp] - 10;
				}
				tmp--;
			}
			k--;
			j--;
		}
		i--;
	}
	k = 0;
	while (k < argc)
		res[k++] += 48;
	k = 0;
	while (res[k] == '0')
		k++;
	if ((argv[1][0] == '-' && argv[2][0] != '-') ||
			(argv[2][0] == '-' && argv[1][0] != '-'))
		write(1, "-", 1);
	while (res[k])
		write(1, &(res[k++]), 1);
	write(1, "\n", 1);
	free(res);
	return (0);
}
