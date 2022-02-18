#include <stdbool.h>
#include <string.h>

int tolower(int c)
{
  if (c >= 'A' && c <= 'Z')
    return (c + 32);
  return (c);
}

bool IsIsogram (const char *string)
{
  int array[127] = {0, };
  int i;
  char  *str;
  int   c;

  str = (char *)string;
  i = 0;
  while (str[i])
  {
    c = tolower(str[i]);
    if (!array[c])
    {
        array[c] = c;
        i++;
    }
    else
        return (false);
  }
  return (true);
}
