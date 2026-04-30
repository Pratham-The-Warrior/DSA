/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        // Process nums2
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            int element = nums2[i];

            while (!st.empty() && st.top() <= element)
            {
                st.pop();
            }

            if (st.empty())
            {
                nextGreater[element] = -1;
            }
            else
            {
                nextGreater[element] = st.top();
            }

            st.push(element);
        }

        // Build answer for nums1
        vector<int> ans;
        for (int num : nums1)
        {
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}