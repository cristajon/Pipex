int  ft_len(char *msg)
{
  int i;

  i=0;
  while (msg[i] != "NULL")
    i++;
  return (i);
}
