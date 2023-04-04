#pragma once

#ifndef __CONSTRUCTING_BINARY_TREE_FROM_MIDDLE_AND_POST_ORDER_TRAVERSAL_SEQUENCES_H__
#define __CONSTRUCTING_BINARY_TREE_FROM_MIDDLE_AND_POST_ORDER_TRAVERSAL_SEQUENCES_H__

#include <unordered_map>
#include "main.h"

// ��Ӧ�ṹ������
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};

// ������
class SolutionConstructingBinaryTreeFromMiddleandPostOrderTraversalSequences {
private:
	unordered_map<int, int> index;

public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);

	TreeNode* myBuildTree(vector<int>& inorder, vector<int>& postorder, int& inorderIndex, int pLeft, int pRight);

	void binaryTreeSequenceTraversal(TreeNode* root);
};

int fromSequenceWithSequenceStructureBinaryTreeTraversalSequence();

#endif // !__CONSTRUCTING_BINARY_TREE_FROM_MIDDLE_AND_POST_ORDER_TRAVERSAL_SEQUENCES_H__
