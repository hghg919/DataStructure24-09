#pragma once

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>

/*
*  balaned BST -  �����͵��� ���ĵǾ� �־�� �Ѵ�.
*  ������ �Ǿ� ���� �ʾƵ� ������ �����͸� �˻��� �� �ִ� �ڷᱸ�� -> unordered_set, map // hashFunction, 
*  hashFunction : Ư�� �԰����� ������ ���� ��ȯ�ϴ� �Լ�
*  hashKey : �ſ� ū ���ڸ� �����ϴ�.
*  bucket  : ���� ���ڷ� ��ȯ�� �մϴ�.
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
	// bucket �ٱ��� ���ڰ� ������ �Ǵ°�
	std::cout << "bucket �� :" << unordSet.bucket_count();

	unordSet.find("abc");

	// ������ �ϴ¹�
	// Ž���� �� ���� �ſ� ������, �����Ϳ� ����� ���� ������ �߰�,���� �� �� ���� �ٲ��.
}


