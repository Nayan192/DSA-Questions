#include<bits/stdc++.h>
using namespace std; 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head)
{
    if(head==NULL || head->next==NULL) return head;
    ListNode* curr=head;
    ListNode* prev=NULL;
    ListNode* nxt=NULL;
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    head=prev;
    return head;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL || head->next==NULL) return head;
    ListNode* temp1=head;
    int cnt=0;
    while(temp1!=NULL)
    {
        temp1=temp1->next;
        cnt++;
    }
    k=k%cnt;
    for(int i=1;i<=k;i++)
    {
        ListNode* temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        ListNode* end=temp->next;
        end->next=head;
        temp->next=NULL;
        head=end;
    }
    return head;
}

ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL ||head->next==NULL) return head;
    ListNode* prev=head;
    ListNode* curr=head->next;
    while(curr!=NULL)
    {
        if(curr->val==prev->val)
        {
            prev->next=curr->next;
        }
        else{
            prev=curr;
        }
        curr=curr->next;
    }
    return head;
}

ListNode* reverseNodesInKgroups(ListNode* head,int k,int cnt)
{
    //cnt=total number of ListNodes initially
    if(cnt<k) return head;
    int c=k;
    ListNode* curr=head;
    ListNode* prev=NULL;
    ListNode* nxt=NULL;
    while(c-- && curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    if(head!=NULL) head->next=reverseNodesInKgroups(nxt,k,cnt-k);
    return prev;
}

ListNode* addTwoLists(ListNode* first, ListNode* second)
{
    first=reverseList(first);
    second=reverseList(second);
    int carry=0;
   ListNode* ans=new ListNode(-1);
   ListNode* temp=ans;
    while(first!=NULL || second!=NULL)
    {
        int v1=first==NULL?0:first->val;
        int v2=second==NULL?0:second->val;
        carry+=v1+v2;
        temp->next=new ListNode(carry%10);
        temp=temp->next;
        carry/=10;
        if(first!=NULL) first=first->next;
        if(second!=NULL) second=second->next;
    }
    if(carry>0)
    {
        temp->next=new ListNode(carry);
        temp->next->next=NULL;
    }
    return reverseList(ans->next);
}

ListNode* midNode(ListNode* head,ListNode* tail)
{
   ListNode* fast=head;
   ListNode* slow=head;
    while(fast!=tail && fast->next!=tail){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

ListNode* mergeList(ListNode* l1,ListNode* l2)
{
   ListNode* ans=new ListNode(0);
   ListNode* temp=ans;
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->val<l2->val){
            temp->next=l1;
            l1=l1->next;
        }
        else{
                temp->next=l2;
            l2=l2->next;
        }
        temp=temp->next;
    }
    temp->next=l1!=NULL?l1:l2;
    return ans->next;
}

ListNode* mergeSort(ListNode* head,ListNode* tail)
{
    if(head==tail)
    {
       ListNode* ans=new ListNode(head->val);
        return ans;
    }
   ListNode* mid=midNode(head,tail);
   ListNode* l1=mergeSort(head,mid);
   ListNode* l2=mergeSort(mid->next,tail);
    return mergeList(l1,l2);
}