#include "lectures.h"
#include <iostream>
#include <list>
#include <string>

// 연결 리스트 - std::list template

// 게임 아이템. 삭제, 추가 - 인벤토리
// 배열 - 연결 리스트
// 장점 : 임의의 원소 접근이 빠르다.      <->    임의의 원소 접근이 불가능하다.
// 단점 : 데이터의 삭제 및 추가가 느리다.  <->    데이터 삭제 및 추가가 빠르다.

class Item
{
private:
    int itemCode;
    std::string name;
public:
    Item(int _itemCode, std::string _name) : itemCode(_itemCode), name(_name) {}

    void ShowInfo()
    {
        std::cout << "아이템 코드 : " << itemCode << std::endl;
        std::cout << "아이템 이름 : " << name << std::endl;
    }
};

template<typename T>
class Node
{
    T value;
    Node* next;
};

template<typename T>
class LinkedList
{

};

class Pos
{
private:
    int posX;
    int posY;
    char tag;
public:
    Pos(int x, int y, char v) : posX(x), posY(y), tag(v) {}
};

class Point
{
public:
    Pos data;
    Point* next;
    Point(Pos _data) : data(_data) {}
};

void lecture4()
{
    std::cout << "STL : 연결 리스트 사용" << std::endl;

    // 동적할당 : std::list<int>* iList = new std::list<int>();

    // std::list<int> iList; // 클래스 생성
    std::list<Item> inventory;

    // 데이터 앞에 저장 pushFront  -   push_front 
    // 데이터 뒤에 저장 pushBack   -   push_back
    // 앞에 데이터 삭제 removeFront -  pop_front
    // 뒤에 데이터 삭제 removeBack  -  pop_back

    Item* newItem = new Item(1001, "대검");
    Item* newItem2 = new Item(1002, "한손검");
    Item* newItem3 = new Item(1003, "해머");
    inventory.push_front(*newItem);
    inventory.push_back(*newItem2);
    inventory.push_back(*newItem3);
    
    std::list<Item>::iterator iPos = inventory.end();
  
    inventory.insert(iPos, 1, *newItem3);

    inventory.pop_back();

    // iterator : 포인터를 일반화시킨 클래스

    std::list<Item>::iterator iterEnd = inventory.end();

    for(std::list<Item>::iterator iterPos = inventory.begin(); iterPos != iterEnd; ++iterPos)
    {
        iterPos->ShowInfo();
    }




    // 클래스 구현

    // LinkedList.h - int,  DoubliyLinkedList.h - string 

    // LinkedList<int> iList1;
    // std::list<int> iList2;

    // DoubliyLinkedList dList1;
    // std::list<string> dList2;


    // 예제 문제

    // 도형을 클래스로 정의를 합니다.
    // A(50,200) B(20, 80) C(75, 10) D(130,80) E(100,200)
    // class Pos{ posX, posY}
    // Pos value로 갖는, node를 재정의

    Pos A = Pos(50, 200, 'A');
    Pos B = Pos(50, 200, 'B');
    Pos C = Pos(50, 200, 'C');
    Pos D = Pos(50, 200, 'D');
    Pos E = Pos(50, 200, 'E');

    // (1)
    std::list<Pos> Star;

    Star.push_back(A);
    Star.push_back(B);
    Star.push_back(C);
    Star.push_back(D);
    Star.push_back(E);
  
    // (2)

    Point A_P = Point(A);
    Point B_P = Point(B);
    Point C_P = Point(C);
    Point D_P = Point(D);
    Point E_P = Point(E);

    A_P.next = &B_P;
    B_P.next = &C_P;

}

