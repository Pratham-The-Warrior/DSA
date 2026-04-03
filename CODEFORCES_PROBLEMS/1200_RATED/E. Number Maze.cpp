#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// function to get k-th permutation (1-based index)
vector<int> getKthPermutation(vector<int> v, int k)
{
    int cnt = 1;

    do
    {
        if (cnt == k)
            return v;
        cnt++;
    } while (next_permutation(v.begin(), v.end()));

    return {}; // safety
}

vector<vector<int>> perms4 = {
    {1, 2, 3, 4},
    {1, 2, 4, 3},
    {1, 3, 2, 4},
    {1, 3, 4, 2},
    {1, 4, 2, 3},
    {1, 4, 3, 2},

    {2, 1, 3, 4},
    {2, 1, 4, 3},
    {2, 3, 1, 4},
    {2, 3, 4, 1},
    {2, 4, 1, 3},
    {2, 4, 3, 1},

    {3, 1, 2, 4},
    {3, 1, 4, 2},
    {3, 2, 1, 4},
    {3, 2, 4, 1},
    {3, 4, 1, 2},
    {3, 4, 2, 1},

    {4, 1, 2, 3},
    {4, 1, 3, 2},
    {4, 2, 1, 3},
    {4, 2, 3, 1},
    {4, 3, 1, 2},
    {4, 3, 2, 1}};

vector<vector<int>> perms3 = {
    {1, 2, 3},
    {1, 3, 2},

    {2, 1, 3},
    {2, 3, 1},

    {3, 1, 2},
    {3, 2, 1}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* ====================================
     the questionn basically asks us to find number of _A_B pairs present in jth and kth permuation
     of n
     so first we will have to find the permutations that can be formed by n then get the jth and kth permutations
     then check how many digit codes match the same position and value => A
     and remaing will be => B

     we have been given that n = {12,123,1234}

     12 = {12,21}
     123 = {123,132,213,231,312,321}
     1234 = {} around 24 combinations will come or we can use next_permutation() in STL


    ======================================*/

    int t;
    cin >> t;
    while (t--)
    {
        int n, j, k;
        cin >> n >> j >> k;

        if (n == 12)
        {
            if (j == k)
            {
                cout << "2A0B" << endl;
            }
            else
            {
                cout << "0A2B" << endl;
            }
            continue;
        }
        int ctA = 0;
        if (n == 123)
        {
            // check for the jth and kth permutation
            vector<int> t1 = perms3[j - 1];
            vector<int> t2 = perms3[k - 1];

            for (int i = 0; i < 3; i++)
            {
                if (t1[i] == t2[i])
                {
                    ctA++;
                }
            }

            cout << to_string(ctA) + 'A' + to_string(3 - ctA) + 'B' << endl;
            continue;
        }

        // now only case is 1234
        if (n == 1234)
        {
            vector<int> t1 = perms4[j - 1];
            vector<int> t2 = perms4[k - 1];

            for (int i = 0; i < 4; i++)
            {
                if (t1[i] == t2[i])
                {
                    ctA++;
                }
            }

            cout << to_string(ctA) + 'A' + to_string(4 - ctA) + 'B' << endl;
        }
    }

    return 0;
}