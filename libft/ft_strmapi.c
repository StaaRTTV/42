#include <stdio.h>
#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int    index;
    char    *result;
    
    index = 0;
    result = malloc(ft_strlen(s) * sizeof(char));
    while (s[index])
    {
        result[index] = f(index, s[index]);
        index++;
    }
    return (result);
}