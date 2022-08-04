#include<bits/stdc++.h>
using namespace std;
bool isPathPossible(vector<int> graph[],int source,int destination,vector<bool> &visited)
{
    if(source==destination){
        return true;
    }
    visited[source]=true;
    for(int i=0;i<graph[source].size();i++){
        if(visited[graph[source][i]]==false){
            bool hasPath=isPathPossible(graph,graph[source][i],destination,visited);
            if(hasPath==true) return true;
        }
    }
    return false;
}

void printAllPaths(vector<vector<int>> graph,vector<int> ans,vector<bool> &visited,int sr,int ds)
{
    if(sr==ds){
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
        return ;
    }
    visited[sr]=true;
    for(int i=0;i<graph[sr].size();i++){
        ans.push_back(graph[sr][i]);
        printAllPaths(graph,ans,visited,graph[sr][i],ds);
        ans.pop_back();
    }
    visited[sr]=false;
}

int dfs(vector<int> adj[],vector<bool> &vis,vector<bool> &dfsvis,int node)
{
    vis[node]=true;
    dfsvis[node]=true;
    for(int it:adj[node])
    {
        if(vis[it]==false){
            if(dfs(adj,vis,dfsvis,it)==1) return 1;
        }
        else if(dfsvis[it]==true) return 1;
    }
    dfsvis[node]=false;
    return 0;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> adj[n+1];
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
    }
    vector<bool> vis(n+1,false),dfsvis(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            if(dfs(adj,vis,dfsvis,i)==1) return 1;
        }
    }
    return 0;
}

void bfs(int V, vector<int> adj[],vector<bool> &visited) {
    queue<int> q;
    q.push(0);
    while(q.size()>0)
    {
        int j=q.front();
        q.pop();
        if(visited[j]) continue;
        visited[j]=true;
        cout<<j<<" ";
        for(int i=0;i<adj[j].size();i++)
        {
            if(visited[adj[j][i]]==false) q.push(adj[j][i]);
        }
    }
}

void topologicalSortdfs(vector<int> adj[],vector<bool> &vis,stack<int> &st,int node)
{
    vis[node]=true;
    for(auto it:adj[node])
    {
        if(!vis[it]) topologicalSortdfs(adj,vis,st,it);
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    stack<int> st;
    vector<int> adj[v];
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<bool> vis(v,false);
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            topologicalSortdfs(adj,vis,st,i);
        }
    }
    vector<int> res;
    while(st.size()>0){
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

vector<int> topologicalSortBFS(int V, vector<int> adj[])
{
    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) q.push(indegree[i]);
	    }
	    vector<int> ans;
	    while(q.size()>0)
	    {
	        int node=q.front();
	        q.pop();
	        for(auto it:adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0) q.push(indegree[it]);
	        }
	        ans.push_back(node);
	    }
	    return ans;
}

bool dfsBirpatite(vector<int> adj[],vector<int> &color,int node)
{
    if(color[node]==-1) color[node]=1;
    for(auto it:adj[node])
    {
        if(color[it]==-1){
            color[it]=1-color[node];
            if(!dfsBirpatite(adj,color,it)) return false;
        }
        else if(color[it]==color[node]) return false;
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	int V=edges.size();
    vector<int> adj[V];
    for(int i=0;i<edges.size();i++)
    {
        for(int j=0;j<edges[0].size();j++)
        {
            if(edges[i][j]==1) adj[i].push_back(j);
        }
    }
    vector<int> color(V,-1);
    for(int i=0;i<V;i++)
    {
        if(color[i]==-1)
        {
            if(!dfsBirpatite(adj,color,i)) return false;
        }
    }
    return true;
}

int kosaraju(int V, vector<int> adj[])
{
    stack<int> st;
    int cnt=0;
    vector<bool> vis(V,false);
    for(int i=0;i<V;i++)
    {
        if(!vis[i]){
           topologicalSortdfs(adj,vis,st,i);
        }
    }
    vector<int> transpose[V];
    for(int i=0;i<V;i++){
        vis[i]=false;
        for(auto it:adj[i]){
            transpose[it].push_back(i);
        }
    }
    while(st.size()>0){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            bfs(node,transpose,vis);
            cnt++;
        }
    }
    return cnt;
}

vector<int> dijkstraAlgorithm(int V, vector<vector<int>> adj[], int S)
{
    vector<int> distance(V,INT_MAX);
    distance[S]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,S});
    while(q.size()>0)
    {
        int dist=q.top().first;
        int prev=q.top().second;
        q.pop();
        for(auto it:adj[prev])
        {
            int next=it[0];
            int nextdist=it[1];
            if(distance[next]>dist+nextdist){
                distance[next]=dist+nextdist;
                q.push({distance[next],next});
            }
        }
    }
    return distance;
}

int primAlgo(int V, vector<vector<int>> adj[])
{
    vector<int> key(V,INT_MAX);
    vector<bool> mst(V,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,0});
    key[0]=0;
    while(q.size()>0)
    {
        int u=q.top().second;
        q.pop();
        mst[u]=true;
        for(auto it:adj[u]){
            int node=it[0];
            int wt=it[1];
            if(mst[node]==false && wt<key[node]){ 
                key[node]=wt;
                q.push({key[node],node});
            }
        }
        
    }
    return accumulate(key.begin(),key.end(),0);
}

vector<int> bellman_ford(int V, vector<vector<int>> adj, int S) {
    
    vector <int> distance(V,100000000);
    distance[S]=0;
    for(int i=1;i<=V-1;i++)
    {
        for(auto it:adj){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(distance[u]+wt<distance[v]){
                distance[v]=distance[u]+wt;
            }
        }
    }
    return distance;
}

int orangesRotting(vector<vector<int>>& grid) {
    // Code here
    if(grid.size()==0) return 0;
    int m=grid.size(),n=grid[0].size(),tot=0,cnt=0,ans=0;
    queue<pair<int,int>> q;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]!=0) tot++;
            if(grid[i][j]==2) q.push({i,j});
        }
    }
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    while(q.size()>0)
    {
        int k=q.size();
        cnt+=k;
        while(k--)
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int x=0;x<4;x++)
            {
                int ni=i+dx[x];
                int nj=j+dy[x];
                if(ni<0||nj<0||ni>=m||nj>=n||grid[ni][nj]!=1) continue;
                grid[ni][nj]=2;
                q.push({ni,nj});
            }
        }
        if(!q.empty()) ans++;
    }
    return tot==cnt?ans:-1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    //undirected weighted graph
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt}); //remove this line in case of directed graph;
    }
}