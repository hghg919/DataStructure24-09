#pragma once
#include <iostream>
#include <set>

// set �ڷᱸ���� Ư¡
// Red-blackƮ���� �����Ǿ� �ִ�.
// ���ĵǾ� �ִ� �ڷᱸ��.
// �ߺ��� ������� �ʴ´�.

// balanced BST ���ǰ� �ִ� set�� ����Ͽ���. 
// Ž��,����,���� log n
// data ������ ũ�� �񱳸� �ؾ��ϴµ�, ��� �� ���ΰ�? ���α׷��Ӱ� ���� ���踦 ������մϴ�.
// string char* 
// apple > banana 
//  1 >  5

// Ÿ���� �ΰ� ����ϴ� Ŭ������ ������.

template<typename T1, typename T2>
struct MyPair
{
	T1 first;  // key
	T2 second; // value

	MyPair() : first(), second() {}
	MyPair(const T1& x, const T2& y) : first(x), second(y) {}

	const T1& GetFirst() { return first; }
	const T2& GetSecond() { return second; }

};

class SomeData
{
private:
	int count;
	float time;
public:
	SomeData(int Count, int Time) : count(Count), time(Time) {}

	void Print()
	{
		std::cout << count << ", " << time << std::endl;
	}
};



void SetExample()
{
	std::set<int> mySet;

	mySet.emplace(1);
	mySet.emplace(-1000);
	mySet.emplace(10);
	mySet.emplace(15);
	mySet.emplace(1000);
	mySet.emplace(25);

	for (const int num : mySet)
	{
		std::cout << num << " ";
	}

	std::set<SomeData*> set2;

	// �տ� ���� count�� ������ �񱳸� �� ��, 

	set2.insert(new SomeData(1, 0.5f));
	set2.insert(new SomeData(2, 1.5f));
	set2.insert(new SomeData(4, 0.8f));


	std::cout << "pair ����" << std::endl;

	MyPair<int, SomeData*> mp1(1, new SomeData(1, 0.5f));
	MyPair<int, SomeData*> mp2(2, new SomeData(2, 1.5f));
	MyPair<int, SomeData*> mp3(4, new SomeData(4, 0.8f));

	std::cout << "No" << mp1.GetFirst() << std::endl;
	mp1.GetSecond()->Print();

	std::cout << "��Ƽ �� ����" << std::endl;

	std::multiset<int> myMultiSet;

	myMultiSet.emplace(1);
	myMultiSet.emplace(-1000);
	myMultiSet.emplace(10);
	myMultiSet.emplace(15);
	myMultiSet.emplace(1000);
	myMultiSet.emplace(25);
	myMultiSet.emplace(25);
	myMultiSet.emplace(25);
	myMultiSet.emplace(25);


	for (const int num : myMultiSet)
	{
		std::cout << num << " ";
	}
}

