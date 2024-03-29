/*
  Problem Name:
  algorithm tag:
 /

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

set<pair<int, string>> st;
unordered_map<string, int> mp;
int main()
{
    st.insert({3, "#21"});
    st.insert({1, "32131"});
    st.insert({1, "3213"});

    auto t = *(st.begin());
    cout << t.first << " " << t.second << endl;

    auto t = *(st.begin());
    cout << t.first << " " << t.second << endl;
}  