/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
*PROBLEM STATEMENT
Student Dima from Kremland has a matrix a
of size n×m filled with non-negative integers.
He wants to select exactly one integer from each row of the matrix
so that the bitwise exclusive OR of the selected integers is strictly
greater than zero. Help him!
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
i am thinking
since n,m <= 500 and a[i]<1024
that means there are around 10 bits at max
so for each row i will mantain a vector<int>bit(10)  in this i will storre count of bit position found
in that row of a[i]...
do this for all rows so we will get a vector<vector<>>
now loop over each bit one by one
lets start from first bit i.e(2^0) , see the only case
in which we could not use this bit will be when the count of this bit
in thee vector we made from bit count is n across all m rows
that is it is present in all a[i]
and if m is odd thats okay we can take that as xor of that all nums and get a non zero
but if it even , cnt++ , if this cnt becomes equal to 10 or simply all bits 0...10 are in same condition then
in that case it wont be possible cout<<"NO"
except that case we can get n integer positions



*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int curr_xor = 0, change_row = -1, change_col = -1;

    vector<int> first_col(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            if (j == 0)
            {
                first_col[i] = val;
                curr_xor ^= val;
            }
            else if (val != first_col[i])
            {
                change_row = i;
                change_col = j;
                // we can take last mismatch
            }
        }
    }

    if (curr_xor > 0 || change_row != -1)
    {
        cout << "TAK" << endl;

        for (int i = 0; i < n; i++)
        {
            if (curr_xor == 0 && i == change_row)
            {                                  // only if curr_xor becomes zero else all 1s is okay
                cout << change_col + 1 << " "; // 1 based
            }
            else
            {
                cout << 1 << " ";
            }
        }
    }
    else
    {
        cout << "NIE" << endl;
    }

    return 0;
}