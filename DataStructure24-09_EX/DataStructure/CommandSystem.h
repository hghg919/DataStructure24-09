#pragma once

#include <iostream>
#include <queue>
#include <string>


class Command
{
protected:
	std::string Key; // 키 : Command 명령어를 저장을 할겁니다.

public:
	Command(std::string key) : Key(key) {}     // 커맨드 클래스의 생성자 - 키를 초기화
	virtual ~Command() = default;              // 가상 소멸자 : 부모 클래스가 가장 마지막에 소멸되도록 해주는 문법
	virtual std::string execute() const = 0;   // 모든 커맨드의 실행 기능
	std::string GetKey() { return Key; }
};

class FireBall : public Command
{
public:
	FireBall(std::string key) : Command(key) {}
	std::string execute() const override
	{
		return "파이어볼 시전!";
	}		 
};

//   class 이름 Command 
class IceBall : public Command
{
public:
	IceBall(std::string key) : Command(key) {}
	std::string execute() const override
	{
		return "아이스볼 시전!";
	}
};


template <typename T>
class CiruclarQueue
{
private:
	T* arr;	       // T 타입의 배열 이름
	int iCount;	   // 현재 원소의 수
	int iMaxCount; // 최대 저장 가능한 수
	int front;	   // front index
	int rear;      // rear index
public:
	CiruclarQueue(int size = 4)	   // 생성자
	{
		iMaxCount = size;
		arr = new T[size];
		iCount = 0;
		front = 0;
		rear = 0;
	}
	// 접근자 Accessor ( T Front.. Rear.. Size..)
	T Front() {	return arr[front];}    
	T Rear()  { return arr[rear]; }
	int Size() { return iCount; }
	// Helper Method	( Empty.. Full..)
	bool IsEmpty()
	{
		return rear == front ? true : false;
	}
	 
	bool IsFull()
	{
		return (rear + 1) % iMaxCount == front ? true : false;
	}

	// Main   Method	( Push, Pop..)   enqueue dequeue

	void push(T data)
	{
		if (IsFull())
		{
			std::cout << "원형 큐가 가득찼습니다." << std::endl;
			return;
		}
		else
		{
			arr[rear] = data;
			rear = (rear + 1) % iMaxCount; // rear++
			iCount++;
		}
	}

	void pop()
	{
		if (IsEmpty())
		{
			std::cout << "원형 큐가 비었습니다." << std::endl;
			return;
		}
		else
		{
			front = (front + 1) % iMaxCount;
			iCount--;
		}
	}

};


/// <summary>
/// Command를 사용해서 특별한 동작을 실행하는 클래스
/// </summary>
class CommandSystem
{
private:
	// 자료구조 Command들을 가장 효율적으로 저장할 수 있는 것이 무엇일지 생각해보세요.
	std::vector<Command*> Commands;  // 특별한 이유가 없으면 vector가 효율적이다. (원소 수가 적으면 적을 수록) 
	CiruclarQueue<std::string> inputs;	 // 유저가 보낸 신호를 순서대로 저장을 해야 하는 데이터

public:

	void addCommand(Command* command)
	{
		Commands.push_back(command);       
	}

	void addInput(const std::string& input)
	{
		// 최대 갯수  

		if (inputs.Size() < 3)
		{
			// 예외처리는 구현이 안되어 있다.
			inputs.push(input);
		}
		
		if (inputs.Size() == 3)
		{
			ProcessCommand(); // 커맨드를 실행한다.
			ClearQueue();     // 큐를 비워준다.
		}

	}

	void ProcessCommand()
	{
		std::string userCommand = "";
		// 유저가 입력한 순서대로 커맨드가 실행되어야 한다.

		while (!inputs.IsEmpty())	  // 큐가 0이 될 때까지 실행한다.
		{
			userCommand += inputs.Front();
			inputs.pop();
		}
	
		// 커맨드의 Key와 userCommand 비교 값이 일치하는 게 있다.
		
		for (int i = 0; i < Commands.size(); i++)
		{
			if (userCommand == Commands[i]->GetKey())
			{
				std::cout << Commands[i]->execute() << std::endl;
				return;
			}
		}

		std::cout << "일치하는 커맨드가 없습니다." << std::endl;

	}

	void ClearQueue()
	{
		while (!inputs.IsEmpty())
		{
			inputs.pop();
		}
	}

	void ShowCommandList()
	{
		std::cout << "=== 커맨드 목록 ===" << std::endl;
		std::cout << "FireBall 커맨드 : " << "ABC" << std::endl;
		std::cout << "IceBall 커맨드	: " << "DEF" << std::endl;
		std::cout << "=== ========== === " << std::endl;
	}

	void ShowPlayerInput()
	{
		std::cout << "현재 입력 값 : [ ";
		CiruclarQueue<std::string> temp = inputs;

		while (!temp.IsEmpty())	  // 큐가 0이 될 때까지 실행한다.
		{
			std::cout << temp.Front() << " ";
			temp.pop();
		}

		std::cout << "]" << std::endl;
	}
};

// CommandSystemExample 호출 함수
void CommandSystemExample()
{
	CommandSystem manager;

	FireBall command1("ABC");
	IceBall command2("DEF");

	manager.addCommand(&command1);
	manager.addCommand(&command2);

	std::string input;

	while (true)
	{
		manager.ShowCommandList();
		manager.ShowPlayerInput();

		std::cin >> input;
		manager.addInput(input);

		if (input == "Q")
		{
			std::cout << "시스템 종료 " << std::endl;
			break;
		}
	}	
}