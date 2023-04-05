#include "clone_graph.h"

int cloningFigure()
{
	// 创建对象
	SolutionCloneGraph s;
	Node* n = new Node;

	DWORD start_time = GetTickCount();

	cout << s.cloneGraph(n) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

// 深度优先dfs
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

// 广度优先bfs
Node* SolutionCloneGraph::cloneGraph_(Node* node)
{
	if (node == NULL)
		return node;

	// 记录克隆情况的哈希表
	unordered_map<Node*, Node*> visited_;
	// 克隆首个节点
	Node* cloneNode = new Node(node->val);
	// 记录首个节点已经克隆
	visited_[node] = cloneNode;
	// 将首个节点入队进行广度优先
	queue<Node*> q{ {node} };


	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		for (auto& neighbor : temp->neighbors)
		{
			if (visited_.find(neighbor) == visited_.end()) // 节点未被克隆将进行克隆
			{
				visited_[neighbor] = new Node(neighbor->val); // 克隆节点并记录已经克隆
				q.push(neighbor);
			}
			visited_[temp]->neighbors.emplace_back(visited_[neighbor]);
		}
	}

	return cloneNode;
}