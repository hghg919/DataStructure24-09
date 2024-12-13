#include "lectures.h"
#include "MyVector.h"
#include "RandomNumber.h"

// �н� ��ǥ : ���� �迭(Vector) - Array List

// ����(Vector)
// ���� ����ϴ� �ڷᱸ�� �� �ϳ��Դϴ�. Linked List, Array List(Vector)
// �迭�� Ư¡�� ��� ���´�.
// int arr[10];			
// ������ �����ε����� ����   [], ==, !=

// ���� ����Ʈ vs ���� �迭

//						   |�ڷᱸ���� ũ�� ���� ��� |  �߰� ����, ���� ��� | ���� ���� ��� | ���� ���� ��� 
// ���� ����Ʈ(Linked List) |  	        o  		    |		   o		   |      o		  |	       x 
// ���� �迭  (Vector)	   |			o			|		   X		   |	  o		  | 	   o
// �÷��̾��� �κ��丮 ->   ���� ����Ʈ ���� Inventory,  Vector Inventory

// ����    : ũ�� �߰� ���� ��ɰ� ���� ���� ������� �� �ڷᱸ���� �������� ���� �� �ִ�.
// �߰� ����, ������ ���ų� ���� �߻��ϴ� ��쿡��  Vector�� ����ϸ� ����.
// �߰� ����, ������ ���� �߻��ϴ� ��쿡�� ���� ����Ʈ�� ����ϸ� ����.

void lecture5()
{
	MyVector<float> i_Vec(20);
	
	MyVector<int> i_Vec2;

	MyVector<float> i_Vec3;

	if (i_Vec != i_Vec3)
	{
		std::cout << "������ �����ε��� ���������� ������!" << std::endl;
	}

	i_Vec.push_back(0.1f);
	i_Vec.push_back(0.2f);
	i_Vec.push_back(0.3f);
	i_Vec.Print();

	int r_index = R_Number(0, i_Vec.GetSize() - 1);
	std::cout << "i_Vec ���� ���ҿ� ���� : " << r_index + 1 << std::endl;

	std::cout << "���� �� : " << i_Vec[r_index] << std::endl;
	std::cout << "private ����� vec�� ���� ������ : " << i_Vec.GetVector()[0] << std::endl;

	i_Vec.pop_back();
	i_Vec.Print();

	// ������ ��������. 
	// Vector�� Ư¡. ������ ���ҿ� �����ϴ� �ð��� O(1);
	// Vector ���� ���ҿ� �����ϴ� ��� ����
	// int randomNumber = <<      srand(time(nullptr)); rand() % 100 + 1;    ���� seed	c++ <random>
}