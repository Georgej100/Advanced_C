#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

bool enqueue(Queue* q, int value)
{
	//Create a new node
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) { return false; }
	newNode->value = value;

	if (q->tail != NULL)
	{
		q->tail->next = newNode;
	}
	q->tail = newNode;

	if (q->head == NULL)
	{
		q->head = newNode;
	}

	return true;
}

int dequeue(Queue* q)
{
	//Check if queue is empty
	if (q->head == NULL)
	{
		return 0;
		printf("Queue is empty!\n");
	}

	//Store value
	int value = q->head->value;

	//Cut of head
	Node* newHead = q->head->next;
	free(q->head);
	q->head = newHead;

	if (q->head == NULL)
	{
		q->tail = NULL;
	}

	return value;
}

int main()
{
	Queue queue;
	queue.head = NULL;
	queue.tail = NULL;

	enqueue(&queue, 5);
	enqueue(&queue, 4);
	enqueue(&queue, 3);
	enqueue(&queue, 2);
	enqueue(&queue, 1);

	
	printf("%d\n", dequeue(&queue));
	printf("%d\n", dequeue(&queue));
	printf("%d\n", dequeue(&queue));
	printf("%d\n", dequeue(&queue));
	printf("%d\n", dequeue(&queue));
	return 0;
	
}