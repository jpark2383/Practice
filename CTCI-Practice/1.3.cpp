#include <iostream>
#include <climits>
#include <string.h>

using namespace std;

//O(N) runtime O(N) space
bool isPermutation(string s1, string s2)
{
	if(s1.length() != s2.length())
		return false;
	int letters[256];
	memset(letters, 0, sizeof(letters));
	int length = s1.length();
	for(int i = 0; i < length; i++)
	{
		int curr1 = (int)s1[i];
		int curr2 = (int)s2[i];
		letters[curr1]++;
		letters[curr2]--;
	}
	for(int i = 0; i < 256; i++)
	{
		if(letters[i] > 0)
			return false;
	}
	return true;
}

int main()
{
	string word1 = "racecar";
	string word2 = "caracer";
	if(isPermutation(word1, word2))
		cout << "Test1 Passed" << endl;
	else
		cout << "Test2 Failed" << endl;
	string trick1 = "TUXEDO";
	string trick2 = "tuxedo";
	if(isPermutation(trick1, trick2))
		cout << "Test1 Failed" << endl;
	else
		cout << "Test2 Passed" << endl;
	string trick3 = "~!@#$%^&*()";
	string trick4 = "~@!#$^%&*)(";
	if(isPermutation(trick3, trick4))
		cout << "Test1 Passed" << endl;
	else
		cout << "Test2 Failed" << endl;
	return 0;
}
