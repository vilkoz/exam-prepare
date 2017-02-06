#include <stdlib.h>
#include <stdio.h>

char	*g_base = "0123456789abcdef";
char	*g_base1 = "0123456789ABCDEF";

int		ft_pow(int x, int pow)
{
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (x);
	else
		return (x * ft_pow(x, pow - 1));
}

int		ft_index(const char c, int str_base)
{
	int		i;

	i = -1;
	while (g_base[++i] && i < str_base)
		if (c == g_base[i] || c == g_base1[i])
			return (i);
	return (-1);
}

int		ft_size(const char *str, int str_base)
{
	int		i;

	i = -1;
	while (g_base[++i] && (ft_index(str[i], str_base) >= 0))
		;
	return (i);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		is_neg;
	int		res;
	int		tmp;
	int		size;

	i = 0;
	res = 0;
	is_neg = 0;
	size = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			if (is_neg)
				return (0);
			is_neg = 1;
		}
		i++;
	}
	size = ft_size(str, str_base);
	while (str[i] && (tmp = ft_index(str[i], str_base)) >= 0)
	{
		res += ft_index(str[i], str_base) * ft_pow(str_base, size - 1);
		size--;
		i++;
	}
	return (res);
}

int		main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	printf("%d\n", ft_atoi_base(av[1], atoi(av[2])));
}
