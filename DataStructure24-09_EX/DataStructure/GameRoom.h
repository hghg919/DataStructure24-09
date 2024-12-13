#pragma once

#include <iostream>
#include <string>
#include <vector>

// �н� ��ǥ : [Room - User System] �ڷᱸ���� ����ؼ� Ŭ������ ����ڴ�.
// 1. List<����� ������ Ŭ����> iList; <<- �ڷᱸ���� ���ο� Ŭ���� Ÿ���� �����Ѵ�.
// 2. class GameRoom{ private: vector m_Vector;}

// �濡 ���� ������ ����
// (private) �ʵ� : name : std::string, id: int , level: int
// (public)  ��� : getName(), getid(), getLevel(), GetUserInfo()     

// GameRoom ������ �����ϴ� Ŭ����
// UserInfo - �迭, �����迭, ������ ����Ʈ�� ����
// addPlayer, deletePlayer, showPlayerList, BanPlayer(�߰� ����),  isEmpty, isFull

class UserInfo
{
private:
	std::string name;
	int id;
	int level;
public:
	UserInfo(){}
	UserInfo(std::string name, int id, int level) : name(name), id(id), level(level) {}

	void GetName() 
	{
		std::cout << "���� �̸� : " << name << std::endl;
	}
	void GetId() 
	{
		std::cout << "���� ���̵� : " << id << std::endl;
	}
	void GetLevel() 
	{
		std::cout << "���� ���� : " << level << std::endl;
	}
	void ShowUserInfo()
	{
		GetName();
		GetId();
		GetLevel();
	}
};


// ������ ����Ʈ vs ���� �迭
// GameRoom - User.
// �߰� ����,����	- UserInfo
// ���� ����

class GameRoom
{
	// UserInfo �����ϴ� �ڷᱸ��... �迭, �����迭, ������ ����Ʈ
	// �迭�� userInfo�� ǥ������ �� ������
	// 6�θ��. 12�θ��.. <- ������ �����Ŷ�� Ȯ��
	// �迭�� �������� �ʴ�.

	// ���� �迭 std::vector

private:
	std::vector<UserInfo> users;  
	int maxCount;        // �� �ִ� �ο���
	int userCount;		 // ���� �� �ο���

public:

	// ������

	GameRoom(int max = 8)
	{
		maxCount = max;
		userCount = 0;
	}

	// ���
	void AddPlayer(UserInfo& user)
	{
		// vector<UserInfo>  pushback  
		// if - bool IsFull - ���� ���� á�� ��
		if (!IsFull())
		{		
			users.push_back(user);
			userCount++;
		}
		else
		{
			std::cout << "���� ����á���ϴ�." << std::endl;
		}
	}

	// BanPlayer
	
	void BanPlayer(int Order)  // 0 ~ 7 ����..   order 2 -> 3��° users[2] ����
	{
		if (0 <= Order <= users.size())
		{
			users[Order].GetName();
			std::cout << "��(��) �߹��߽��ϴ�." << std::endl;

			users.erase(users.begin() + Order);
			
			userCount--;

		}
		else
		{
			std::cout << "�ε����� ��ȿ���� �ʽ��ϴ�." << std::endl;
		}
	}

	// ShowListPlayer
	void ShowListplayer()
	{
		if (IsEmpty())
		{
			std::cout << "�濡 ����� �����ϴ�." << std::endl;
			return;
		}

		// ���� ���� ~ ������ ����
		for (int i = 0; i < userCount; i++)
		{
			users[i].ShowUserInfo();
		}
	}

	// IsEmpty
	
	bool IsEmpty()
	{
		return userCount <= 0 ? true : false;   //  userCount?   true , false
	}

	// IsFull
	bool IsFull()
	{
		return userCount >= maxCount ? true : false; // userCount >= maxCount ������(true) : false
	}

	void IsClear()   // ���� �������� �Լ�
	{
		while (!IsEmpty())
		{
			users.pop_back();  // ������ ���� �ϳ��� �����ش�.
			userCount--;
		}
	}

	void IsClear2()
	{
		users.erase(users.begin(), users.end());
		userCount = 0;
	}
};



void IGameRoomExample()
{
	std::cout << "GameRoom ���� �Դϴ�." << std::endl;

	// ������ ���� 3���� �����غ���.
	// ���� 1 : A�̸�, �ڵ� 1000, ���� 10
	UserInfo user1("A", 1000, 10);
	//user1.ShowUserInfo();
	// ���� 2 : B,   �ڵ� ..., ���� ..
	UserInfo user2("B", 1001, 5);
	//user2.ShowUserInfo();
	// ���� 3 : C, �ڵ�  ,  ���� ...
	UserInfo user3("C", 1005, 15);
	//user3.ShowUserInfo();

	GameRoom room(3);
	room.AddPlayer(user1);
	room.AddPlayer(user2);
	room.AddPlayer(user3);
	room.BanPlayer(1);
	room.ShowListplayer();

	room.IsClear();
	room.ShowListplayer();


}