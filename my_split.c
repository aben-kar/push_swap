#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	if (size != 0 && (count > SIZE_MAX / size))
		return (NULL);
	s = (unsigned char *)malloc(count * size);
	if (s == NULL)
		return (NULL);
	while (i < count * size)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}

int	count_word(char const *s1, char sp)
{
	int	i;
	int	count;
	int	check;

	i = 0;
	count = 0;
	check = 1;
	while (s1[i])
	{
		if (s1[i] != sp && check == 1)
		{
			count += 1;
			check = 0;
		}
		else if (s1[i] == sp)
			check = 1;
		i++;
	}
	return (count);
}

char	*ft_strsdup(char const *s, size_t *j, char sp)
{
	char	*result;
	size_t	i;
	size_t	k;

	i = *j;
	while (s[*j] != sp && s[*j])
		(*j)++;
	result = (char *)malloc((*j - i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	k = 0;
	while (k < *j - i)
	{
		result[k] = s[i + k];
		k++;
	}
	result[k] = '\0';
	return (result);
}

void	*ft_free(char **prr)
{
	int	i;

	i = 0;
	while (prr[i])
	{
		free(prr[i]);
		i++;
	}
	free(prr);
	return (NULL);
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
	if (prr == NULL)
		return (NULL);
	while (j < len_word)
	{
		while (s[i] == c && s[i])
			i++;
		prr[j] = ft_strsdup(s, &i, c);
		if (!prr[j])
			return (ft_free(prr));
		j++;
	}
	return (prr);
}