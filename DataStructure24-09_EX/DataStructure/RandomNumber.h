#pragma once

#include <iostream>
#include <cstdlib>    // rand(), srand()
#include <ctime>      // time()

#include <random>     // c++ �����ϴ� ���� ���̺귯��

int ReturnRandomNumber(int endNumber) // s :0, e : 100  1���� endNumber���� ���ڸ� �����ϰ� ��ȯ�ϴ� �Լ�
{
	std::srand(time(nullptr)); //    ���� �ð��� ������(seed) 
	int randNumber = std::rand() % endNumber + 1; // 1���� endNumber - 1������ ���ڰ� ��ȯ  

	return randNumber;
}

int R_Number(int startNumber, int endNumber)
{
	std::random_device rd;  // �õ带 �����ϱ� ���� ��ü 
	std::mt19937 gen(rd());   // mt19937 �˰����� ����Ͽ� ������ �����Ѵ�.  // rd();
	std::uniform_int_distribution<> distrib(startNumber, endNumber); // ���� ���ں��� �� ���ڱ��� ������ִ� ���
	int randomNumber = distrib(gen);
	return randomNumber;
}