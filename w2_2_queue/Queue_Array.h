#pragma once

template<class T>
class Queue_Array
{
public:
	Queue_Array(void) : nHead(0),
		nEnd(0),
		count(0),
		nSize(2)
	{
		items = new T[nSize];
	}

	~Queue_Array(void) { }

	void push(T item)
	{
		Expand();

		if (IsEmpty())
		{
			nHead = 0;
			nEnd = 0;

			items[nHead] = item;
		}
		else
		{
			nEnd++;
			items[nEnd] = item;
		}
		count++;
	}

	T pop()
	{
		if (IsEmpty())
		{
			throw "Out of Bound";
		}

		T value = items[nHead];

		nHead++;
		count--;

		return value;
	}

	void Expand()
	{
		if ((nEnd+1) == nSize)
		{
			nSize *= 2;
			T* newItem = new T[nSize];

			for (int i = nHead; i <= nEnd; i++)
			{
				newItem[i-nHead] = items[i];
			}
			nEnd -= nHead;
			nHead -= nHead;

			delete[] items;
			items = newItem;
		}
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
	T *items;
	int nHead;
	int nEnd;

	int nSize;
	int count;
};

