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

int	ft_isdigit(int c)
{
	while (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int print_error(char *msg) {
    write(2, msg, 5); // error
    write(2, "\n", 1);
    return -1;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int write_error(char *msg)
{
	write (2, msg, 5);
	write (2, "\n", 1);
	return (1);
}