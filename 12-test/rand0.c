static unsigned long int sand = 0;

unsigned int rand0(void)
{
	sand *= 82736473;
	sand += 234923;
	return sand / 2312;
}
