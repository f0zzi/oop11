#include <iostream>
#include "Auto.h"
using namespace std;

int main()
{
	Auto test("A1234CD", 100, 99);
	test.SetNumber("A11234CC");
	test.SetNumber("AA1234CC");
	test.SpeedUp();
	test.ShowInfo();
	system("pause");
	return 0;
}