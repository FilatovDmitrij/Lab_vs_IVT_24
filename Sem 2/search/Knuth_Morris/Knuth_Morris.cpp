#include <iostream>

using namespace std;

int* calcPrefixFunc(string pat, int size)
{
	int* lps = new int[size];
	lps[0] = 0;
	int i = 1;
	int len = 0;

	while (i < size)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
			else len = lps[len - 1];
		}
	}

	cout << "lps: ";
	for (int i = 0; i < size; i++) { cout << lps[i] << ' '; }
	cout << endl;

	return lps;
}

void knuthMorrisPrattSearch(string str, string pat)
{
	int strSize = str.size();
	int patSize = pat.size();

	int* lps = calcPrefixFunc(pat, patSize);

	int strIdx = 0;
	int patIdx = 0;

	while (strIdx < strSize)
	{
		if (str[strIdx] == pat[patIdx])
		{
			strIdx++;
			patIdx++;
		}
		if (patIdx == patSize)
		{
			cout << strIdx - patSize << ' ';
			patIdx = lps[patIdx - 1];
		}
		else if (pat[patIdx] != str[strIdx])
		{
			if (patIdx != 0) patIdx = lps[patIdx - 1];
			else strIdx++;
		}
	}
}

int main()
{
	string inpStr, outStr;
	cin >> inpStr >> outStr;
	knuthMorrisPrattSearch(inpStr, outStr);
	return 0;
}