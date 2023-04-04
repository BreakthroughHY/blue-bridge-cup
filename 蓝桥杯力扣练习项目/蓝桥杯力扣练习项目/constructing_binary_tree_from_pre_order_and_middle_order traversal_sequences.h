#pragma once

#ifndef __CONSTRUCTING_BINARY_TREE_FROM_PRE_ORDER_AND_MIDDLE_ORDER_TRAVERSAL_SEQUENCES_H__
#define __CONSTRUCTING_BINARY_TREE_FROM_PRE_ORDER_AND_MIDDLE_ORDER_TRAVERSAL_SEQUENCES_H__

#include <queue> // 写一个二叉树的层序遍历
#include <unordered_map>
#include "main.h"

// 对应结构体声明
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 类声明
class SolutionConstructingBinaryTreeFromPreOrderandMiddleOrderTraversalSequences {
private:
	unordered_map<int, int> index;
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

	TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int pLeft, int pRight, int iLeft, int iRight);
};

int onceUponTimeSequenceTheSequenceStructureBinaryTreeTraversalSequence();

// 二叉树的层序遍历
void binaryTreeSequenceTraversal(TreeNode* root);

#endif // !__CONSTRUCTING_BINARY_TREE_FROM_PRE_ORDER_AND_MIDDLE_ORDER_TRAVERSAL_SEQUENCES_H__
