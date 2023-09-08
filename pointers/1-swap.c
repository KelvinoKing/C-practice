void swap_int(int *a, int *b)
{
	int tempInt;

	tempInt = *a;
  *a = *b;
	*b = tempInt;
}
