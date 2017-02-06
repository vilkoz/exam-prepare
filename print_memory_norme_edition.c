/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory_norme_edition.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:18:56 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/01/24 19:19:01 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(unsigned const char *tmp, size_t *i, size_t j, size_t size)
{
	const char	*str;
	int			k;

	str = "0123456789abcdef";
	(*i) = 0;
	while ((*i) < 16 && (*i) + j < size)
	{
		k = *(tmp + (*i) + j);
		write(1, (str + (k >> 4) % 16), 1);
		write(1, (str + k % 16), 1);
		if ((*i) % 2)
			write(1, " ", 1);
		(*i)++;
	}
	while ((*i) < 16)
	{
		write(1, "  ", 2);
		if ((*i) % 2)
			write(1, " ", 1);
		(*i)++;
	}
}

void	print_memory(const void *addr, size_t size)
{
	unsigned const char	*tmp;
	size_t				i;
	size_t				j;
	int					d;

	j = 0;
	tmp = addr;
	while (j < size)
	{
		print(tmp, &i, j, size);
		i = 0;
		while (i < 16 && i + j < size)
		{
			d = *(tmp + i + j);
			if (d >= 32 && d <= 126)
				write(1, &d, 1);
			else
				write(1, ".", 1);
			i++;
		}
		j += 16;
		write(1, "\n", 1);
	}
}
