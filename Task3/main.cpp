#include <iostream>
#include <ctime>
#include "Priority.h"
using namespace std;

int main()
{
	srand(time(nullptr));
	PriorityQueue<int> stack;
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		if (stack.GetSize() == stack.GetMaxSize() && !stack.isFull())
			stack.ResortStack();
		stack.ShowStack();
		cout << "(1) add random   (2) extract   (3) clear stack   (4) show front   (0) exit\n";
		cout << "Your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			try 
			{
				stack.add(rand() % 100, rand() % 10);
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}
			break;
		case 2:
			try
			{
				stack.extract();
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}
			break;
		case 3:
			stack.Clear();
			break;
		case 4:
			try
			{
				cout << "Front: " << stack.front() << endl;
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}
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