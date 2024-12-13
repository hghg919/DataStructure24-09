#pragma once

#include <map>
#include <iostream>
#include <string>

// �л� Ŭ����
// �ε��� . 

using namespace std;

class student
{
private:
	std::string name;
	int score;

public:
	student() {}
	student(std::string Name, int Score) : name(Name), score(Score) {}

	std::string GetName() const { return name; }
	int GetScore() const { return score; }
};

// map

// player ���̵�,  �̸�

void mapExample()
{
	std::pair<int, student*> myPair;

	std::map<int, student*> myMap;

	// map�� �����͸� �Է��ϴ� ���

	myMap.insert(make_pair(2, new student("BBB", 200)));
	myMap.insert(make_pair(2, new student("BBB", 400)));
	myMap.emplace(make_pair(1, new student("AAA", 100)));


	myMap.insert({ 4, new student("CCC", 300) });

	myMap.insert(pair<int, student*>(5, new student("DDD", 400)));

	// begin, end

	for (auto i = myMap.begin(); i != myMap.end(); i++)
	{
		std::cout << i->first << "," << i->second->GetName() << "," << i->second->GetScore() << std::endl;
	}



	// class player

	// std::map  �̸� myDB;


}
