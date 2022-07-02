#include <stddef.h> // NULL

const char* how_much_i_love_you(int nb_petals)
{
  if (nb_petals > 0)
    {
    int res;
    res = nb_petals % 6;
    if (res == 1)
      return("I love you");
    else if (res == 2)
      return("a little");
    else if (res == 3)
      return("a lot");
    else if (res == 4)
      return("passionately");
    else if (res == 5)
      return("madly");
    else if (res == 0)
      return("not at all");
  }
  return NULL;
}

#include <stdio.h>
int main(void)
{
	printf("%s\n", how_much_i_love_you(7));
	return(0);
}