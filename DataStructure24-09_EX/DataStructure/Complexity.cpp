#include "Complexity.h"

void Print()
{

}

void lecture1()
{
	// �ð� ���⵵�� �ܼ� ��� 1.

	// 1~n������ ���� ���ϱ� ���� �ذ� ��� - �ð� ���⵵�� �� �غ��Ҵ�.

	float s = 0.0f;		             // ���� 1��.
	for (int i = 0; i < 10; i++)	 // (�� 1��, ���� 1��, ���� ���� 1) * n(10)
	{
		s += i;
	}								// 3n + 1�� ����	  �ð� ���⵵ : O(n)
	std::cout << "0���� 10������ �� : " << s << std::endl;

	// n�� ������ ���� ũ�� �غ��ڽ��ϴ�. 1 ~ 1�� ����.  => 3�� + 1 ����

	// �ð� ���⵵�� �ܼ� ��� 1-2.		1 ~ n ���ϱ� : n(n+1)/2

	int sum = 0;
	int count = 10;
	sum = sum + 1;
	sum = sum / 2;
	sum = sum * count;		      // �ð� ���⵵ : 5 O(1);

	// �ð� ���⵵�� �Ի��ϱ� ���� ��� : ��� ���� 
	// Best Case  : �� ���ް� 
	// Worst Case : ��� ǥ���
	// ��� Case  : �� ��Ÿ

	// ��� ǥ����� Ư¡ 
	// 1. ���� ū ����   n^3+n^2+n+1	   // 10�� x 10�� x 10��     
	// 2. ���� ����ϴ� ����� ����

	// (���� ����) O(1) < O(logn) < O(n) < O(nlogn) < O(n^2) < O(n!)
	//  a�� ���ڸ� n�� ���ؼ�  =  x     a^n = x	    n = 1ogaX;
	//  Ư�� ���� n�� �������� �� ���� 1�� �Ǵ��� ���Ѵ�.


}

void Example01()
{
    // 1. �ð� ���⵵�� ���� ������� ��� ǥ��� ����غ�����.
	// ��� ���´� O(��ȣ)�� ���߾  O(a) < O(b) <.... O(N!)

	// 2. �Ʒ��� �ڵ��� �ð� ���⵵�� ���� ���⵵�� ����ؼ� std::cout ����غ�����
	// �ð� ���⵵ : O()
	// ���� ���⵵ : O()

	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; i++)
		{
			sum += sum + j;
		}
	}

}

// ���� ���⵵ ����
float abc(float a, float b, float c)
{
	return(a + b + b * c + (a + b - c) / (a + b) + 4.0);

	// ���� ���⵵ : 0(���� �ذ�� ���� ������� �޸� ����)
}

float Sum(float a[], int n)
{
	float result = 0.0f;
	for (int i = 0; i <= n; i++)
	{
		result += a[i];
	}
	return result;			 // a[] - n, n(1), r(1), i(1) => n+3
}

// C�� ó�� ������ ��..  �ֱ� �ϵ��� �ſ� �ߴ��� �߽��ϴ�.
// NASA ���ֺ���� (embeded)	- 

