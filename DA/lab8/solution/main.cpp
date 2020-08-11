#include <iostream>
#include <vector>

bool cycl(int i, std::vector<std::vector<int> > &gr, std::vector<int > &col) {
    col[i] = 1;
    for(int j = 0; j < gr[i].size(); j++) {
        int to = gr[i][j];
        if(col[to] == 0) {
            if(cycl(to, gr, col)) return true;
        }
        else if(col[to] == 1) return true;
    }
    col[i] = 2;
    return false;
}

void dfs(int i, std::vector<std::vector<int> > &gr, std::vector<bool> &used, std::vector<int> &ans) {
    used[i] = true;
    for(int j = 0; j < gr[i].size(); j++) {
        int to = gr[i][j];
        if(!used[to]) {
            dfs(to, gr, used, ans);
        }
    }
    ans.push_back(i + 1);
}

void sort(std::vector<std::vector<int> > &gr, std::vector<int> &ans) {
    std::vector<bool> used(gr.size(),false);
    for(int i = 0; i < gr.size(); i++) {
        if(!used[i]) {
            dfs(i, gr, used, ans);
        }
    }
}

int main() {
    int n, m, a, b;
    std::cin >> n >> m;
    std::vector<std::vector<int> > graf(n, std::vector<int>());
    std::vector<int> answer(0);
    std::vector<int> color(n, 0);
    // input
    for(int i = 0; i < m; i++) {
        std::cin >> a >> b;
        graf[a - 1].push_back(b - 1);
    }
    // check cycl
    for(int i = 0; i < n; i++) {
        if(cycl(i, graf, color)) {
            std::cout << "-1\n";
            return 0;
        }
    }
    sort(graf, answer);
    for(int i = answer.size() - 1; i >= 0; i--) {
        std::cout << answer[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}