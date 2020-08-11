#include <algorithm>
#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>>& graph, std::vector<bool>& used, int v, std::vector<int>& component) {

    used[v] = true;
    component.push_back(v);
    for (int i = 0; i < graph[v].size(); ++i) {
        if (!used[graph[v][i]]) {
            dfs(graph, used, graph[v][i], component);
        }
    }

}

int main() {

    int countVertex;
    int countEdges;

    std::cin >> countVertex >> countEdges;

    std::vector<std::vector<int>> graph(countVertex, std::vector<int>());

    for (int i = 0; i < countEdges; ++i) {
        
        int u;
        int v;

        std::cin >> u >> v;
        
        --u;
        --v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::vector<bool> used(countVertex, false);
    std::vector<std::vector<int>> components;

    for (int i = 0; i < graph.size(); ++i) {
        if(!used[i]) {
            std::vector<int> component;
            dfs(graph, used, i, component);
            components.push_back(component);
        }
    }

    for (auto& i: components) {
        std::sort(i.begin(), i.end());
    }

    std::sort(components.begin(), components.end(), [] (const std::vector<int>& l, const std::vector<int>& r) ->bool {return l[0] < r[0];});

    for (const auto& i: components) {
        for (const auto& j: i) {
            std::cout << j + 1 << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}


