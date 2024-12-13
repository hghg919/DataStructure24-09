#pragma once
// Game���� �ֱ� �α׾ƿ��� �ð��� ����ϴ� Ŭ������ ���� �����غ� ��
#include <stack>
#include <string>
#include <iostream>

class GameData
{
private:
	std::string iDate;   // "2024-09-23/16:00:00"
   
public:
	GameData(std::string _date) : iDate(_date) {}
	
	std::string GetDate() { return iDate; }

	void Print()
	{
		std::cout << "�α׾ƿ� �� �ð� : " << iDate << std::endl;
	}
};

class GameHistory
{
private:
	// �ڷᱸ�� : Ŭ���� ������ �� ���� �����ϰ� �����͸� ������ �� �ִ� ���� ���� ��.
    // Stack �ڷᱸ��
	std::stack<GameData> GameDatas; 

	// GameData*       m_Data;
	// int			   capacity
    // int			   top
	// pop , push, empty, isfull
public:
	void SaveLogoutTime(GameData time)
	{
		GameDatas.push(time);
	}

	void PrintLogoutTime()
	{
		GameData printData = GameDatas.top();
		printData.Print();
		GameDatas.pop();
	}
};

// GameData
// std::string iDate; "2024-09-23/16:57:00"
// Print() { "���� �α׾ƿ� �ð� : " << iDate  }

// class GameHistory 
// Stack<GameData>
// Pop, push 
// SaveLogoutTime(std::string �ð�)     push
// PrintLogoutTime()     pop

void iGameHistoryExample()
{
	// �α׾ƿ��� �̷�
	GameData data1("2024-09-20/17:00");
	GameData data2("2024-09-21/17:00");
	GameData data3("2024-09-22/17:00");
	GameData data4("2024-09-23/17:00");

	// Ư�� ������ �α׾ƿ��� �ð��� ����� �� �ִ� ���

	GameHistory GameDatas;
	GameDatas.SaveLogoutTime(data1);
	GameDatas.SaveLogoutTime(data2);
	GameDatas.SaveLogoutTime(data3);
	GameDatas.SaveLogoutTime(data4);

	GameDatas.PrintLogoutTime();
	GameDatas.PrintLogoutTime();
	GameDatas.PrintLogoutTime();
	GameDatas.PrintLogoutTime();

}
