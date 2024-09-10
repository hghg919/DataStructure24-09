#include "Complexity.h"

void print()
{

}

void lecture1()
{
	// 시간 복잡도의 단순 계산 1.

	float s = 0.0f;
	for (int i = 0; i < 10; i++)
	{
		s += 1;
	}
	
	std::cout << "0부터 10까지의 합 : " << s << std::endl;

	// n의 범위를 크개

	// 시간 복잡도의 단순 게산 1-2

	int sum = 0;
	int count = 100;
	sum = sum + 1;
	sum = sum / 2;
	sum = sum * count; // 시간복잡도 : 5

	// 시간 복잡도를 계산 하기 위한 방법 : 빅오 계산법
	// 베스트 : 빅오메가
	// 워스트 : 빅오 표기법
	// 평균 :: 빅 세타

	// 빅오 표기법의 특징
	// 1. 가장 큰 차수 n^3+n^2+n+1 // 10억	
}
void Example01()
{
	// 1. 시간 복잡도를 빠른 순선대로 빅오 표기로 출력해보세요
}