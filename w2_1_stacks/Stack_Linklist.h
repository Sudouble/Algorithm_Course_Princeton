#pragma once

template<class T>
class Stack_Linklist;

template<class T>
struct Node{
	T item;
	Node *next;
};

template<class T>
class Stack_Linklist
{
public:
	Stack_Linklist(void)
	{
		count = 0;
		first = NULL;
	}
	~Stack_Linklist(void){}

	void push(T item)
	{
		Node<T> *oldFirst = first;	

		Node<T> *link = new Node<T>;
		link->item = item;
		link->next = oldFirst;

		first = link;

		++count;
	}

	T pop()
	{
		if (first == NULL)
		{
			cout << "NULL param " << __FUNCTION__ << endl;
			throw "NULL param";
		}

		T value = first->item;
		Node<T> *needDelete = first;

		first = first->next;

		delete needDelete;

		--count;

		return value;
	}
	int size()
	{
		return count;
	}

	bool IsEmpty()
	{
		return count == 0;
	}

private:
	int count;
	Node<T> *first;
};

