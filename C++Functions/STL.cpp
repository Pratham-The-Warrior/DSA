#include <bits/stdc++.h>
using namespace std;

int main()
{
    // =============================
    // 1. VECTOR
    // =============================
    vector<int> v = {1, 2, 3};
    v.push_back(4);              // add element at end
    v.pop_back();                // remove last
    cout << v.size();            // number of elements
    cout << v.empty();           // check if empty
    cout << v.front();           // first element
    cout << v.back();            // last element
    v.insert(v.begin() + 1, 10); // insert
    v.erase(v.begin());          // erase element
    v.clear();                   // remove all

    // =============================
    // 2. DEQUE
    // =============================
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.pop_front();
    dq.pop_back();
    cout << dq.front() << dq.back();

    // =============================
    // 3. STACK
    // =============================
    stack<int> st;
    st.push(10);
    st.push(20);
    cout << st.top();
    st.pop();
    cout << st.empty();

    // =============================
    // 4. QUEUE
    // =============================
    queue<int> q;
    q.push(5);
    q.push(6);
    cout << q.front() << q.back();
    q.pop();

    // =============================
    // 5. PRIORITY QUEUE
    // =============================
    priority_queue<int> pq; // max-heap
    pq.push(10);
    pq.push(20);
    cout << pq.top();
    pq.pop();
    priority_queue<int, vector<int>, greater<int>> minpq; // min-heap

    // =============================
    // 6. SET
    // =============================
    set<int> s;
    s.insert(10);
    s.insert(20);
    cout << s.count(10);
    s.erase(20);
    auto it = s.find(10);
    auto lb = s.lower_bound(5);
    auto ub = s.upper_bound(10);

    // =============================
    // 7. MAP
    // =============================
    map<int, string> mp;
    mp[1] = "one";
    mp.insert({2, "two"});
    cout << mp.count(1);
    mp.erase(2);
    auto it2 = mp.find(1);
    auto lb2 = mp.lower_bound(1);
    auto ub2 = mp.upper_bound(1);

    // =============================
    // 8. ALGORITHMS – SEARCH & SORT
    // =============================
    vector<int> arr = {5, 2, 7, 1, 3};
    sort(arr.begin(), arr.end());                 // ascending
    sort(arr.begin(), arr.end(), greater<int>()); // descending
    stable_sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    cout << *max_element(arr.begin(), arr.end());
    cout << *min_element(arr.begin(), arr.end());
    cout << accumulate(arr.begin(), arr.end(), 0);
    cout << count(arr.begin(), arr.end(), 2);
    auto it3 = find(arr.begin(), arr.end(), 7);
    bool found = binary_search(arr.begin(), arr.end(), 3);
    auto lb3 = lower_bound(arr.begin(), arr.end(), 3);
    auto ub3 = upper_bound(arr.begin(), arr.end(), 3);
    auto range = equal_range(arr.begin(), arr.end(), 3);
    next_permutation(arr.begin(), arr.end());
    prev_permutation(arr.begin(), arr.end());

    // =============================
    // 9. ALGORITHMS – MODIFICATION
    // =============================
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    rotate(arr.begin(), arr.begin() + 2, arr.end());
    random_shuffle(arr.begin(), arr.end()); // (deprecated in C++17, use shuffle)
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(arr.begin(), arr.end(), rng);
    partition(arr.begin(), arr.end(), [](int x)
              { return x % 2 == 0; });
    stable_partition(arr.begin(), arr.end(), [](int x)
                     { return x % 2 == 0; });
    nth_element(arr.begin(), arr.begin() + 2, arr.end());
    vector<int> a = {1, 3}, b = {2, 4}, out(4);
    merge(a.begin(), a.end(), b.begin(), b.end(), out.begin());

    // =============================
    // 10. NUMERIC UTILITIES
    // =============================
    cout << __gcd(12, 18); // C++17
    vector<int> nums(5);
    iota(nums.begin(), nums.end(), 1); // 1,2,3,4,5
    vector<int> pref(5);
    partial_sum(nums.begin(), nums.end(), pref.begin());
    vector<int> diff(5);
    adjacent_difference(nums.begin(), nums.end(), diff.begin());
    cout << inner_product(a.begin(), a.end(), b.begin(), 0);
    cout << pow(2, 10);
    cout << sqrt(16) << cbrt(27);
    cout << ceil(2.3) << floor(2.9) << round(3.5);

    // =============================
    // 11. BIT OPERATIONS
    // =============================
    int x = 29;
    cout << __builtin_popcount(x);
    cout << __builtin_popcountll(1LL << 40);
    cout << __builtin_clz(x); // leading zeros
    cout << __builtin_ctz(x); // trailing zeros
    bitset<8> bs("10101010");
    cout << bs.count();
    cout << bs.any() << bs.none() << bs.all();

    // =============================
    // 12. STRING UTILITIES
    // =============================
    string s2 = "hello world";
    cout << s2.substr(0, 5);
    cout << s2.find("world");
    cout << s2.rfind("l");
    s2.erase(0, 5);
    s2.insert(0, "hi ");
    s2.replace(0, 2, "hey");
    s2.push_back('!');
    s2.pop_back();
    cout << stoi("123") + 5;
    cout << to_string(42);
    stringstream ss("10 20 30");
    int xx;
    while (ss >> xx)
        cout << xx;

    return 0;
}
