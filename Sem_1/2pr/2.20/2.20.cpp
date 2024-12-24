#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	
	float n, s, a;
	bool flag = false;
	int i = 1;

	cin >> n >> s;

	while (i <= n && !flag)
	{
		a = round(sin(n + i / n));
		if (a == s)
		{
			cout << "Ýëåìåíò íàéäåí" << endl;
			flag = true;
		}
		else { i++; }
	}

	if (!flag) { cout << "Ýëåìåíò íå íàéäåí !" << endl; }

	return 0;
}