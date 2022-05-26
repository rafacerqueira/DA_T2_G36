#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "transporte.cpp"
#include <list>
#include <string>
#include <queue>
using std::cerr;
using std::endl;
int V;
int veiculos;
std::vector<transporte> vec;
using namespace std;



// A directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices in graph
    list<int> *adj; // Pointer to an array containing adjacency lists
public:
    Graph(int V);   // Constructor
    void addEdge(int u, int v);

};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add v to u’s list.
}

bool BFS(vector< vector<int> > &resAdjMatrix, int &source, int &sink, vector<int> &parent)
{
    // Create an array for all nodes we visited. Initialized to false.
    int n = resAdjMatrix.size();
    bool visited[n] = { false };

    // Create a queue to check each node.
    queue<int> q;

    // Push our source into the queue and mark it as visited. It has no parent.
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    // Keep visiting vertices.
    while(q.empty() == false)
    {
        int u = q.front();
        q.pop();

        // Check all of u's friends.
        for(int i = 0; i < n; i++)
        {
            int v = i;
            int capacity = resAdjMatrix[u][v];

            // We find a neighbor that hasn't been visited, and the capacity is bigger than 0.
            if(visited[v] == false && capacity > 0)
            {
                // Push the neighbor onto the queue, mark it's parent, and mark it as visited.
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // If the sink got visited, then we found a path to it.
    if(visited[sink] == true)
    { return true; }

    return false;
}

int FordFulkerson(vector< vector<int> > &adjMatrix, int &source, int &sink)
{
    int maxflow = 0;

    // 1. Create the residual graph. (Same as the original graph.)
    vector< vector<int> > resAdjMatrix;
    int n = adjMatrix.size();
    for(int i = 0; i < n; i++)
    {
        vector<int> row;
        resAdjMatrix.push_back(row);
        for(int j = 0; j < adjMatrix[i].size(); j++)
        {
            resAdjMatrix[i].push_back(adjMatrix[i][j]);
        }
    }

    // 2. Create an empty parent array for BFS to store the augmenting path.
    vector<int> parent;
    for(int i = 0; i < n; i++)
    {
        parent.push_back(-1);
    }

    // 3. Keep calling BFS to check for an augmenting path (from the source to the sink...
    while(BFS(resAdjMatrix, source, sink, parent) == true)
    {
        // 4. Find the max flow through the path we just found.
        int pathflow = 10000007;

        // Go through the path we just found. Iterate through the path.
        int v = sink;
        while(v != source)
        {
            int u = parent[v]; // The parent.

            // Update the pathflow to this capacity if it's smaller
            int capacity = resAdjMatrix[u][v];
            pathflow = min(pathflow, capacity);

            // Setup for the next edge in the path.
            v = u;
        }

        // 5. Update the residual capacities of the edges and reverse edges.
        v = sink;
        while(v != source)
        {
            int u = parent[v]; // The parent.

            // Update the capacities.

            resAdjMatrix[u][v] -= pathflow;
            resAdjMatrix[v][u] += pathflow;

            // Setup for the next edge in the path.
            v = u;
        }

        // 6. Add this path's flow to our total max flow so far.
        maxflow += pathflow;
    }

    return maxflow;
}

int main()
{
    vector<vector<int>> adjMatrix;
    std::ofstream output;
    output.open("output.txt");
    int x1, x2, x3, x4;
    std::ifstream newfile("input_simples.txt");
    newfile >> x1 >> x2;
    V = x1;
    veiculos = x2;
    for(int i = 0; i < V; i++)
    {
        vector<int> row;
        adjMatrix.push_back(row);
        for(int j = 0; j < V; j++)
        {
            adjMatrix[i].push_back(0);
        }
    }
    Graph g(V);
    for(int i=0; i<veiculos; i++){
        newfile >> x1 >> x2 >> x3 >> x4;
        vec.push_back(transporte(x1, x2, x3, x4, i));
        g.addEdge(x1, x2);
        adjMatrix[x1][x2]=x3;
    }
    newfile.close();
    int source, sink;
    int max_flow = 0;
    int flow;
    for(int i=1; i<=5; i++){
        for(int j=1;j<=5; j++) {
            int s = i, d = j;
            cout << "entrou" << endl;
            flow = FordFulkerson(adjMatrix, s, d);
            cout << "saiu" << endl;
            if (flow >= max_flow) {
                max_flow = flow;
                source = s;
                sink = d;
            }
        }
    }
    cout << "The max flow from " << source << " to " << sink << " is: ";
    cout << max_flow << endl;
    output.close();
    return 0;
}