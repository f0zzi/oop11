#include <iostream>
#include <ctime>
#include <Windows.h>
#include "Classes.h"
using namespace std;

int main()
{
	srand(time(nullptr));
	AssaultRifle rifle;
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		cout << "You are at shooting range. Assault rifle in your hands." << endl;
		cout << "(1) Shoot   (2) New clip   (0) Exit" << endl;
		cout << "Choose action: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			rifle.Shoot();
			break;
		case 2:
			rifle.Reload();
			break;
		case 0:
			cout << "Have a nice day." << endl;
			break;
		default:
			cout << "Invalid input." << endl;
			break;
		}
		system("pause");
	}
	return 0;
}