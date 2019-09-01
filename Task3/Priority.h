#pragma once
#include <iostream>
using namespace std;

template<typename T>
class PriorityQueue
{
private:
	static const int   MAX_SIZE = 10;
	int realSize = 0, size = 0;
	pair<T, int > queue[MAX_SIZE];
public:
	PriorityQueue(T value = T())
	{
		for (size_t i = 0; i < MAX_SIZE; i++)
		{
			queue[i] = { value, -1 };
		}
	}
	int GetMaxSize() const { return MAX_SIZE; }
	int GetRealSize() const { return realSize; }
	int GetSize() const { return size; }
	void add(const T& data, int priority)
	{
		if (!isFull())
		{
			queue[size++] = { data, priority };
			realSize++;
		}
		else
			throw "add() : stack is full";
	}
	bool isFull() const
	{
		return realSize == MAX_SIZE;
	}
	bool isEmpty() const
	{
		return realSize == 0;
	}
	void ShowStack() const
	{
		for (int i = MAX_SIZE - 1; i >= 0; i--)
		{
			cout << i + 1 << ":\t";
			if (i <= size && queue[i].second != -1)
				cout << "Value: " << queue[i].first << "\t Priority: " << queue[i].second;
			else
				cout << "-";
			cout << endl;
		}
	}
	void extract()
	{
		if (!isEmpty())
		{
			int index = 0, maxPrior = queue[index].second;
			for (int i = 1; i < MAX_SIZE; i++)
			{
				if (queue[i].second > maxPrior)
				{
					maxPrior = queue[i].second;
					index = i;
				}
			}
			queue[index].second = -1;
			if (--realSize == 0)
				size = 0;
		}
		else
			throw "extract() : stack is empty";
	}
	void ResortStack()
	{
		int emptyIndex = 0, elementIndex = 0;
		for (size_t i = 0; i < MAX_SIZE; i++)
		{
			if (queue[i].second == -1)
			{
				emptyIndex = i;
				elementIndex = i + 1;
				for (size_t j = elementIndex; j <= MAX_SIZE; j++)
				{
					if (j == MAX_SIZE)
					{
						size = realSize;
						return;
					}
					if (queue[j].second != -1)
					{
						queue[emptyIndex] = queue[j];
						queue[j].second = -1;
						elementIndex = j + 1;
						break;
					}
				}
			}
		}
	}
	void Clear()
	{
		if (isEmpty())
			cout << "Stack is empty." << endl;
		else
		{
			for (int i = 0; i < MAX_SIZE; i++)
			{
				queue[i].second = -1;
			}
			size = realSize = 0;
		}
	}
	bool extract(T& element)
	{
		if (!isEmpty())
		{
			int index = 0, maxPrior = queue[index].second;
			for (size_t i = 1; i < MAX_SIZE; i++)
			{
				if (queue[i].second > maxPrior)
				{
					maxPrior = queue[i].second;
					index = i;
				}
			}
			realSize--;
			if (realSize == 0)
				size = 0;
			queue[index].second = -1;
			return true;
		}
		else
			return false;
	}
	T front() const
	{
		if (!isEmpty())
		{
			int index = 0, maxPrior = queue[index].second;
			for (int i = 1; i < size; i++)
			{
				if (queue[i].second > maxPrior)
				{
					maxPrior = queue[i].second;
					index = i;
				}
			}
			return queue[index].first;
		}
		else
			throw "front() : stack is empty";
	}
};
