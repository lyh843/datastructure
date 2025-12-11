#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const ll INF = 1e18;

int n, m;
int h[MAXN];
vector<pair<int, int>> adj[MAXN];
bool reachable[MAXN];
ll minInEdge[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> h[i];
    

    for (int i = 0; i < m; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        if (h[u] >= h[v]) adj[u].push_back({v, k});
        if (h[v] >= h[u]) adj[v].push_back({u, k});
    }

    queue<int> q;
    fill(reachable, reachable + n + 1, false);
    reachable[1] = true;
    q.push(1);

    // 找联通分量
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& e : adj[u]) {
            int v = e.first;
            if (!reachable[v]) {
                reachable[v] = true;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        minInEdge[i] = INF;
    }

    for (int u = 1; u <= n; u++) {
        if (!reachable[u]) continue;
        for (auto& e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if (reachable[v] && h[u] >= h[v]) {
                if (w < minInEdge[v]) {
                    minInEdge[v] = w;
                }
            }
        }
    }

    int countReachable = 0;
    ll totalCost = 0;
    for (int i = 1; i <= n; i++) {
        if (reachable[i]) {
            countReachable++;
            if (i != 1) {
                if (minInEdge[i] != INF) {
                    totalCost += minInEdge[i];
                }
            }
        }
    }

    cout << countReachable << " " << totalCost << "\n";

    return 0;
}