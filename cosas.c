int  ft_len(char *msg)
{
  int i;

  i=0;
  while (msg[i] != "NULL")
    i++;
  return (i);
}

int	ft_countl(char const *s, char c)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (s[i] != c && s[i])
	{
		l++;
		i++;
	}
	return (l);
}

int	ft_countw(char const *s, char c)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			w++;
		while (s[i] != c && s[i])
			i++;
	}
	return (w);
}

char	**ft_enter(char **sol, const char *s, char c)
{
	int	i;
	int	w;
	int	l;

	i = 0;
	w = 0;
	while (s[i] && w < ft_countw(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			sol[w] = malloc(ft_countl(s, c) * sizeof(char));
			if (!sol[w])
				return (NULL);
			l = 0;
			while (s[i] != c && s[i])
				sol[w][l++] = s[i++];
			sol[w][l] = 0;
			w++;
		}
	}
	sol[w] = NULL;
	return (sol);
}

char	**ft_split(char const *s, char c)
{
	char	**sol;

	if (!s)
		return (NULL);
	if (!*s)
	{
		sol = malloc(sizeof(char *));
		sol[0] = NULL;
		return (sol);
	}
	sol = malloc((ft_countw(s, c) + 1) * sizeof(char *));
	if (!sol)
		return (NULL);
	return (ft_enter(sol, s, c));
}
