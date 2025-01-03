#pragma once

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>

/*
*  balaned BST -  데이터들이 정렬되어 있어야 한다.
*  정렬이 되어 있지 않아도 빠르게 데이터를 검색할 수 있는 자료구조 -> unordered_set, map // hashFunction, 
*  hashFunction : 특정 규격으로 정해진 값을 반환하는 함수
*  hashKey : 매우 큰 숫자를 가집니다.
*  bucket  : 작은 숫자로 변환을 합니다.
*/


void HashExample()
{
	std::unordered_set<std::string> unordSet;

	unordSet.reserve(50000);

	unordSet.emplace("abc");
	unordSet.emplace("def");
	unordSet.emplace("hgc");
	unordSet.emplace("abc2");
	unordSet.emplace("def2");
	unordSet.emplace("hgc2");
	unordSet.emplace("abc3");
	unordSet.emplace("def3");
	unordSet.emplace("hgc3");

	for (const std::string& str : unordSet)
	{
		std::cout << str << std::endl;
	}

	std::cout << "abc :" << std::hash<std::string>{}("abc") << std::endl;
	// bucket 바구니 숫자가 생성이 되는가
	std::cout << "bucket 수 :" << unordSet.bucket_count();

	unordSet.find("abc");

	// 접근을 하는법
	// 탐색을 할 때는 매우 빠른데, 데이터에 저장된 값이 데이터 추가,삭제 될 때 마다 바뀐다.
}


