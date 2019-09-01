#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Bullet
{
private:
	static int Number;
	int bulletNumber;
public:
	Bullet()
	{
		if (Number == -1)
			Number = rand();

		bulletNumber = Number++;
	}
	int GetBulletNumber() const { return bulletNumber; }
	bool Shoot()
	{
		return (rand() % 100) < 70;
	}
};
int Bullet::Number = -1;

class Clip
{
	static const int EMPTY = -1;
	static const int CLIP_SIZE = 30;
	Bullet* clip[CLIP_SIZE] = {};
	int top = EMPTY;
public:
	Clip()
	{
		for (int i = 0; i < CLIP_SIZE; i++)
			Push(new Bullet());
	}
	bool isEmpty() const
	{
		return top == EMPTY;
	}
	bool isFull() const
	{
		return top == (CLIP_SIZE - 1);
	}
	void Push(Bullet* bullet)
	{
		if (!isFull())
			clip[++top] = bullet;
	}
	Bullet* GetBullet()
	{
		if (!isEmpty())
		{
			return clip[top--];
		}
		else
			throw "Clip is empty";
	}
	//Деструктор?
	//~Clip()
	//{
	//	for (int i = 0; i < CLIP_SIZE; i++)
	//		delete clip[i];
	//}
};

class AssaultRifle
{
private:
	Clip* clip = nullptr;
	Bullet* bullet = nullptr;
public:
	AssaultRifle()
	{
		Reload();
	}
	void Reload()
	{
		cout << "Reloading...\t";
		//if (clip != nullptr)
		//	delete clip;
		clip = new Clip();
		cout << "READY." << endl;
	}
	void Shoot()
	{
		try
		{
			bullet = clip->GetBullet();
			cout << "Bullet#: " << bullet->GetBulletNumber() << "  ";
			cout << "Result:" << (bullet->Shoot() ? " hit." : " miss.") << endl;
		}
		catch (const char* ex)
		{
			cout << ex << endl;
		}
	}
};