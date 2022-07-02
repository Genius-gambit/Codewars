#include <string.h>
#include<stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	is_open_bracket(char c)
{
	if (c == '(')
		return (c);
	else if (c == '[')
		return (c);
	else if (c == '{')
		return (c);
	return (0);
}

int	is_close_bracket(char c)
{
	if (c == ')')
		return (c);
	else if (c == ']')
		return (c);
	else if (c == '}')
		return (c);
	return (0);
}

int	get_ending_point(const char *str)
{
	int	i = 0;

	while (str[i] && !is_open_bracket(str[i]))
		i++;
	while (str[i] && is_open_bracket(str[i]))
		i++;
	while (str[i] && !is_close_bracket(str[i]))
		i++;
	while (str[i] && is_close_bracket(str[i]))
		i++;
	if (str[i] == 0)
		return(0);
	return(i);
}

char	**ft_split(const char *str)
{
	int	i = 0;
	int	count = 0;
	char	**str_split;
	int		trigger = 0;

	while (str[i] && !is_open_bracket(str[i]))
		i++;
	while (str[i] && is_open_bracket(str[i]))
	{
		trigger = 1;
		i++;
	}
	while (str[i] && !is_close_bracket(str[i]))
		i++;
	while (str[i] && is_close_bracket(str[i]))
	{
		trigger = 1;
		i++;
	}
	if (str[i] == 0 && !trigger)
		return(NULL);
	i = 0;
	while (str[i])
	{
		if (is_open_bracket(str[i]))
		{
			while (!is_close_bracket(str[i]))
				i++;
			while (is_close_bracket(str[i]))
				i++;
			count++;
		}
		else
			i++;
	}
	if (count == 0)
		return(NULL);
	str_split = malloc(sizeof(char *) * (count + 1));
	i = 0;
	int	k = 0;
	char	*res;
	res = NULL;
	k = count;
	int	j = 0;
	while (str[i])
	{
		if (is_open_bracket(str[i]))
		{
			count = 0;
			res = malloc(sizeof(char) * 100);
			while (!is_close_bracket(str[i]))
			{
				res[count] = str[i];
				count++;
				i++;
			}
			while (is_close_bracket(str[i]))
			{
				res[count] = str[i];
				count++;
				i++;
			}
			res[count] = 0;
			if (j < k)
				str_split[j++] = strdup(res);
			free(res);
		}
		else
			i++;
	}
	str_split[j] = NULL;
	return (str_split);
}

int main(void)
{
	char	**split;

	split = ft_split("[{(())}]()");
	printf("%s\n", split[0]);
	printf("%s\n", split[1]);
	// printf("%s\n", split[2]);
}