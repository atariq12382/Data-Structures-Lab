#include<iostream>
using namespace std;

class minHeap
{
public:
	int* arr;
	int currentSize;
	int maxSize;
	minHeap(int size)
	{
		currentSize = 0;
		maxSize = size;
		arr = new int[size];
	}
	int parentIndex(int i)
	{
		int a = (i - 1);
		a = a / 2;
		return a;
	}
	int leftChildIndex(int i)
	{
		int a = (2 * i + 1);
		return a;
	}
	int rightChildIndex(int i)
	{
		int a = (2 * i + 2);
		return a;
	}
	void insert(int data)
	{
		int temp;
		int index;
		if (currentSize == maxSize)
		{
			cout << "Heap is already full." << endl;
			return;
		}
		currentSize++;
		index = currentSize - 1;
		arr[index] = data;
		while (index != 0 && arr[parentIndex(index)] > arr[index])
		{
			temp = arr[parentIndex(index)];
			arr[parentIndex(index)] = arr[index];
			arr[index] = temp;
			index = parentIndex(index);
		}
	}
	void minHeapyfy(int index)
	{
		int temp;
		int left = leftChildIndex(index);
		int right = rightChildIndex(index);
		int smallest = index;
		if (left < currentSize && arr[left] < arr[index])
			smallest = left;
		if (right < currentSize && arr[right] < arr[smallest])
			smallest = right;
		if (smallest != index)
		{
			temp = arr[index];
			arr[index] = arr[smallest];
			arr[smallest] = temp;
			minHeapyfy(smallest);
		}
	}
	int extractMin()
	{
		if (currentSize <= 0)
			return -1111;
		if (currentSize == 1)
		{
			currentSize--;
			return arr[currentSize];
		}
		int ret = arr[0];
		arr[0] = arr[currentSize - 1];
		currentSize--;
		minHeapyfy(0);
		return ret;
	}
	int getMin()
	{
		return arr[0];
	}
	void decreaseKey(int index, int newValue)
	{
		int temp;
		arr[index] = newValue;
		while (index != 0 && arr[parentIndex(index)] > arr[index])
		{
			temp = arr[parentIndex(index)];
			arr[parentIndex(index)] - arr[index];
			arr[index] = temp;
			index = parentIndex(index);
		}
	}
	void Delete(int index)
	{
		decreaseKey(index, INT_MIN);
		extractMin();
	}
	void maxHeapyfy(int index)
	{
		int temp;
		int left = leftChildIndex(index);
		int right = rightChildIndex(index);
		int largest = index;
		if (left < currentSize && arr[left] > arr[index])
			largest = left;
		if (right < currentSize && arr[right] > arr[largest])
			largest = right;
		if (largest != index)
		{
			temp = arr[index];
			arr[index] = arr[largest];
			arr[largest] = temp;
			maxHeapyfy(largest);
		}
	}
	void converMax()
	{
		for (int i = (currentSize - 2) / 2; i >= 0; i--)
			maxHeapyfy(i);
	}
};

int main()
{
	int size, index;
	cout << "Please enter the size of Heap:";
	cin >> size;
	bool condition = 1;
	int choice;
	minHeap H(size);
	system("cls");
	while (condition)
	{
		system("cls");
		cout << "Please select from the following option:\n1.Get minimum value from heap.\n2.Deletes minimum value from heap.\n3.Decrease the value at any index.\n4.Insert a value.\n5.Delete a value.\n6.Convert to max heap.\nPlease enter the numer of selected option:";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			index = H.getMin();
			cout << "Minimum value in the heap is " << index << endl;
			cout << "If you want to perform any other function press 1 else press 0 :";
			cin >> condition;
			break;
		case 2:
			index = H.extractMin();
			cout << "The value " << index << " has been extracted from the heap." << endl;
			cout << "If you want to perform any other function press 1 else press 0 :";
			cin >> condition;
			break;
		case 3:
			cout << "Please enter the index at which you want to decrease value:";
			cin >> index;
			cout << "Please enter new decreased value for index " << index << " :";
			cin >> size;
			H.decreaseKey(index, size);
			cout << "If you want to perform any other function press 1 else press 0 :";
			cin >> condition;
			break;
		case 4:
			cout << "Please enter the value you want to insert in heap:";
			cin >> index;
			H.insert(index);
			cout << "If you want to perform any other function press 1 else press 0 :";
			cin >> condition;
			break;
		case 5:
			cout << "Please enter the index number which's value you want to delete:";
			cin >> index;
			H.Delete(index);
			cout << "If you want to perform any other function press 1 else press 0 :";
			cin >> condition;
			break;
		case 6:
			H.converMax();
			cout << "If you want to perform any other function press 1 else press 0 :";
			cin >> condition;
			break;
		default:
			cout << "Wrong Input!!" << endl;
			cout << "If you want to perform any other function press 1 else press 0 :";
			cin >> condition;
			break;
		}
	}
}