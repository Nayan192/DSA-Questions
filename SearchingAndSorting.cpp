#include<bits/stdc++.h>
using namespace std;

double NthRoot(int n,int m){
    double low=0,high=m;
    while((high-low)>1e-6){
        double mid=(low+high)/2.0;
        if(pow(mid,n)<m) low=mid;
        else high=mid; 
    }
    return high;
}

vector<int> majorityElementII(vector<int>& nums) {
    int num1=-1,num2=-1,c1=0,c2=0,n=nums.size();
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==num1) c1++;
        else if(nums[i]==num2) c2++;
        else if(c1==0){
            num1=nums[i];
            c1=1;
        }
        else if(c2==0){
            num2=nums[i];
            c2=1;
        }
        else{
            c1--;
            c2--;
        }
    }
    vector<int> ans;
    int cnt1=0,cnt2=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==num1) cnt1++;
        else if(nums[i]==num2) cnt2++;
    }
    if(cnt1>n/3) ans.push_back(num1);
    if(cnt2>n/3) ans.push_back(num2);
    return ans;
}

vector<vector<int>> fourSum(vector<int> &arr, int k) {
    sort(arr.begin(),arr.end());
    vector<vector<int>> res;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        for(int j=(i+1);j<n;j++)
        {
            int value=k-arr[j]-arr[i];
            int left=j+1;
            int right=n-1;
            while(left<right)
            {
                int sum=arr[left]+arr[right];
                if(value>sum) left++;
                else if(value<sum) right--;
                else{
                    vector<int> ans;
                    ans.push_back(arr[i]);
                    ans.push_back(arr[j]);
                    ans.push_back(arr[left]);
                    ans.push_back(arr[right]);
                    res.push_back(ans);
                    
                    //Skipping the same value for both left and right
                    while(left<right && arr[left]==ans[2]) left++;
                    while(left<right && arr[right]==ans[3]) right--;
                }
            }
            while(j+1<n && arr[j+1]==arr[j]) ++j;
        }
        while(i+1<n && arr[i+1]==arr[i]) ++i;
    }
    return res;
}

long long countTripletsWithSumLessThanGivenSum(long long arr[], int n, long long sum)
{
    sort(arr,arr+n);
    long long int start,end,i,c=0;
    for(int i=0;i<n-2;i++){
        start=i+1;
        end=n-1;
        while(start<end){
            if(arr[i]+arr[start]+arr[end]>=sum) end--;
            else{
                c+=(end-start);
                start++;
            }
        }
    }
    return c;
}

int countSubarraysWithZeroSum(int arr[],int n){
    int count=0;
    unordered_map<int,int> visited;
    visited[0]=1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        count+=(visited[sum]++);
    }
    return count;
}

bool isValid(int A[],int n,int k,int maxpages){
    int sum=0,student=1;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(sum>maxpages){
            student++;
            sum=A[i];
        }
        if(student>k) return false;
    }
    return true;
}
int allocateMinimumNumberOfPages(int A[], int N, int M) 
{
    if(M>N) return -1;
    int sum=0,m=A[0];
    for(int i=0;i<N;i++){
        sum+=A[i];
        m=max(m,A[i]);
    }
    int l=m,h=sum,res=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(isValid(A,N,M,mid)){
            res=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    return res;
}

bool canPlaceCow(long long int A[],long long int n,long long int c,long long int minDistance){
    int f=A[0],cnt=1;
    for(int i=1;i<n;i++){
        if(A[i]-f>=minDistance){
            f=A[i];
            cnt++;
        }
        if(cnt==c) return true;
    }
    return false;
}
long long int aggresiveCows(long long int A[],long long int n,long long int c){
    if(c>n) return -1;
    sort(A,A+n);
    long long int low=0, high=A[n-1]-A[0],res,mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(canPlaceCow(A,n,c,mid)){
            res=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return res;
}

int findMininRotatedSortedArray(vector<int>& nums) {
    int n=nums.size();
    int l=0,h=n-1;
    if(nums[h]>nums[l]) return nums[0];
    while(l<=h){
        int mid=(l+h)/2;
        int next=(mid+1)%n;
        int prev=(mid+n-1)%n;
        if(nums[next]>=nums[mid] && nums[prev]>=nums[mid]) return nums[mid];
        else if(nums[h]>=nums[mid]) h=mid-1;
        else if(nums[l]<=nums[mid]) l=mid+1;
    }
    return -1;
}

bool canCutTree(long long int A[],long long int n,long long int m,long long int h){
    long long int sum=0;
    for(int i=0;i<n;i++){
        if(A[i]>h){
            sum+=(A[i]-h);
        }
        if(sum>=m) return true;
    }
    return false;
}
long long int ekoSPOJ(long long int A[],long long int n,long long int m){
    long long int p=A[0];
    for(int i=0;i<n;i++) p=max(p,A[i]);
    long long int low=0,high=p,res,mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(canCutTree(A,n,m,mid)){
            res=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return res;
}

bool possible(int num,int n){
    int cnt=0,p=5;
    while((num/p)>0){
        cnt+=num/p;
        p=p*5;
    }
    return cnt>=n;
}
int findNumberOfTrailingZeroInFactorial(int n)
{
    if(n==1) return 5;
    
    int low=0,high=5*n,res;
    while(low<high){
        int mid=(low+high)/2;
        if(possible(mid,n)){
            high=mid;
        }
        else low=mid+1;
    }
    return low;
}
int main(){
    long long int n,c;
    cin>>n>>c;
    long long int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<ekoSPOJ(a,n,c);
    return 0;
}