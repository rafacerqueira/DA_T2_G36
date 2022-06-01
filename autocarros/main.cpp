#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<iostream>
#include <fstream>
using namespace std;
int c[5000][5000];
int flowPassed[5000][5000];
vector<int> g[5000];
int parList[5000];
int currentPathC[5000];
#include <list>
#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;
class Graph {
    int V; // No. of vertices in graph
    list<int>* adj; // Pointer to an array containing adjacency lists

    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int, int, bool[], int[], int&, ofstream&);

public:
    Graph(int V); // Constructor
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
    bool* visited = new bool[V];

    // Create an array to store paths
    int* path = new int[V];
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
                              int path[], int& path_index, ofstream& output)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u == d) {
        for (int i = 0; i < path_index; i++)
            output << path[i] << " ";
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
// A directed graph using
// adjacency list representation

int bfs(int sNode, int eNode)//breadth first search
{
    memset(parList, -1, sizeof(parList));
    memset(currentPathC, 0, sizeof(currentPathC));
    queue<int> q;//declare queue vector
    q.push(sNode);
    parList[sNode] = -1;//initialize parlist’s source node
    currentPathC[sNode] = 999;//initialize currentpath’s source node
    while(!q.empty())// if q is not empty
    {
        int currNode = q.front();
        q.pop();
        for(int i=0; i<g[currNode].size(); i++)
        {
            int to = g[currNode][i];
            if(parList[to] == -1)
            {
                if(c[currNode][to] - flowPassed[currNode][to] > 0)
                {
                    parList[to] = currNode;
                    currentPathC[to] = min(currentPathC[currNode],
                                           c[currNode][to] - flowPassed[currNode][to]);
                    if(to == eNode)
                    {
                        return currentPathC[eNode];
                    }
                    q.push(to);
                }
            }
        }
    }
    return 0;
}
void read(ifstream& file){
    std::string line;
    std::getline(file, line);
    int length = line.length();
    int arr[length]= { 0 };
    int j = 0, i, sum = 0;

    // Traverse the string
    for (i = 0; line[i] != '\0'; i++) {
        if (line[i] == ' '){
            // Increment j to point to next
            // array location
            j++;
        }
        else {

            // subtract str[i] by 48 to convert it to int
            // Generate number by multiplying 10 and adding
            // (int)(str[i])
            arr[j] = arr[j] * 10 + (line[i] - 48);
        }
    }
    for (i = 0; i < j; i++) {
        cout << arr[i] << " ";
    }

}
int edmondsKarp(int sNode, int eNode)
{
    int maxFlow = 0;
    while(true)
    {
        int flow = bfs(sNode, eNode);
        if (flow == 0)
        {
            break;
        }
        maxFlow += flow;
        int currNode = eNode;
        while(currNode != sNode)
        {
            int prevNode = parList[currNode];

            flowPassed[prevNode][currNode] += flow;
            flowPassed[currNode][prevNode] -= flow;
            currNode = prevNode;
        }
    }
    return maxFlow;
}
void cenario2_3(){
    std::ofstream output;
    output.open("output.txt");
    int nodCount, edCount;
    int x1, x2, x3, x4;
    std::ifstream newfile("input_simples.txt");
    newfile >> x1 >> x2;
    nodCount=x1;
    edCount=x2;
    Graph graph(nodCount);
    int source, sink;
    source=1;
    sink=x1;
    for(int ed = 0; ed < edCount; ed++){
        newfile >> x1 >> x2 >> x3 >> x4;
        int from, to, cap;
        from=x1;
        to=x2;
        cap=x3;
        c[from][to] = cap;
        g[from].push_back(to);
        g[to].push_back(from);
        graph.addEdge(x1,x2);
    }
    int maxFlow = edmondsKarp(source, sink);
    cout<<"Max Flow is:"<<maxFlow<<endl;
}
void cenario1_1() {
    std::ofstream output;
    //output.open("output.txt");
    int nodCount, edCount;
    int x1, x2, x3, x4;
    std::ifstream newfile("input_simples.txt");
    newfile >> x1 >> x2;
    nodCount=x1;
    edCount=x2;
    int source, sink;
    source=1;
    sink=x1;
    Graph g(x1);
    for(int ed = 0; ed < edCount; ed++){
        newfile >> x1 >> x2 >> x3 >> x4;
        g.addEdge(x1,x2);
        c[x1][x2]=x3;
    }
    newfile.close();
    //g.printAllPaths(1,5, output);
    //output.close();
    std::ifstream file("output.txt");
    read(file);
}
void cenario2_1(){
    std::ofstream output;
    output.open("output.txt");
    int dimensao;
    cout << "Que dimensao pretende?" << endl;
    cin >> dimensao;
    cout << "dimensao de: " << dimensao << endl;
    int nodCount, edCount;
    int x1, x2, x3, x4;
    std::ifstream newfile("in01_b.txt");
    newfile >> x1 >> x2;
    nodCount=x1;
    edCount=x2;
    Graph graph(nodCount);
    int source, sink;
    source=0;
    sink=x1+1;
    c[0][1] = dimensao;
    g[0].push_back(1);
    c[x1][x1+1] = dimensao;
    g[x1].push_back(x1+1);

    //50<-12<-46<-8<-1<-50<-41<-33<-6<-1<-50<-31<-40<-48<-8<-1<-50<-39<-19<-7<-37<-38<-1<-50<-39<-44<-22<-35<-38<-1<-50<-39<-17<-36<-10<-6<-1<-

    for(int ed = 0; ed < edCount; ed++){
        graph.addEdge(0,x1+1);
        newfile >> x1 >> x2 >> x3 >> x4;
        int from, to, cap;
        from=x1;
        to=x2;
        cap=x3;
        c[from][to] = cap;
        g[from].push_back(to);
        g[to].push_back(from);
        graph.addEdge(x1,x2);
    }
    edmondsKarp(source,sink);

}
void displaymenu(){ cout<<"===================================================== \n";
cout<<" \t\tMENU \t \n ";
cout<<"===================================================== \n";
cout<<" 1.Determinar a dimensão máxima do grupo e um encaminhamento.\n";
cout<<" 2.Maximizar a dimensão do grupo e minimizar o número de transbordos, sem privilegiar um dos critérios relativamente ao outro.\n";
cout<<" 3.Determinar um encaminhamento para um grupo, dada a sua dimensão.\n";
cout<<" 4.View all student records \n";
cout<<" 5.Find a student by ID \n";
}


int main(){
    displaymenu();
    int yourchoice;
     cout<<"Enter your choice(1-5):";
        cin>>yourchoice;
        switch (yourchoice)
        {
            case 1: cenario2_3(); break;
            case 2: cenario1_1();break;
            case 3: cenario2_1(); break;
            default: cout<<"invalid"; break;
        }

    return 0;
}