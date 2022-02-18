long long findNb(long long m)
{
  long long ret;
  long long n;

  ret = 1;
  n = 0;
  while (n < m)
  {
    n += pow(ret, 3);
    if (n >= m)
      break;
    ret++;
  }
  if (n > m)
    ret = -1;
  return (ret);
}