#include<bits/stdc++.h>
using namespace std;

int countFriendsPairings(int n) 
{ 
    long long int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    int mod=1e9+7;
    for(int i=3;i<=n;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2]*(i-1))%mod;
    }
    return dp[n]%mod;
}

int goldMineProblem(int n, int m, vector<vector<int>> M)
{
    int dp[n][m];
    // memset(dp,0,sizeof(dp));
    for(int j=m-1;j>=0;j--)
    {
        for(int i=n-1;i>=0;i--) 
        {
            if(j==m-1) dp[i][j]=M[i][j];
            else if(i==0){
                dp[i][j]=M[i][j]+max(dp[i][j+1],dp[i+1][j+1]);
            }
            else if(i==n-1)
            {
                dp[i][j]=M[i][j]+max(dp[i][j+1],dp[i-1][j+1]);
            }
            else {
                dp[i][j]=M[i][j]+max(dp[i-1][j+1],max(dp[i][j+1],dp[i+1][j+1]));
            }
        }
    }
    int g=dp[0][0];
    for(int k=0;k<n;k++){
        if(dp[k][0]>g) g=dp[k][0];
    }
    return g;
}

int dp[10001];
int solve(int n,int x,int y,int z){ 
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int a,b,c;
    a=b=c=INT_MIN;
    if(x<=n) a=solve(n-x,x,y,z);
    if(y<=n) b=solve(n-y,x,y,z);
    if(z<=n) c=solve(n-z,x,y,z);
    int ans=1+max({a,b,c});
    return dp[n]=ans;
    }  
int maximizeTheCuts(int n, int x, int y, int z)
{
    memset(dp,-1,sizeof(dp));
    int ans=solve(n,x,y,z);
    return ans<0?0:ans;
    
}

int longestIncreasingSubsequence(int n, int a[])
{
    vector<int> dp(n);
    int g=0;
    for(int i=0;i<n;i++)
    {
        int m=0;
        for(int j=(i-1);j>=0;j--)
        {
            if(a[j]<a[i]) m=max(m,dp[j]);
        }
        dp[i]=m+1;
        g=max(g,dp[i]);
    }
    return g;
}

int maxSumIncreasingSubsequence(int arr[], int n)  
{  
    vector<int> dp(n);
    dp[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=arr[i];
        for(int j=(i-1);j>=0;j--)
        {
            if(arr[j]<arr[i]){
                int possibleAns=arr[i]+dp[j];
                dp[i]=max(possibleAns,dp[i]);
            }
        }
    }
    //for(int i=0;i<n;i++) cout<<dp[i]<<" ";
    return *max_element(dp.begin(),dp.end());
}  

int longestSubsequenceWithAdjacentDiffrenceOne(int arr[], int n)  
{  
    vector<int> dp(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=(i-1);j>=0;j--)
        {
            if(abs(arr[j]-arr[i])==1){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    //for(int i=0;i<n;i++) cout<<dp[i]<<" ";
    return *max_element(dp.begin(),dp.end());
}  

int editDistance(string word1, string word2) 
{
    int n=word1.size();
    int m=word2.size();
    int t[n+1][m+1];
    for(int i=0;i<=m;i++) t[0][i]=i;
    for(int i=0;i<=n;i++) t[i][0]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]) t[i][j]=t[i-1][j-1];
            else{
                t[i][j]=1+min(t[i-1][j],min(t[i][j-1],t[i-1][j-1]));
            }
        }
    }
    return t[n][m];
}

int maxSquareWithAllOnes(int n, int m, vector<vector<int>> mat){
    int dp[n][m];
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==n-1 && j==m-1) dp[i][j]=mat[i][j];
            else if(i==n-1) dp[i][j]=mat[i][j];
            else if(j==m-1) dp[i][j]=mat[i][j];
            else{ 
                if(mat[i][j]==0) dp[i][j]=0;
                else dp[i][j]=1+min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
            }
        }
        
    }
    int ans=dp[0][0];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans=max(dp[i][j],ans);
        }
    }
    return ans;
}

int kadaneAlgorithm(vector<int> arr,int n)
{
    int max=arr[0];
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum<arr[i]) sum=arr[i];
        if(max<sum) max=sum;
        
    }
    return max;
}

int countPalindromicSubstrings(string s) {
    int n=s.size(),cnt=0;
    int t[n][n];
    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            if(gap==0) t[i][j]=1;
            else if(gap==1)
            {
                if(s[i]==s[j]) t[i][j]=1;
                else t[i][j]=0;
            }
            else{
                if(s[i]==s[j] && t[i+1][j-1]==1) t[i][j]=1;
                else t[i][j]=0;
            }
            if(t[i][j]==1) cnt++;
        }
    }
    return cnt;
}

int countPalindromicSubsequence(string s)
{
    int n=s.size();
    int t[n][n];
    for(int g=0;g<n;g++)
    {
        for(int i=0,j=g;j<n;i++,j++)
        {
            if(g==0) t[i][j]=1;
            if(g==1) t[i][j]=s[i]==s[j]?3:2;
            else{
                if(s[i]==s[j]) t[i][j]=t[i+1][j]+t[i][j-1]+1;
                else t[i][j]=t[i+1][j]+t[i][j-1]-t[i+1][j-1];
            }
        }
    }
    return t[0][n-1];
}

long long optimalStrategyToWin(int arr[], int n){
    long long int t[n][n];
    for(long long int g=0;g<n;g++)
    {
        for(long long int i=0,j=g;j<n;i++,j++)
        {
            if(g==0) t[i][j]=arr[i];
            else if(g==1) t[i][j]=max(arr[i],arr[j]);
            else
            {
                long long int left=arr[i]+min(t[i+2][j],t[i+1][j-1]);
                long long int right=arr[j]+min(t[i][j-2],t[i+1][j-1]);
                t[i][j]=max(left,right);
            }
        }
    }
    return t[0][n-1];
}

struct Job
{
    int id;
    int dead;
    int profit;
};
bool comparison(Job a,Job b)
{
    return (a.profit>b.profit);
}
vector<int> JobScheduling(Job arr[], int n) 
{ 
    sort(arr,arr+n,comparison);
    int mdeadline=arr[0].dead,cnt=0,sum=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i].dead>mdeadline) mdeadline=arr[i].dead;
    }
    vector<int> jsq(mdeadline+1,-1);
    for(int i=0;i<n;i++)
    {
        for(int j=arr[i].dead;j>0;j--)
        {
            if(jsq[j]==-1)
            {
                jsq[j]=arr[i].id;
                cnt++;
                sum+=arr[i].profit;
                break;
            }
        }
    }
    vector<int> res(2);
    res[0]=cnt;
    res[1]=sum;
    return res;
} 

int countDerangements(int n)
{
  // Base cases
  if (n == 1) return 0;
  if (n == 2) return 1;
 
  // countDer(n) = (n-1)[countDer(n-1) + der(n-2)]
  return (n - 1) * (countDerangements(n - 1) + countDerangements(n - 2));
}

int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
    int m=INT_MIN;
    for(int i=0;i<R;i++)
    {
        vector<int> ans(C);
        for(int j=i;j<R;j++)
        {
            for(int k=0;k<C;k++)
            {
                ans[k]+=M[j][k];
            }
            m=max(m,kadaneAlgorithm(ans,ans.size()));
        }
    }
    return m;
}

int maxProfitByStockWithKtransactions(int K, int N, int A[]) {
    // code here
    int t[K+1][N];
    memset(t,0,sizeof(t));
    for(int i=1;i<=K;i++)
    {
        int m=INT_MIN;
        for(int j=1;j<N;j++)
        {
            m=max(m,t[i-1][j-1]-A[j-1]);
            t[i][j]=max(t[i][j-1],m+A[j]);
        }
    }
    return t[K][N-1];
}

int wildCard(string pattern,string str)
{
    int m=str.size(),n=pattern.size();
    int dp[n+1][m+1];
    for(int i=n;i>=0;i--)
    {
        for(int j=m;j>=0;j--)
        {
            if(i==n && j==m) dp[i][j]=1;
            else if(i==n) dp[i][j]=0;
            else if(j==m)
            {
                if(pattern[i]=='*') dp[i][j]=dp[i+1][j];
                else dp[i][j]=0;
            }
            else{
                if(pattern[i]=='?'){
                    dp[i][j]=dp[i+1][j+1];
                }
                else if(pattern[i]=='*'){
                    dp[i][j]=dp[i+1][j]||dp[i][j+1];
                }
                else{
                    dp[i][j]=str[j]==pattern[i]?dp[i+1][j+1]:0;
                }
            }
        }
    }
    return dp[0][0];
}

int numberOfArithmeticSlicesSubSequences(vector<int>& nums) {
        int n=nums.size(),ans=0;
        unordered_map<long long,int> mp[n];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long long diff=(long long)nums[i]-nums[j];
                int cnt=mp[j].count(diff)?mp[j][diff]:0;
                ans+=cnt;
                mp[i][diff]+=cnt+1;
            }
        }
        return ans;
    }

bool regularExpressionMatch(string s, string p) {
    int n=p.size(),m=s.size();
    bool dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 && j==0) dp[i][j]=true;
            else if(i==0) dp[i][j]=false;
            else if(j==0)
            {
                if(p[i-1]=='*') dp[i][j]=dp[i-2][j];
                else dp[i][j]=false;
            }
            else
            {
                if(p[i-1]=='.') dp[i][j]=dp[i-1][j-1];
                else if(p[i-1]=='*')
                {
                    dp[i][j]=dp[i-2][j];
                    if(p[i-2]=='.' || p[i-2]==s[j-1]) 
                        dp[i][j]=dp[i][j]||dp[i][j-1];
                }
                else{
                    dp[i][j]=p[i-1]==s[j-1]?dp[i-1][j-1]:false;
                }
            }
        }
    }
    return dp[n][m];
}

vector<vector<int>> nearestCellWithZerosOrOnes(vector<vector<int>>grid)
{
    int n=grid.size(),m=grid[0].size();
    int INF=m+n;
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1) continue;
            int top=INF,left=INF;
            if(i-1>=0) top=dp[i-1][j];
            if(j-1>=0) left=dp[i][j-1];
            dp[i][j]=min(left,top)+1;
        }
    }
        for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(grid[i][j]==1) continue;
            int bottom=INF,right=INF;
            if(i+1<n) bottom=dp[i+1][j];
            if(j+1<m) right=dp[i][j+1];
            dp[i][j]=min(dp[i][j],min(bottom,right)+1);
        }
    }
    return dp;
}

int main()
{
    return 0;
}