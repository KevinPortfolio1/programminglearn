#include <iostream>
#include <vector>
#include <stack>
#include <chrono>

using namespace std;


class Graph {
private:
	int V;
	vector<vector<int>> adj; 

public:
	Graph(int V) : V(V), adj(V) {}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void DFS(int start) {
		vector<bool> visited(V, false);
		stack<int> s;
		s.push(start);

		while (!s.empty()) {
			int node = s.top();
			s.pop();

			if (!visited[node]) {
				cout << node << " "; 
				visited[node] = true; 
			}

			for (int neighbor : adj[node]) {
				if (!visited[neighbor]) {
					s.push(neighbor);
				}
			}
		}
		cout << endl;
	}
};

int main()
{
	auto start = chrono::high_resolution_clock::now(); 

	Graph g(7); 
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 5);
	g.addEdge(2, 6);

	cout << "深度優先搜尋結果: ";
	g.DFS(0);

	auto end = chrono::high_resolution_clock::now(); 
	chrono::duration<double, milli> duration = end - start; 

	cout << "執行時間: " << duration.count() << " 毫秒" << endl;

	return 0;
}

/*

深度優先搜尋結果: 0 2 6 5 1 4 3
執行時間: 2.9975 毫秒

*/