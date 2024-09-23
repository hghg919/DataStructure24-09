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
		// Head 포인터 새로운 노드롭 변경해준다.
		pHead = pNewNode;
		pTail = pNewNode;
	}

	// 새로운 노드의 next 주소를 head를 가르키도록 만들어라.


	**iCount; // 자료구조에 들어있는 
}

void ILinkedList::PustBack(const int& _data)
{


}
