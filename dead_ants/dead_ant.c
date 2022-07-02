#include <ctype.h>
#include <unistd.h>
#include <stdio.h>

int	part_of_ant(int c)
{
	if (c == 'a' || c == 'n' || c == 't')
		return(c);
	return(0);
}

int deadAntCount(const char* ants)
{
	int	i = 0;
	int	dead = 0;
	int	trig = 0;
	while (ants[i])
	{
		if (ants[i] == 'a')
		{
			i++;
			if (ants[i] == 'n')
			{
				i++;
				if (ants[i] == 't')
					i++;
				else if (!trig)
				{
					trig = 1;
					dead++;
				}
			}
			else if (!trig)
			{
				trig = 1;
				dead++;
			}
		}
		else if (part_of_ant(ants[i]))
		{
			if (!trig)
				dead++;
			else
			{
				while (ants[i] && isalpha(ants[i]))
					i++;
				trig = 0;
			}
			i++;
		}
		else
			i++;
	}
  return dead;
}

int main(void)
{
	printf("%d\n", deadAntCount("ant anantt aantnt"));
	return(0);
}