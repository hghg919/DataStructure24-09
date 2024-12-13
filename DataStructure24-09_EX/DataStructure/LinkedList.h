#pragma once

#include <iostream>
#include <string>


// �ڷ� ���� : �����͸� �� ����ϱ� ���ؼ� �����ϴ� ����
// �迭 : �����͸� �����غ���.
// �ð� ���⵵(��� ǥ���) : ���� �ӵ��� ���� ���� ������ ������.
// ���� ���⵵(��� ǥ���) :	ũ�Ⱑ ���� ���� �޸� ������ ���� ���´�.

// �˰�����
// 1. �������� ���� (Insert) <-> ����
// 2. 1�� ���� n�� ���(��ȸ)	����ȸ
// 3. ������ ���� 
// 4. ������ Ž��

// �迭
// ���� : ������ ���� �� ���� : O(n) - �������� ũ�Ⱑ ũ�� Ŭ���� �ð��� �����ɸ���.
// ���� : �迭�� ���� �ִ� ������ �����ϴ� �ð��� ª��. arr[100000] O(1)	

// ���� ����Ʈ
// ���� : ������ ���� �� ���� : O(1) - ���� �� ������ �ð��� ������.
// ���� : ������ ���ҿ� �����ϴ� �ð��� ���. O(n)

// ���� ���� ����Ʈ : ���� + ���� + ����Ʈ = �ڷᱸ��.
// �߻� ������ ����(ADT)
// 1. �����Ϳ� ��ũ(������) ������ �̷���� �ִ� ��带 ���Ҹ��� �����Ѵ�.  => ����� ��ü�� ��������
// 2. ���� ����Ʈ ��ü�� ù��° ��带 head �̸����� ���´�. ������ ��带 tail �̸����� ���´�. => tList{ head, tail} 
// 3. ������ ���� �����̾�� �Ѵ�.

// ������ �����ϴ� ���� ���� ����Ʈ

// ������ ���� �����ϴ� ���

struct IntNode
{
	int value;      // ��尡 �����ϰ� �ִ� ������ ��
	IntNode* pNext; //	���� ����� �ּҸ� �����ϴ� ������
};

// ��带 �ʵ�� ���� ���� ���� ����Ʈ��� �̸��� ��ü

class ILinkedList
{
private:
	IntNode* pHead;     // ����� ù��°�� �����Ѵ�.	   
	IntNode* pTail;     // ����� �������� �����Ѵ�.
	int iCount;         // ����� �� ����


public:
	ILinkedList();  // ������ 
	~ILinkedList(); // �Ҹ���

	// Node�� �߰��Ѵ�.

	void PushFront(const int& _data);
	void PushBack(const int& _data);

	void RemoveFront();
	void RemoveBack();

	// �����͸� �����ִ� ���

	void FrontValue();
	void TailValue();
};