#include <ft.h>

int     ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t          i;
    unsigned char   *cs1;
    unsigned char   *cs2;

    cs1 = (unsigned char*) s1;
    cs2 = (unsigned char*) s2;
    i = -1;
    while (++i < n)
        if (cs1[i] != cs2[i])
            return (s1 - s2);
    return (0);
}