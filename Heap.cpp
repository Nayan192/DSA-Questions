#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i)
{
    int left=2*i;
    int right=2*i+1;
    int largest=i;
    if(left<=n && arr[left]>arr[i]) largest=left;
    if(right<=n && arr[right]>arr[largest]) largest=right;
    if(largest!=i) 
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void buildheap(int arr[],int n)
{
    int sIndex=n/2-1;
    for(int i=sIndex;i>=0;i--)
    {
        heapify(arr,n,i);
    }
}

void heapsort(int arr[],int n)
{
    buildheap(arr,n);
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[i],arr[0]);
        heapify(arr,n,i);
    }
}

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    //code here
    vector<int> pointer(K,1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<K;i++)
    {
        pq.push({arr[i][0],i});
    }
    vector<int> res;
    while(pq.size()>0){
        int val=pq.top().first;
        int row=pq.top().second;
        pq.pop();
        res.push_back(val);
        if(pointer[row]<K) {
            pq.push({arr[row][pointer[row]],row});
        }
        pointer[row]++;
    }
    return res;
}

string reorganizeString(string s) {
    unordered_map<char,int> mp;
    for(int i=0;i<s.size();i++) mp[s[i]]++;
    priority_queue<pair<int,char>> pq;
    for(auto it:mp) pq.push({it.second,it.first});
    string res;
    pair<int, int> top1, top2;
    while (!pq.empty()) {
        top1 = pq.top(); pq.pop();
        res += top1.second;
        if (!pq.empty()) {
            res += pq.top().second;
            top2 = pq.top(); pq.pop();
            if (top2.first > 1) pq.push({ top2.first - 1, top2.second });
        }
        if (top1.first > 1) pq.push({ top1.first - 1, top1.second });
    }

    for (int i = 1; i < res.size(); i++)
        if (res[i] == res[i - 1]) return "";
    return res;
}