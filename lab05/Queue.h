#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
	//private variables
	int arr_size;
	char *arr;
	int head;
	int tail;
	int count;
public:
	Queue(int); //constructor
	//functions
	int enqueue(char);
	int dequeue(char&);
	int dequeue(char*);
	int operator+= (char);
	int operator-=(char&);
	~Queue() { delete[] arr; }
};
#endif

