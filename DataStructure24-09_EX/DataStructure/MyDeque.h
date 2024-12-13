#pragma once

#include <deque>
#include <vector>
#include <iostream>
/*
*  �н� ��ǥ : Deque�� ���� �����ϰ� �����Ѵ�.
* 
*    Vector�� Deque�� ���ؼ� ����
* 
*  Vector
* - ������ ���� ���� �ϴ� �ð� O(1)
* - �ڿ��� ���� ���Ҹ� ������ �� ȿ�����̴�.O(1)
* - �߰��� ���Ҹ� ���� ���� O(n)                   - Node��� �����ϸ� O(1)
* 
* Deque
* - ������ ���� ���� �ϴ� �ð� O(1)
* - �հ� �ڿ��� ���Ҹ� ������ �� ȿ�����̴�.O(1)
* - �߰��� ���Ҹ� ���� ���� O(n)                   - Node��� �����ϸ� O(1)
*/

// heap corruption..  index ã�� �� ����. -> new T[];

template <typename T>
class MyDeque
{
private:

	std::vector<T*> blocks;     // �� ����� �����ϴ� �ڷᱸ�� , �񿬼����� �޸� ���� ���

	int blockSize;              // ����� �ִ�� ������ �� �ִ� ũ��
	int frontIndex;             // ù��° ����� �ε���
	int backIndex;				// ������ ����� �ε���
	int iCount;					// ���� Deque ����� ������ ����

	void allocateBlock()   // ��� ���� �Լ�
	{
		blocks.push_back(new T[blockSize]);  //   new T(blockSize) -> vector<T*>blocks�� push_back
	}

	void addFrontBlock()   // ���� ��� �߰�
	{
		blocks.insert(blocks.begin(), new T[blockSize]);
		frontIndex = blockSize - 1;
	}

	void addBackBlock()	   // ���� ��� �߰�
	{
		blocks.push_back(new T[blockSize]);
		backIndex = 0;
	}

public:
	MyDeque(int blockSize = 4) : blockSize(blockSize), frontIndex(0), backIndex(0), iCount(0)     // ������ & �Ҹ���
	{
		allocateBlock();
	}

	~MyDeque()
	{
		// for(int i = 0; i, size; i++)

		for (T* block : blocks)
		{
			delete[] block;
		}
	}
	//	Accessor
	int getSize() const { return iCount; }
	
	bool isEmpty() const { return iCount == 0 ? true : false; }

	T& getFront() const
	{
		if (isEmpty())
		{
			throw std::out_of_range("���� �����");
		}
		return blocks[0][frontIndex];
	}

	T& getBack() const
	{
		if (isEmpty())
		{
			throw std::out_of_range("���� �����");
		}
		return blocks.back()[backIndex];
	}

    // Main Method

	void pushFront(const T& data) //      int, float, std::string
	{
		frontIndex--;
		if (frontIndex < 0)
		{
			addFrontBlock();
		}
		blocks[0][frontIndex] = data;
		++iCount;
	}

	void pushBack(const T& data)
	{
		backIndex++;
		if (backIndex == blockSize)
		{
			addBackBlock();
		}
		blocks.back()[backIndex] = data;
		++iCount;
	}

	void popFront()
	{
		if (isEmpty())
		{
			std::cout << "���� ������ϴ�." << std::endl;
			return;
		}
		++frontIndex;
		--iCount;
		
		if (frontIndex == blockSize)
		{
			delete[] blocks.front();
			blocks.erase(blocks.begin());
			frontIndex = 0;
		}
	}

	void popBack()
	{
		if (isEmpty())
		{
			std::cout << "���� ������ϴ�." << std::endl;
			return;
		}
		--backIndex;
		--iCount;

		if (backIndex < 0)
		{
			delete[] blocks.back();
			backIndex = blockSize - 1;
		}

	}
};

void IDequeExample()
{
	MyDeque<int> M_Deq;

	// main method

	M_Deq.pushBack(10);
	M_Deq.pushBack(20);
	M_Deq.pushBack(30);
	M_Deq.pushFront(5);
	M_Deq.pushFront(1);

	std::cout << "�Ӹ� : " << M_Deq.getFront() << std::endl;
	std::cout << "���� : " << M_Deq.getBack() << std::endl;

	M_Deq.popBack();
	M_Deq.popFront();

	std::cout << "�Ӹ� : " << M_Deq.getFront() << std::endl;
	std::cout << "���� : " << M_Deq.getBack() << std::endl;

}
