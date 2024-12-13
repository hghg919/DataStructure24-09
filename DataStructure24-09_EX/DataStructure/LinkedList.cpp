#include "LinkedList.h"

ILinkedList::ILinkedList()
{
}

ILinkedList::~ILinkedList()
{
}

void ILinkedList::PushFront(const int& _data)
{
	IntNode* pNewNode = new IntNode;
	pNewNode->value = _data;

	if (nullptr == pHead) // Head�� ����Ű�� �ִ� ������ null ����ִ� �ڷᱸ��.
	{
		// Head �����͸� ���ο� ���� �������ش�.
		pHead = pNewNode;
		pTail = pNewNode;
	}

	pNewNode->pNext = pHead;  // ���ο� ����� next �ּҸ� head�� ����Ű���� ������.
	pHead = pNewNode;         // ���� head�� ���ο� ���� �����ض�

	++iCount; // �ڷᱸ���� ����ִ� �������� �� ����
}

void ILinkedList::PushBack(const int& _data)
{
	IntNode* pNewNode = new IntNode;
	pNewNode->value = _data;

	// �����Ͱ� ó�� �� �� ����
	if (nullptr == pHead)
	{
		pHead = pNewNode;
		pTail = pNewNode;
	}

	// ���� tail�� ���� �ּҿ� ��带 �����ϴ� �ڵ� 

	pTail->pNext = pNewNode;      //  ������ ���� �����Ͱ� ���ο� ��尡 �ȴ�.
	pTail = pNewNode;			  //  ������ �����Ͱ� ���ο� ��尡 �ȴ�.
	++iCount;
}

void ILinkedList::RemoveFront()
{

	if (nullptr == pHead)  // bool IsEmpty()
	{
		std::cout << "�����Ͱ� �����ϴ�. ������ ����մϴ�." << std::endl;
		return;
	}

	IntNode* pOldNode = pHead;          // pHead �ӽ� �����͸� �������ش�.

	if (nullptr == pOldNode->pNext)
	{
		pHead = nullptr;
		pTail = nullptr;
	}
	else
	{
		pHead = pOldNode->pNext;            // pHead->pNext : head�� �����.
		                                    // tail�� ã�Ƽ� �Ҵ����ִ� �ڵ� (while... node->pNext == nullPtr) : tail
	}
	delete pOldNode;	                // oldNode �޸𸮸� �������ش�.

	iCount--;
}

void ILinkedList::RemoveBack()
{
	if (nullptr == pHead)
	{
		std::cout << "�����Ͱ� �����ϴ�. ������ ����մϴ�." << std::endl;
		return;
	}

    // iCount�� �̿��ؼ� ������ �� �ִ�.

}

void ILinkedList::FrontValue()
{
	std::cout << "���� �ڷᱸ���� �� ���� : " << iCount << "," << "ù��° ������ �� ��� : " << pHead->value << std::endl;
}

void ILinkedList::TailValue()
{
	std::cout << "���� �ڷᱸ���� �� ���� : " << iCount << "," << "ù��° ������ �� ��� : " << pTail->value << std::endl;
}
