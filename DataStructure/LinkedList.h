#pragma once

#include <iostream>

// 자료 구조 : 데이터를 잘 사용하기 위해서 선택하는 도구
// 배열 : 데이터를 정리해본다.
// 시간 복잡도(빅오 표기법) : 연산 속도가 적을 수록 실행이 빠르다
// 공간 복잡도(빅오 표기법) : 크기가 적을 수록 메모리 공간이 많이 남는다.
// 
// 알고리즘
// 1. 데이터의 저장 (insert) <-> 삭제
// 2. 1번 부터 n번 출력(순회) 역순회
// 3. 데이터 정렬
// 4. 데이터 탐색
// 
// 배열
// 단점 : 데이터 삭제 및 저장 : O(n) - 데이터의 크기가 크면 클수록 시간이 오래 걸린다.
// 장점 : 배열에 속해 있는 원소의 접근하는 시간이 짧다. arr[100000] O(1)

struct IntNode
{
	int value; // 노드가 저장하고 있는 정수형 값
	IntNode* pNext; // 다음 노드의 주소를 저장하는 포인터		
}; 

class ILinkedList
{
private:
	IntNode* pHead; // 노드의 첫번째를 저장한다.
	IntNode* pTail; // 노드의 마지막을 저장한다.
	int iCount;		// 노드의 총 갯수
public:
	ILinkedList(); // 생성자
	~ILinkedList(); // 소멸자

	// Node를 추가한다.

	void PushFront(const int& _data);
	void PustBack(const int& _data);
};