/* This program implements the data structures called queues. Queue follows the FIFO structure, 
   i.e. , the first item to enter the queue is the first item to be popped out of the queue.

   Mainly the following four basic operations are performed on queue:

        Enqueue: Adds an item to the queue. If the queue is full, then it is said to be 
        		 an Overflow condition.

		Dequeue: Removes an item from the queue. The items are popped in the same order in 
				 which they are pushed. If the queue is empty, then it is said to be an 
				 Underflow condition.

		Front: Get the front item from queue.
		Rear: Get the last item from queue.

*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

//A structure to represent a queue.

struct Queue
{
	int front, rear, size;
	unsigned capacity;
	int* array;
};

class QueueImp
{
	public :
		Queue* createQueue(unsigned capacity);
		int isFull(Queue* queue);
		int isEmpty(Queue* queue);
		void enqueue(Queue* queue, int item);
		int dequeue(Queue* queue);
		int front(Queue* queue);
		int rear(Queue* queue);
};

Queue* QueueImp::createQueue(unsigned capacity)
{
	Queue *queue = new Queue;
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity -1;
	queue->array = new int;
	return queue;
}

int QueueImp::isFull(Queue* queue)
{
	return (queue->size == queue->capacity);
}

int QueueImp::isEmpty(Queue* queue)
{
	return (queue->size == 0);
}

void QueueImp::enqueue(Queue* queue, int item)
{
	if isFull(queue)
		return;

	queue->rear = ((queue->rear + 1) % queue->capacity);
	queue->array[queue->rear] = item;
	queue->size += 1;
	cout << item << " has been enqueued to the queue." << endl;
}

int QueueImp::dequeue(Queue* queue)
{
	if isEmpty(queue)
		return;

	item = queue->array[queue->front];
	queue->front = ((queue->front + 1) % queue->capacity);
	queue->size -= 1;
	return item;
}

int QueueImp::front(Queue* queue)
{
	if isEmpty(queue)
		return;

	return queue->array[queue->front];
}

int QueueImp::rear(Queue* queue)
{
	if isEmpty(queue)
		return;

	return queue->array[queue->rear];
}

