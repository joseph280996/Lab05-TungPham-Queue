#include <iostream>
#include "Queue.h"
using namespace std;
Queue::Queue(int size) {
	//initializing
	arr_size = size;
	arr = new char[size];
	for (int i = 0; i < arr_size; i++) {
		arr[i] = NULL;
	}
	head = 0;
	tail = 0;
	count = 0;
}
int Queue::enqueue(char value) {
	if (count<arr_size) //if array is not full, execute below
	{
			arr[tail++] = value;  //pass value of first-to-last element in array
			count++; //counting the input value
			if (tail == arr_size) tail = 0; //rewind the index back to the first if it reach the size input
			return 0;
	}
	else {
		return -1;
	}
	
}
int Queue::dequeue(char &read_val) {
	if (count >0) { //if array has elements, execute below
		read_val = arr[head++]; //pass-by-reference the value of first-to-last element in array to parameter of function
		arr[head-1] = NULL; //reassign the dequeue value back to NULL
		count--; //decrement the size of the queue
		if (head == arr_size ) head = 0;//rewind the index back to the first if it reach the size input
		return 0;
	}
	else { //If array is empty, assign the dequeue index to the enqueue index
		return -1;
	}
}
int Queue::dequeue(char* read_val) {
	if (count >0) { //if array has elements, execute below
		*read_val = arr[head++]; //using pointer to manipulate the value pass into the function
		count--; //decrement the size of the queue
		if (head == arr_size) head = 0; //rewind the index back to the first if it reach the size input
		return 0;
	}
	else {
		return -1;
	}
}
int Queue::operator += (char value)
{
	return enqueue(value);
}
int Queue::operator -= (char& read_val)
{
	return dequeue(read_val);
}