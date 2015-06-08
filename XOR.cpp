#include <string>

using namespace std;

#include "XOR.h"

string XOR(string s, string code)
{
	
	int len = code.length();
	int len2 = s.length();
	int i = 0;
	int j = 0;
	
	for (int i = 0; i < len2;i++)
	{
		s[i] = s[i] ^ code[j];
		j++;
		if (j >= len) j = 0;
		i++;
	}
	return s;
}