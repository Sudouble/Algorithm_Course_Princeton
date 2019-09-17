#pragma once

template<class T>
class Stack_Array
{
public:
	Stack_Array(void) :
		Size(20),
		bExpanded(false)
	{
		count = 0;
		items = new T[Size];
	}

	~Stack_Array(void) { }

	void push(T item)
	{
		if (count == Size)
			Expand();

		items[count] = item;
		count++;
	}

	T pop()
	{
		if (IsEmpty())
		{
			cout << "Empty stack " << __FUNCTION__ << endl;
			throw "Empty stack";
		}

		T item = items[count-1];
		count--;

		return item;
	}

	bool IsEmpty()
	{
		return count == 0;
	}

	void Expand()
	{		
		bExpanded = true;

		Size *= 2;

		T *newItem = new T[Size];

		// copy
		for (int i = 0; i < Size/2; i++)
		{
			newItem[i] = items[i];
		}
		delete[] items;
		items = newItem;
	}

	void Shrink()
	{
		if (bExpanded && count <= 0.75*Size)
		{
			Size *= 0.75;

			T *newItem = new T[Size];

			// copy
			for (int i = 0; i < Size; i++)
			{
				newItem[i] = items[i];
			}
			delete[] items;
			items = newItem;
		}
	}

private:
	T *items;
	int count;
	int Size;

	bool bExpanded;
};

