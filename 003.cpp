#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> bfs(int start, const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> dist(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int nv : graph[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }

    int far_v = start;
    for (int i = 0; i < n; i++) {
        if (dist[i] > dist[far_v]) {
            far_v = i;
        }
    }
    return { far_v, dist[far_v] };
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> g(N);

    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        g[A].push_back(B);
        g[B].push_back(A);
    }

    pair<int, int> res1 = bfs(0, g);
    int s = res1.first;

    pair<int, int> res2 = bfs(s, g);
    int diameter = res2.second;

    cout << diameter + 1 << '\n';

    return 0;
}
