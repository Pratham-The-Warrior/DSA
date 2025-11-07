
#include <bits/stdc++.h>
using namespace std;

// ------------------------- SORTING ALGORITHMS -------------------------

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[minIdx], arr[i]);
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partitionQS(int arr[], int low, int high)
{
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionQS(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ------------------------- SEARCHING ALGORITHMS -------------------------

// Linear Search
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

// Binary Search
int binarySearch(int arr[], int l, int r, int key)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

// ------------------------- GREEDY ALGORITHMS -------------------------

struct Item
{
    int value, weight;
};
bool cmp(Item a, Item b) { return (double)a.value / a.weight > (double)b.value / b.weight; }
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, cmp);
    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            res += arr[i].value;
        }
        else
        {
            res += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return res;
}

// ------------------------- GRAPH ALGORITHMS -------------------------

// BFS
void BFS(int s, vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
    }
}

// DFS
void DFSUtil(int v, vector<int> adj[], vector<bool> &visited)
{
    visited[v] = true;
    cout << v << " ";
    for (int u : adj[v])
        if (!visited[u])
            DFSUtil(u, adj, visited);
}
void DFS(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
        if (!visited[i])
            DFSUtil(i, adj, visited);
}

// Dijkstra
void dijkstra(vector<vector<pair<int, int>>> &adj, int src, int V)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < V; i++)
        cout << dist[i] << " ";
}

// Kruskal
struct Edge
{
    int u, v, w;
};
int findSet(int parent[], int i) { return (parent[i] == i) ? i : parent[i] = findSet(parent, parent[i]); }
void UnionSet(int parent[], int rank[], int x, int y)
{
    x = findSet(parent, x);
    y = findSet(parent, y);
    if (rank[x] < rank[y])
        parent[x] = y;
    else if (rank[x] > rank[y])
        parent[y] = x;
    else
    {
        parent[y] = x;
        rank[x]++;
    }
}
void kruskal(vector<Edge> edges, int V)
{
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.w < b.w; });
    int parent[V], rank[V];
    for (int i = 0; i < V; i++)
        parent[i] = i, rank[i] = 0;
    vector<Edge> mst;
    for (auto e : edges)
    {
        int x = findSet(parent, e.u), y = findSet(parent, e.v);
        if (x != y)
        {
            mst.push_back(e);
            UnionSet(parent, rank, x, y);
        }
    }
    for (auto e : mst)
        cout << e.u << " - " << e.v << " : " << e.w << "\\n";
}

// ------------------------- DYNAMIC PROGRAMMING -------------------------

// 0/1 Knapsack
int knapSack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

// Fibonacci
int fib(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// LCS
int LCS(string X, string Y)
{
    int m = X.size(), n = Y.size();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = (i == 0 || j == 0) ? 0 : (X[i - 1] == Y[j - 1] ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]));
    return dp[m][n];
}

// ------------------------- BACKTRACKING -------------------------

// N-Queens
bool isSafe(int board[10][10], int row, int col, int n)
{
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;
    return true;
}
bool solveNQUtil(int board[10][10], int col, int n)
{
    if (col >= n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col, n))
        {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1, n))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    cout << "DAA Algorithms in one file. Add test cases as needed.\\n";
    return 0;
}
