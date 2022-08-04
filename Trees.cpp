#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//ITERATIVE TRAVERSALS
void inOrder(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* cur=root;
    while(s.size()>0 || cur!=NULL)
    {
        if(cur!=nullptr){
            s.push(cur);
            cur=cur->left;
        }
        else{
            cur=s.top();
            s.pop();
            cout<<cur->val<<" ";
            cur=cur->right;
        }
    }
}
void preOrder(TreeNode* root)
{
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty())
    {
        TreeNode* cur=s.top();
        s.pop();
        cout<<cur->val<<" ";
        if(cur->left) s.push(cur->left);
        if(cur->right) s.push(cur->right);
    }
}
void postOrder(TreeNode* root)
{
    stack<TreeNode*> s;
    stack<int> out;
    s.push(root);
    while(!s.empty())
    {
        TreeNode* cur=s.top();
        s.pop();
        out.push(cur->val);
        if(cur->left) s.push(cur->left);
        if(cur->right) s.push(cur->right);
    }
    while(!out.empty())
    {
        cout<<out.top()<<" ";
        out.pop();
    }
}

int dfs(TreeNode* root)
{
    if(root==NULL) return 0;
    int l=dfs(root->left);
    int r=dfs(root->right);
    if(l==-1 ||r==-1) return -1;
    if(abs(l-r)>1) return -1;
    return max(l,r)+1;
}
bool isBalanced(TreeNode *root)
{
    if(dfs(root)==-1) return false;
    return true;
}

vector<int> topView(TreeNode *root)
{
    vector<int> res;
    map<int,int> mp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        TreeNode* cur=q.front().first;
        int h=q.front().second;
        q.pop();
        if(!mp[h]){
            mp[h]=cur->val;
        }
        if(cur->left) q.push({cur->left,h-1});
        if(cur->right) q.push({cur->right,h+1});
    }
    for(auto it:mp) res.push_back(it.second);
    return res;
}

vector<int> rightView(TreeNode *root)
{
    vector<int> res;
    if(root==NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(i==n-1) //left view-->i==0
            res.push_back(temp->val);
            if(temp->left!=NULL)
            q.push(temp->left);
                if(temp->right!=NULL)
            q.push(temp->right);
        }
    }
    return res;
}

vector <int> zigZagTraversal(TreeNode* root)
{
    vector<int> ans;
    stack<int> st;
    queue<TreeNode*> q;
    q.push(root);
    bool rev=false;
    while(q.size()>0)
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            TreeNode* cur=q.front();
            if(rev) st.push(cur->val);
            else ans.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            q.pop();
        }
        while(st.size()>0 && rev){
            ans.push_back(st.top());
            st.pop();
        }
        rev=!rev;
    }
    return ans;
}

vector<int> diagonalTraversal(TreeNode *root)
{
   vector<int> ans;
   queue<TreeNode*> q;
   q.push(root);
   while(q.size()>0)
   {
       TreeNode* cur=q.front();
       q.pop();
       while(cur!=NULL)
       {
           ans.push_back(cur->val);
           if(cur->left!=NULL) q.push(cur->left);
           cur=cur->right;
       }
   }
   return ans;
}

bool isLeaf(TreeNode* root){
    if(root->left==NULL && root->right==NULL) return true;
    return false;
}
void addLeft(TreeNode* root,vector<int> &res)
{
    TreeNode* cur=root->left;
    while(cur)
    {
        if(!isLeaf(cur)) res.push_back(cur->val);
        if(cur->left) cur=cur->left;
        else cur=cur->right;
    }
    return ;
}
void addLeaves(TreeNode* root,vector<int> &res)
{
    if(isLeaf(root)) {
        res.push_back(root->val);
        return ;
    }
    if(root->left) addLeaves(root->left,res);
    if(root->right) addLeaves(root->right,res);
}
void addRight(TreeNode* root,vector<int> &res)
{
    TreeNode* cur=root->right;
    stack<int> s;
    while(cur)
    {
        if(!isLeaf(cur)) s.push(cur->val);
        if(cur->right) cur=cur->right;
        else cur=cur->left;
    }
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    return ;
}
vector <int> boundaryTraversal(TreeNode *root)
{
    vector<int> res;
    if(!root) return res;
    res.push_back(root->val);
    if(isLeaf(root))  return res;
    addLeft(root,res);
    addLeaves(root,res);
    addRight(root,res);
    return res;
}

void binaryTreeToDLL(TreeNode* root,TreeNode* prev,TreeNode* head)
{
    if(root==NULL) return ;
    binaryTreeToDLL(root->left,prev,head);
    if(prev==NULL) head=root;
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
   binaryTreeToDLL(root->right,prev,head);
}

pair<int,int> getMaxSumWithNonAdjacentNodes(TreeNode* root)
{
    if(root==NULL){
        pair<int,int> p={0,0};
        return p;
    }
    pair<int,int> left=getMaxSumWithNonAdjacentNodes(root->left);
    pair<int,int> right=getMaxSumWithNonAdjacentNodes(root->right);
    pair<int,int> res;
    res.first=root->val+left.second+right.second;
    res.second=max(left.first,left.second)+max(right.first,right.second);
    return res;
}

TreeNode* lca(TreeNode* root ,int n1 ,int n2 )
{
    if(root==NULL) return NULL;
    if(root->val==n1 || root->val==n2) return root;
    TreeNode* leftAns=lca(root->left,n1,n2);
    TreeNode* rightAns=lca(root->right,n1,n2);
    if(leftAns!=NULL && rightAns!=NULL) return root;
    if(leftAns!=NULL && rightAns==NULL) return leftAns;
    if(leftAns==NULL && rightAns!=NULL) return rightAns;
    else return NULL;
}

TreeNode* preOrderToBST(int pre[],int &i,int size,int bound)
{
    if(i>=size||pre[i]>bound) return NULL;
    TreeNode* root= new TreeNode(pre[i++]);
    root->left=preOrderToBST(pre,i,size,root->val);
    root->right=preOrderToBST(pre,i,size,bound);
    return root;
}

void cntOfPathsWithKsum(TreeNode* root,int &cnt,int k,vector<int> ans)
{
    if(root==NULL) return ;
    ans.push_back(root->val);
    cntOfPathsWithKsum(root->left,cnt,k,ans);
    cntOfPathsWithKsum(root->right,cnt,k,ans);
    int sum=0;
    for(int i=ans.size()-1;i>=0;i--){
        sum+=ans[i];
        if(sum==k) cnt++;
    }
    ans.pop_back();
}

TreeNode* kthAncestor(TreeNode *root, int &k, int node)
{
    if(root==NULL) return NULL;
    if(root->val==node) return root;
    TreeNode* leftAns=kthAncestor(root->left,k,node);
    TreeNode* rightAns=kthAncestor(root->right,k,node);
    if(leftAns!=NULL && rightAns==NULL)
    {
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns==NULL && rightAns!=NULL)
    {
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

TreeNode* insert(TreeNode* root,int val,TreeNode* &succ)
{
    if(root==NULL){
        return root=new TreeNode(val);
    }
    else if(val<root->val){
        succ=root;
        root->left=insert(root->left,val,succ);
    }
    else root->right=insert(root->right,val,succ);
    return root;
}
vector<int> findLeastGreater(vector<int>& arr, int n) {
    TreeNode* root=NULL;
    vector<int> res(n);
    for(int i=n-1;i>=0;i--)
    {
        TreeNode* succ=NULL;
        root=insert(root,arr[i],succ);
        if(succ) res[i]=succ->val;
        else res[i]=-1;
    }
    return res;
}

unordered_map<int,int> mp;
TreeNode* buildBT(vector<int> inorder,int si,int ei,vector<int> preorder,int &rootidx)
{
    if(si>ei) return NULL;
    int idx=mp[preorder[rootidx]];
    TreeNode* root=new TreeNode(preorder[rootidx]);
    rootidx++;
    root->left=buildBT(inorder,si,idx-1,preorder,rootidx);
    root->right=buildBT(inorder,idx+1,ei,preorder,rootidx);
    return root;
}
TreeNode* buildTreeFromPreorderAndInorderxxy(vector<int>& preorder, vector<int>& inorder) {
    int n=inorder.size();
    for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
    int rootidx=0;
    TreeNode* root=buildBT(inorder,0,n-1,preorder,rootidx);
    return root;
}

//GO Right->Left->val
void flattenTreeToLinkedList(TreeNode* root,TreeNode* prev) {
    if(root==NULL) return ;
    flattenTreeToLinkedList(root->right,prev);
    flattenTreeToLinkedList(root->left,prev);
    root->right=prev;
    root->left=NULL;
    prev=root;
}

class info{
    public:
    int maxi;
    int mini;
    bool isBst;
    int size;
};
info largestBstInABinaryTree(TreeNode* root,int &ans)
{
    if(root==NULL) return {INT_MIN,INT_MAX,true,0};
    info left=largestBstInABinaryTree(root->left,ans);
    info right=largestBstInABinaryTree(root->right,ans);
    
    info curNode;
    curNode.size=left.size+right.size+1;
    curNode.maxi=max(root->val,right.maxi);
    curNode.mini=min(root->val,left.mini);
    
    if(left.isBst==true && right.isBst==true && (root->val>left.maxi && root->val<right.mini))
    {
        curNode.isBst=true;
    }
    else curNode.isBst=false;
    if(curNode.isBst) ans=max(ans,curNode.size);
    return curNode;
}