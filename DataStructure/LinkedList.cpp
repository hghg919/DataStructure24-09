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

	if (nullptr == pHead) // 
	{
		// Head ������ ���ο� ���� �������ش�.
		pHead = pNewNode;
		pTail = pNewNode;
	}

	// ���ο� ����� next �ּҸ� head�� ����Ű���� ������.


	**iCount; // �ڷᱸ���� ����ִ� 
}

void ILinkedList::PustBack(const int& _data)
{


}
