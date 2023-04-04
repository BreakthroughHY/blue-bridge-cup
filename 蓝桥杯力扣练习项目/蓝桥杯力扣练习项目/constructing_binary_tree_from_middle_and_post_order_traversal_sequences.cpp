#include "constructing_binary_tree_from_middle_and_post_order_traversal_sequences.h"

int fromSequenceWithSequenceStructureBinaryTreeTraversalSequence()
{
	// 创建对象
	SolutionConstructingBinaryTreeFromMiddleandPostOrderTraversalSequences s;
	vector<int> v = { 9,3,15,20,7 };
	vector<int> vv = { 9,15,7,20,3 };

	DWORD start_time = GetTickCount();

	TreeNode* tree = s.buildTree(v, vv);

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	s.binaryTreeSequenceTraversal(tree);

	return 0;
}

TreeNode* SolutionConstructingBinaryTreeFromMiddleandPostOrderTraversalSequences::buildTree(vector<int>& inorder, vector<int>& postorder)
{
	int n = inorder.size();

	for (int i = 0; i < n; ++i)
		index[inorder[i]] = i;

	return myBuildTree(inorder, postorder, --n, 0, n + 1);
}

TreeNode* SolutionConstructingBinaryTreeFromMiddleandPostOrderTraversalSequences::myBuildTree(vector<int>& inorder, vector<int>& postorder, int& inorderIndex, int pLeft, int pRight)
{
	if (pLeft == pRight)
		return nullptr;

	TreeNode* root = new TreeNode(postorder[inorderIndex--]);
	int temp = index[postorder[inorderIndex + 1]];

	root->right = myBuildTree(inorder, postorder, inorderIndex, temp + 1, pRight);

	root->left = myBuildTree(inorder, postorder, inorderIndex, pLeft, temp);

	return root;
}


// 二叉树的层序遍历
void SolutionConstructingBinaryTreeFromMiddleandPostOrderTraversalSequences::binaryTreeSequenceTraversal(TreeNode* root)
{
	queue<TreeNode*> q;

	if (root == NULL)
		return;

	q.push(root);
	TreeNode* temp = nullptr;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		cout << temp->val << endl;
		if (temp->left)
			q.push(temp->left);

		if (temp->right)
			q.push(temp->right);
	}
}