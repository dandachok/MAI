#include <cstdint>
#include <climits>
#include <iostream>
#include <vector>

const int64_t MAX = LLONG_MAX;

struct TEdge {
    TEdge(int v, int64_t w): vertex(v), wieght(w) {}
    
    int vertex;
    int64_t wieght;
};

int main() {

    std::ios::sync_with_stdio(false);
    int countVertex;
    int countEdges;
    int start;
    int finish;
    
    std::cin >> countVertex >> countEdges;
    std::cin >> start >> finish;

    --start;
    --finish;

    std::vector<std::vector<TEdge>> gr(countVertex, std::vector<TEdge>());

    for (int i = 0; i < countEdges; ++i) {
        int u;
        int v;
        int64_t w;

        std::cin >> u >> v >> w;
        --u;
        --v;
        gr[u].push_back(TEdge(v, w));
    }

    std::vector<int64_t> distance(countVertex, MAX);
    distance[start] = 0;

    bool isChange;
    for (int k = 0; k < countVertex; ++k) {
        isChange = false;
        for (int i = 0; i < countVertex; ++i) {
            for (int j = 0; j < gr[i].size(); ++j) {
                if (distance[i] != MAX && distance[gr[i][j].vertex] > distance[i] + gr[i][j].wieght) {
                    distance[gr[i][j].vertex] = distance[i] + gr[i][j].wieght;
                    isChange = true;
                }
            }
        }

        if (!isChange) {
            break;
        }
    }

    if (distance[finish] == MAX) {
        std::cout << "No solution\n";
    } else {
        std::cout << distance[finish] << '\n';
    }

    return 0;

}

