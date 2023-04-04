#include "constructing_binary_tree_from_middle_and_post_order_traversal_sequences.h"

int onceUponTimeSequenceTheSequenceStructureBinaryTreeTraversalSequence()
{
	// 创建对象
	SolutionConstructingBinaryTreeFromPreOrderandMiddleOrderTraversalSequences s;
	vector<int> v = { 3,9,20,15,7 };
	vector<int> vv = { 9,3,15,20,7 };

	DWORD start_time = GetTickCount();

	TreeNode* tree = s.buildTree(v, vv);

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	binaryTreeSequenceTraversal(tree);

	return 0;
}

TreeNode* SolutionConstructingBinaryTreeFromPreOrderandMiddleOrderTraversalSequences::buildTree(vector<int>& preorder, vector<int>& inorder)
{
	int n = inorder.size();

	for (int i = 0; i < n; ++i)
		index[inorder[i]] = i;

	int nn = 0;
	return myBuildTree(preorder, inorder, nn, 0, n);
}

TreeNode* SolutionConstructingBinaryTreeFromPreOrderandMiddleOrderTraversalSequences::myBuildTree(vector<int>& preorder, vector<int>& inorder, int& pLeft, int iLeft, int iRight)
{
	if (iLeft == iRight)
		return nullptr;

	int temp;

	TreeNode* root = new TreeNode(preorder[pLeft++]);
	temp = pLeft;

	root->left = myBuildTree(preorder, inorder, pLeft, iLeft, index[preorder[pLeft - 1]]);

	root->right = myBuildTree(preorder, inorder, pLeft, index[preorder[temp - 1]] + 1, iRight);

	return root;
}

// 二叉树的层序遍历
void binaryTreeSequenceTraversal(TreeNode* root)
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