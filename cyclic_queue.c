#include <stdio.h>
#include <stdlib.h>
typedef struct NODE {
	struct NODE *next;
	int data;
}node;
typedef struct QUEUE {
	struct NODE *front;
	struct NODE *last;
}Queue;
//void Josep(int *all, int sel);
void MakeQueue(int i, Queue *queue);
int main()
{
	int all, sel, i;
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	node *curr = NULL;
	queue->front = NULL;
	queue->last = NULL;
	scanf("%d %d", &all, &sel);
	getchar();
	for (i = 1; i < all + 1; i++)
	{
		MakeQueue(i, queue);
	}
	queue->last->next = queue->front;
	curr = queue->front;
	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		getchar();
		curr = curr->next;
	}
	//Josep(&all, sel);
	return 0;
}
void MakeQueue(int i, Queue *queue)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = i;
	newnode->next = NULL;
	if (i == 1)
	{
		queue->front = newnode;
		queue->last = newnode;
	}
	else
	{
		queue->last->next = newnode;
		queue->last = newnode;
	}
	return;
}