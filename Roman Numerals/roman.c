#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return(0);
}

static int	nbr_len(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nbr;

	nbr = n;
	i = nbr_len(n);
	if (nbr < 0)
		nbr = -nbr;
	str = calloc((i + 1), sizeof(char));
	if (!str)
		return (NULL);
	i--;
	while (nbr != 0)
	{
		str[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
		dst = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
		if (!dst)
			return (0);
		i = 0;
		while (s1[i] != '\0')
		{
			dst[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			dst[i++] = s2[j++];
		}
		dst[i] = '\0';
		return (dst);
	}
	return (0);
}

char	*base_dec(char c)
{
	int	num = 0;
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	num = ft_atoi(c);
	if (num == 0)
		return(strdup(""));
	if (num == 4 || num == 5)
	{
		if (num == 5)
			return(strdup("V"));
		return(strdup("IV"));
	}
	else if (num >= 6 && num < 9)
	{
		while (num % 5 > 0)
		{
			if (!str)
				str = strdup("VI");
			else
			{
				tmp = strdup(str);
				free(str);
				str = ft_strjoin(tmp, "I");
				free(tmp);
			}
			num--;
		}
		return(str);
	}
	else if (num == 9)
		return(strdup("IX"));
	while (num > 0)
	{
		if (!str)
			str = strdup("I");
		else
		{
			tmp = strdup(str);
			free(str);
			str = ft_strjoin(tmp, "I");
			free(tmp);
		}
		num--;
	}
	return (str);
}

char	*base_ten(char c)
{
	int	num = 0;
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	num = ft_atoi(c);
	if (num == 0)
		return(strdup(""));
	if (num == 4 || num == 5)
	{
		if (num == 5)
			return(strdup("L"));
		return(strdup("XL"));
	}
	else if (num >= 6 && num < 9)
	{
		while (num % 5 > 0)
		{
			if (!str)
				str = strdup("LX");
			else
			{
				tmp = strdup(str);
				free(str);
				str = ft_strjoin(tmp, "X");
				free(tmp);
			}
			num--;
		}
		return(str);
	}
	else if (num == 9)
		return(strdup("XC"));
	while (num > 0)
	{
		if (!str)
			str = strdup("X");
		else
		{
			tmp = strdup(str);
			free(str);
			str = ft_strjoin(tmp, "X");
			free(tmp);
		}
		num--;
	}
	return (str);
}

char	*base_hun(char c)
{
	int	num = 0;
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	num = ft_atoi(c);
	if (num == 0)
		return(strdup(""));
	if (num == 4 || num == 5)
	{
		if (num == 5)
			return(strdup("D"));
		return(strdup("CD"));
	}
	else if (num >= 6 && num < 9)
	{
		while (num % 5 > 0)
		{
			if (!str)
				str = strdup("DC");
			else
			{
				tmp = strdup(str);
				free(str);
				str = ft_strjoin(tmp, "C");
				free(tmp);
			}
			num--;
		}
		return(str);
	}
	else if (num == 9)
		return(strdup("CM"));
	while (num > 0)
	{
		if (!str)
			str = strdup("C");
		else
		{
			tmp = strdup(str);
			free(str);
			str = ft_strjoin(tmp, "C");
			free(tmp);
		}
		num--;
	}
	return (str);
}

char	*base_th(char c)
{
	int	num = 0;
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	num = ft_atoi(c);
	if (num == 0)
		return(strdup(""));
	if (num == 4 || num == 5)
	{
		if (num == 5)
			return(strdup("V"));
		return(strdup("MMMM"));
	}
	while (num > 0)
	{
		if (!str)
			str = strdup("M");
		else
		{
			tmp = strdup(str);
			free(str);
			str = ft_strjoin(tmp, "M");
			free(tmp);
		}
		num--;
	}
	return (str);
}

char	*get_rn(char c, int zeroes)
{
	char	*res;
	if (c >= '0' && c <= '9')
	{
		if (zeroes == 1)
			res = base_dec(c);
		else if (zeroes == 2)
			res = base_ten(c);
		else if (zeroes == 3)
			res = base_hun(c);
		else if (zeroes == 4)
			res = base_th(c);
		return (res);
	}
	return(0);
}

char	*parse_num(char *str, int len)
{
	int	i;
	char	*res = NULL;
	char	*tmp = NULL;
	char	*cpy = NULL;

	i = 0;
	while (len > 0)
	{
		if (!res)
			res = get_rn(str[i], len);
		else
		{
			tmp = get_rn(str[i], len);
			cpy = strdup(res);
			free(res);
			res = ft_strjoin(cpy, tmp);
			free(cpy);
			free(tmp);
		}
		i++;
		len--;
	}
	return (res);
}


char *solution(int n)
{
	// Your code here
	char  *buffer;
	char	*ret;
	int	len = 0;

	if (n == 0)
		return("");
	buffer = ft_itoa(n);
	printf("%s\n", buffer);
	len = strlen(buffer);
	ret = parse_num(buffer, len);
	free(buffer);
	return (ret);
}