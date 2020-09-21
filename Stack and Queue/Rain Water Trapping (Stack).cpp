#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int trappedWater(int height[])
{
    stack <int> stk;    // stores the indexes with decreasing height
    int maxWater = 0;

    for (int curr = 0; curr< n; curr++)
    {
        while(! stk.empty() && height[curr] > height[stk.top()])   // if current bar height is greater than to be filled bar
        {
            int top = stk.top();          // pop the to be filled bar
            stk.pop();
            
            if (stk.empty())              // no bar before to be filled bar
                break;
            
            int distance = curr - stk.top() - 1;     // calculate amount of water can be filled in to be filled bar
            int bounded_height = min(height[curr], height[stk.top()]) - height[top];   
            maxWater += distance * bounded_height;
        }
        stk.push(curr);                 // push the index of current bar
    }

    return maxWater;
}

void test_case()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 1, 1};  n = sizeof(arr) / sizeof(arr[0]);

    cout << trappedWater(arr);

    cout << endl;
    return;
}



























void solve()
{
    int t;
    t = 1;
    // cin >> t;
    for (int nr = 1; nr <= t; nr++)
    {
        test_case();
    }
}

int main()
{   
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //synchronize c++ streams with c streams
    ios_base::sync_with_stdio(false);
    //guarentes flushing
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
