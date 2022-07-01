#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ONE I
#define FIVE V
#define TEN X
#define FIFTY L
#define HUNDRED C
#define F_HUNDRED D
#define TH M
#define DEC "012345789"

int	ft_atoi(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return(0);
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

char	*placing_i(char c)
{
	int	num = 0;
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	num = ft_atoi(c);
	if (num >= 4)
	{
		if (num == 5)
			return(strdup("V"));
		return(strdup("IV"));
	}
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

char	*placing_v(char *c)
{
	int	num = 0;
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	num = atoi(c);
	if (num >= 9)
	{
		if (num == 10)
			return(strdup("X"));
		return(strdup("IX"));
	}
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
	return (str);
}

char	*placing_ten_r(char c)
{
	int	num = 0;
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	num = ft_atoi(c);
	if (num >= 4)
	{
		if (num == 5)
			return(strdup("L"));
		return(strdup("XL"));
	}
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

char	*base_dec(int len, char *buffer, int n)
{
	char	*str;

	str = NULL;
	if (len == 1 || (len == 2 && n == 10))
	{
		if ((buffer[0] <= '5') && len == 1)
			str = placing_i(buffer[0]);
		else
			str = placing_v(buffer);
	}
	return (str);
}

char	*placing_ten_end(char *c)
{
	int	num = 0;
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	num = atoi(c);
	if (num >= 90)
	{
		if (num == 100)
			return(strdup("C"));
		return(strdup("XC"));
	}
	while (num % 50 > 0)
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
		num-= 10;
	}
	return (str);
}

char	*base_ten(int len, char *buffer, int n)
{
	char	*str = NULL;
	char	*tmp = NULL;
	char	*dec = NULL;

	if (len == 2 || (len == 3 && n == 100))
	{
		if ((buffer[0] <= '5') && len == 2)
		{
			str = placing_ten_r(buffer[0]);
			if (buffer[1] != '0')
			{
				tmp = strdup(str);
				free(str);
				dec = base_dec(1, &buffer[1], n);
				str = ft_strjoin(tmp, dec);
				free(tmp);
				free(dec);
			}
		}
		else
		{
			str = placing_ten_end(buffer);
			if (n != 100 && buffer[1] != '0')
			{
				tmp = strdup(str);
				free(str);
				dec = base_dec(1, &buffer[1], n);
				str = ft_strjoin(tmp, dec);
				free(tmp);
				free(dec);
			}
		}
	}
	return (str);
}

char	*placing_hun_r(char c)
{
	int	num = 0;
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	num = ft_atoi(c);
	if (num >= 4)
	{
		if (num == 5)
			return(strdup("D"));
		return(strdup("CD"));
	}
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

char	*placing_hun_end(char *c)
{
	int	num = 0;
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	num = atoi(c);
	if (num >= 900)
	{
		if (num == 1000)
			return(strdup("M"));
		return(strdup("CM"));
	}
	while (num % 500 > 0)
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
		num-= 100;
	}
	return (str);
}

char	*base_hun(int len, char *buffer, int n)
{
	char	*str = NULL;
	char	*tmp = NULL;
	char	*ten = NULL;

	if (len == 3 || (len == 4 && n == 1000))
	{
		if ((buffer[0] <= '5') && len == 3)
		{
			str = placing_hun_r(buffer[0]);
			if (buffer[1] != '0' || buffer[2] != '0')
			{
				tmp = strdup(str);
				free(str);
				ten = base_ten(2, &buffer[1], n);
				str = ft_strjoin(tmp, ten);
				free(tmp);
				free(ten);
			}
		}
		else
		{
			str = placing_hun_end(buffer);
			if (n != 1000 && (buffer[1] != '0' || buffer[2] != '0'))
			{
				tmp = strdup(str);
				free(str);
				ten = base_ten(2, &buffer[1], n);
				str = ft_strjoin(tmp, ten);
				free(tmp);
				free(ten);
			}
		}
	}
	return (str);
}

char *solution(int n) {
  // Your code here
  char  buffer[20];
  char	*str;
  itoa(n, buffer, 10);
  int	len;
  len = strlen(buffer);
  printf("Str: %s, Len: %d\n", buffer, len);
  if (len == 1 || (len == 2 && n == 10))
	str = base_dec(len, buffer, n);
	else if (len == 2 || (len == 3 && n == 100))
		str = base_ten(len, buffer, n);
	else if (len == 3 || (len == 4 && n == 1000))
		str = base_hun(len, buffer, n);
printf("%s\n", str);
  return "";
}

int main(void)
{
  solution(806);
  return (0);
}