#include<bits/stdc++.h>
using namespace std;
int setBits(int N) 
{
    int cnt=0;
    while(N!=0)
    {
        if(N%2==1) cnt++;
        N=N/2;
    }
    return cnt;
}

vector<int> singleNumber(vector<int> nums) 
{
    vector<int> ans(2);
    int xxory =0;
    for(int val:nums) xxory=xxory^val;
    int rsb=xxory & -xxory;
    int off=0,on=0;
    for(int i=0;i<nums.size();i++)
    {
        if((nums[i] & rsb)==0) off=off^nums[i];
        else on=on^nums[i];
    }
    ans[0]=off;
    ans[1]=on;
    sort(ans.begin(),ans.end());
    return ans;
}

int countSetBits(int n)
{
    if(n==0) return 0;
    int x=0;
    while(pow(2,x)<=n) x++;
    x=x-1;
    int range=x*pow(2,x-1);
    int left=n-pow(2,x)+1;
    int res=countSetBits(n-pow(2,x));
    int ans=range+left+res;
    return ans;
}

int main()
{
    return 0;
}