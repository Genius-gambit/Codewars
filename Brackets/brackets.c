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
			while (str[i] && !is_close_bracket(str[i]))
				i++;
			while (str[i] && is_close_bracket(str[i]))
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
			while (str[i] && !is_close_bracket(str[i]))
			{
				res[count] = str[i];
				count++;
				i++;
			}
			while (str[i] && is_close_bracket(str[i]))
			{
				res[count] = str[i];
				count++;
				i++;
			}
			res[count] = 0;
			if (j < k)
				str_split[j++] = ft_strdup(res);
			free(res);
		}
		else
			i++;
	}
	str_split[j] = NULL;
	return (str_split);
}

void	free_split(char **str)
{
	int	i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_puts_split(char **str)
{
	for (int i = 0; str[i] != NULL; i++)
		printf("%s\n", str[i]);
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

bool validParentheses(const char *str_in)
{
	t_info	info;

	ft_info(&info);
	// printf("Start: %s End\n", str_in);
	// while (str_in[info.i] && !is_open_bracket(str_in[info.i]))
	// 	info.i++;
	// while (str_in[info.i] && is_open_bracket(str_in[info.i]))
	// 	info.i++;
	// if (str_in[info.i] == '\0')
	// 	return (false);
	// info.start = str_in[info.i - 1];
	// info.old_open = info.i - 1;
	// while (str_in[info.i] && is_close_bracket(str_in[info.i]))
	// {
	// 	if (check_full_brackets(info.start, str_in[info.i]) == true)
	// 	{
	// 		info.end = str_in[info.i];
	// 		info.old_close = info.i;
	// 		if (info.i == 1)
	// 			return(true);
	// 		break;
	// 	}
	// 	info.i++;
	// }
	char	**split;
	split = ft_split(str_in);
	ft_puts_split(split);
	int	check = 0;
	int	j = 0;
	// info.open = info.old_open;
	// info.close = info.old_close;
	// bool	res= false;
	// check = next_bracket(&info, str_in);
	// while (!check)
	// {
	// 	check = next_bracket(&info, split[j]);
	// 	if (check == 2)
	// 	{
	// 		j++;
	// 		if (split[j] == NULL)
	// 		{
	// 			res = true;
	// 			break;
	// 		}
	// 		check = phase_one(&info, split[j]);
	// 		if (check == 1)
	// 		{
	// 			res = false;
	// 			break;
	// 		}
	// 		else if (check == 2)
	// 		{
	// 			res = true;
	// 			break;
	// 		}
	// 	}
	// 	else if (check == 1)
	// 	{
	// 		res = false;
	// 		break;
	// 	}
	// }
	// free_split(split);
	// return(res);
	// if (check == 2)
	// 	return (true);
	return (false);
}

#include <stdio.h>
int main(void)
{
	bool	res;

	res = validParentheses("Write ((a function) that takes (a string) of parentheses), and (determines if) the order is valid(.)");
	printf("%d\n", res);
	return (0);
}