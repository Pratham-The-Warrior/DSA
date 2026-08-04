// /*-------------------------------------------------------------
//    NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
// ---------------------------------------------------------------*/

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string a, b;
//     cin >> a >> b;

//     int n = a.size(), m = b.size();

//     int cnt = 0;

//     for (int i = 0; i <= n - m; i++)
//     {
//         bool ok = true;
//         for (int j = 0; j < m; j++)
//         {
//             if (a[j + i] != b[j])
//             {
//                 ok = false;
//                 break;
//             }
//         }
//         if (ok)
//             cnt++;
//     }

//     cout << cnt;

//     return 0;
// }

//**************************KMP**************************/
//! optimized

/*
tep 1: Build the LPS array

LPS = Longest Proper Prefix which is also a Suffix

For every position i in the pattern,

lps[i] tells us the length of the longest prefix of the pattern that is also a suffix of pattern[0...i].


Pattern = a b a b a c

Index      0 1 2 3 4 5
Pattern    a b a b a c
LPS        0 0 1 2 3 0







*/

/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> lps(string &p)
{
    int m = p.size();
    vector<int> pi(m);

    for (int i = 1, j = 0; i < m; i++)
    {

        while (j > 0 && p[i] != p[j])
        {
            j = pi[j - 1];
        }

        if (p[i] == p[j])
        {
            j++;
        }

        pi[i] = j;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}