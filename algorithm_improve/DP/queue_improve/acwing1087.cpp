/*
  Problem Name:修剪草坪  
  algorithm tag:
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

#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1e5 + 50;

ll s[N];
ll f[N];
ll q[N];
int n, k;

ll g(int i)
{
    if (!i)
        return 0;
    else
        return f[i - 1] - s[i];
}

int main()
{
    iosf;

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s[i] = s[i - 1] + x;
    }

    int hh = 0, tt = 0;

    for (int i = 1; i <= n; i++) {
        while (q[hh] < i - k)
            hh++;
        f[i] = max(f[i - 1], g(q[hh]) + s[i]);

        while (g(q[tt]) <= g(i) && tt >= hh)
            tt--;
        q[++tt] = i;
    }

    cout << f[n] << endl;
}