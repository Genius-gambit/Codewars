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

int	ft_atoi(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return(0);
}

char	*base_dec(char c)
{
	int	num = 0;
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	num = ft_atoi(c);
	if (num == 4 || num == 5)
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
		else if (zeroes == 5)
			res = base_tth(c);
		else if (zeroes == 6)
			res = base_hth(c);
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
}


char *solution(int n) {
  // Your code here
  char  buffer[20];
  int	len = 0;

	itoa(n, buffer, 10);
	printf("%s\n", buffer);
	len = strlen(buffer);
	parse_num(buffer, len);
	return "";
}

int main(void)
{
  solution(15);
  return (0);
}