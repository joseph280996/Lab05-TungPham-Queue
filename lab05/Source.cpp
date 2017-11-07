//Description: This program takes in the size of queue and enqueue, dequeue and display the assigned string
//Programmer: Tung Pham
//Date: 10/20/17
//Lab: Lab05
#include "Queue.h"
#include <iostream>
using namespace std;
void getInt(int &n) { //Input Validating function
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "Please input an integer: ";
		cin >> n;
	}
}
int main() {
	//Initialize
	int n, test1_size, choice, choice_type;
	char read_val = NULL;
	char* readptr = &read_val;
	char arr[] = "Hello World, this is ELEC3150";
	int size = sizeof(arr) - 1; //minus 1 because for character array, there's always a NULL element at the end
	int count = 0;
	int i = 0;
	test1_size = 10;
	cout << "Please enter the desired size for the queue: ";
	cin >> n;
	getInt(n);
	Queue myqueue(n);
	cout << "Please choose test: ";
	cin >> choice;
	getInt(choice);
	//Queue
	switch (choice) {
	case 1:
		//Test1:
		//enqueue using overload operator
		
		cout << "Test 1: \n";
		while (arr[i] != '\0') { 
			cout << "\nEnqueue: " << arr[i];
			if ( (myqueue+=arr[i]) == -1) { cout << " Array is full."; }
			i++;
		}
		//dequeue and print out
		cout << "\n";
		for (int j = 0; j < test1_size; j++) {
			if ((myqueue-=read_val) == -1) { cout << "\nArray is empty. Cannot be dequeue"; }
			else cout << "\nDequeue: " << read_val;
		}
		break;
	case 2:
		//Test 2:
		cout << "Please enter which type to enqueue: (1.reference 2.reference using overload operator or 3.pointer) ";
		cin >> choice_type;
		getInt(choice_type);
		cout << endl << "\nTest 2: ";
		//Enqueue using overload operator
		while (count < size) {
			for (int i=0; i < 5; i++) {
				cout << "\nEnqueue: ";
				if (arr[count] != NULL) //Check end of array
				{
					if ((myqueue+=arr[count]) == -1) { //if return error
						cout << "Array is full. Value cannot be write: " << arr[count];
					} else{ cout << arr[count]; }
				}
				else {break;}
				count++;
			}
			cout << "\n";
			for (int j = 0; j < 5; j++) {
				cout << "\nDequeue: ";
				switch (choice_type) {
				case 1:	//Reference
					if (myqueue.dequeue(read_val) == -1) { //if return error
						cout << "Array is empty. Cannot be dequeue";
					}
					else { cout << read_val; }
					break;
				case 2:
					if ((myqueue-=read_val) == -1) { //if return error
						cout << "Array is empty. Cannot be dequeue";
					}
					else { cout << read_val; }
					break;
				case 3://Pointer
					if (myqueue.dequeue(readptr) == -1) { //if return error
						cout << "Array is empty. Cannot be dequeue";
					}
					else { cout << *readptr; }
					break;
				}
			}
			cout << "\n";
		}
		break;
	}
	cin.ignore();
	cin.get();
	return 0;
}