#pragma once

template<class T>
struct Node{
	T item;
	Node *next;
};

template<class T>
class Queue_LinkList
{
public:
	Queue_LinkList(void) : count(0),
		  first(NULL),
		  last(NULL)
	{
	}

	~Queue_LinkList(void) { }

	void push(T item)
	{
		Node<T> *node = new Node<T>;
		node->item = item;

		if (IsEmpty())
		{			
			first = node;
			last = node;
		}
		else
		{
			last->next = node;
			last = last->next;
		}

		count++;
	}

	T pop()
	{
		if (IsEmpty())
		{
			throw "Empty queue";
		}

		T value = first->item;

		Node<T> *oldFirst = first;
		first = first->next;
		delete oldFirst;
		//////////////////////////////////////////////////////////////////////////
		count--;
		if (IsEmpty())
		{
			first = NULL;
			last = NULL;
		}

		return value;
	}

	bool IsEmpty()
	{
		return count == 0;
	}

private:
	Node<T> *first;
	Node<T> *last;

	int count;
};

