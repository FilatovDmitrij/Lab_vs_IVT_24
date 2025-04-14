#include <iostream>

using namespace std;

const int CHAR_NUM = 256;

void calcShiftTable(const string& pat, const int& patSize, int shiftTable[CHAR_NUM]) 
{
    for (int i = 0; i < CHAR_NUM; i++) { shiftTable[i] = patSize; }

    for (int i = 0; i < patSize - 1; i++) { shiftTable[static_cast<int>(pat[i])] = patSize - i - 1; }
}

void boyerMooreSearch(const string& str, const string& pat)
{
    int strSize = str.size();
    int patSize = pat.size();
    int shiftTable[CHAR_NUM];

    calcShiftTable(pat, patSize, shiftTable);

    int i = patSize - 1;

    while (i < strSize) 
    {
        int j = patSize - 1;

        while (j >= 0 && pat[j] == str[i - (patSize - 1 - j)]) { j--; }

        if (j < 0) 
        {
            cout << i - patSize + 1 << ' ';
            i += patSize;
        }
        else 
        {
            int shift = shiftTable[static_cast<int>(str[i])] - (patSize - 1 - j);
            i += max(1, shift);
        }
    }
}

int main() 
{
    string inpStr, outStr;
    cin >> inpStr >> outStr;

    boyerMooreSearch(inpStr, outStr);

    return 0;
}