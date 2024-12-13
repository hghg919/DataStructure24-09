#include "lectures.h"

// �ڷḦ �����ϴ� �� ������ ������ϴ�.
// �ڷᱸ�� �ȿ� �ִ� �����͸� ã�Ƽ�, ����ϱ� ���ؼ��̴�.
// �����͸� ���� ȿ�������� �����ϴ� ����� ���ؼ� ������ϴ�.

// ADT . Queue. Stack. Priority_Queue

// �ڷᱸ�� ���ο� �ִ� �����͸� ��� ���� ã����
// 1���� �ð� ���⵵ time complexity
// 2���� ���� ���⵵ Space complexity

// �ݺ����� ���ؼ� ��� ���Ҹ� ��ȸ(traverse) �ð� O(n) : ������ ������ �������� �����ɸ���.
// O(logn) - �ڷᱸ���� ���ĵǾ� ������. ���� Ž��(binary search)���� O(logn)Ž�� �� �� �ִ�.
// O(1)


// �ڷᱸ���� vector ���� Ž���� ������ �߽��ϴ�.
// Linked list.. -> ���� Ž�� �����ұ��? -> �Ұ����մϴ�.
// �߰��� ������ ����, ���� �߻� vector _rebuilding
// ���� Ž���� �ϰ� ������, �߰� ����,������ ������ �ڷᱸ���� ������?



#include <vector>
#include <iostream>
#include <chrono>

using namespace std::chrono;

class MySearchTool
{
public:
	int search(const std::vector<int>& arr, int target)
	{
		auto it = arr.begin();

		// iterator �ݺ���
		for (it; it != arr.end(); it++)
		{
			if ((*it) == target)
			{
				std::cout << "��ǥ ���� ã�ҽ��ϴ� :" << *it << std::endl;

				return (*it);
			}
		}

		std::cout << "Ÿ���� �������ϴ�." << std::endl;
		return -1;
	}

	int binarySearch(const std::vector<int>& arr, int target)
	{
		int left = 0;
		int right = arr.size() - 1;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;

			if (arr[mid] < target)
			{
				left = mid + 1;
			}
			else if (arr[mid] > target)
			{
				right = mid - 1;
			}
			else 
			{
				std::cout << "��ǥ ���� ã�ҽ��ϴ� :" << std::endl;
				return arr[mid];
			}		
		}

		std::cout << "Ÿ���� �������ϴ�." << std::endl;
		return -1;
	}
};

void lecture7()
{
	// command system Ž�� -> (vector Ŀ�ǵ� - queue ��ǲ) ���� �༮ ���

	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	// vector�ȿ� �ִ� ���ڸ� ã�´�. Ž��
	int targetNumber = 3;
	
	MySearchTool tool;

	auto start = high_resolution_clock::now();

	tool.search(vec, targetNumber);

	auto end = high_resolution_clock::now();
	
	auto duration = duration_cast<microseconds>(end - start);

	std::cout << "for �ݺ��� ��ȸ Ž�� ��� �ɸ� �ð� : " << duration.count() / 1000.0 << "ms" << std::endl;

	auto start2 = high_resolution_clock::now();

	tool.binarySearch(vec, targetNumber);

	auto end2 = high_resolution_clock::now();

	auto duration2 = duration_cast<microseconds>(end2 - start2);

	std::cout << "���� Ž�� ��� �ɸ� �ð� : " << duration2.count() / 1000.0 << "ms" << std::endl;
}