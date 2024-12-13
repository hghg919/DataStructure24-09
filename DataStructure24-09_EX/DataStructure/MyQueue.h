#pragma once
#include <iostream>
#include <queue>

/*
*    �ڷᱸ�� : �����̳ʸ� �����ؼ� ������ ���صΰ� ����ϴ� ��� �ڷᱸ���Դϴ�.
*    �ڷᱸ���� �����͸� ������ �� ���� �� �ڷᰡ ���� ������ ������ �ڷᱸ��. 
*	 ����) ���ǥ�� ����� �մϴ�. ������� ���� ���ϴ�. ���� �»�� ���� ó���Ѵ�. ���� �������� �� ����� ���� �������� ���� �����Ѵ�.
* 
*	 ť �ڷᱸ�� ����.
*	 - �����Ͱ� ��µǴ� �ε����� front�̸����� ǥ��
*    - �����Ͱ� ����Ǵ� �ε����� rear �̸����� ǥ��
*    - ���� ť front rear �ʱⰪ���� �ǵ��ư� �� ����.
*/

// �����ؾ��� �Լ�
// �Է� �� ���� : push, pop 
// �ʵ� �� ǥ�� : empty(), size(), front(), back() 



template <typename T>
class ArrayBasedQueue
{
private:
	T* queue;      // �����͸� �����ϱ� ���� �迭 �̸�
	int front;	   // ��� ��ġ�� ����Ű�� �ε���
	int rear;	   // ������ �Է� ��ġ�� ����Ű�� �ε���
	int iCount;	   // ���� �ڷᱸ���� ������ ����

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

public:
	using iterator = Iterator;
	iterator begin() { return iterator(queue); }
	iterator end() { return begin() + iCount; }


public:
	// ������ & �Ҹ���
	ArrayBasedQueue(int size = 10)
	{
		queue	= new T[size];
		front	= 0;
		rear	= 0;
		iCount	= 0;
	}
	~ArrayBasedQueue()
	{
		delete[] queue;
	}
	// Accesor : �ʵ忡 ������ ���� �Լ�
	
	int Size()
	{
		return iCount;
	}

	int Front()
	{
		return queue[front];
	}

	int Back()
	{
		return queue[rear - 1];
	}

	bool Empty()
	{
		return (iCount == 0) ? true : false;
	}


	// Main Method : ����, ����
	void Push(T data)
	{
		queue[rear] = data;          // queue �迭 data ����
		rear++;				         // rear �����Ų��.
		iCount++;          // ������ ���������ش�.
	}

	void Pop()
	{
		if (iCount != 0)                 // queue ������� �ʾ��� ��
		{
			front++;					 // queue �迭 front ��������ش�.
			iCount--;					 // ������ ���ҽ����ش�.
		}
		else
		{
			std::cout << "ť�� ������ϴ�." << std::endl;
		}
	}

	void Print()
	{
		std::cout << "Front Index : " << front << std::endl;
		std::cout << "Rear Index : " << rear << std::endl;
		std::cout << "Queue Count : " << iCount << std::endl;
	}
};


template <typename T>
class LinkedQueue
{
private:
	struct QueueNode
	{
		T data;
		QueueNode* pNext;

		QueueNode(T _data, QueueNode* pNode)
		{
			data = _data;
			pNext = pNode;
		}
	};

	QueueNode*	front;
	QueueNode*	rear;
	int			iCount;

public:
	// ������ & �Ҹ���
	LinkedQueue()
	{
		front	= nullptr;
		rear	= nullptr;
		iCount	= 0;
	}
	~LinkedQueue() {}
	// Accessor

	T Front() { return front->data;}

	T Back() { return rear->data; }

	int Size()
	{
		return iCount;
	}

	bool Empty()
	{
		return iCount == 0 ? true : false;
	}

	// Main Method (�Է�, ����)

	void Push(T data)
	{
		QueueNode* newNode = new QueueNode(data, nullptr);
		//QueueNode* newNode = new QueueNode;		// newNode �����Ҵ�
		//newNode->data = data;
		//newNode->pNext = nullptr;
		if (Empty())
		{
			front	= newNode;
			rear	= newNode;
		}
		else
		{
			rear->pNext = newNode;   // ������ �������� ���� �����Ϳ� ���� �Ҵ��� ��带 �־��ش�. 
			rear = newNode;			 //	���ο� ��带 rear�� ���������ش�.
		}
		iCount++;
	}

	void Pop()
	{
		if (Empty())
		{
			std::cout << "ť�� ������ϴ�." << std::endl;
			return;
		}
		
		QueueNode* oldNode = front;    // ������ ��带 �����Ѵ�.
		front = front->pNext;		   // ������ front����� ���� ��带 front�� �����Ѵ�.
		delete oldNode;
		iCount--;
	}	

};


void IQueueExample()
{
	std::queue<int> m_q;

	// ť�� �̿��ؼ� 1,2,3,4,5 ������� �����͸� �ܼ�â�� ����غ�����.

	m_q.push(1);
	m_q.push(2);
	m_q.push(3);
	m_q.push(4);
	m_q.push(5);

	std::cout << m_q.front() << std::endl;
	m_q.pop();
	std::cout << m_q.front() << std::endl;
	m_q.pop();
	std::cout << m_q.front() << std::endl;
	m_q.pop();
	std::cout << m_q.front() << std::endl;
	m_q.pop();
	std::cout << m_q.front() << std::endl;
	m_q.pop();



	// �迭 ��� ť ����
	ArrayBasedQueue<int> myQueue;
	myQueue.Push(1);
	myQueue.Push(2);
	myQueue.Push(3);
	myQueue.Push(4);
	myQueue.Push(5);

	// iterator�� �ݺ��� ����ϱ�

	std::cout << "iterator �ݺ��� ����" << std::endl;

	auto queueIt = myQueue.begin();

	for (queueIt; queueIt != myQueue.end(); queueIt++)
	{
		std::cout << *queueIt << std::endl;
	}


	std::cout << myQueue.Front() << std::endl;
	myQueue.Pop();
	std::cout << myQueue.Front() << std::endl;
	myQueue.Pop();
	std::cout << myQueue.Front() << std::endl;
	myQueue.Pop();
	std::cout << myQueue.Front() << std::endl;
	myQueue.Pop();
	myQueue.Print();                                  // Alt + Ű���� (�� ��) Ű �Է�
	std::cout << myQueue.Front() << std::endl;
	myQueue.Pop();

	//           linkedQueue;

	LinkedQueue<int> linkedQueue;
	linkedQueue.Push(1);
	linkedQueue.Push(2);
	linkedQueue.Push(3);
	linkedQueue.Push(4);
	linkedQueue.Push(5);

	std::cout << "Rear �����Ͱ� ����Ű�� �ִ� �� : " << linkedQueue.Back() << std::endl;
	std::cout << "Front �����Ͱ� ����Ű�� �ִ� �� : " << linkedQueue.Front() << std::endl;
	std::cout << "Queue�� �� �� : " << linkedQueue.Size() << std::endl;

	std::cout << linkedQueue.Front() << std::endl;
	linkedQueue.Pop();
	std::cout << linkedQueue.Front() << std::endl;
	linkedQueue.Pop();
	std::cout << linkedQueue.Front() << std::endl;
	linkedQueue.Pop();
	std::cout << linkedQueue.Front() << std::endl;
	linkedQueue.Pop();
	std::cout << linkedQueue.Front() << std::endl;
	linkedQueue.Pop();

}

/// <summary>
/// ���� ť�� ���� ť�� ������ �����ϱ� ���� ������ �ڷᱸ���Դϴ�.
/// ���� ť�� Front, Rear�� ��Ȱ���ϱ� �����.
/// Pop(Dequeue)  : Front = (Front + 1) % �ִ� ��
/// Push(Enqueue) : Rear  = (Rear  + 1)	% �ִ� ��
/// 
/// ���� : Front, rear ���� ������ �ɸ� �� �ִ�, ���۰� ���� �ľ��ϱ� ��ƴ�.
/// 
/// ���� ����ϸ� ������? ť�� �ݺ��ؼ� ����ؾ� �ϴµ�, �� ������ ���� ���� �� ����ϸ� ����.
/// </summary>


//  1. ���� ť�� ���� :  Front, Rear�� ��� �����ϰ�, ��Ȱ���� �����. 
//  �̸� �����ϱ� ���� ���� ť�� ����� �� �� �ִ�.

//  2. ť�� ��� ���� : �Է¹��� ������� �����͸� ������ �� �ִ�. (Ŀ�ǵ带 ���� == ����)


//  �÷��̾��� Ŀ�ǵ带 ����ϴ� ����� �����غ�����.
// 
//  class�� ��� ����  command ����ؼ� ������ �غ��̴ϴ�.
//  == draw.io ���̾�׷� ==
// 
//  std::in << input;
//  std::<queue> inputs ���� 
//  std::<queue>temp
//  temp.front(). pop()   
//  [            ]
