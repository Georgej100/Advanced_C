#pragma once

typedef struct Node
{
	int value;
	struct Node* next;
} Node;

typedef struct Queue
{
	Node* head;
	Node* tail;
} Queue;

bool enqueue(Queue* q, int value);
int dequeue(Queue* q);