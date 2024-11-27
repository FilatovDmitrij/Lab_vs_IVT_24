#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int n, a = 1;
	cout << " N: ";
	cin >>n;
	if (n <= 0)
	{
		cout << "Íåâîçìîæíî ïîñ÷èòàòü ïðîèçâåäåíèå íàòóðàëüíûõ ÷èñåë ïðè n <= 0";
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			a *= i;
		}
		cout <<a;
	}
	return 0;
}