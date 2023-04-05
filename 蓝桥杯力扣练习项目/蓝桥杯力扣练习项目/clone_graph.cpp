#include "clone_graph.h"

int cloningFigure()
{
	// ��������
	SolutionCloneGraph s;
	Node* n = new Node;

	DWORD start_time = GetTickCount();

	cout << s.cloneGraph(n) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

// �������dfs
Node* SolutionCloneGraph::cloneGraph(Node* node)
{
	if (node == NULL)
		return node;

	if (visited.find(node) != visited.end())
	{
		return visited[node];
	}

	Node* cloneNode = new Node(node->val);

	visited[node] = cloneNode;

	for (auto& neighbor : node->neighbors)
	{
		cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
	}

	return cloneNode;
}

// �������bfs
Node* SolutionCloneGraph::cloneGraph_(Node* node)
{
	if (node == NULL)
		return node;

	// ��¼��¡����Ĺ�ϣ��
	unordered_map<Node*, Node*> visited_;
	// ��¡�׸��ڵ�
	Node* cloneNode = new Node(node->val);
	// ��¼�׸��ڵ��Ѿ���¡
	visited_[node] = cloneNode;
	// ���׸��ڵ���ӽ��й������
	queue<Node*> q{ {node} };


	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		for (auto& neighbor : temp->neighbors)
		{
			if (visited_.find(neighbor) == visited_.end()) // �ڵ�δ����¡�����п�¡
			{
				visited_[neighbor] = new Node(neighbor->val); // ��¡�ڵ㲢��¼�Ѿ���¡
				q.push(neighbor);
			}
			visited_[temp]->neighbors.emplace_back(visited_[neighbor]);
		}
	}

	return cloneNode;
}