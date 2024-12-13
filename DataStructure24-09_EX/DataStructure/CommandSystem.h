#pragma once

#include <iostream>
#include <queue>
#include <string>


class Command
{
protected:
	std::string Key; // Ű : Command ��ɾ ������ �Ұ̴ϴ�.

public:
	Command(std::string key) : Key(key) {}     // Ŀ�ǵ� Ŭ������ ������ - Ű�� �ʱ�ȭ
	virtual ~Command() = default;              // ���� �Ҹ��� : �θ� Ŭ������ ���� �������� �Ҹ�ǵ��� ���ִ� ����
	virtual std::string execute() const = 0;   // ��� Ŀ�ǵ��� ���� ���
	std::string GetKey() { return Key; }
};

class FireBall : public Command
{
public:
	FireBall(std::string key) : Command(key) {}
	std::string execute() const override
	{
		return "���̾ ����!";
	}		 
};

//   class �̸� Command 
class IceBall : public Command
{
public:
	IceBall(std::string key) : Command(key) {}
	std::string execute() const override
	{
		return "���̽��� ����!";
	}
};


template <typename T>
class CiruclarQueue
{
private:
	T* arr;	       // T Ÿ���� �迭 �̸�
	int iCount;	   // ���� ������ ��
	int iMaxCount; // �ִ� ���� ������ ��
	int front;	   // front index
	int rear;      // rear index
public:
	CiruclarQueue(int size = 4)	   // ������
	{
		iMaxCount = size;
		arr = new T[size];
		iCount = 0;
		front = 0;
		rear = 0;
	}
	// ������ Accessor ( T Front.. Rear.. Size..)
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
			std::cout << "���� ť�� ����á���ϴ�." << std::endl;
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
			std::cout << "���� ť�� ������ϴ�." << std::endl;
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
/// Command�� ����ؼ� Ư���� ������ �����ϴ� Ŭ����
/// </summary>
class CommandSystem
{
private:
	// �ڷᱸ�� Command���� ���� ȿ�������� ������ �� �ִ� ���� �������� �����غ�����.
	std::vector<Command*> Commands;  // Ư���� ������ ������ vector�� ȿ�����̴�. (���� ���� ������ ���� ����) 
	CiruclarQueue<std::string> inputs;	 // ������ ���� ��ȣ�� ������� ������ �ؾ� �ϴ� ������

public:

	void addCommand(Command* command)
	{
		Commands.push_back(command);       
	}

	void addInput(const std::string& input)
	{
		// �ִ� ����  

		if (inputs.Size() < 3)
		{
			// ����ó���� ������ �ȵǾ� �ִ�.
			inputs.push(input);
		}
		
		if (inputs.Size() == 3)
		{
			ProcessCommand(); // Ŀ�ǵ带 �����Ѵ�.
			ClearQueue();     // ť�� ����ش�.
		}

	}

	void ProcessCommand()
	{
		std::string userCommand = "";
		// ������ �Է��� ������� Ŀ�ǵ尡 ����Ǿ�� �Ѵ�.

		while (!inputs.IsEmpty())	  // ť�� 0�� �� ������ �����Ѵ�.
		{
			userCommand += inputs.Front();
			inputs.pop();
		}
	
		// Ŀ�ǵ��� Key�� userCommand �� ���� ��ġ�ϴ� �� �ִ�.
		
		for (int i = 0; i < Commands.size(); i++)
		{
			if (userCommand == Commands[i]->GetKey())
			{
				std::cout << Commands[i]->execute() << std::endl;
				return;
			}
		}

		std::cout << "��ġ�ϴ� Ŀ�ǵ尡 �����ϴ�." << std::endl;

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
		std::cout << "=== Ŀ�ǵ� ��� ===" << std::endl;
		std::cout << "FireBall Ŀ�ǵ� : " << "ABC" << std::endl;
		std::cout << "IceBall Ŀ�ǵ�	: " << "DEF" << std::endl;
		std::cout << "=== ========== === " << std::endl;
	}

	void ShowPlayerInput()
	{
		std::cout << "���� �Է� �� : [ ";
		CiruclarQueue<std::string> temp = inputs;

		while (!temp.IsEmpty())	  // ť�� 0�� �� ������ �����Ѵ�.
		{
			std::cout << temp.Front() << " ";
			temp.pop();
		}

		std::cout << "]" << std::endl;
	}
};

// CommandSystemExample ȣ�� �Լ�
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
			std::cout << "�ý��� ���� " << std::endl;
			break;
		}
	}	
}