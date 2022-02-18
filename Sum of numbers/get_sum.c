int get_sum(int a , int b) 
{
  int start;
  int end;
  int sum;
  int i;

  if (a == b)
    return (a);
  if (a < b)
  {
    start = a;
    end = b;
  }
  else
  {
    start = b;
    end = a;
  }
  i = start;
  sum = 0;
  while (i <= end)
  {
    sum += i;
    i++;
  }
  return (sum);
}