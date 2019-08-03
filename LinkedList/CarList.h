#ifndef CARLIST_H
#define CARLIST_H

using namespace std;

class CarList
{
private:
	class node
	{
	public:
		Cars data;
		node *next;
	};
	node *head, *tail;

public:
	CarList()
	{
		head = nullptr;
		tail = nullptr;
	}

	//Functions
	void Add(Cars _node);
	void Insert(Cars _node);
	void Display(node *head);
	void Remove(node *prev, node *cur, int _pos);
	node get_head(void)
	{
		return *head;
	}
	bool IsEmpty(void);

	//Exception Class
	class exEmptyList {};
	class exValueNotFound {};
};

//Functions
void CarList::Add(Cars _node)
{
	node *temp = new node;
	temp->data = _node;
	temp->next = nullptr;

	if (head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = tail->next;
	}
}
void CarList::Insert(Cars _node)
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
void CarList::Display(node *head)
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
void CarList::Remove(node *prev, node *cur, int pos)
{
	if (IsEmpty())
	{
		throw(exEmptyList());
	}
	
	if (cur->data.get_VIN() == pos)
	{
		if (head->data.get_VIN() == cur->data.get_VIN())
		{
			node *temp = new node;
			temp->data = head->next->data;
			temp->next = head->next->next;
			head = temp;
		}
		else
		{
			prev->next = cur->next;
		}
	}
	else
	{
		if (cur->next == nullptr)
		{
			throw(exValueNotFound());
		}
		else
		{
			Remove(cur, cur->next, pos);
		}
	}
}
bool CarList::IsEmpty()
{
	if (head == nullptr && tail == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif