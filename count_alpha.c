/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 12:26:42 by exam              #+#    #+#             */
/*   Updated: 2017/01/24 13:21:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct 	s_list
{
	int			num[26];
	char		let[26];
}				t_list;

void		ft_zero(t_list *p, int	i)
{
	while (i < 26)
	{
		p->num[i] = 0;
		p->let[i] = 0;
		i++;
	}
}
int			ft_chr(char c, t_list *p, int j)
{
	int		i;

	i = 0;
	while (i < 26)
	{
		if (p->let[i] == c)
		{
			p->num[i]++;
			return (1);
		}
		i++;
	}
	p->let[j] = c;
	p->num[j]++;
	return (0);
}

void		count_alpha(char *str)
{
	int		i;
	t_list	count;
	int		j;

	ft_zero(&count, 0);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] < 123 && str[i] > 96)
			if (ft_chr(str[i], &count, j) == 0)
				j++;
		if (str[i] < 91 && str[i] > 64)
			if (ft_chr(str[i] + 32, &count, j) == 0)
				j++;
		i++;
	}
	i = -1;
	while (++i < 26)
	{
		if (count.num[i] > 0)
		{
			printf("%d%c", count.num[i], count.let[i]);
			j = i;
			while (++j < 26)
			{
				if (count.num[j] > 0)
				{
					printf(", ");
					break ;
				}
			}
		}

	}
}

int		main(int argc, char	**argv)
{
	if (argc == 2)
		count_alpha(argv[1]);
	printf("\n");
	return (0);
}
