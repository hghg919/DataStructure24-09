#pragma once

// Ʈ�� : ����, ������� ����ó�� ���� �ڷᱸ��.

// Ʈ���� ��尡 ���� �� �ִ� �ִ� ���� ���� �з�
// 2�� : ���� Ʈ�� (binary tree)	 - �ַ� �ٷ�� �� ��
// 3�� : Ternary tree
// 4�� : Octree

// Ʈ���� ��� :
// ��� : Ʈ���� �⺻��ҷ� �����͸� �����ϴ� ����
// ��Ʈ : �ֻ����� �ִ� ���. �θ� ��尡 ���� ���� ����Դϴ�.
// �θ� ��� : ������ ���� ���� ����� ���.
// �ڽ� ��� : �θ� ����� ������ ���� ����� ���.
// ���� ��� : ���� �θ� ���� �����Դϴ�.
// ���� ��� : Ư�� ��忡�� ��Ʈ���� ��ο� �ִ� ��� �����Դϴ�.
// �ļ� ��� : Ư�� ����� ��� �ڽ�, �ڽ��� �ڽ� ���� ������ �����Դϴ�.
// ���� : ��Ʈ�� ������ �Ÿ�.  ��Ʈ��� ���� : 0
// ���� : Ʈ������ ���� ���� ������ �ǹ��Ѵ�.
// ���� Ʈ�� : Ʈ�� ������ ���� �� �ļյ�� ������ Ʈ��
// ���� (degree) : �ϳ��� ��尡 ���� �ڽ� ����� �� 
// ��� : �ϳ��� ��忡�� �ٸ� ���� �̵��� �� ��ġ�� ������ ����

// Ʈ��
// 1. ��Ʈ�� �� ���̾�� �մϴ�.
// 2. ������ ��ȯ���� �ʾƾ� �մϴ�.

// ���� Ʈ���� ����
// ���� Ʈ�� : ��� ������ ���� �� �ִ� �ڽ��� ��(degree) 2�� ���Ϸ� ������ �ڷᱸ��
// ���� Ž��, �߰� ���� ���� ���� �ڷᱸ�� - ���� �˻� Ʈ��
// Full binary tree	 
// complete binary tree
// perfect binary tree

// Ʈ���� ��ȸ ���
// PreOrder ���� ��ȸ
// InOrder ���� ��ȸ
// PostOrder ���� ��ȸ

// ���� ���� ���� �˻� Ʈ�� 
// Red - Black Tree,  AVL Tree

// 1. ��� ���� ������ Ȥ�� �������̴�.
// 2. ��Ʈ ���� �������̴�.
// 3. NIL(Null leaf) ���� ������ �������̴�. Null Left : �ڷḦ ���� �ʰ� Ʈ���� ���� ��Ÿ���� ���
// 4. ������ ����� �ڽ��� �������̴�. (NO DOUBLE RED) // �������� �ڽ��� �������̾ �ȴ�.
// 5. ��� ���� ��忡�� Blcak Depth�� ����.  // ��� ���� ��忡�� Ư�� ���� ���� ������ ����� ������ ���ƾ� �Ѵ�.

#include <iostream>

class Tree
{
public:
	struct Node
	{
		int data;
		Node* left;
		Node* right;

		Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
	};

	void PreOrder(Node* root)
	{
		// ��� �Լ� : �ڱ� �ڽ��� �Լ��� ȣ���ϴ� �Լ� 
		if (root == nullptr) return;

		std::cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
	void InOrder(Node* root)
	{
		if (root == nullptr) return;

		InOrder(root->left);
		std::cout << root->data << " ";
		InOrder(root->right);
	}
	void PostOrder(Node* root)
	{
		if (root == nullptr) return;

		PostOrder(root->left);
		PostOrder(root->right);
		std::cout << root->data << " ";
	}

};

// BST : ���� �˻� Ʈ��
// ���� �ڷᱸ������ ���� �˻��� ��ȿ�����̴�. ���� �˻��� ȿ�������� �� �� �ִ� �ڷᱸ��

// ���� �˻��� �ϱ� ���ؼ� ������ ��Ģ�� �����ϴ�.
// ����� �������� ���� ���� �ڽ� ��庸�� ���� ��, ������ ���� �ڽź��� ū ���� �����Ѵ�.
// �ߺ��� ������� �ʽ��ϴ�.

// �˻��� �ɸ��� �ð� : logn
// �߰� ���� ���� : logn 
// Insert
// Delete


// ������ ���

// 1. �����ϰ��� �ϴ� ����� �ڽ��� ���� ��

// 2. �����ϰ��� �ϴ� ����� ���ʿ��� �ڽ��� ���� ��

// 3. �����ϰ��� �ϴ� ����� �����ʿ��� �ڽ��� ���� ��

// 4. ���ʿ� �ڽ��� ���� ��

class BinarySearchTree
{
public:
	struct Node
	{
		int data;
		Node* left;
		Node* right;

		Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
	};

private:
	Node* root;

	Node* insert(Node* root, int value)
	{
		if (root == nullptr)
			return new Node(value);

		if (value < root->data)
		{
			root->left = insert(root->left, value);
		}

		if (value > root->data)
		{
			root->right = insert(root->right, value);
		}

		return root;
	}

	Node* search(Node* root, int target)
	{
		if (root == nullptr || root->data == target)
		{
			return root;
		}

		if (target < root->data)
		{
			return search(root->left, target);
		}
		else if (target > root->data)
		{
			return search(root->right, target);
		}
		
	}

	// ����� ����

	// 1. ���� ���	�Ǵ� �ڽ��� 1���� ���� ��� : ��带 �����ϰ� �ڽ� ��带 �θ� ���� ���� ���� �ش�.

	// 2. �ڽ��� 2���� ���� ��� : case1, case2 �׸� ���� (����)

	Node* removeNode(Node* root, int target)
	{
		if (root == nullptr) return root;

		 // 1. ������ ��带 ã�´�.
		if (target < root->data)
		{
			root->left = removeNode(root->left, target);
		}
		else if (target > root->data)
		{
			root->right = removeNode(root->right, target);
		}
		else  // 2. ��带 ã�Ҵٸ�
		{
			// �� ����� �ڽ��� 1���� �����ϰų�, ���� ����� ���
			
			if (root->left == nullptr)
			{
				Node* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr)
			{
				Node* temp = root->left;
				delete root;
				return temp;
			}

			// �ڽ��� 2���� ���� ���
			// ���� ��带 �θ�� �ø���, ������ ��带 �θ�� �ø��� ����
			// �������� �����Ѵٰ� ����, ������ ��� �߿��� ���� ���� �Ʒ��� �ִ� ��带 �θ�� �������ش�.

			Node* temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = removeNode(root->right, temp->data);
		}	 

		return root;
	}

	Node* minValueNode(Node* node)
	{
		Node* current = node;
		while (current && current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}

	void inOrder(Node* root)
	{
		 // LNR
		if (root == nullptr) return;

		inOrder(root->left);
		std::cout << root->data << " ";
		inOrder(root->right);
	}

public:
	BinarySearchTree() : root(nullptr) {}

	void insert(int value)
	{
		root = insert(root, value);
	}

	bool search(int value)
	{
		return search(root, value) != nullptr;
	}
    
	void InOrder()
	{
		inOrder(root); // root�� ���ڷ� ���� inOrder �Լ��� �����غ�����.
		std::cout << std::endl;
	}

	void remove(int target)
	{
		removeNode(root, target);
	}

	void leftRotate(Node* oldTop)
	{
		bool isRoot = false;

		if (oldTop->data == root->data)
			isRoot = true;

		Node* newTop = oldTop->right;
		oldTop->right = newTop->left;
		newTop->left = oldTop;

		if (isRoot)
			root = newTop;
	}

	void rightRotate(Node* oldTop)
	{
		bool isRoot = false;

		if (oldTop->data == root->data)
			isRoot = true;

		Node* newTop = oldTop->left;
		oldTop->left = newTop->right;
		newTop->right = oldTop;

		if (isRoot)
			root = newTop;
	}

	Node* GetRoot() { return root; }
};

void TreeExample()
{
	// Tree �ڷᱸ���� ����Ǿ� �ִ� ���� root
	// �����͸� ��ȸ�ϴ� ��� :  preOrder, InOrder, PostOrder
	Tree::Node* root = new Tree::Node(19);
	root->left = new Tree::Node(24);
	root->right = new Tree::Node(35);
	root->left->left = new Tree::Node(40);
	root->left->right = new Tree::Node(52);

	Tree myTree;

	// preorder�� ��� : 1 - 2 - 4 - 5 - 3
	std::cout << " == ���� ��ȸ preOrder == " << std::endl;
	myTree.PreOrder(root);
	std::cout << std::endl;
	// Inorder�� ��� : 4 - 2 - 5 -1 3
	std::cout << " == ���� ��ȸ InOrder == " << std::endl;
	myTree.InOrder(root);
	std::cout << std::endl;
	// PostOrder�� ��� : 	4 -5 - 2 -3- 1
	std::cout << " == ���� ��ȸ postOrder ==" << std::endl;
	myTree.PostOrder(root);
	std::cout << std::endl;
	// 10, 7,  25, 8 , 49



	BinarySearchTree bst;

	bst.insert(10);
	bst.insert(7);
	bst.insert(25);
	bst.insert(8);
	bst.insert(49);
	bst.insert(17);
	bst.insert(40);
	bst.remove(7);
	bst.remove(25);

	bst.rightRotate(bst.GetRoot());
	
	bst.InOrder();

	std::cout << "Ž�� ��� :" << (bst.search(30) ? "ã��" : "��ã��") << std::endl;
}