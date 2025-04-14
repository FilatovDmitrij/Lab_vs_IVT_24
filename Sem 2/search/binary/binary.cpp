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
	quickSort(arr, pI+1, high);
}

int binarySearchIt(int arr[], int low, int high, int x)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (arr[mid] == x) return mid;

		if (arr[mid] < x) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

int binarySearchRec(int arr[], int low, int high, int x)
{
	if (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (arr[mid] == x) return mid;

		if (arr[mid] > x) return binarySearchRec(arr, low, mid - 1, x);
		else return binarySearchRec(arr, mid + 1, high, x);
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

	int res = binarySearchIt(arr, 0, 4, x);

	if (res == -1) cout << "Ёлменет " << x << " не найдет !";
	else cout << "Ёлемент найдет по индексу " << res << '.' << endl;

	return 0;
}