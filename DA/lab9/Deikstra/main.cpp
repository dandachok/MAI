#include <cstdint>
#include <iostream>
#include <vector>
#include <set>
#include <climits>

const uint64_t  MAX = ULLONG_MAX;

struct TEdge {
    TEdge(int v, uint64_t w) : vertex(v), wieght(w) {};

    int vertex;
    uint64_t wieght;
};


int main() {

    int countVertex;
    int countEdges;
    int start;
    int finish;

    std::cin >> countVertex >> countEdges;
    std::cin >> start >> finish;

    --start;
    --finish;

    std::vector<std::vector<TEdge>> gr(countVertex, std::vector<TEdge>());

    for(int i = 0; i < countEdges; ++i) {
        int v;
        int u;
        int w;
        
        std::cin >> v >> u >> w;

        --v;
        --u;

        gr[v].push_back(TEdge(u, w));
        gr[u].push_back(TEdge(v, w));
    }

    std::vector<uint64_t> distance(countVertex, MAX);

    distance[start] = 0;

    auto comp = [&distance] (const int& l, const int& r) ->bool {return distance[l] == distance[r] ? l < r: distance[l] < distance[r];};

    std::set<int, decltype(comp)> q(comp);

    q.insert(start);

    while (!q.empty()) {

        int v = *q.begin();
        q.erase(v);

        for (int i = 0; i < gr[v].size(); ++i) {
            int to = gr[v][i].vertex;
            uint64_t len = gr[v][i].wieght;

            if (distance[v] + len < distance[to]) {
                q.erase(to);
                distance[to] = distance[v] + len;
                q.insert(to);
            }
        }
    }

    if (distance[finish] == MAX) {
        std::cout << "No solution\n";
    } else {
        std::cout << distance[finish] << '\n';
    }

    return 0;
}
