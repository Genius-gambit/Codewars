#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_info
{
	int	i;
	int	start;
	int	old_open;
	int	old_close;
	int	open;
	int	close;
	int	end;
}				t_info;

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	dst = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dst)
		return (0);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

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

bool	check_full_brackets(char start, char end)
{
	if (start == '(' && end == ')')
		return (true);
	else if (start == '[' && end == ']')
		return (true);
	else if (start == '{' && end == '}')
		return (true);
	return (false);
}

void	ft_info(t_info *info)
{
	info->end = 0;
	info->i = 0;
	info->old_close = 0;
	info->old_open = 0;
	info->open = 0;
	info->close = 0;
	info->start = 0;
}

int	check_open_bracket(const char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (is_open_bracket(str[i]))
			return(str[i]);
		i++;
	}
	return(0);
}

int	check_close_bracket(const char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (is_close_bracket(str[i]))
			return(str[i]);
		i++;
	}
	return(0);
}

bool	parse_str(const char *str, int open, int count, t_info *info)
{
	int	i;
	int	j = 0;
	char	brackets[open + 1];

	i = 0;
	ft_info(info);
	while (str[i])
	{
		if (is_open_bracket(str[i]))
			break;
		else if (is_close_bracket(str[i]))
			return(false);
		i++;
	}
	if (str[i] && is_open_bracket(str[i]))
	{
		info->start = i;
		brackets[j++] = str[i];
	}
	while (str[i] && !is_close_bracket(str[i]))
		i++;
	while (str[i] && is_close_bracket(str[i]))
		i++;
	if (str[i - 1] && is_close_bracket(str[i - 1]))
	{
		info->end = i - 1;
		brackets[j++] = str[i - 1];
	}
	next_bracket()
	int	k = 0;
	for (k = 0; brackets[k]; k++);
	if (is_close_bracket(brackets[k - 1]))
		return(true);
	return(false);
}

bool validParentheses(const char *str_in)
{
	t_info	info;
	int	count_o = 0;
	int	count_c = 0;

	ft_info(&info);
	if (!str_in && !*str_in)
		return (true);
	while (str_in[info.i])
	{
		if (is_open_bracket(str_in[info.i]))
			count_o++;
		else if (is_close_bracket(str_in[info.i]))
			count_c++;
		info.i++;
	}
	if (!count_c && !count_o)
		return(true);
	if (count_o != count_c)
		return(false);
	bool	res = false;
	res = parse_str(str_in, count_o, count_c, &info);
	return (res);
}

int main(void)
{
	bool	res;

	res = validParentheses("hi()");
	printf("%d\n", res);
	return (0);
}