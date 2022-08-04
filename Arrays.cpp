#include<bits/stdc++.h>
using namespace std;
// Function to print the array
void display(int arr[], int right){
  for (int i=0;i<=right;++i){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int kthSmallest(vector<int> arr,int l,int r,int k){
    //O(nlogk)
    // priority_queue<int,vector<int>,greater<int>> minhp;
    // for(int i=0;i<v.size();i++) {
    //     minhp.push(v[i]);
    //     if(minhp.size()>k) minhp.pop();
    // }
    // return minhp.top();

    //O(n)-average case (**for Kth Largest pass n-k+1 instead of k**)
    int pivot=arr[r];
    int p=l;
    for(int i=l;i<r;i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr[i],arr[p]);
            p++;
        }
    }
    swap(arr[r],arr[p]);
    if(p>k-1) return kthSmallest(arr,l,p-1,k);
    else if(p<k-1) return kthSmallest(arr,p+1,r,k);
    return arr[p];
}

void moveNegativeElements(int arr[],int n){
    int l=0,r=n-1;
    while(l<r)
    {
        if(arr[l]<0 && arr[r]>0){
            l++;
            r--;
        }
        else if(arr[l]<0 && arr[r]<0){
            l++;
        }
        else if(arr[l]>0 && arr[r]<0){
            swap(arr[l],arr[r]);
            l++;
            r--;
        }
        else if(arr[l]>0 && arr[r]>0){
            r--;
        }
    }
}

int KadaneAlgorithm(int arr[],int n)
{
    int m=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>m) m=arr[i];
    }
    if(m<=0) return m;
    int sum=0,ans=0;
    for(int i=0;i<n;i++)
    {
        if(sum+arr[i]<0) {
            sum=0;
        }
        else sum+=arr[i];
        ans=max(sum,ans);
    }
    return ans;
}

int minimizeMaxheights(int arr[], int n, int k) {
    sort(arr,arr+n);
    int mx=0,mn=0,res=0;
    res=arr[n-1]-arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>=k){
            mx=max(arr[i-1]+k,arr[n-1]-k);
            mn=min(arr[i]-k,arr[0]+k);
            res=min(res,mx-mn);
        }
        else continue;
    }
    return res; 
}

int minimumjumps(int arr[],int n)
{
    if(arr[0]==0 && n!=1) return -1;
    int halt=0,mjump=0,jumps=0;
    for(int i=0;i<n-1;i++)
    {
        mjump=max(mjump,i+arr[i]);
        if(i==halt)
        {
            halt=mjump;
            jumps++;
        }
    }
    if(halt>=n-1) return jumps;
    return -1;
}

vector<vector<int>> mergeIntervals(vector<vector<int>> interval){
    vector<vector<int>> mergedIntervals;
    if(interval.size()==0) return mergedIntervals;
    sort(interval.begin(),interval.end());
    vector<int> temp=interval[0];
    for(auto it: interval){
        if(it[0]<=temp[1]) temp[1]=max(temp[1],it[1]);
        else{
            mergedIntervals.push_back(temp);
            temp=it;
        }
    }
    mergedIntervals.push_back(temp);
    return mergedIntervals;
}

vector<int> nextpermutation(vector<int> nums){
    int n=nums.size(),i,j;
    for(i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]) break;
    }
    if(i<0) {
        reverse(nums.begin(),nums.end());
        return nums;
    }
    else{
        for(j=n-1;j>i;j--){
            if(nums[j]>nums[i]) break;
        }
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
    }
    return nums;
}

long long maxProductSubarray(vector<int> nums, int n) {
     int res=nums[0];
    int maxProduct=res,minProduct=res;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]<0) swap(maxProduct,minProduct);
        maxProduct=max(nums[i],nums[i]*maxProduct);
        minProduct=min(nums[i],nums[i]*minProduct);
        res=max(res,maxProduct);
    }
    return res;
}

void rightRotate(int arr[],int start,int end){
    int temp=arr[end];
    for(int i=end;i>start;i--){
        arr[i]=arr[i-1];
    }
    arr[start]=temp;
}
void alternatePositiveAndnegative(int arr[],int n)
{
    int outplace=-1;
    for(int i=0;i<n;i++)
    {
        if(outplace>=0)
        {
            if((arr[i]>=0 && arr[outplace]<0) || (arr[i]<0 && arr[outplace]>=0))
            {
                rightRotate(arr,outplace,i);
                if(i-outplace>=2) outplace+=2;
                else outplace=-1;
            }
        }
        else if(outplace==-1)
        {
            if((arr[i]>=0 && i%2==0) || (arr[i]<0 && i%2!=0)) 
            outplace=i;
        }
    }
    return ;
}

int longestConsecutiveSubsequence(int arr[],int n)
{
    unordered_set<int> h(arr,arr+n);
    int res=1;
    for(auto x:h)
    {
        if(h.find(x-1)==h.end())
        {
            int curr=1;
            while(h.find(x+curr)!=h.end()) curr++;
            res=max(res,curr);
        }
    }
    return res;
}

bool tripletSum(int arr[],int n,int X)
{
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        int low=i+1,high=n-1;
        while(low<high){
            int sum=arr[low]+arr[i]+arr[high];
            if(sum==X) return true;
            else if(sum>X) high--;
            else low++;
        }
    }
    return false;
}

int trappingRainwater(int arr[],int n)
{
    long long int mxr[n],mxl[n];
    long long int mxval=arr[n-1],mnval=arr[0];
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]>mxval) mxval=arr[i];
        mxr[i]=mxval;
    }
    for(int i=0;i<=n;i++)
    {
        if(arr[i]>mnval) mnval=arr[i];
        mxl[i]=mnval;
    }
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum+=min(mxr[i],mxl[i])-arr[i];
    }
    return sum;
}

int minSwap(int arr[],int n,int k)
{
    int cnt=0; //cnt elements <=k
    for(int i=0;i<n;i++){
        if(arr[i]<=k) cnt++;
    }
    if(cnt==0) return 0;
    int i=0,j=0,z=0,ans=INT_MAX;
    while(j<n){
        if(arr[j]<=k) z++;
        if(j-i+1==cnt){
            ans=min(ans,cnt-z);
            if(arr[i]<=k) z--;
            i++;
        }
        j++;
    }
    return ans;
}

int medianOf2SortedArrays(int a[],int n,int b[],int m){
    /* Basic idea for O(log(n+m)) is to find the partion between the arrays i.e 
     how many elements to take from each array in first half and rest in second of merged array.*/  
    if(m<n) return medianOf2SortedArrays(b,m,a,n);
    int low=0,high=m;
    while(low<=high){
        int partitionOne=(low+high)/2;
        int partitionTwo=(n+m+1)/2-partitionOne;

        int l1=partitionOne==0?INT_MIN:a[partitionOne-1];
        int l2=partitionTwo==0?INT_MIN:b[partitionTwo-1];

        int r1=partitionOne==n?INT_MIN:a[partitionOne];
        int r2=partitionTwo==m?INT_MIN:a[partitionTwo];

        if(l1<=r2 && l2<=r1){
            if((n+m)%2==0) return ((max(l1,l2)+min(r1,r2))/2.0);
            else return max(l1,l2);
        }

        else if(l1>r2) high=partitionOne-1;
        else low=partitionOne+1;
    }
    return 0.0;
}

int maxProfitByBuyingShareAtmostTwice(vector<int>& prices) {
    int n=prices.size();
    int sell[n],buy[n],lsf=INT_MAX,p=0,op=0;
    for(int i=0;i<n;i++)
    {
        if(prices[i]<lsf) lsf=prices[i];
        p=prices[i]-lsf;
        op=max(op,p);
        sell[i]=op;
    }
    int msf=INT_MIN;
    p=0,op=0;
    for(int i=n-1;i>=0;i--)
    {
        if(prices[i]>msf) msf=prices[i];
        p=msf-prices[i];
        op=max(op,p);
        buy[i]=op;
    }
    int ans=0;
    for(int i=0;i<n;i++) ans=max(sell[i]+buy[i],ans);
    return ans;
}

int main()
{
     int arr[] = { -5, -2, 5, 2,4, 7, 1, 8, 0, -8 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    alternatePositiveAndnegative(arr,arr_size-1);
     display(arr,arr_size-1);
    return 0;
}