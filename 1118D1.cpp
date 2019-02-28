#include <iostream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>

using namespace std;

bool canFinish(vector<int> & nums, int m, int d)
{
    int n = nums.size();

    int sum = 0;
    for(int j=0; j<n; j++)
    {
        sum += max(0, nums[j] - (j/d));
    }

    return sum>=m;
}

int solve(vector<int> & nums, int m)
{
    int n = nums.size();

    sort(nums.rbegin(), nums.rend());

    for(int i=1; i<=n; i++)
    {
        if(canFinish(nums, m, i))
        {
            return i;
        }
    }

    return -1;
}

int solveMore(vector<int> & nums, int m)
{
    int n = nums.size();

    sort(nums.rbegin(), nums.rend());

    int l = 1;
    int r = n;

    if(!canFinish(nums, m, r))
    {
        return -1;
    }

    if(canFinish(nums, m, l))
    {
        return l;
    }

    while(l+1<r)
    {
        int mid = l + (r-l)/2;
        if(canFinish(nums, m, mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    return r;
}


int main()
{
    int n;
    int m;

    cin >> n >> m;

    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }

    int result = solveMore(nums, m);

    cout<<result<<endl;

    return 0;
}