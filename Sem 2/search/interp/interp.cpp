#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int num = 0;

	for (int i = low + 1; i <= high; i++)
	{
		if (arr[i] < pivot) { num++; }
	}

	int pos = low + num;
	int i = low; int j = high;

	while (i <= pos && j >= pos)
	{
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;

		if (i <= pos && j >= pos)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	return pos;
}

void quickSort(int arr[], int low, int high)
{
	if (low >= high) return;

	int pI = partition(arr, low, high);

	quickSort(arr, low, pI - 1);
	quickSort(arr, pI + 1, high);
}

int interpolationSearchIt(int arr[], int low, int high, int x)
{
	while (low <= high && x >= arr[low] && x <= arr[high])
	{
		if (low == high)
		{
			if (arr[low] == x) return low;
			return -1;
		}

		int pos = low + (((x - arr[low]) * (high - low)) / (arr[high] - arr[low]));

		if (arr[pos] == x) return pos;

		if (arr[pos] < x) low = pos + 1;
		else high = pos - 1;
	}
	return -1;
}

int interpolationSearchRec(int arr[], int low, int high, int x)
{
	while (low <= high && x >= arr[low] && x <= arr[high])
	{
		if (low == high)
		{
			if (arr[low] == x) return low;
			return -1;
		}

		int pos = low + (((x - arr[low]) * (high - low)) / (arr[high] - arr[low]));

		if (arr[pos] == x) return pos;

		if (arr[pos] < x) return interpolationSearchRec(arr, pos + 1, high, x);
		else return interpolationSearchRec(arr, low, pos - 1, x);
	}
	return -1;
}

int main()
{
	int arr[5]{ 31, 123, 64, 9, 1 };
	int x = 64;

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	quickSort(arr, 0, 4);

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	int res = interpolationSearchIt(arr, 0, 4, x);

	if (res == -1) cout << "Ёлменет " << x << " не найдет !";
	else cout << "Ёлемент найдет по индексу " << res << '.' << endl;

	return 0;
}