#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int r, vector<int> & nums)
{
    if(n==0 || r<=0)
    {
        return 0;
    }
    
    int result = 0;
    int i=0;
    
    while(i<n)
    {
        int l = max(0, i-r+1);
        int h = min(n-1, i+r-1);
        
        while(h>=l)
        {
            if(nums[h])
            {
                break;
            }
            h--;
        }
        
        if(h<l)
        {
            return -1;
        }
        
        result++;
        i = h + r;
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    int n;
    int r;
  
    cin>>n>>r;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }
    
    int result = solve(n, r, nums);
    
    cout<<result<<endl;
    
    return 0;
}