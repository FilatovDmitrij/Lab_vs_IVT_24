#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int a= 0, n;

 cout <<" N: ";
 cin >> n;

	if (n <= 0)
	{
 cout << "Íåâîçìîæíî ïîñ÷èòàòü ñóììó ïî ïîðÿäêó ïðè n<=0.";
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			int b = 1;
			for (int j = i; j <= i * 2; j++)
			{
 b *= j;
			}
 a += b;
		}

 cout << a;
	}

	return 0;
}