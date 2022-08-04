#include<bits/stdc++.h>
using namespace std;
//MCM
int t[501][501];
int solveForMCM(int arr[],int i,int j)
{
    if(i>=j) return 0;
    if(t[i][j]!=-1) return t[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int tempAns=solveForMCM(arr,i,k)+solveForMCM(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        ans=min(ans,tempAns);
    }
    return t[i][j]=ans;
}
int matrixChainMultiplication(int N, int arr[])
{
    memset(t,-1,sizeof(t));
    return solveForMCM(arr,1,N-1);
}

//Palindrome Partioning
int t[501][501];
bool isPali(string str,int i,int j)
{
    while(i<j){
        if(str[i]!=str[j]) return false;
        i++;
        j--;
    }
    return true;
}
int solveForPP(string str,int i,int j)
{
    if(i>=j) return 0;
    if(t[i][j]!=-1) return t[i][j];
    if(isPali(str,i,j)) return 0;
    int ans=INT_MAX,right,left;
    for(int k=i;k<j;k++)
    {
        if(t[i][k]!=-1) left=t[i][k];
        else left=solveForPP(str,i,k);
        if(t[k+1][j]!=-1) right=t[k+1][j];
        else right=solveForPP(str,k+1,j);
        int tempAns=left+right+1;
        ans=min(ans,tempAns);
    }
    return t[i][j]=ans;
}
int palindromicPartition(string str)
{
    //O(n^3) solution
    memset(t,-1,sizeof(t));
    return solveForPP(str,0,str.size()-1);

    //O(n^2) solution
    
    // int n=s.size();
    // bool check[n][n];
    // for(int g=0;g<n;g++)
    // {
    //     for(int i=0,j=g;j<n;i++,j++)
    //     {
    //         if(g==0) check[i][j]=true;
    //         else if(g==1) check[i][j]=s[i]==s[j];
    //         else{
    //             if(s[i]==s[j] && check[i+1][j-1]==true) check[i][j]=true;
    //             else check[i][j]=false;
    //         }
    //     }
    // }
    // int dp[n];
    // dp[0]=0;
    // for(int j=1;j<n;j++)
    // {
    //     if(check[0][j]) dp[j]=0;
    //     else{
    //         int m=INT_MAX;
    //         for(int i=j;i>=1;i--)
    //         {
    //             if(check[i][j]) 
    //             {
    //                 if(dp[i-1]<m) m=dp[i-1];
    //             }
    //         }
    //         dp[j]=m+1;
    //         cout<<dp[j]<<" ";
    //     }
    // }
    // return dp[n-1];
}

//Boolean Parenthization
int t1[201][201][2];
int booleanParenthization(string s,int i,int j,bool isTrue)
{
    if(i>j) return 0;
    if(i==j)
    {
        if(isTrue) return s[i]=='T';
        else return s[i]=='F';
    }
    if(t1[i][j][isTrue]!=-1) return t1[i][j][isTrue];
    int ans=0;
    for(int k=i+1;k<j;k+=2)
    {
        int lT=booleanParenthization(s,i,k-1,true);
        int lF=booleanParenthization(s,i,k-1,false);
        int rT=booleanParenthization(s,k+1,j,true);
        int rF=booleanParenthization(s,k+1,j,false);
        if(s[k]=='&')
        {
            if(isTrue) ans+=rT*lT;
            else ans+=rT*lF+rF*lT+rF*lF;
        }
        else if(s[k]=='/')
        {
            if(isTrue) ans+=rT*lT+rF*lT+rT*lF;
            else ans+=rF*lF;
        }
        else{
            if(isTrue) ans+=rT*lF+rF*lT;
            else ans+=rF*lF+rT*lT;
        }
    }
    return ((t1[i][j][isTrue]=ans));
}
int countWays(int N, string S){
    memset(t1,-1,sizeof(t1));
    return booleanParenthization(S,0,N-1,true);
}

//WORD BREAK
int dp[1101][1101];
unordered_map<string,bool> dict;
int solve(string A,int i,int j)
{
    if(i>j) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(dict[A.substr(i,j-i+1)]) return 1;
    for(int k=i;k<j;k++)
    {
        if((solve(A,i,k)==1) &&(solve(A,k+1,j)==1)){
            return dp[i][j]=1;
        }
    }
    return dp[i][j]=0;
}
int wordBreak(string A, vector<string> &B) {
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<B.size();i++) dict[B[i]]=true;
    return solve(A,0,A.size()-1);
}

//SCRAMBLE STRING
unordered_map<string,bool> mp;
bool isScramble(string s1, string s2) {
    if(s1.size()==0 && s2.size()==0) return true;
    if(s1.size()!=s2.size()) return false;
    if(s1==s2) return true;
    if(s1.length()<=1) return false;
    string key=s1+" "+s2;
    if(mp.find(key)!=mp.end()) return mp[key];
    int n=s1.size();
    bool flag=false;
    for(int i=1;i<n;i++)
    {
        string a1=s1.substr(0,i);
        string b1=s2.substr(n-i,i);
        string c1=s1.substr(i,n-i);
        string d1=s2.substr(0,n-i);
        string c2=s2.substr(0,i);
        string d2=s2.substr(i,n-i);
        if((isScramble(a1,b1) && isScramble(c1,d1))||(isScramble(a1,c2) && isScramble(c1,d2))){
            flag=true;
            break;
        }
    }
    return mp[key]=flag;
}

//EGG DROPING
int t[201][201];
int eggDrop(int n,int k)
{
    if(k==1 || k==0) return k;
    if(n==1) return k;
    if(t[n][k]!=-1) return t[n][k];
    int mn=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        int tempAns=1+max(eggDrop(n,k-i),eggDrop(n-1,i-1));
        mn=min(mn,tempAns);
    }
    return t[n][k]=mn;
}

int main()
{
    memset(t,-1,sizeof(t));
    return 0;
}