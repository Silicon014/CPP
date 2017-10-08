unsigned int rand1(void)
{
	sand = 14458943 * sand + 2334928;
	sand /= 65535;
	return sand / 1232;
}
void set_sand(unsigned long int n)
{
	sand = n;
}
void sort_int(unsigned int ar[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		int j;
		unsigned tmp = ar[i];
		for (j = i - 1; j >= 0 && ar[j] > ar[i]; --j)
		{
			ar[j + 1] = ar[j];
		}
		ar[j + 1] = tmp;
	}
}
void qwq(unsigned int ar[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j > i && j < length; ++j)
		{
			if (ar[i] > ar[j])
			{
				ar[i] = ar[i] ^ ar[j];
				ar[j] = ar[i] ^ ar[j];
				ar[i] = ar[i] ^ ar[j];
			}
		}
	}
}
/*bug*/	
