#include <stddef.h>

int find_min(int length, int array[length])
{
  int i;
  int min;

  i = 1;
  min = array[0];
  while (i < length)
  {
    if (array[i] < min)
      min = array[i];
    i++;
  }
  return (min);
}

int find_max(int length, int array[length])
{
  int i;
  int max;

  i = 1;
  max = array[0];
  while (i < length)
  {
    if (array[i] > max)
      max = array[i];
    i++;
  }
  return (max);
}

int find_s_min(int length, int array[length], int *num)
{
  int i;
  int min;

  i = 0;
  while (array[i] <= *num)
    i++;
  min = array[i];
  i = 0;
  while (i < length)
  {
    if (array[i] < min && array[i] > *num)
          min = array[i];
    i++;
  }
  return (min);
}

void  order(int length, int temp[length], int ar[length], int *num, int *j)
{
  int i;

  i = 0;
  while (i < length)
  {
    if (ar[i] == *num)
    {
      temp[*j] = ar[i];
      (*j)++;
    }
    i++;
  }
}

int find_odd (size_t length, const int array[length])
{
  int   ar[length];
  int   temp[length];
  int   i;
  int   j;
  int   num;
  int   count;

  i = 0;
  j = 0;
  count = 1;
  while (i < length)
  {
      ar[i] = array[i];
      temp[i] = 0;
      i++;
  }
  if (length == 1)
    return (ar[0]);
  num = find_min(length, ar);
  order(length, temp, ar, &num, &j);
  while (j < length)
  {
    if (find_s_min(length, ar, &num) != num)
      num = find_s_min(length, ar, &num);
    else
      num = find_max(length, ar);
    order(length, temp, ar, &num, &j);
  }
  num = temp[0];
  i = 1;
  while (i < length)
  {
    if (num == temp[i])
      count++;
    else
    {
      if (count % 2)
        return (temp[--i]);
      count = 1;
      num = temp[i];
    }
    i++;
  }
  return (temp[--i]);
}