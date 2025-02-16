#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int ft_isspace(char c)
{
    if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int is_only_spaces(const char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!ft_isspace(str[i]))
            return (0);
        i++;
    }
    return (1);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	ptr = (char *)ft_calloc((len + 1), sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, len);
	ptr[len] = '\0';
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s;
	size_t			i;

	if (size != 0 && (count > SIZE_MAX / size))
		return (NULL);
	s = (unsigned char *)malloc(count * size);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}