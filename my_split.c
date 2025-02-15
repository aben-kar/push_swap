#include "push_swap.h"

void *ft_calloc(size_t count, size_t size) {
    unsigned char *s;
    size_t i;
    if (size != 0 && (count > SIZE_MAX / size))
        return NULL;
    s = (unsigned char *)malloc(count * size);
    if (!s)
        return NULL;
    for (i = 0; i < count * size; i++)
        s[i] = 0;
    return s;
}

int count_word(const char *s1, char sp) {
    int i = 0, count = 0, check = 1;
    while (s1[i]) {
        if (s1[i] != sp && check == 1) {
            count++;
            check = 0;
        } else if (s1[i] == sp)
            check = 1;
        i++;
    }
    return count;
}

char	*ft_strsdup(char const *s, size_t *j, char sp)
{
	char	*result;
	size_t	i;
	size_t	k;
	size_t	len;

	i = *j;
	while (s[*j] != sp && s[*j])
		(*j)++;
	len = *j - i;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	k = 0;
	while (k < len)
	{
		result[k] = s[i + k];
		k++;
	}
	result[k] = '\0';
	return (result);
}

void ft_free(char **prr) {
    int i = 0;
    while (prr[i])
        free(prr[i++]);
    free(prr);
}


char	**ft_split(char const *s, char c)
{
	size_t	j;
	size_t	i;
	char	**prr;
	size_t	len_word;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len_word = count_word(s, c);
	prr = (char **)ft_calloc((len_word + 1), sizeof(char *));
	if (!prr)
		return (NULL);
	while (j < len_word)
	{
		while (s[i] == c && s[i])
			i++;
		prr[j] = ft_strsdup(s, &i, c);
		if (!prr[j])
		{
			ft_free(prr);
			return (NULL);
		}
		j++;
	}
	prr[j] = NULL;
	return (prr);
}