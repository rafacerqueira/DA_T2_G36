#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<iostream>
#include <fstream>
using namespace std;
int c[5000][5000]; // array that stores the capacity of 2 vertices
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

    // If current vertex is same as destination, then print to output
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

//Function to calculate max capacity in a graph and print the path
void read(ifstream& file){
    int control;
    int capacidade = INFINITO ;
    int capacidade_max=0;
    std::string line;
    std::getline(file, line); // read file line by line
    int length = line.length();
    int final[length] = { 0 }; //array containing the path with the bigger capacity

    //do while cicle for saving every line inside the file inside a array to help the calculation
    do{
        int arr[length] = { 0 };
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
        control = j;
        // calculate the capacity by searching in the c[][] array that contains the capacity of each par u and v
        for (i = 0; i < j-1; i++) {
            for(int k=i+1; k<i+2; k++){
                if(c[arr[i]][arr[k]] < capacidade){
                    capacidade = c[arr[i]][arr[k]];
                }
            }
        }

        if(capacidade >= capacidade_max){


            for(int i=0; i<j; i++){
                final[i] = arr[i];
            }
            capacidade_max = capacidade;
        }
        capacidade=INFINITO;
    }while(std::getline(file, line));


    cout << endl;
    cout << "capacidade maxima: " <<capacidade_max << endl;
    cout << "encaminhamento de capacidade maxima: ";
    for(int i=0; i<=control; i++){
        if(i==0){
            cout << final[i];
        }else{
            cout<< " -> " << final[i];
        }
    }
    cout << endl;

}

//Function almost the same as read() but calculates the path with less transshipments
void read_transbordos(ifstream& file){
    int transbordos = INFINITO;
    int control;
    int capacidade = INFINITO ;
    int capacidade_max=0;
    std::string line;
    std::getline(file, line);
    int length = line.length();
    int final[length] = { 0 };
    int menos_transbordos[length] = { 0 };
    do{
        int arr[length] = { 0 };
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
        control = j;
        if(j <= transbordos){
            transbordos = j;
            for(int i=0; i<=transbordos; i++){
                menos_transbordos[i] = arr[i];
            }
        }
        for (i = 0; i < j-1; i++) {
            for(int k=i+1; k<i+2; k++){
                if(c[arr[i]][arr[k]] < capacidade){
                    capacidade = c[arr[i]][arr[k]];
                }
            }
        }

        if(capacidade >= capacidade_max){


            for(int i=0; i<=j; i++){
                final[i] = arr[i];
            }
            capacidade_max = capacidade;
        }
        capacidade=INFINITO;
    }while(std::getline(file, line));

    if(control==transbordos){
        cout << endl;
        cout << "capacidade maxima: " <<capacidade_max << endl;
        cout << "encaminhamento de capacidade maxima e menos transbordos: ";
        for(int i=0; i<=control; i++){
            if(i==0){
                cout << final[i];
            }else{
                cout<< " -> " << final[i];
            }
        }
    }else{
        cout << endl;
        cout << "capacidade maxima: " <<capacidade_max << endl;
        cout << "encaminhamento de capacidade maxima: ";
        for(int i=0; i<=control; i++){
            if(i==0){
                cout << final[i];
            }else{
                cout<< " -> " << final[i];
            }
        }
        cout << endl;
        cout << "caminho com menos transbordos: " << endl;
        for(int i=0; i<transbordos; i++){
            if(i==0){
                cout << menos_transbordos[i];
            }else{
                cout<< " -> " << menos_transbordos[i];
            }
        }

    }
}

//bfs function to help edmondsKarp algorithm
int bfs(int sNode, int eNode){
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
//edmondsKarp function that returns the max flow
int edmondsKarp_int(int sNode, int eNode){
    int maxFlow = 0;
    while(true){
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

//edmondsKarp function that prints the max flow and the path to the max flow
void edmondsKarp(int sNode, int eNode, int dimensao){
    int maxFlow = 0;
    while(true){
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
            if(c[prevNode][currNode]>=0){
                cout << currNode << " <- ";
                if (prevNode == sNode || prevNode == eNode){
                    cout << prevNode;
                }
            }
            currNode = prevNode;

        }
    cout << endl;
    }
    if(maxFlow >= dimensao){
        cout << "maxflow is: " << maxFlow << endl;
    }else{
        cout << "Como fluxo maximo e: " << maxFlow << ", uma dimensao de " << dimensao << " nao e possivel levar pelo grafo." << endl;
    }

}

// Functions for multiple testing
void cenario1_1_in01() {
    std::ofstream output;
    output.open("output.txt");
    cout << "Source vertice ? ";
    int source, sink;
    cin >> source;
    cout << endl;
    cout << "Sink vertice ? ";
    cin >> sink;
    cout << endl;
    int nodCount, edCount;
    int x1, x2, x3, x4;
    std::ifstream newfile("in01_b.txt");
    newfile >> x1 >> x2;
    if(source < 1 || sink > x1){
        cout << "Invalid source and sink" << endl << "source and sink must be between 1 and " << x1 << endl;
        return;
    }
    nodCount=x1;
    edCount=x2;
    Graph g(x1);
    for(int ed = 0; ed < edCount; ed++){
        newfile >> x1 >> x2 >> x3 >> x4;
        g.addEdge(x1,x2);
        c[x1][x2]=x3;
    }
    newfile.close();
    g.printAllPaths(source,sink, output);
    output.close();
    std::ifstream file("output.txt");
    read(file);
}
void cenario1_1_in02() {
    std::ofstream output;
    output.open("output.txt");
    cout << "Source vertice ? ";
    int source, sink;
    cin >> source;
    cout << endl;
    cout << "Sink vertice ? ";
    cin >> sink;
    cout << endl;
    int nodCount, edCount;
    int x1, x2, x3, x4;
    std::ifstream newfile("in02_b.txt");
    newfile >> x1 >> x2;
    if(source < 1 || sink > x1){
        cout << "Invalid source and sink" << endl << "source and sink must be between 1 and " << x1 << endl;
        return;
    }
    nodCount=x1;
    edCount=x2;
    Graph g(x1);
    for(int ed = 0; ed < edCount; ed++){
        newfile >> x1 >> x2 >> x3 >> x4;
        g.addEdge(x1,x2);
        c[x1][x2]=x3;
    }
    newfile.close();
    g.printAllPaths(source,sink, output);
    output.close();
    std::ifstream file("output.txt");
    read(file);
}
void cenario1_1_simples() {
    std::ofstream output;
    output.open("output.txt");
    cout << "Source vertice ? ";
    int source, sink;
    cin >> source;
    cout << endl;
    cout << "Sink vertice ? ";
    cin >> sink;
    cout << endl;
    int nodCount, edCount;
    int x1, x2, x3, x4;
    std::ifstream newfile("input_simples.txt");
    newfile >> x1 >> x2;
    if(source < 1 || sink > x1){
        cout << "Invalid source and sink" << endl << "source and sink must be between 1 and " << x1 << endl;
        return;
    }
    nodCount=x1;
    edCount=x2;
    Graph g(x1);
    for(int ed = 0; ed < edCount; ed++){
        newfile >> x1 >> x2 >> x3 >> x4;
        g.addEdge(x1,x2);
        c[x1][x2]=x3;
    }
    newfile.close();
    g.printAllPaths(source,sink, output);
    output.close();
    std::ifstream file("output.txt");
    read(file);
}
void cenario1_2_in01(){
    std::ofstream output;
    output.open("output.txt");
    cout << "Source vertice ? ";
    int source, sink;
    cin >> source;
    cout << endl;
    cout << "Sink vertice ? ";
    cin >> sink;
    cout << endl;
    int nodCount, edCount;
    int x1, x2, x3, x4;
    std::ifstream newfile("in01_b.txt");
    newfile >> x1 >> x2;
    if(source < 1 || sink > x1){
        cout << "Invalid source and sink" << endl << "source and sink must be between 1 and " << x1 << endl;
        return;
    }
    nodCount=x1;
    edCount=x2;
    Graph g(x1);
    for(int ed = 0; ed < edCount; ed++){
        newfile >> x1 >> x2 >> x3 >> x4;
        g.addEdge(x1,x2);
        c[x1][x2]=x3;
    }
    newfile.close();
    g.printAllPaths(source,sink, output);
    output.close();
    std::ifstream file("output.txt");
    read_transbordos(file);
}
void cenario1_2_in02(){
    std::ofstream output;
    output.open("output.txt");
    cout << "Source vertice ? ";
    int source, sink;
    cin >> source;
    cout << endl;
    cout << "Sink vertice ? ";
    cin >> sink;
    cout << endl;
    int nodCount, edCount;
    int x1, x2, x3, x4;
    std::ifstream newfile("in02_b.txt");
    newfile >> x1 >> x2;
    if(source < 1 || sink > x1){
        cout << "Invalid source and sink" << endl << "source and sink must be between 1 and " << x1 << endl;
        return;
    }
    nodCount=x1;
    edCount=x2;
    Graph g(x1);
    for(int ed = 0; ed < edCount; ed++){
        newfile >> x1 >> x2 >> x3 >> x4;
        g.addEdge(x1,x2);
        c[x1][x2]=x3;
    }
    newfile.close();
    g.printAllPaths(source,sink, output);
    output.close();
    std::ifstream file("output.txt");
    read_transbordos(file);
}
void cenario1_2_simples(){
    std::ofstream output;
    output.open("output.txt");
    cout << "Source vertice ? ";
    int source, sink;
    cin >> source;
    cout << endl;
    cout << "Sink vertice ? ";
    cin >> sink;
    cout << endl;
    int nodCount, edCount;
    int x1, x2, x3, x4;
    std::ifstream newfile("input_simples.txt");
    newfile >> x1 >> x2;
    if(source < 1 || sink > x1){
        cout << "Invalid source and sink" << endl << "source and sink must be between 1 and " << x1 << endl;
        return;
    }
    nodCount=x1;
    edCount=x2;
    Graph g(x1);
    for(int ed = 0; ed < edCount; ed++){
        newfile >> x1 >> x2 >> x3 >> x4;
        g.addEdge(x1,x2);
        c[x1][x2]=x3;
    }
    newfile.close();
    g.printAllPaths(source,sink, output);
    output.close();
    std::ifstream file("output.txt");
    read_transbordos(file);
}
void cenario2_1_in01(){
    std::ofstream output;
    output.open("output.txt");
    int dimensao;
    cout << "Que dimensao pretende?" << endl;
    cin >> dimensao;
    cout << "dimensao de: " << dimensao << endl;
    cout << "Source vertice ? ";
    int source, sink;
    cin >> source;
    cout << endl;
    cout << "Sink vertice ? ";
    cin >> sink;
    cout << endl;
    int nodCount, edCount;
    int x1, x2, x3, x4;
    std::ifstream newfile("in01_b.txt");
    newfile >> x1 >> x2;
    nodCount=x1;
    edCount=x2;
    if(source < 1 || sink > x1){
        cout << "Invalid source and sink" << endl << "source and sink must be between 1 and " << x1 << endl;
        return;
    }
    Graph graph(nodCount);
    source--;
    sink++;
    c[0][1] = dimensao;
    g[0].push_back(1);
    c[x1][x1+1] = dimensao;
    g[x1].push_back(x1+1);


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
    edmondsKarp(source,sink, dimensao);
}
void cenario2_1_in02(){
    std::ofstream output;
    output.open("output.txt");
    int dimensao;
    cout << "Que dimensao pretende?" << endl;
    cin >> dimensao;
    cout << "dimensao de: " << dimensao << endl;
    cout << "Source vertice ? ";
    int source, sink;
    cin >> source;
    cout << endl;
    cout << "Sink vertice ? ";
    cin >> sink;
    cout << endl;
    int nodCount, edCount;
    int x1, x2, x3, x4;
    std::ifstream newfile("in02_b.txt");
    newfile >> x1 >> x2;
    nodCount=x1;
    edCount=x2;
    if(source < 1 || sink > x1){
        cout << "Invalid source and sink" << endl << "source and sink must be between 1 and " << x1 << endl;
        return;
    }
    Graph graph(nodCount);
    source--;
    sink++;
    c[0][1] = dimensao;
    g[0].push_back(1);
    c[x1][x1+1] = dimensao;
    g[x1].push_back(x1+1);


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
    edmondsKarp(source,sink, dimensao);

}
void cenario2_1_simples(){
    std::ofstream output;
    output.open("output.txt");
    int dimensao;
    cout << "Que dimensao pretende?" << endl;
    cin >> dimensao;
    cout << "dimensao de: " << dimensao << endl;
    cout << "Source vertice ? ";
    int source, sink;
    cin >> source;
    cout << endl;
    cout << "Sink vertice ? ";
    cin >> sink;
    cout << endl;
    int nodCount, edCount;
    int x1, x2, x3, x4;
    std::ifstream newfile("input_simples.txt");
    newfile >> x1 >> x2;
    nodCount=x1;
    edCount=x2;
    if(source < 1 || sink > x1){
        cout << "Invalid source and sink" << endl << "source and sink must be between 1 and " << x1 << endl;
        return;
    }
    Graph graph(nodCount);
    source--;
    sink++;
    c[0][1] = dimensao;
    g[0].push_back(1);
    c[x1][x1+1] = dimensao;
    g[x1].push_back(x1+1);


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
    edmondsKarp(source,sink, dimensao);

}
void cenario2_3_in01(){
    std::ofstream output;
    output.open("output.txt");
    cout << "Source vertice ? ";
    int source, sink;
    cin >> source;
    cout << endl;
    cout << "Sink vertice ? ";
    cin >> sink;
    cout << endl;
    int nodCount, edCount;
    int x1, x2, x3, x4;
    std::ifstream newfile("in01_b.txt");
    newfile >> x1 >> x2;
    nodCount=x1;
    edCount=x2;
    if(source < 1 || sink > x1){
        cout << "Invalid source and sink" << endl << "source and sink must be between 1 and " << x1 << endl;
        return;
    }
    Graph graph(nodCount);
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
    edmondsKarp(source, sink, 0);
}
void cenario2_3_in02(){
    std::ofstream output;
    output.open("output.txt");
    cout << "Source vertice ? ";
    int source, sink;
    cin >> source;
    cout << endl;
    cout << "Sink vertice ? ";
    cin >> sink;
    cout << endl;
    int nodCount, edCount;
    int x1, x2, x3, x4;
    std::ifstream newfile("in02_b.txt");
    newfile >> x1 >> x2;
    nodCount=x1;
    edCount=x2;
    if(source < 1 || sink > x1){
        cout << "Invalid source and sink" << endl << "source and sink must be between 1 and " << x1 << endl;
        return;
    }
    Graph graph(nodCount);
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
    edmondsKarp(source, sink, 0);
}
void cenario2_3_simples(){
    std::ofstream output;
    output.open("output.txt");
    cout << "Source vertice ? ";
    int source, sink;
    cin >> source;
    cout << endl;
    cout << "Sink vertice ? ";
    cin >> sink;
    cout << endl;
    int nodCount, edCount;
    int x1, x2, x3, x4;
    std::ifstream newfile("input_simples.txt");
    newfile >> x1 >> x2;
    nodCount=x1;
    edCount=x2;
    if(source < 1 || sink > x1){
        cout << "Invalid source and sink" << endl << "source and sink must be between 1 and " << x1 << endl;
        return;
    }
    Graph graph(nodCount);
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
    edmondsKarp(source, sink, 0);
}


void displaymenu(){ cout<<"===================================================== \n";
cout<<" \t\tMENU \t \n ";
cout<<"===================================================== \n";
cout << "GRUPOS QUE NAO SE SEPARAM\n";
cout<<" 1.Maximizar a dimensao do grupo e indicar encaminhamento.(input 01)\n";
cout<<" 2.Maximizar a dimensao do grupo e indicar encaminhamento.(input 02)\n";
cout<<" 3.Maximizar a dimensao do grupo e indicar encaminhamento.(input simples)\n";
cout<<" 4.Maximizar a dimensao do grupo e minimizar o número de transbordos, sem privilegiar um dos critérios relativamente ao outro.(input 01)\n";
cout<<" 5.Maximizar a dimensao do grupo e minimizar o número de transbordos, sem privilegiar um dos critérios relativamente ao outro.(input 02)\n";
cout<<" 6.Maximizar a dimensao do grupo e minimizar o número de transbordos, sem privilegiar um dos critérios relativamente ao outro.(input simples)\n";
cout<<"===================================================== \n";
cout<<"GRUPOS QUE SE PODEM SEPARAR\n";
cout<<" 7.Determinar um encaminhamento para um grupo, dada a sua dimensão.(input 01)\n";
cout<<" 8.Determinar um encaminhamento para um grupo, dada a sua dimensão.(input 02)\n";
cout<<" 9.Determinar um encaminhamento para um grupo, dada a sua dimensão.(input simples)\n";
cout<<" 10.Determinar a dimensao maxima do grupo e um encaminhamento.(input 01)\n";
cout<<" 11.Determinar a dimensao maxima do grupo e um encaminhamento.(input 02)\n";
cout<<" 12.Determinar a dimensao maxima do grupo e um encaminhamento.(input simples)\n";

cout<<"===================================================== \n";
}


int main(){
    displaymenu();
    int yourchoice;
     cout<<"Enter your choice(1-12):";
        cin>>yourchoice;
        switch (yourchoice)
        {
            case 1: cenario1_1_in01(); break;
            case 2: cenario1_1_in02(); break;
            case 3: cenario1_1_simples(); break;
            case 4: cenario1_2_in01(); break;
            case 5: cenario1_2_in02(); break;
            case 6: cenario1_2_simples(); break;
            case 7: cenario2_1_in01(); break;
            case 8: cenario2_1_in02(); break;
            case 9: cenario2_1_simples(); break;
            case 10: cenario2_3_in01(); break;
            case 11: cenario2_3_in02(); break;
            case 12: cenario2_3_simples(); break;
            default: cout<<"invalid"; break;
        }

    return 0;
}