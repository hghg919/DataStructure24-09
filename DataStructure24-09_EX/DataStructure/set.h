#pragma once
#include <iostream>
#include <set>

// set 자료구조의 특징
// Red-black트리로 구현되어 있다.
// 정렬되어 있는 자료구조.
// 중복을 허용하지 않는다.

// balanced BST 사용되고 있는 set을 사용하였다. 
// 탐색,삽입,삭제 log n
// data 사이의 크기 비교를 해야하는데, 어떻게 할 것인가? 프로그래머가 직접 설계를 해줘야합니다.
// string char* 
// apple > banana 
//  1 >  5

// 타입을 두개 사용하는 클래스를 만들자.

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

	// 앞에 오는 count를 가지고 비교를 할 때, 

	set2.insert(new SomeData(1, 0.5f));
	set2.insert(new SomeData(2, 1.5f));
	set2.insert(new SomeData(4, 0.8f));


	std::cout << "pair 예제" << std::endl;

	MyPair<int, SomeData*> mp1(1, new SomeData(1, 0.5f));
	MyPair<int, SomeData*> mp2(2, new SomeData(2, 1.5f));
	MyPair<int, SomeData*> mp3(4, new SomeData(4, 0.8f));

	std::cout << "No" << mp1.GetFirst() << std::endl;
	mp1.GetSecond()->Print();

	std::cout << "멀티 셋 예제" << std::endl;

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

