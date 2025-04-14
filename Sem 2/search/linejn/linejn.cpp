#include <iostream>

using namespace std;

int search(int arr[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x) return i;
	}
	return -1;
}

int main()
{
	int arr[5]{ 1, 2, 6, 2, 103 };
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	int x = 10;
	int res = search(arr, arrLength, x);

	if (res == -1) cout << "Ёлемент " << x << " не найдет !";
	else cout << "Ёлемент " << x << " найдет по индексу " << res << '.' << endl;

	return 0;
}