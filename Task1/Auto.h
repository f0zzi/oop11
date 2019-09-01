#pragma once
#include <iostream>
#include <string>
using namespace std;

//Створити  Auto  з полями :
class Auto
{
private:
	string number;	//номер авто(у форматі AB1234CD)
	int maxSpeed;				//максимальна швидкість авто
	int currentSpeed;			//поточна швидкість авто

protected:
	void SetMaxSpeed(int maxSpeed)
	{
		if (maxSpeed > 0 && maxSpeed <= 360)
			this->maxSpeed = maxSpeed;
		else
			throw WrongMaxSpeedException(maxSpeed);
	}
	void SetCurrentSpeed(int currentSpeed)
	{
		if (currentSpeed >= 0 && currentSpeed <= maxSpeed)
			this->currentSpeed = currentSpeed;
		else
			throw WrongSpeedException(currentSpeed);
	}
	bool isValid(string number)
	{
		if (number.size() != 8)
			throw InvalidNumberException(number);
		initializer_list<int> letters = { 1, 2, 7, 8 };
		initializer_list<int> numbers = { 3, 4, 5, 6 };

		for (int elem : numbers)
			if (!stoi(number.substr(elem - 1, 1)))
				throw InvalidNumberException(number);
		for (int elem : letters)
			if (!isalpha(number.data()[elem - 1]))
				throw InvalidNumberException(number);
		return true;
	}
	string GetNumber() const { return number; }
	int GetMaxSpeed() const { return maxSpeed; }
	int GetCurrentSpeed() const { return currentSpeed; }

public:
	Auto(string number, int maxSpeed, int currentSpeed)
	{
		SetNumber(number);
		try
		{
			SetMaxSpeed(maxSpeed);
		}
		catch (WrongMaxSpeedException& ex)
		{
			cout << ex.what() << endl;
			SetMaxSpeed(360);
		}
		try
		{
			SetCurrentSpeed(currentSpeed);
		}
		catch (WrongSpeedException& ex)
		{
			cout << ex.what() << endl;
			SetCurrentSpeed(0);
		}
	}
	void SetNumber(string number)
	{
		try
		{
			if (isValid(number))
				this->number = number;
		}
		catch (InvalidNumberException& ex)
		{
			cout << ex.what() << endl;
		}
	}
	void SpeedUp(int speed = 5)		//метод збільшення швидкості(по замовчуванню на 5)
	{
		try
		{
			SetCurrentSpeed(GetCurrentSpeed() + speed);
		}
		catch (WrongSpeedException& ex)
		{
			cout << ex.what() << endl;
		}
	}
	void SpeedDown(int speed = 5)	//метод зменшення швидкості(по замовчуванню на 5)
	{
		try
		{
			SetCurrentSpeed(GetCurrentSpeed() - speed);
		}
		catch (WrongSpeedException& ex)
		{
			cout << ex.what() << endl;
		}
	}
	//Створити у класі авто власні класи виключень WrongSpeed, WrongMaxSpeed   
	//та InvalidNumber, які інкапсулюють у собі невірне дане та повідомлення про помилку.
	class WrongSpeedException
	{
	private:
		int speed;
	public:
		WrongSpeedException(int speed) :speed(speed) {}
		string what() const { return "Unacceptable speed: " + to_string(speed); }
	};
	class WrongMaxSpeedException
	{
	private:
		int speed;
	public:
		WrongMaxSpeedException(int speed) :speed(speed) {}
		string what() const { return "Unacceptable speed: " + to_string(speed); }
	};
	class InvalidNumberException
	{
	private:
		string number;
	public:
		InvalidNumberException(string number) :number(number) {}
		string what() const { return "Invalid number: " + number; }
	};
	void ShowInfo() const
	{
		cout << "Number: " << GetNumber() << "\tSpeed: " << GetCurrentSpeed() << "\tMax speed: " << GetMaxSpeed() << endl;
	}
};