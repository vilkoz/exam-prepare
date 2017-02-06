/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brain_fuck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:18:07 by orizhiy           #+#    #+#             */
/*   Updated: 2017/01/25 13:47:56 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_brain_fuck(char *s, char *p, int i)
{
	while (*s)
	{
		*s == '>' ? p++ : 0;
		*s == '<' ? p-- : 0;
		*s == '+' ? (*p)++ : 0;
		*s == '-' ? (*p)-- : 0;
		*s == '.' ? write(1, p, 1) : 0;
		if (*s == '[' && !*p && (i = 1))
			while (i && s++)
			{
				*s == ']' ? i-- : 0;
				*s == '[' ? i++ : 0;
			}
		if (*s == ']' && *p && (i = 1))
			while (i && s--)
			{
				*s == '[' ? i-- : 0;
				*s == ']' ? i++ : 0;
			}
		s++;
	}
}

int		main(int ac, char **av)
{
	char	*p;
	int		i;

	i = 0;
	if (ac == 2)
	{
		p = (char *)malloc(sizeof(char) * 2048);
		while (i < 2048)
			p[i++] = '\0';
		ft_brain_fack(av[1], p, i);
	}
	else
		write(1, "\n", 1);
}
