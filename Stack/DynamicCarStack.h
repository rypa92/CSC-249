#ifndef DYNAMICCARSTACK_H
#define DYNAMICCARSTACK_H

using namespace std;

class DynamicCarStack
{
private:
	class node
	{
	public:
		Cars data;
		node *next;
	};
	node *top;

public:
	DynamicCarStack()
	{
		top = nullptr;
	}

	//Functions
	void Push(Cars _node);
	void Display(node *head);
	Cars Pop();
	int Size(node *cur);
	node get_top(void)
	{
		return *top;
	}
	bool IsEmpty(void);

	//Exception Class
	class exEmptyList {};
	class exValueNotFound {};
};

//Functions
void DynamicCarStack::Push(Cars _node)
{
	node *temp = new node;
	temp->data = _node;
	temp->next = nullptr;

	if (top == nullptr)
	{
		top = temp;
	}
	else {
		temp->next = top;
		top = temp;
	}
}
/*
void DynamicCarStack::Insert(Cars _node)
{
	if (head == nullptr)
	{
		Add(_node);
	}
	else {
		node *temp = new node;
		temp->data = _node;
		temp->next = head;
		head = temp;
	}
}
*/
void DynamicCarStack::Display(node *head)
{
	if(IsEmpty())
	{
		throw(exEmptyList());
	}

	head->data.get_values();
	if (head->next != nullptr)
	{
		Display(head->next);
	}
}
Cars DynamicCarStack::Pop()
{
	if (IsEmpty())
	{
		throw(exEmptyList());
	}
	else
	{
		node temp = *top;
		top = top->next;
		return temp.data;
	}
}
int DynamicCarStack::Size(node *cur)
{
	if (IsEmpty())
	{
		return 0;
	}
	else
	{
		int tempSize = 1;
		for (tempSize; cur->next != nullptr; tempSize++)
		{
			cur = cur->next;
		}
		return tempSize;
	}
}
bool DynamicCarStack::IsEmpty()
{
	if (top == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif