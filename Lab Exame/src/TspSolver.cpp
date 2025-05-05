#include <TspSolver.h>
#include <queue>
#include <set>
#include <functional>
#include <algorithm>
#include <limits>

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

// Função auxiliar para encontrar um caminho Euleriano
void findEulerianPath(int node, std::vector<std::multiset<int>> &adjList, std::vector<int> &path) {
    while (!adjList[node].empty()) {
        int neighbor = *adjList[node].begin();
        adjList[node].erase(adjList[node].begin());
        adjList[neighbor].erase(adjList[neighbor].find(node));
        findEulerianPath(neighbor, adjList, path);
    }
    path.push_back(node);
}

// Função auxiliar para encontrar um Casamento Mínimo
std::vector<Edge> findMinimumMatching(const std::vector<int> &oddVertices, const std::vector<City> &cities) {
    std::vector<Edge> matching;
    std::vector<bool> matched(oddVertices.size(), false);
    for (size_t i = 0; i < oddVertices.size(); ++i) {
        if (!matched[i]) {
            int u = oddVertices[i];
            int minDist = std::numeric_limits<int>::max();
            int minIndex = -1;
            for (size_t j = i + 1; j < oddVertices.size(); ++j) {
                if (!matched[j]) {
                    int v = oddVertices[j];
                    // Usa const_cast para converter a referência constante
                    int dist = const_cast<City&>(cities[u]).disti(const_cast<City&>(cities[v]));
                    if (dist < minDist) {
                        minDist = dist;
                        minIndex = j;
                    }
                }
            }
            if (minIndex != -1) {
                int v = oddVertices[minIndex];
                matching.push_back(Edge{u, v, const_cast<City&>(cities[u]).disti(const_cast<City&>(cities[v]))});
                matched[i] = true;
                matched[minIndex] = true;
            }
        }
    }
    return matching;
}

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
        pq.push({start, i, const_cast<City&>(cities[start]).disti(const_cast<City&>(cities[i]))});
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
                pq.push({e.to, i, const_cast<City&>(cities[e.to]).disti(const_cast<City&>(cities[i]))});
            }
        }
    }

    // Encontra vértices de grau ímpar na MST
    std::vector<int> degree(numCities, 0);
    for (const auto &e : mstEdges) {
        degree[e.from]++;
        degree[e.to]++;
    }

    std::vector<int> oddVertices;
    for (int i = 0; i < numCities; ++i) {
        if (degree[i] % 2 != 0) {
            oddVertices.push_back(i);
        }
    }

    // Encontra um Casamento Mínimo nos vértices de grau ímpar
    std::vector<Edge> matching = findMinimumMatching(oddVertices, cities);

    // Une as arestas da MST e do Casamento Mínimo para formar um multigrafo
    std::vector<std::multiset<int>> multigraph(numCities);
    for (const auto &e : mstEdges) {
        multigraph[e.from].insert(e.to);
        multigraph[e.to].insert(e.from);
    }
    for (const auto &e : matching) {
        multigraph[e.from].insert(e.to);
        multigraph[e.to].insert(e.from);
    }

    // Encontra um caminho Euleriano no multigrafo resultante
    std::vector<int> eulerianPath;
    findEulerianPath(start, multigraph, eulerianPath);

    // Remove arestas redundantes para criar o ciclo Hamiltoniano
    std::vector<bool> visited(numCities, false);
    for (int node : eulerianPath) {
        if (!visited[node]) {
            visited[node] = true;
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
