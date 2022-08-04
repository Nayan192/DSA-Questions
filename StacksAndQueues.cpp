#include<bits/stdc++.h>
using namespace std;
bool ispar(string x)
{
    stack<int> s;
    for(int i=0;i<x.size();i++)
    {
        if(x[i]=='{' || x[i]=='[' || x[i]=='(') s.push(x[i]);
        else if(x[i]=='}' && !s.empty() && s.top()=='{') s.pop();
        else if(x[i]==']' && !s.empty() && s.top()=='[') s.pop();
        else if(x[i]==')' && !s.empty() && s.top()=='(') s.pop();
        else return false;
    }
    if(s.empty()) return true;
    return false;
}

vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> res;
    stack<long long> s;
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0) res.push_back(-1);
        else if(s.size()!=0 && s.top()>arr[i]) res.push_back(s.top());
        else if(s.size()!=0 && s.top()<arr[i])
        {
            while(s.size()!=0 && s.top()<arr[i]) s.pop();
            if(s.size()==0) res.push_back(-1);
            else res.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(res.begin(),res.end());
    return res;
}

int celebrityProblem(vector<vector<int> >& M, int n) 
{
    stack<int> s;
    for(int i=0;i<n;i++) s.push(i);
    while(s.size()>=2)
    {
        int i=s.top(); 
        s.pop();
        int j=s.top(); 
        s.pop();
        if(M[i][j]==1) s.push(j);
        else s.push(i);
    }
    int t=s.top();
    for(int i=0;i<n;i++)
    {
        if(i!=t)
        {
            if(M[i][t]==0 || M[t][i]==1) return -1;
        }
    }
    return t;
}

int operation(int op1,int op2,char op)
{
    if(op=='+') return op1+op2;
    if(op=='-') return op1-op2;
    if(op=='*') return op1*op2;
    return op1/op2;
}
int evalPostFixExpression(string s) {
    stack<int> st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='+' && s[i]!='-' && s[i]!='/' && s[i]!='*') st.push(s[i]-'0');
        else {
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            st.push(operation(op2,op1,s[i]));
        }
    }
    return st.top();
}

vector<long long> NSR(long long arr[],int n)
{
    vector<long long> res;
    stack<pair<long long,long long>> s;
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0) res.push_back(n);
        else if(s.size()!=0 && s.top().first<arr[i]) res.push_back(s.top().second);
        else if(s.size()!=0 && s.top().first>=arr[i])
        {
            while(s.size()!=0 && s.top().first>=arr[i]) s.pop();
            if(s.size()==0) res.push_back(n);
            else  res.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    reverse(res.begin(),res.end());
    return res;
}

vector<long long> NSL(long long arr[],int n)
{
    vector<long long> res;
    stack<pair<long long,long long>> s;
    for(int i=0;i<n;i++)
    {
        if(s.size()==0) res.push_back(-1);
        else if(s.size()!=0 && s.top().first<arr[i]) res.push_back(s.top().second);
        else if(s.size()!=0 && s.top().first>=arr[i])
        {
            while(s.size()!=0 && s.top().first>=arr[i]) s.pop();
            if(s.size()==0) res.push_back(-1);
            else  res.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    return res;
}

long long getMaxAreaOfHistogram(long long arr[], int n)
{
    vector<long long> left=NSL(arr,n);
    vector<long long> right=NSR(arr,n);
    vector<long long> area(n);
    for(int i=0;i<n;i++){
        area[i]=arr[i]*(right[i]-left[i]-1);
    }
    return *max_element(area.begin(),area.end());
}

int isStackPermutation(int N,vector<int> &A,vector<int> &B){
    int i=0,j=0,n=A.size();
    stack<int> s;
    while(i<n && j<n)
    {
        if(s.size()==0){ 
            s.push(A[i]);
            i++;
        }
        else{
            if(s.top()==B[j])
            {
                s.pop();
                j++;
            }
            else {
                s.push(A[i]);
                i++;
            }
        }
    }
    while(!s.empty() && j<n)
    {
        if(s.top()==B[j]) s.pop();
        j++;
    }
    return s.size()==0?1:0;
}

void interLeaveQueue(queue < int > & q) {
    int half=q.size()/2;
    stack<int> s;
    for(int i=0;i<half;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<half;i++){
        int t=q.front();
        q.pop();
        q.push(t);
    }
    for(int i=0;i<half;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int i=0,j=0,curMax=INT_MIN;
    deque<int> q;
    vector<int> res;
    while(j<nums.size())
    {
        while(q.size()>0 && q.back()<nums[j]) q.pop_back();
        q.push_back(nums[j]);
        if(j-i+1==k)
        {
            res.push_back(q.front());
            if(nums[i]==q.front()) q.pop_front();
            i++;
        }
        j++;
    }
    return res;
}