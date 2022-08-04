#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    
    Node* getNode(char ch){
        return links[ch-'a'];
    }
};
class Trie {
    private: Node* root;
    public:
        Trie() {
            root=new Node();
        }

        void insert(string word) {
            Node* temp=root;
            for(int i=0;i<word.size();i++)
            {
                if(!temp->containsKey(word[i])){
                    temp->put(word[i],new Node());
                }
                temp=temp->getNode(word[i]);
            }
            temp->flag=true;
        }

        bool search(string word) {
            Node* temp=root;
            for(int i=0;i<word.size();i++)
            {
                if(!temp->containsKey(word[i])) return false;
                temp=temp->getNode(word[i]);
            }
            if(temp->flag) return true;
            return false;
        }

        bool startsWith(string prefix) {
            Node* temp=root;
            for(int i=0;i<prefix.size();i++)
            {
                if(!temp->containsKey(prefix[i])) return false;
                temp=temp->getNode(prefix[i]);
            }
            return true;
        }
        void print(Node* cur,vector<string> &temp,string p)
        {
            if(cur->flag) temp.push_back(p);
            for(char a='a';a<='z';a++)
            {
                Node* nxt=cur->links[a-'a'];
                if(nxt!=NULL){
                    p.push_back(a);
                    print(nxt,temp,p);
                    p.pop_back();
                }
            }
        }
        vector<vector<string>> solve(string s)
        {
            vector<vector<string>> res;
            string pre="";
            Node* prev=root;
            for(int i=0;i<s.size();i++)
            {
                char ch=s[i];
                pre+=ch;
                Node* cur=prev->links[ch-'a'];
                if(cur==NULL) break;
                vector<string> temp;
                print(cur,temp,pre);
                prev=cur;
                res.push_back(temp);
            }
            return res;
        }
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie* t=new Trie();
    for(int i=0;i<contactList.size();i++)
    {
        t->insert(contactList[i]);
    }
    return t->solve(queryStr);
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> s;
    bool flag=false;
    for(auto word:wordList){
        s.insert(word);
        if(word==endWord) flag=true;
    }
    if(!flag) return 0;
    queue<string> q;
    int ladder=0;
    q.push(beginWord);
    while(q.size()>0)
    {
        ladder++;
        int lsize=q.size();
        for(int i=0;i<lsize;i++)
        {
            string cur=q.front();
            q.pop();
            for(int i=0;i<cur.size();i++)
            {
                string temp=cur;
                for(char a='a';a<='z';a++)
                {
                    temp[i]=a;
                    if(temp.compare(cur)==0) continue;
                    else if(temp.compare(endWord)==0) return ladder+1;
                    if(s.find(temp)!=s.end()){
                        q.push(temp);
                        s.erase(temp);
                    }
                }
                
            }
        }
    }
    return 0;
}
