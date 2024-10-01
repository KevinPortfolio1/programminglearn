#include <iostream>
#include <vector>
#include <queue>
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

	void BFS(int start) {
		vector<bool> visited(V, false);
		queue<int> q;
		q.push(start);
		visited[start] = true;

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cout << node << " "; 

			for (int neighbor : adj[node]) {
				if (!visited[neighbor]) {
					visited[neighbor] = true; 
					q.push(neighbor); 
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

	cout << "廣度優先搜尋結果: ";
	g.BFS(0);

	auto end = chrono::high_resolution_clock::now(); 
	chrono::duration<double, milli> duration = end - start; 

	cout << "執行時間: " << duration.count() << " 毫秒" << endl;

	return 0;
}


/*

廣度優先搜尋結果: 0 1 2 3 4 5 6
執行時間: 3.406 毫秒

*/