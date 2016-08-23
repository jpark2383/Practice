#include <iostream>
#include <climits>
#include <string.h>

using namespace std;

/* Replace spaces in a string with %20 */

void replaceSpaces (char *s, int len)
{
	int numSpaces = 0;
	int i = 0;
	int j = 0;
	for(i = 0; i < len; i++)
	{
		if(s[i] == ' ')
		{
			numSpaces++;
		}
	}
	int extended = len + 2 * numSpaces;
	i = extended - 1;
	for(j = len - 1; j >= 0; j--)
	{
		if (s[j] != ' ')
		{
			s[i--] = s[j];
		}
		else
		{
			s[i--] = '0';
			s[i--] = '2';
			s[i--] = '%';
		}
	}
}

int main()
{
	char str[] = "I don't know what this is";
	cout << "Actual String : " << str << endl;
	replaceSpaces(str, 25);
	cout << "String with spaces replaced with %20 : " << str << endl;
	return 0;
}

