#include <iostream>
#include <climits>
#include <string.h>

using namespace std;

/* Reverses a string */

//O(n) runtime and O(1) space
string reverseString1(string s)
{
	int length = s.length()
	for(int head = 0, tail = length - 1; head < tail; head++, tail-- )
	{
		char temp = s[head];
		s[head] = s[tail];
		s[tail] = temp;
	}
	return s;
}

//O(n) runtime and O(n) space
string reverseString2(string s)
{
	int length = s.length();
	string reversed = "";
	for(int i = 0; i < length; i++)
	{
		reversed.push_back(s[length - i]);
	}
	return reversed;
}


int main()
{
	string test = "I have a dream that all people will fly";
	string reversed1 = reverseString1(test);
	string reversed2 = reverseString2(test);
	cout << reversed1 << endl;
	cout << reversed2 << endl;
	return 0;
}
