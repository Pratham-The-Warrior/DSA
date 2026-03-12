#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// dsu implementation
vector<int> parent, sz;
int find(int a)
{
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]);
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return;
    if (sz[a] < sz[b])
        swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // dsu question

    int n, m;
    cin >> n >> m;

    parent.resize(n);

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    sz.resize(n, 1);

    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        int first;
        if (k)
        {
            cin >> first;
            first--;
            for (int j = 1; j < k; j++)
            { // join all to first node
                int a;
                cin >> a;
                a--;
                join(first, a);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        // output size of graph the a[i] is part of
        cout << sz[find(i)] << " ";
    }

    return 0;
}
