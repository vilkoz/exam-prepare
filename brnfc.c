#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_putchar(char c)
{
	write (1, &c, 1);
	return (0);
}

void	brainfuck(char *in)
{
	char *out = (char*)malloc(64000);
	int count = 0;
	int i = 0;
	int j = 0;

	while (in[i])
	{
//		putchar(in[i]);
		if (in[i] == '>')
			j++;
		else if (in[i] == '<')
			j--;
		else if (in[i] == '+')
			out[j]++;
		else if (in[i] == '-')
			out[j]--;
		else if (in[i] == '.')
			ft_putchar(out[j]);
		else if (in[i] == ',')
			out[j] = getchar();
		else if (in[i] == '[')
		{
			if (out[j] == 0)
			{
				count = 1;
				while (count)
				{
					i++;
					if (in[i] == ']')
						count--;
					if (in[i] == '[')
						count++;
				}
			}
		}
		else if (in[i] == ']')
		{
			if (out[j] != 0)
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
		}
		i++;
	}
}

int		main(int ac,char **av)
{
	(void)ac;
	brainfuck(av[1]);
	return (0);
}
