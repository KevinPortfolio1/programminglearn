/*

在 C++ 中，圖（Graph）是一種數據結構，用於表示物體之間的關係。
圖由節點（或稱頂點）和邊（或稱連接）組成。
以下是一些基本概念和表示方法：
基本概念
    節點（Vertex）：圖中的基本單位，代表物體。
    邊（Edge）：連接兩個節點的鏈接，表示這兩個節點之間的關係。
    有向圖：邊有方向，從一個節點指向另一個節點。
    無向圖：邊沒有方向，連接的兩個節點互相可達。
    權重（Weight）：邊的數值，用於表示邊的成本、距離等。
表示方法

    鄰接矩陣（Adjacency Matrix）：
        使用二維數組表示，數組的行和列代表節點。
        如果有邊存在，對應位置標記為1（或邊的權重），否則為0。

    
    c++
     const int MAX = 100;
     int graph[MAX][MAX]; // MAX 是最大節點數

   鄰接表（Adjacency List）：

     每個節點都有一個列表，該列表包含所有與之相連的節點。
     比較節省空間，適合稀疏圖。

   c++

    #include <vector>
    #include <list>
    std::vector<std::list<int>> graph(MAX);

基本操作

    插入節點：在圖中增加新的節點。
    插入邊：在兩個節點之間建立邊。
    遍歷圖：
        深度優先搜尋（DFS）
        廣度優先搜尋（BFS）

*/

//簡單的無向圖的鄰接表實現

#include <iostream>
#include <vector>
#include <list>

class Graph {
public:
    int V; // 節點數量
    std::vector<std::list<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // 無向圖
    }

    void printGraph() {
        for (int i = 0; i < V; ++i) {
            std::cout << "Node " << i << ":";
            for (auto v : adj[i]) {
                std::cout << " " << v;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g(5); // 創建一個有5個節點的圖
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}

/*
Output

Node 0: 1 4
Node 1: 0 2 3 4
Node 2: 1 3
Node 3: 1 2 4
Node 4: 0 1 3


*/