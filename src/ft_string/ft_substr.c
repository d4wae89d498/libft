#include "./../../inc/ft.h"

char        *ft_substr(char const *s, unsigned int start, size_t len)
{
    char            *out;
    unsigned int    i;
    size_t          real_len;

    i = -1;
    real_len = 0;
    while (s[++i])
        if (i >= start)
            real_len += 1;
    real_len = real_len > len ? len : real_len;
    out = malloc ((real_len + 1) * sizeof(char));
    if (!out)
        return (NULL);
    i = -1;
    while (s[++i] && (long) ((long)i - (long)start) < (long)len)
        if (i >= start)
            out[i - start] = s[i];
    out[i - start] = '\0';
    return (out);
}