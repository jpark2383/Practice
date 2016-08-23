#include <iostream>
#include <climits>
#include <string.h>

using namespace std;
/* method to compress a string to count the number of each char in the string.
Return original string if compressed string is longer than original string */

int countCompression(string s)
{
	if(s.empty())
		return NULL;
	char end = s.at(0);
	int size = 0;
	int count = 1;
	int length = s.length();
	for(int i = 1; i < length; i++)
	{
		if(s.at(i) == end)
			count++;
		else
		{
			end = s.at(i);
			size += 2;
			count = 1;
		}
	}
	return size;
}

string Compress(string s)
{
	if(s.empty())
		return NULL;
	int length = s.length();
	if(length <= countCompression(s))
		return s;
	char end = s.at(0);
	int count = 1;
	string res = "";
	for(int i = 1; i < length; i++)
	{
		if(s.at(i) == end)
			count++;
		else
		{
			res.push_back(end);
			res.append(to_string(count));
			end = s.at(i);
			count = 1;
		}
	}
	res.push_back(end);
	res.append(to_string(count));
	return res;
}

int main()
{
	string test1 = "aaaaabbbbbbccccccdddddeeeeeffff";
	string test2 = "abcde";
	cout << Compress(test1) << endl;
	cout << Compress(test2) << endl;
	return 0;
}

