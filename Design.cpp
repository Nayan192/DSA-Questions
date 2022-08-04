#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
    public:
    class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
            node(int newkey, int newval){
                key = newkey;
                val = newval;
            }
        };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*> m;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;        
    }
    
    void addnode(node* newnode){
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode){
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delnext->prev = delprev;
        delprev->next = delnext;        
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            node *resnode = m[key];
            int res = resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return res;
        } else return -1;
        
    }
    
    void set(int key, int value) {
        if(m.find(key)!=m.end()){
            node *existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }        
        addnode(new node(key,value));
        m[key] = head->next;
    }
};