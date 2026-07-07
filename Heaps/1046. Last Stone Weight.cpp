/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
}
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        int n = stones.size();

        // use priority quue to simulate the situtaion at last output pq.top

        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if (x != y)
            {
                pq.push(x - y);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};