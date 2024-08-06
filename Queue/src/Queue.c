#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

int enqueue(Queue* q, int value)
{
	//Create a new node
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) { return 0; }
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

	return 1;
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

	while(1)
	{
		char command = ' ';
		printf("Hit 'E' to add an item to Queue or hit 'D' to pop an item from queue or hit 'X' to quit\n");
		scanf("%c", &command);
		switch(command)
		{
			case 'E':
				int value = 0;
				printf("Enter a value to add to queue\n");
				scanf("%d", &value);
				enqueue(&queue, value);
				break;
			case 'D':
				printf("The value poped from the queue was: %d\n", dequeue(&queue));
				break;
			case 'X':
				return 0;
				break;
			default:
				printf("Invalid command given\n");
				break;
		}
	}
	
}
