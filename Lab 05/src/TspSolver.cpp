#include <TspSolver.h>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>

// Estrutura para armazenar arestas com comparador personalizado para a fila de prioridade
struct Edge {
    int from;
    int to;
    int weight;  // Distância inteira arredondada
    bool operator>(const Edge &e) const {
        if (weight != e.weight)
            return weight > e.weight;
        if (from != e.from)
            return from > e.from;
        return to > e.to;
    }
};

void TspSolver::solve(TspReader &tr, std::vector<int> &percourse) {
    int numCities = tr.getNumCities();
    std::vector<City> cities;
    tr.copyCitiesVector(cities);
    
    // Priority queue para selecionar a aresta de menor peso
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
    
    std::vector<bool> inMST(numCities, false);
    std::vector<Edge> mstEdges;
    
    // Começa com o vértice 1 (índice 0 no vetor)
    int start = 0;
    inMST[start] = true;
    int mstSize = 1;
    
    // Adiciona todas as arestas do vértice inicial à fila de prioridade
    for (int i = 1; i < numCities; i++) {
        pq.push({start, i, cities[start].disti(cities[i])});
    }
    
    // Constrói a árvore de custo mínimo utilizando Prim
    while (mstSize < numCities) {
        Edge e = pq.top();
        pq.pop();
        
        if (inMST[e.to]) continue;
        
        inMST[e.to] = true;
        mstEdges.push_back(e);
        mstSize++;
        
        for (int i = 0; i < numCities; i++) {
            if (!inMST[i]) {
                pq.push({e.to, i, cities[e.to].disti(cities[i])});
            }
        }
    }
    
    // Construção do ciclo C' percorrendo a MST em pré-ordem
    std::vector<int> visitOrder;
    std::vector<std::vector<int>> adjList(numCities);
    
    for (const auto &e : mstEdges) {
        adjList[e.from].push_back(e.to);
        adjList[e.to].push_back(e.from);
    }
    
    std::vector<bool> visited(numCities, false);
    std::function<void(int)> dfs = [&](int node) {
        visited[node] = true;
        visitOrder.push_back(node);
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor);
                visitOrder.push_back(node); // Adiciona novamente ao retornar
            }
        }
    };
    
    dfs(start);
    
    // Construção do ciclo C evitando arestas redundantes
    std::vector<bool> visitedFinal(numCities, false);
    for (int node : visitOrder) {
        if (!visitedFinal[node]) {
            visitedFinal[node] = true;
            percourse.push_back(node + 1); // Ajusta para 1-based index
        }
    }
    
    // Garante que é uma permutação de 1 a n
    if (percourse.size() != numCities) {
        percourse.clear();
        for (int i = 1; i <= numCities; i++)
            percourse.push_back(i);
    }
}
