/*
  Problem Name:信使
  algorithm tag:dijkstra
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define x first
#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 105, M = 205;

int n, m;
vector<pii> g[N];
int dist[N];
bool state[N];

void dij()
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, 1});
    dist[1] = 0;
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        if (state[t.y])
            continue;
        state[t.y] = 1;

        for (auto v : g[t.y]) {
            if (dist[v.y] > dist[t.y] + v.x) {
                dist[v.y] = dist[t.y] + v.x;
                heap.push({dist[v.y], v.y});
            }
        }
    }
}

int main()
{
    iosf;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }
    dij();
    bool is_valid = true;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 0x3f3f3f3f) {
            is_valid = false;
            break;
        } else
            ans = max(ans, dist[i]);
    }

    if (is_valid)
        cout << ans << endl;
    else
        cout << -1 << endl;
}