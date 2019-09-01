#include <iostream>
#include <ctime>
#include <Windows.h>
#include "Stack.h"
using namespace std;

int main()
{
	srand(time(nullptr));
	Stack<int> stack;
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		stack.ShowStack();
		cout << "(1) add random\t (2) pop top\t (3) clear stack\t (0) exit\n";
		cout << "Your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			stack.Push(rand() % 100);
			break;
		case 2:
			stack.Pop();
			break;
		case 3:
			stack.Clear();
			break;
		case 0:
			cout << "Have a nice day." << endl;
			break;
		default:
			cout << "Invalid input. Try again.\n";
			break;
		}
		system("pause");
	}
	return 0;
}