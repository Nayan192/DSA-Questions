#include<bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    vector<int> res;
    int t=0,b=r-1,l=0,R=c-1,dir=0;
    while(t<=b && l<=R)
    {
        if(dir==0){
            for(int i=l;i<=R;i++) res.push_back(matrix[t][i]);
            t++;
        }
        else if(dir==1){
            for(int i=t;i<=b;i++) res.push_back(matrix[i][R]);
            R--;
        }
        else if(dir==2){
            for(int i=R;i>=l;i--) res.push_back(matrix[b][i]);
            b--;
        }
        else if(dir==3) {
            for(int i=b;i>=t;i--) res.push_back(matrix[i][l]);
            l++;
        }
        dir=(dir+1)%4;
    }
    return res;
}

//Function to count Elements Less Than A given value in An array using Binary Search
int lessElementsThanMid(vector<int> A,int mid){
    int l=0,h=A.size()-1;
    while(l<=h){
        int m=(l+h)/2;
        if(A[m]<=mid) l=m+1;
        else h=m-1;
    }
    return l;
}

int medianOfRowWiseSortedMatrix(vector<vector<int>> &matrix, int r, int c){
    int R=matrix.size();
    int C=matrix[0].size();
    int low=0,high=1e9;
    while(low<=high){
        int mid=(low+high)/2;
        int elementCounter=0;
        for(int i=0;i<R;i++){
            elementCounter+=lessElementsThanMid(matrix[i],mid);
        }
        if(elementCounter<=(R*C)/2) low=mid+1;
        else high=mid-1;
    }
    return low;
}

int KthSmallestInMatrix(vector<vector<int>> mat,int k){
    int n=mat.size(),ans;
    int low=mat[0][0],high=mat[n-1][n-1];
    while(low<=high){
        int mid=(low+high)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=lessElementsThanMid(mat[i],mid);
        }
        if(cnt<k) low=mid+1;
        else {
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}

int main()
{
    return 0;
}