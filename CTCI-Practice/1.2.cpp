#include <iostream>
#include <climits>
#include <string.h>

using namespace std;

bool isUnique(string s)
{
	bool letters[256];
	memset(letters, 0, sizeof(letters));
	int length = s.length();
	for(int i = 0; i < length; i++)
	{
		int temp = (int)s[i];
		if(letters[temp])
		{
			return false;
		}
		letters[temp] = true;
	}
	return true;
}

int main ()
{
	string test1 = "i am ixmike";
	if (isUnique(test1))
	{
		cout << "Test1 Passed" << endl;
	}
	else
	{
		cout << "Test1 Failed" << endl;
	}
	string test2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (isUnique(test2))
	{
		cout << "Test2 Passed" << endl;
	}
	else
	{
		cout << "Test2 Failed" << endl;
	}
	string test3 = "!@#$%^&*()/`~";
	if (isUnique(test3))
	{
		cout << "Test3 Passed" << endl;
	}
	else
	{
		cout << "Test3 Failed" << endl;
	}
}