#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Stack
{
private:
	static const int EMPTY = -1;
	static const int MAXLEN = 10;
	T buffer[MAXLEN]{T()};
	int top = EMPTY;
public:
	bool isEmpty() const
	{
		return top == EMPTY;
	}
	bool isFull() const
	{
		return top == (MAXLEN - 1);
	}
	void Push(T elem)
	{
		if (!isFull())
		{
			buffer[++top] = elem;
			cout << elem << " successfully added to stack." << endl;
		}
		else
			cout << "Stack is full." << endl;
	}
	T GetTop() const
	{
		if (isEmpty())
			throw logic_error("Stack is empty");
		else
			return buffer[top];
	}
	void Pop()
	{
		if (!isEmpty())
		{
			cout << GetTop() << " successfully poped." << endl;
			--top;
		}
		else
			cout << "Stack is empty." << endl;
	}
	void ShowStack()
	{
		for (int i = MAXLEN - 1; i >= 0; i--)
		{
			cout << i + 1 << ":\t";
			if (i <= top)
				cout << buffer[i];
			else
				cout << "-";
			cout << endl;
		}
	}
	void Clear()
	{
		if (isEmpty())
			cout << "Stack is empty." << endl;
		else
			top = -1;
	}
};