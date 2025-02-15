#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int is_string(char *str)
{
    return (str[0] == '"' && str[ft_strlen(str) - 1] == '"');
}