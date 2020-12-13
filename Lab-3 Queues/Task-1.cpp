#include<iostream>

using namespace std;

class Queue {
private:
    int front;
    int rear;
    int arr[5];

public:
    Queue() {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }
    bool isEmpty() {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }
    bool isFull() {
        if (rear == 4)
            return true;
        else
            return false;
    }
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue full" << endl;
            return;
        }
        else if (isEmpty()) {
            rear = 0;
            front = 0;
            arr[rear] = val;
        }
        else {
            rear++;
            arr[rear] = val;
        }

    }

    int dequeue() {
        int x = 0;
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return x;
        }
        else if (rear == front) {
            x = arr[rear];
            rear = -1;
            front = -1;
            return x;
        }
        else {
            cout << "front value: " << front << endl;
            x = arr[front];
            arr[front] = 0;
            front++;
            return x;
        }
    }
    void display() {
        cout << "All values in the Queue are - " << endl;
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << "  ";
        }
    }

};

int main() {
    Queue q1;
    int value, option;
    bool condition = 1;
    while (condition)
    {
        system("cls");
        cout << "Please selectfrom the following:" << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. display()" << endl;
        cout << "pleas enter the number of selected option:";
        cin >> option;
        system("cls");
        switch (option) {
        case 1:
            cout << "Enter a number you want to enqueue:" << endl;
            cin >> value;
            q1.enqueue(value);
            cout << "If you want to perform any other function press 1 else press 0";
            cin >> condition;
            break;
        case 2:
            cout << "Dequeued Value : " << q1.dequeue() << endl;
            cout << "If you want to perform any other function press 1 else press 0";
            cin >> condition;
            break;
        case 3:
            if (q1.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is not Empty" << endl;
            cout << "If you want to perform any other function press 1 else press 0";
            cin >> condition;
            break;
        case 4:
            if (q1.isFull())
                cout << "Queue is Full" << endl;
            else
                cout << "Queue is not Full" << endl;
            cout << "If you want to perform any other function press 1 else press 0";
            cin >> condition;
            break;
        case 5:
            cout << "Queue is:-" << endl;
            q1.display();
            cout << "If you want to perform any other function press 1 else press 0";
            cin >> condition;
            break;
        default:
            cout << "Enter Proper Option number." << endl;
            cout << "If you want to perform any other function press 1 else press 0";
            cin >> condition;
            break;
        }
    }
}
