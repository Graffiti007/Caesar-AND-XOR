#include <string>

using namespace std;

#include "cesar.h"


string Caesar(string s, int offset)
{
	while (offset >= 28) offset=offset-28;
	int size = s.length();
	int temp;
	for (int i = 0; i < size;i++)
	{
		if ((s[i] >= 'a') && (s[i] <= 'z'))
		{
			temp = s[i] + offset;
			if ((temp >= 'a') && (temp <= 'z'))
			{
				s[i] = temp;
			}
			else
			{
				s[i] = 'a' - 1 + (temp - 'z');
			}
		}
		else if ((s[i] >= 'A') && (s[i] <= 'Z'))
		{
			temp = s[i] + offset;
			if ((temp >= 'A') && (temp <= 'Z'))
			{
				s[i] = temp;
			}
			else
			{
				s[i] = 'A' - 1 + (temp - 'Z');
			}

		}
	}
	
	return s;
}