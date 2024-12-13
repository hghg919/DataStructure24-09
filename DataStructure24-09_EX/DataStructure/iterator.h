#pragma once

#include <vector>
#include <iostream>
#include <string>
// �������� ����

// int abc = 10;
// int* intptr = &abc;
// ������ ������ *, ++, ++ ,==, !=, 

// class Item -> Inventory Items �ڷᱸ�� ->  std::vector<int><float>. Item.Print(); ������

// vector<Item> inventory




template <typename T>
class Container
{
private:
	T* arr;
	int size;
	int capacity;

	class Iterator
	{
	private:
		T* ptr;
	public:
		// ������
		Iterator() : ptr(nullptr) {}
		Iterator(T* ptr) : ptr(ptr) {}

		T& operator*()
		{
			return *ptr;
		}

		// ���� ������ ++it
		Iterator& operator++()
		{
			ptr++;
			return *this;
		}

		// ���� ������ it++
		Iterator& operator++(int)
		{
			Iterator temp = *this;
			ptr++;
			return temp;
		}

		bool operator==(const Iterator& other)
		{
			return ptr == other.ptr;
		}

		bool operator!=(const Iterator& other)
		{
			return ptr != other.ptr;
		}

		Iterator operator+(const int count)
		{
			Iterator temp = *this;
			temp.ptr += count;
			return temp;
		}

	};

	// iterator ���� �Լ�
	// iterator Iterator<int>
public:
	using iterator = Iterator;
	iterator begin() { return iterator(arr); }
	iterator end() { return begin() + size; }


	// Containter �ڷᱸ���� ��� ����
public:
	Container(int _size = 3)
	{
		arr = new T[_size];
		size = 0;
		capacity = _size;
	}

	void push_back(T data)
	{
		arr[size] = data;
		size++;
	}

	void pop_back()
	{
		size = size > 0 ? size - 1 : 0;	 // 1. size > 0 �� true -> (size - 1 )����, false -> 0 ����� size ����
	}
};


class Item
{
private:
	float time;
	int idx;
public:
	Item() {}
	Item(float Time, int Idx) : time(Time), idx(Idx) {}

	void Print()
	{
		std::cout << "�ð� : " << time << std::endl;
		std::cout << "NO." << idx << std::endl;
	}
};

void IteratorExample()
{
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}

	auto it = vec.begin();

	std::cout << "iterator�� ����� �ݺ� �����" << std::endl;

	for (it; it != vec.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	// for�ݺ��� : range based for loop

	std::cout << "���� ��� ���� �����" << std::endl;

	for (int elem : vec)   // iterator vec.begin() ~ vec.end()   it++
	{
		std::cout << elem << std::endl;
	}


	Container<int> myCon;
	myCon.push_back(10);
	myCon.push_back(20);
	myCon.push_back(30);

	auto myIt = myCon.begin();
	
	for (myIt; myIt != myCon.end(); myIt++)
	{
		std::cout << "���ͷ����� ����� ��� :" << *myIt << std::endl;
	}

	// range base for loop 
	// ���� ��� for �ݺ���
	for (int& elem : myCon)
	{
		elem += 100;
		std::cout << "���� ��� ��� ��� :" << elem << std::endl;
	}

	myIt = myCon.begin();

	for (myIt; myIt != myCon.end(); myIt++)
	{
		std::cout << "���ͷ����� ����� ��� :" << *myIt << std::endl;
	}

	// auto	: �ڵ����� �ڿ� �ִ� ������ Ÿ���� �������ش�.

	auto a = 10;
	auto b = 0.1f;
	auto c = 'c';
	auto d = "hello";

	std::cout << a << "," << b << "," << c << "," << d << std::endl;

	std::cout << "Item Class ��� ����" << std::endl;

	Container<Item> inventory(10);
	
	Item item1(12.345f, 1);
	Item item2(32.167f, 2);

	inventory.push_back(item1);
	inventory.push_back(item2);

	auto itemIt = inventory.begin();

	// iterator for �ݺ���
	std::cout << "Item Iterator�� �̿��� �ݺ���" << std::endl;
	for (itemIt; itemIt != inventory.end(); itemIt++)
	{
		(*itemIt).Print();
	}
}


