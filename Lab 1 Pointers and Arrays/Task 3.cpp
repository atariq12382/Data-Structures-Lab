#include<iostream>
using namespace std;

void smallest(int* arr, int size)
{
	int small = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (small > arr[i])
			small = arr[i];
	}
	cout << "Smallest value of the array is " << small<<endl;
}

void largest(int* arr, int size)
{
	int large = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (large < arr[i])
			large = arr[i];
	}
	cout << "Largest value of the array is " << large<<endl;
}

int main()
{
	int size;
	cout << "Please enter the size of array:";
	cin >> size;
	int* arr = new int[size];
	cout << "Please enter the value in array:" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	cout << endl;
	smallest(arr, size);
	cout << endl;
	largest(arr, size);
}