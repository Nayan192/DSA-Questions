#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> F;
unordered_map<int,bool> CS;
long long int GT[500][500];
// FIBONACCI WITH MEMOIZATION
int Fib(int n){
    if(F[n]) return F[n];
    if(n<=1) return 1;
    F[n]=Fib(n-1)+Fib(n-2);
    return F[n];
}
// GRID TRAVELLER MEMOIZATION
long long int gridTraveller(int n,int m)
{   
   if(GT[n][m]) return GT[n][m];
   if(n==1 && m==1) return 1;  
   if(n==0 || m==0) return 0;
   GT[n][m]=gridTraveller(n-1,m)+gridTraveller(n,m-1);
   return GT[n][m];  
//    long long int table[n+1][m+1];
//     for(int i=0;i<=n;i++)
//     {
//          for(int j=0;j<=m;j++)
//          {
//             table[i][j]=0;
//         }
//     }
//     table[1][1]=1;
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=m;j++)
//         {
//             long long int curr=table[i][j];
//             if(i+1<=n) table[i+1][j]+=curr;
//              if(j+1<=m) table[i][j+1]+=curr;
//         }
//     }
//    return table[n][m];  
}
//TARGET SUM PROBLEM
bool canSum(int targetSum,int* arr,int n)
{
    // if(CS.count(targetSum)>0) return CS[targetSum];
    // if(targetSum==0) return true;
    // if(targetSum<0) return false;
    // for(int i=0;i<n;i++)
    // {
    //     int remainder=targetSum-arr[i];
    //     if(canSum(remainder,arr,n)==true) {
    //         CS[targetSum]=true;
    //         return true;
    //     };
    // }
    // CS[targetSum]=false;
    // return false;
    bool table[targetSum+1];
    for(int i=0;i<=targetSum;i++)
        table[i]=false;
    table[0]=true;
    for(int i=0;i<=targetSum;i++)
    {
        if(table[i]==true)
        {
            for(int j=0;j<n;j++)
            {
                table[i+arr[j]]=true;
            }
        }
    }
    return table[targetSum];
}
/////../////
//KNAPSACK PROBLEMS START HERE
/*1ST*/
int dp[100][1000];
int knapsack(int* wt,int* val,int w,int n)
{
    // if(n==0||w==0)
    // return 0;
    // if(dp[n][w]) return dp[n][w];
    // if(wt[n-1]<=w)
    // {
    //     return (dp[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1)));
    // }
    // else return (dp[n][w]=knapsack(wt,val,w,n-1));
    int table[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0||j==0) table[i][j]=0;
            
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(wt[i-1]<=j)
            {
                table[i][j] =max(val[i-1]+table[i-1][j-wt[i-1]],table[i-1][j]);
            }
            else 
            {
                table[i][j]=table[i-1][j];
            }
        }
    }
    return table[n][w];
}
/*2ND*/
unordered_map<int,bool> ssdp;
bool subsetSum(int* arr,int n,int sum)
{
    // if(ssdp.count(sum)>0) return ssdp[sum];
    // if(sum==0) return true;
    // if(n==0) return false;
    // if(arr[n-1]<=sum) return (ssdp[sum]=(subsetSum(arr,n-1,sum-arr[n-1])||subsetSum(arr,n-1,sum)));
    // else return (ssdp[sum]=subsetSum(arr,n-1,sum));
    bool table[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0) table[i][j]=false;
            if(j==0) table[i][j]=true;
        }
    }
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
            {
                table[i][j]=(table[i-1][j-arr[i-1]]||table[i-1][j]);
            }
            else
           { table[i][j]=table[i-1][j];}
        }
    }

    return table[n][sum];
}
/*3RD*/
bool equalSum(int* arr,int n)
{
    int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];
    if(sum%2!=0) return false;
    else return subsetSum(arr,n,sum/2);
}
/*4TH*/
unordered_map<int,int> css;
int countSubsetSum(int* arr,int n,int sum)
{

    // if(sum==0)
    // {
    //     count+=1;
    //     return count;
    // }
    // if(n==0)
    // {
    //     count+=0;
    //     return count;
    // }
    // if(arr[n-1]<=sum) return (countSubsetSum(arr,n-1,sum-arr[n-1],count)+countSubsetSum(arr,n-1,sum,count));
    // else return (countSubsetSum(arr,n-1,sum,count));
    int table[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0) table[i][j]=0;
            if(j==0) table[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
            {
                table[i][j]=table[i-1][j-arr[i-1]]+table[i-1][j];
            }
            else
            {
                table[i][j]=table[i-1][j];
            }
        }
    }
    return table[n][sum];
}
/*5TH*/
int minSubsetDiffrence(int* arr,int n,int sum)
{
    bool table[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0) table[i][j]=false;
            if(j==0) table[i][j]=true;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
            {
                table[i][j]=(table[i-1][j-arr[i-1]]||table[i-1][j]);
            }
            else
            {
                table[i][j]=table[i-1][j];
            }
        }
    }
    vector<int> possibleValuesOfS1;
    for(int i=0;i<=sum/2;i++)
    {
        if(table[n][i]==true) {possibleValuesOfS1.push_back(i);}
    }
    int minValue=INT_MAX;
    for(int i=0;i<possibleValuesOfS1.size();i++)
    {
        //cout<<possibleValuesOfS1[i]<<" ";
        minValue=min(minValue,(sum-2*possibleValuesOfS1[i]));
    }
    return minValue;
}
int countSubsetWithGivenDiff(int* arr,int n,int diff)
{
    int sumOfArray=0;
    for(int i=0;i<n;i++)
    {
        sumOfArray+=arr[i];
    }
    int sum=(diff+sumOfArray)/2;
    return countSubsetSum(arr,n,sum);
}
//<!--UNBOUNDED KNAPSACK--->
int unboundedKnapsack(int* arr,int* val,int n,int w)
{
    if(n==0||w==0)
        return 0;
    if(arr[n-1]<=w) return max(unboundedKnapsack(arr,val,n,w-arr[n-1]),unboundedKnapsack(arr,val,n-1,w));
    else return unboundedKnapsack(arr,val,n-1,w);
}
//COIN CHANGE 2
int coinChange2(int* coin,int n,int s)
{
    int table[n+1][s+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(i==0) table[i][j]=INT_MAX-1;
            if(j==0) table[i][j]=0;
        }
    }
    for(int j=1;j<=s;j++)
    {
        if(j%coin[0]==0) table[1][j]=j/coin[0];
        else table[1][j]=INT_MAX-1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(coin[i-1]<=j)
            {
                table[i][j]=min(1+table[i][j-coin[i-1]],table[i-1][j]);
            }
            else table[i][j]=table[i-1][j];
        }
    }
    return table[n][s];
}
int main()
{
    // cout<<Fib(6)<<endl;
    // cout<<Fib(16)<<endl;
    // cout<<Fib(36)<<endl;
    // cout<<gridTraveller(2,3)<<endl;
    // cout<<gridTraveller(109,109)<<endl;
    // // memset(dp,-1,sizeof(dp));
    //  int val[3]={60,100,120};
    //  int wt[3]={10,20,30};
    //  cout<<knapsack(wt,val,50,3);
    // if(canSum(7,arr,4)) cout<<"YO";
    // else cout<<"lo";
    // int arr[5]={0,10,0,10,10};
    // if(equalSum(arr,5)) cout<<"yes";
    // else cout<<"no";
    // int arr[6]={2,3,5,6,8,10};
    // cout<<countSubsetSum(arr,6,10,0);
    // int arr[3]={1,2,7};
    // cout<<minSubsetDiffrence(arr,3,10);
    // int arr[] = { 3, 3, 3, 3 };
    // cout<<countSubsetWithGivenDiff(arr,4,6);
    int coin[3]={1,2,3};
    cout<<coinChange2(coin,3,5);
    return 0;
}