#ifndef DYNAMICCARQUEUE_H
#define DYNAMICCARQUEUE_H

using namespace std;

class DynamicCarQueue
{
private:
	class node
	{
	public:
		Cars data;
		node *next;
	};
	node *front, *rear;

public:
	DynamicCarQueue()
	{
		front = nullptr;
	}

	//Functions
	void Enqueue(Cars _node);
	Cars Dequeue();
	void Display(node *head);
	void DisplayReverse(node *head);
	int Size(node *cur);
	node get_front(void)
	{
		return *front;
	}
	bool IsEmpty(void);

	//Exception Class
	class exEmptyList {};
	class exValueNotFound {};
};

//Functions
void DynamicCarQueue::Enqueue(Cars _node)
{
	node *temp = new node;
	temp->data = _node;
	temp->next = nullptr;

	if (front == nullptr)
	{
		front = temp;
		rear = temp;
	}
	else {
		rear->next = temp;
		rear = temp;
	}
}
void DynamicCarQueue::Display(node *cur)
{
	if(IsEmpty())
	{
		throw(exEmptyList());
	}

	cur->data.get_values();
	if (cur->next != nullptr)
	{
		Display(cur->next);
	}
}
void DynamicCarQueue::DisplayReverse(node *cur)
{
	if (IsEmpty())
	{
		throw(exEmptyList());
	}
	else if (cur->next != nullptr)
	{
		DisplayReverse(cur->next);
	}
	cur->data.get_values();
}
Cars DynamicCarQueue::Dequeue()
{
	if (IsEmpty())
	{
		throw(exEmptyList());
	}
	else
	{
		node temp = *front;
		front = front->next;
		return temp.data;
	}
}
int DynamicCarQueue::Size(node *cur)
{
	if (IsEmpty())
	{
		return 0;
	}
	else if (cur->next == nullptr)
	{
		return 1;
	}
	else
	{
		return Size(cur->next) + 1;
	}
}
bool DynamicCarQueue::IsEmpty()
{
	if (front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif