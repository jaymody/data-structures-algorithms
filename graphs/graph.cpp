/* directed weighted graph implementation */

////// Includes //////
#include <iostream>
#include <vector>
#include <string>

using namespace std;

////// Structs //////
struct Node {
    string val;
};
struct Edge {
    int dst;
    double weight;
};
struct Graph {
    vector<struct Node> nodes;
    vector<vector<struct Edge>> adj;

    Graph(vector<struct Node> nodes) : nodes(nodes), adj(nodes.size()) {}
    ~Graph() {}

    void addEdge(int src, int dst, double weight) {
        struct Edge edge;
        edge.dst = dst;
        edge.weight = weight;

        adj[src].push_back(edge);
    }

    void addNode(string val) {
        struct Node node;
        node.val = val;

        nodes.push_back(node);
        adj.push_back(vector<struct Edge>());
    }

    void print() {
        for (int i = 0; i < adj.size(); ++i) {
            cout << "(" << i << ": " << nodes[i].val << ")" << " --> ";
            for (struct Edge& e : adj[i])
                cout << "(" << e.dst << ": " << nodes[e.dst].val << ", " << e.weight << ") ";
            cout << endl;
        }
    }

    void DFS(int i) {

    }
};