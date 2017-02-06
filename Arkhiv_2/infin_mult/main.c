#include <stdlib.h>
#include <unistd.h>
#include "add.h"

int     ft_strlen(char *s)
{
    int     i;
    
    i = -1;
    while (s[++i] != '\0')
        ;
    return (i);
}

void    ft_bzero(char **s, int mode)
{
    int     i;
    
    i = -1;
    if (mode == 0)
        while (s[++i] != '\0')
            s[i] = 0;
    else
        while (s[++i] != '\0')
            s[i] += '0';
}

char    *ft_calculate(t_e e)
{
    int     i;
    int     j;
    int     k;
    int     tmp;
    
    e.n2_len = ft_strlen(e.n2);
    e.n1_len = ft_strlen(e.n1);
    i = e.n2_len - 1;
    while (i >= 0 && e.n2[i] != '-')
    {
        k = e.res_len - e.n2_len + i;
        j = e.n1_len - 1;
        while (j >= 0 && e.n1[j] != '-')
        {
            e.res[k] = (e.n1[j] - '0') * (e.n2[i] - '0');
            tmp = e.res_len - 1;
            while (tmp >= 0)
            {
                if (e.res[tmp] > 9)
                {
                    e.res[tmp - 1]++;
                    e.res[tmp] -= 10;
                }
            }
            j--;
            k--;
        }
        i--;
    }
    return (e.res);
}

int     main(int argc, char **argv)
{
    t_e     e;
    
    (void)argc;
    if (argv[1][0] == '0' && argv[2][0] == '0')
        write(1, "0\n", 2);
    e.res_len = ft_strlen(argv[1]) + ft_strlen(argv[2]);
    e.res = (char *)malloc(sizeof(char) * e.res_len + 1);
    e.res[e.res_len] = '\0';
    e.n1 = argv[1];
    e.n2 = argv[2];
    ft_bzero(&e.res, 0);
    e.res = ft_calculate(e);
    ft_bzero(&e.res, 1);
    if ((e.n1[0] == '-' && e.n2[0] != '-') || (e.n1[0] != '-' && e.n2[0] == 45))
        write(1, "-", 1);
    e.dr = -1;
    while (e.res[++e.dr] == '0')
        ;
    while (e.res[++e.dr] != '\0')
        write(1, &(e.res[e.dr]), 1);
    write(1, "\n", 1);
    return (0);
}