#include "./../../inc/ft.h"

void ft_putstr_fd(char *s, int fd)
{
    if (!s)
        return ;
    while (*s)
    {
        ft_putchar_fd(*s, fd);
        ++s;
    }
}
