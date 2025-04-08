#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct Queue
{
	Node* front;
	Node* back;
	int size;
	void init()
	{
		front = nullptr;
		back = nullptr;
		size = 0;
	}
};

void push(Queue*& queue, int data)
{
	Node* tmp = new Node;
	tmp->data = data;
	tmp->next = nullptr;
	if (queue->size == 0)
	{
		queue->front = tmp;
		queue->back = tmp;
	}
	else
	{
		queue->back->next = tmp;
		queue->back = tmp;
	}
	queue->size++;
}

void pop(Queue*& queue)
{
	if (queue->size == 0)
	{
		return;
	}
	queue->front = queue->front->next;
	queue->size--;
}
void insert_element(Queue*& queue, int pos, int data)
{
	Queue* tmp = new Queue;
	tmp->init();
	for (int i = 1; i < pos; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	push(tmp, data);
	int init_size = queue->size;
	for (int i = 0; i < init_size; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	queue=tmp;
}
void insert_elements(Queue*& queue, int pos, int k)
{
	Queue* tmp = new Queue;
	tmp->init();
	int data;
	cout << "Type what elements you want to insert: ";
	for (int i = 1; i < pos; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	for (int i = 0; i < k; i++)
	{
		cin >> data;
		push(tmp, data);
	}
	int init_size = queue->size;
	for (int i = 0; i < init_size; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	queue=tmp;
}
void delete_element(Queue*& queue, int pos)
{
	Queue* tmp = new Queue;
	tmp->init();
	for (int i = 1; i < pos; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	pop(queue);
	int init_size = queue->size;
	for (int i = 0; i < init_size; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	queue=tmp;
}

void delete_elements(Queue*& queue, int pos, int k)
{
	Queue* tmp = new Queue;
	tmp->init();
	for (int i = 1; i < pos; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	for (int i = 0; i < k; i++)
	{
		pop(queue);
	}
	int init_size = queue->size;
	for (int i = 0; i < init_size; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	queue=tmp;
}

void search_element(Queue*& queue, int element)
{
	Queue* curr = new Queue;
	curr->init();
	while (queue->front != nullptr && queue->back !=nullptr)
	{
		if (queue->front->data == element)
		{
			cout << "Founded" << endl;
			return;
		}
		else
		{
			push(curr, queue->front->data);
			pop(queue);
		}
	}
	cout << "Not founded" << endl;
}

Queue* createQueue(int n)
{
	Queue* queue = new Queue;
	queue->init();
	int data;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		push(queue, data);
	}
	return queue;
}

void printQueue(Queue*& queue)
{
	Node* curr = new Node;
	curr = queue->front;
	for (int i = 0; i < queue->size; i++)
	{
		cout << curr->data << ' ';
		curr = curr->next;
	}
	cout << endl;
}

int main()
{
	int size, data, pos, k, element;
	cout << "Type queue's size: ";
	cin >> size;
	cout << "Type data" << endl;
	Queue* queue = createQueue(size);
	cout << "Your queue is" << endl;
	printQueue(queue);
	cout << "Which element to push: ";
	cin >> data;
	push(queue, data);
	printQueue(queue);
	cout << "Popped element ";
	pop(queue);
	printQueue(queue);
	cout << "Where and which element to insert: ";
	cin >> data;
	cin >> pos;
	insert_element(queue, pos, data);
	printQueue(queue);
	cout << "Where and which elements to insert: ";
	cin >> k;
	cin >> pos;
	insert_elements(queue, pos, k);
	printQueue(queue);
	cout << "Which element to delete: ";
	cin >> pos;
	delete_element(queue, pos);
	printQueue(queue);
	cout << "From which number elements to delete: ";
	cin >> k;
	cin >> pos;
	delete_elements(queue, pos, k);
	printQueue(queue);
	cout << "Which element to find: ";
	cin >> element;
	search_element(queue, element);
	return 0;
}

