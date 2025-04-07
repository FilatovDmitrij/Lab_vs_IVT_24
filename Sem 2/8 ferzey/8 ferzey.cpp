#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	const int len = 10;
	int arr[len]{};
	int tmp;
	int range_min = 0, range_max = 10;

	for (int i = 0; i < len; ++i)
	{
		arr[i] = rand() % (range_max - range_min + 1) + range_min;
	}

	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	for (int i = 0; i < len-1; ++i)
	{
		for (int j = 0; j < (len - 1 - i); ++j) 
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	return 0;
}