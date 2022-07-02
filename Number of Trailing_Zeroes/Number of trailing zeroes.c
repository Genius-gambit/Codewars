long zeros(long n)
{
	long	res = 0;
	long	tmp = 0;

	while (n > 0)
	{
		tmp = n / 5;
		res += tmp;
		n /= 5;
	}
	return(res);
}

int main(void)
{
	int	res;
	res = zeros(1000000000);
	printf("%d\n", res);
	return(0);
}