#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "transporte.cpp"
#include <list>
#include <string>
using std::cerr;
using std::endl;
int V;
int veiculos;

using namespace std;

// A directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices in graph
    list<int> *adj; // Pointer to an array containing adjacency lists

    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int , int , bool [], int [], int &, ofstream& output);

public:
    Graph(int V);   // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d, ofstream& output);
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

// Prints all paths from 's' to 'd'
void Graph::printAllPaths(int s, int d, ofstream& output)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];

    // Create an array to store paths
    int *path = new int[V];
    int path_index = 0; // Initialize path[] as empty

    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index, output);
}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index, ofstream& output)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {
        for (int i = 0; i<path_index; i++){
            cout << path[i] << " ";
            output << path[i] << " ";
        }
        cout << endl;
        output << endl;
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index, output);
    }

    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}
int maximizar_fluxo(std::vector<transporte> vec){
    std::ifstream file("output.txt");
    std::vector<transporte> final;
    int x1, x2;
    string line;
    int j=2;
    getline(file,line);
    x1 = (int)line.at(0);
    x2 = (int)line.at(2);
    while(!file.eof()){

        for ( std::string::iterator it=line.begin(); it!=line.end(); ++it){
            for(int i=0; i<veiculos; i++){
                if(vec.at(i).origem == x1 && vec.at(i).destino == x2){
                    final.push_back(transporte(x1,x2,vec.at(i).capacidade,0,i));
                }
            }
        }
        getline(file,line);
    }
}
// Driver program
int main()
{
    std::ofstream output;
    output.open("output.txt");
    int x1, x2, x3, x4;
    std::vector<transporte> vec;
    std::ifstream newfile("input_simples.txt");
    newfile >> x1 >> x2;
    V = x1;
    veiculos = x2;
    Graph g(V);
    for(int i=0; i<veiculos; i++){
        newfile >> x1 >> x2 >> x3 >> x4;
        vec.push_back(transporte(x1, x2, x3, x4, i));
        g.addEdge(x1, x2);
    }
    newfile.close();
    int s = 1, d = 5;
    cout << "Following are all different paths from " << s
         << " to " << d << endl;
    g.printAllPaths(s, d, output);
    output.close();
    maximizar_fluxo(vec);
    return 0;
}