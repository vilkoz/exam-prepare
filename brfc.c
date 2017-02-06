#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

void	brainfuck(char *in)
{
	char	*out;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	out = (char*)malloc(64000);
	while (in[i])
	{
	/*	ft_putchar(in[i]);
		ft_putchar(' ');
		ft_putnbr(i);
		ft_putchar('\n');*/
		if (in[i] == '>')
			j++;
		if (in[i] == '<')
			j--;
		if (in[i] == '+')
			out[j]++;
		if (in[i] == '-')
			out[j]--;
		if (in[i] == '.')
			ft_putchar(out[j]);
		if (in[i] == '[' && out[j] == 0)
		{
			count = 1;
			while (count)
			{
				if (in[i] == '[')
					count++;
				if (in[i] == ']')
					count--;
				i++;
			}
		}
		if (in[i] == ']' && out[j] != 0)
		{
			count = 1;
			while (count)
			{
				i--;
				if (in[i] == ']')
					count++;
				if (in[i] == '[')
					count--;
			}
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	(void)argc;
	brainfuck(argv[1]);
	return (0);
}
