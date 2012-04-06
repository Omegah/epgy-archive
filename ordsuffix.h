char* getOrdSuffix(int i);
char* getOrdSuffix(int i)
{
	int lastDigit;
	char* os;
	/* Determine ordinal suffix */
	lastDigit = i % 10;
	if (i >= 4 && i <= 20)
		os = "th";
	else if (i == 0 || lastDigit == 0)
		os = "th";
	else if (i == 1 || lastDigit == 1)
		os = "st";
	else if (i == 2 || lastDigit == 2)
		os = "nd";
	else if (i == 3 || lastDigit == 3)
		os = "rd";
	else
		os = "th";

	return os;
}