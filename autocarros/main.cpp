#include <iostream>
#include <vector>
#include <fstream>
#include "transporte.cpp"
int V;
int veiculos;
int fordFulkerson(std::vector<transporte> vec, int s, int t) {
    int max_flow = 0;
    return max_flow;
}
void cenario1_1(std::vector<transporte> vec, int origem_grupo, int destino_grupo){
    int flow = 0;
    bool visited[veiculos];
    std::fill_n(visited, veiculos, false); //inicializa array todo falso

    for(int i=0; i<veiculos; i++){
        std::cout << visited[i] << std::endl;
    }
}
int main() {
    int graph[V][V];
    int x1, x2, x3, x4;
    std::vector<transporte> vec;
    std::ifstream newfile("in01.txt");
    newfile >> x1 >> x2;
    V = x1;
    veiculos = x2;
    for(int i=0; i<veiculos; i++){
        newfile >> x1 >> x2 >> x3 >> x4;
        vec.push_back(transporte(x1, x2, x3, x4, i));
    }
    newfile.close();
    newfile.open("in01.txt");
    newfile >> x1 >> x2;
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            newfile >> x1 >> x2 >> x3 >> x4;
            graph[i][j] = x3;
        }
    }
    std::cout << "VERTICES: " << V << " ARESTAS: " << veiculos << std::endl;
    for(int i=0; i<veiculos; i++){
        std::cout << "origem: " << vec.at(i).origem << " "
        << "destino: " << vec.at(i).destino<< " "
        << "capacidade: " << vec.at(i).capacidade<< " "
        << "duracao: " << vec.at(i).duracao<< " "
        << "id: " << vec.at(i).id << std::endl;
    }
    newfile.close();
    cenario1_1(vec, 4,40);
    return 0;
}
