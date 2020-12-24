#include<iostream>
using namespace std;

void bubblesort(int*& arr,int size)
{
	int temp;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int size;
	cout << "Please enter the size of array:";
	cin >> size;
	int* arr = new int[size];
	cout << "Please enter the values of array:" << endl;
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	bubblesort(arr, size);
	cout << "Sorted array is:" << endl;
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}