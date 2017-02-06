#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	int		i;
	int		n;
	char	*s;
	char	*hex;

	hex = "0123456789ABCDEF";
	i = (value < 0 && base == 10) ? 2 : 1;
	n = value;
	while (n /= base)
		i++;
	if ((s = (char*)malloc(sizeof(char) * i + 1)) == 0)
		return (NULL);
	s[i] = 0;
	if (value < 0 && base == 10)
		s[0] = '-';
	if (value == 0)
		s[0] = '0';
	n = value;
	while (n)
	{
		s[--i] = hex[(n < 0) ? -(n % base) : n % base];
		n /= base;
	}
	return (s);
}
