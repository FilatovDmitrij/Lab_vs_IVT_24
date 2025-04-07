#include <iostream>
#include <cstdio>
using namespace std;

int cntVow(const char* s) 
{
    int c = 0;
    for (int i = 0; s[i]; i++) 
      {
          char ch = s[i];
          if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') 
         {
            c++;
         }
      }
    return c;
}

int main() 
{
     FILE* f1 = fopen("F1.txt", "r");
    FILE* f2 = fopen("F2.txt", "w");

    if (!f1) 
      {
        cerr << "Error opening F1!" << endl;
        return 1;
      }
    if (!f2) 
      {
        cerr << "Error opening F2!" << endl;
        fclose(f1);
        return 1;
      }

    char buf[1024];
    int maxV = -1, lineNum = 0, targetLine = 0;

    while (fgets(buf, sizeof(buf), f1)) 
    {
        lineNum++;
        int v = cntVow(buf);
        if (v > maxV) 
        {
            maxV = v;
            targetLine = lineNum;
        }
    }

    rewind(f1); 
    lineNum = 0;

    while (fgets(buf, sizeof(buf), f1)) 
    {
        lineNum++;
        if (lineNum != targetLine) 
        {
            fputs(buf, f2);
        }
    }

    fclose(f1);
    fclose(f2);

    cout << "Line with most vowels: " << targetLine << endl;

    return 0;
}