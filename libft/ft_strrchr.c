char	*ft_strrchr(const char *s, int c)
{
	char	*last_ptr;

	last_ptr = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			last_ptr = (char *)s;
		}
		s++;
	}
	if (last_ptr)
	{
		return (last_ptr);
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return (0);
}
