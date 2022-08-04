#include<bits/stdc++.h> 
using namespace std;
void print(int n){
    if(n==1)
    {
        cout<<n<<" ";
        return ;
    }
    print(n-1);
    cout<<n<<" ";
}
/*POWER OF A NUMBER
        USING RECURSION*/
int powRecur(int k,int n)
{
    if(n==0) return 1;
    return (powRecur(k,n-1)*k);
}
/*REVERSING AN ARRAY
        USING RECURSION*/
int *reverseArrayRecur(int arr[],int i,int j)
{
    if(i<j)
    {
        swap(arr[i],arr[j]);
        reverseArrayRecur(arr,i+1,j-1);
    }
    return arr;
}
/*SORTING AN ARRAY
        USING RECURSION*/
void insert(vector<int> &v,int temp)//v={6},temp=2 v={},temp=2
{
    if(v.size()==0 || temp>=v.at(v.size()-1))//for v={}
    {
        v.push_back(temp);//v={2}
        return;
    }
    int val=v.at(v.size()-1);//val=6
    v.pop_back();//v={}
    insert(v,temp);//insert({},2)
    v.push_back(val);//v={2,6}
}
void sortedArray(vector<int> &v)/*v-{6,2,3}  v={6,2} v={6}*/
{
    if(v.size()==1)//for v={6}
     return;
    int temp=v.at(v.size()-1);//temp=3 temp=2
    v.pop_back();//v={6,2} v={6}
    sortedArray(v);//called on v
    insert(v,temp);//called for v={6} and temp=2
}
/*SORTING A STACK
        USING RECURSION*/
void insertStack(stack<int> &s,int temp)
{
    if(s.size()==0 || temp>=s.top())
    {
        s.push(temp);
        return;
    }
    int val=s.top();
    s.pop();
    insertStack(s,temp);
    s.push(val);
}
void sortedStack(stack<int> &s)
{
    if(s.size()==1)
    {
        return;
    }
    int t=s.top();
    s.pop();
    sortedStack(s);
    insertStack(s,t);
}
/*DELETE MIDDLE ELEMENT 
    IN A STACK USING RECURSION*/
void popMiddleElement(stack<int> &s,int k)
{
    if(k==1)
    {
        s.pop();
        return;
    }
    int val=s.top();
    s.pop();
    popMiddleElement(s,k-1);
    s.push(val);
}
/*REVERSING AN STACK
        USING RECURSION*/
void insertBottomOfStack(stack<int> &s,int temp)
{
    if(s.size()==0)
    {
        s.push(temp);
        return;
    }
    int val=s.top();
    s.pop();
    insertBottomOfStack(s,temp);
    s.push(val);
}
void reverseStack(stack<int> &s)
{
    if(s.size()==1)
        return;
    int temp=s.top();
    s.pop();
    reverseStack(s);
    insertBottomOfStack(s,temp);
}
/*TOWER OF HANOI*/
void TOI(int source,int destination,int helper,int disk)
{
    if(disk==1)
    {
        cout<<"Moving disk"<<disk<<"from"<<source<<"to"<<destination<<endl;
        return;
    }
    TOI(source,helper,destination,disk-1);
     cout<<"Moving disk"<<disk<<"from"<<source<<"to"<<destination<<endl;
     TOI(helper,destination,source,disk-1);
    return;
}
/*SUBSET OF A STRING
        USING RECURSION*/
void subSet(string input,string output,vector<string> &res,unordered_map<string,int> &visited){
    if(input.size()==0)
    {
        if(visited.count(output)>0)
        return;
        res.push_back(output);
        visited[output]=1;
        return;
    }
    string output1=output;
    string output2=output;
    output1.push_back(input[0]);
    input.erase(input.begin()+0);
    subSet(input,output1,res,visited);
    subSet(input,output2,res,visited);
}
/*ADDING SPACES IN A STRING
        USING RECURSION*/
void permuteSpaces(string ip,string op){
    if(ip.size()==0)
    {
        cout<<op<<" ";
        return;
    }
    string op1=op;
    string op2=op;
    op1.push_back('-');
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    permuteSpaces(ip,op1);
    permuteSpaces(ip,op2);
}
int main()
{
    // // int n=5;
    // int arr[5]={1,2,3,4,5};
    // // int sum=0;
    // // cout<<powRecur(5,5);
    // int *reversedArray=reverseArrayRecur(arr,0,4);
    // for(int i=0;i<5;i++)
    //     cout<<reversedArray[i]<<" ";
    // vector<int> v={5,1,3,2,4};
    // sortedArray(v);
    // for(int i=0;i<v.size();i++)
    // {
    //     cout<<v.at(i)<<" ";
    // }
    // stack<int> s;
    // s.push(6);
    // s.push(5);
    // s.push(2);
    // s.push(7);
    // s.push(8);
    // reverseStack(s);
    // while(!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    //TOI(1,2,3,3);
     string i="bc";
    string o="a";
    //  vector<string> res;
    //  unordered_map<string,int> visited;
    //  subSet(i,o,res,visited);
    // for(int i=0;i<res.size();i++)
    //     cout<<res.at(i);
    permuteSpaces(i,o);
    return 0;
}