/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/**
 * Standard Fenwick Tree (BIT) for point updates and range sums.
 */
struct FenwickTree
{
  int n;
  vector<int> tree;

  FenwickTree(int n) : n(n), tree(n + 1, 0) {}

  void add(int idx, int val)
  {
    for (; idx <= n; idx += idx & -idx)
    {
      tree[idx] += val;
    }
  }

  int query(int idx)
  {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
    {
      sum += tree[idx];
    }
    return sum;
  }

  int queryRange(int l, int r)
  {
    return query(r) - query(l - 1);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  /* ====================================

    here logic seems simple but time complexity is the big problem as  we will have to find a way to
    answer each query in O(1) or atmax O(logn) time
    to ensure the each block in a subrectangle is attacked by a rook we would need to ensure that if there is at least
    one rook either in its row or in its column then only we can say that the position will be attacked by the rook



    A Fenwick Tree (BIT) is a data structure that supports:
      Point update
      Prefix sum query
      in O(log n) time.
   ====================================*/
  int n, q;
  cin >> n >> q;
  vector<int> row(n + 1, 0), col(n + 1, 0);
  /*
  row_counts: We need this because multiple rooks can be in
  one row. We only care if a row goes from "empty to occupied"
  or "occupied to empty."
  row_bit: This is what we use for the range query. It tracks the status (filled/not filled) of the rows.
  */
  FenwickTree row_bit(n), col_bit(n);

  while (q--)
  {
    int t;
    cin >> t;
    if (t == 1)
    {
      int x, y;
      cin >> x >> y;
      if (row[x] == 0)
        row_bit.add(x, 1);
      row[x]++;
      if (col[y] == 0)
        col_bit.add(y, 1);
      col[y]++;
    }
    else if (t == 2)
    {
      int x, y;
      cin >> x >> y;
      row[x]--;
      if (row[x] == 0)
        row_bit.add(x, -1);
      col[y]--;
      if (col[y] == 0)
        col_bit.add(y, -1);
    }
    else
    {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;

      // Check if all rows in range are occupied
      bool rows_covered = (row_bit.queryRange(x1, x2) == (x2 - x1 + 1));
      // Check if all columns in range are occupied
      bool cols_covered = (col_bit.queryRange(y1, y2) == (y2 - y1 + 1));

      if (rows_covered || cols_covered)
      {
        cout << "Yes";
      }
      else
      {
        cout << "No";
      }
      cout << endl;
    }
  }

  return 0;
}