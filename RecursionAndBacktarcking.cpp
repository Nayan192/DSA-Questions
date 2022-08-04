#include<bits/stdc++.h>
using namespace std;

void floodFill(vector<vector<int>> arr,int row,int col,string psf,vector<vector<bool>> visited){
    if(row<0|| col<0|| row==arr.size() ||col==arr[0].size() ||arr[row][col]==1 ||visited[row][col]==true){
       return ; 
    }
    if(row==arr.size()-1 && col==arr[0].size()-1){
        cout<<psf;
        return ;
    }
    visited[row][col]=true;
    floodFill(arr,row-1,col,psf+"t",visited);
    floodFill(arr,row,col-1,psf+"l",visited);
    floodFill(arr,row+1,col,psf+"d",visited);
    floodFill(arr,row,col+1,psf+"r",visited);
    visited[row][col]=false;
}

vector<vector<int>> res;
bool isSafe(vector<vector<int>> chess,int row,int col)
{
    for(int i=row-1;i>=0;i--){
        if(chess[i][col]==1) return false;
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(chess[i][j]==1) return false;
    }
    for(int i=row-1,j=col+1;i>=0 && j<chess.size();i--,j++){
        if(chess[i][j]==1) return false;
    }
    return true;
}
void nQueen(vector<vector<int>> chess,int n,int row,vector<int> ans)
{
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(chess[i][j]==1) ans.push_back(j+1);
                
            }
        }
        res.push_back(ans);
        return ;
    }
    for(int col=0;col<n;col++)
    {
        if(isSafe(chess,row,col)){
            chess[row][col]=1;
            nQueen(chess,n,row+1,ans);
            chess[row][col]=0;
        }
    }
}

void knightsTour(vector<vector<int>> chess,int n,int r,int c,int move){
    if(r<0||c<0||r>=n||c>=n||chess[r][c]>0) return;
    else if(move==n*n){
        chess[r][c]=move;
        //display the array
        chess[r][c]=0;
        return ;
    }
    chess[r][c]=move;
    knightsTour(chess,n,r-2,c+1,move+1);
    knightsTour(chess,n,r-1,c+2,move+1);
    knightsTour(chess,n,r+1,c+2,move+1);
    knightsTour(chess,n,r+2,c+1,move+1);
    knightsTour(chess,n,r+2,c-1,move+1);
    knightsTour(chess,n,r+1,c-2,move+1);
    knightsTour(chess,n,r-1,c-2,move+1);
    knightsTour(chess,n,r-2,c-1,move+1);
    chess[r][c]=0;
}

void wordBreak(string s,string ans,unordered_map<string,bool> mp)
{
    if(s.size()==0)
    {
        ans.pop_back();
        cout<<ans<<" ";
        return;
    }
    for(int i=0;i<s.size();i++)
    {
        string left=s.substr(0,i+1);
        if(mp.find(left)!=mp.end()){
            string right=s.substr(i+1);
           wordBreak(right,ans+left+" ",mp);
        }
    }
    
}

bool check(vector<int> adj[],vector<int> color,int node,int i)
{
    for(int j=0;j<adj[node].size();j++)
    {
        int val=adj[node][j];
        if(color[val]==i) return false;
    }
    return true;
}
bool solve(vector<int> adj[],vector<int> color,int m,int n,int node)
{
    if(node>=n) return true;
    for(int i=1;i<=m;i++)
    {
        if(check(adj,color,node,i))
        {
            color[node]=i;
            if(solve(adj,color,m,n,node+1)) return true;
            color[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
   int n=mat.size();
    vector<int> color(n,0);
    vector<int> adj[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==1) adj[i].push_back(j);
        }
    }
    bool ans=solve(adj,color,m,n,0);
    return ans==true?"YES":"NO";
}

int getMin(string s)
{
    stack<int> st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')')
        {
            if(st.size()==0) st.push(s[i]);
            else if(st.top()==')') st.push(s[i]);
            else if(st.top()=='(') st.pop();
        }
    }
    return st.size();
}
void removeInvalidParentheses(string s,int mr,vector<string> res,unordered_map<string,bool> visited)
{
    //mr=getMin(s) in main function
    if(visited[s]) return;
        visited[s]=true;
    if(mr==0){
        if(getMin(s)==0){
            res.push_back(s);
        }
        return;
    }
    for(int i=0;i<s.size();i++)
    {
        string left=s.substr(0,i);
        string right=s.substr(i+1);
        removeInvalidParentheses(left+right,mr-1,res,visited);
    }
}

bool isPali(string s)
{
    int i=0,j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
void allPalindromicPerms(string s,vector<string> ans,vector<vector<string>> res){
    if(s.size()==0){
        res.push_back(ans);
        return ;
    }
    for(int i=0;i<s.size();i++)
    {
        string left=s.substr(0,i+1);
        if(isPali(left)){
            ans.push_back(left);
            string right=s.substr(i+1);
            allPalindromicPerms(right,ans,res);
            ans.pop_back();
        } 
    }
}

string updateAns(vector<int> s1,vector<int> s2){
    string temp="[";
    for(int i=0;i<s1.size();i++) temp+=to_string(s1[i])+","+" ";
    temp.pop_back();
    temp.pop_back();
    temp+=']';
    temp+=" ";
    temp+='[';
    for(int i=0;i<s2.size();i++) temp+=to_string(s2[i])+","+" ";
     temp.pop_back();
     temp.pop_back();
    temp+=']';
    return temp;
}
void tugOfWar(int a[],int n,int idx,vector<int> s1,int sumofs1,vector<int> s2,int sumofs2,int mindiff,string ans)
{
    if(idx==n){
        int temp=abs(sumofs1-sumofs2);
        if(temp<mindiff){
            mindiff=temp;
           ans= updateAns(s1,s2);
        }
        return;
    }
    if(s1.size()<(n+1)/2){
        s1.push_back(a[idx]);
        tugOfWar(a,n,idx+1,s1,sumofs1+a[idx],s2,sumofs2,mindiff,ans);
        s1.pop_back();
    }
    if(s2.size()<(n+1)/2){
        s2.push_back(a[idx]);
        tugOfWar(a,n,idx+1,s1,sumofs1,s2,sumofs2+a[idx],mindiff,ans);
        s2.pop_back();
    }
}

bool isValidPlacement(int grid[8][8],int i,int j,int val){
    for(int k=0;k<8;k++)
    {
        if(grid[i][k]==val) return false;
    }
    for(int k=0;k<8;k++){
        if(grid[k][j]==val) return false;
    }
    int r=3*(i/3);
    int c=3*(j/3);
    for(int a=0;a<3;a++){
        for(int b=0;b<3;b++){
            if(grid[a+r][b+c]==val) return false;
        }
    }
    return true;
}
void sudokuSolve(int grid[8][8],int i,int j)
{
    if(i==9){
       //display the grid
        return;
    }
    int ni=0,nj=0;
    if(j==8){
        ni=i+1;
        nj=0;
    }
    else{
        ni=i;
        nj=j+1;
    }
    if(grid[i][j]!=0) sudokuSolve(grid,ni,nj);
    else{
        for(int po=1;po<=9;po++){
            if(isValidPlacement(grid,i,j,po)){
                grid[i][j]=po;
                sudokuSolve(grid,ni,nj);
                grid[i][j]=0;
            }
        }
    }
}

void combinationalSum(vector<int> a,int idx,int b,vector<int> ans,vector<vector<int>> res)
{
    if(b<0||idx==a.size()) return;
    if(b==0){
        res.push_back(ans);
        return;
    }
    for(int i=idx;i<a.size();i++)
    {
        ans.push_back(a[i]);
        if(a[i]<=b) combinationalSum(a,i,b-a[i],ans,res);
        ans.pop_back();
    }
}

void findMaximumAfterKswaps(string str, string &maxi, int k, int idx)
{
    if(k==0) return;
    char c = str[idx];
    for(int i = idx+1; i<str.length(); ++i){
        if(str[i]>c) c = str[i];
    }
    if(c != str[idx]) k--;
    for(int i =0; i<str.length(); i++){
        if(str[i]==c){
            swap(str[idx], str[i]);
            if(maxi < str) maxi = str;
            findMaximumAfterKswaps(str, maxi, k, idx+1);
            swap(str[idx], str[i]);
        }
    }
}

void printAllPermutations(string s,string res,int n)
{
    if(res.size()==n)
    {
        cout<<res<<" ";
        return ;
    }
    for(int i=0;i<s.size();i++)
    {
        res+=s[i];
        string left=s.substr(0,i);
        string right=s.substr(i+1);
       printAllPermutations(left+right,res,n);
        res.pop_back();
    }
}

bool flag =false;
void partitionArrayIntoKSubsetWithEqualSum(int a[], int n,int idx, int k,int nemptyset,vector<vector<int>> subsets,vector<int> subsetsum)
{
    if(flag==true) return;
    if(idx==n)
    {
        if(nemptyset==k)
        {
            bool t=true;
            for(int i=0;i<subsetsum.size()-1;i++)
            {
                if(subsetsum[i]!=subsetsum[i+1]){
                    t=false;
                    break;
                }
            }
            if(t) flag=true;
        }
        return;
    }
    for(int i=0;i<subsets.size();i++)
    {
        if(subsets[i].size()>0){
            subsets[i].push_back(a[idx]);
            subsetsum[i]+=a[idx];
            partitionArrayIntoKSubsetWithEqualSum(a,n,idx+1,k,nemptyset,subsets,subsetsum);
            subsetsum[i]-=a[idx];
            subsets[i].pop_back();
        }
        else{
            subsets[i].push_back(a[idx]);
            subsetsum[i]+=a[idx];
            partitionArrayIntoKSubsetWithEqualSum(a,n,idx+1,k,nemptyset+1,subsets,subsetsum);
            subsetsum[i]-=a[idx];
            subsets[i].pop_back();
            break;
        }
    }
}

int main(){
    return 0;
}