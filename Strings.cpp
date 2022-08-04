#include<bits/stdc++.h>
using namespace std;
string countAndSaysolve(string s)
{
    string res="";
    int i=0;
    while(i<s.size())
    {
        char a=s[i];
        int cnt=0;
        while(i<s.size() && s[i]==a){
            cnt++;
            i++;
        }
        res+=to_string(cnt)+a;
    }
    return res;
}
string countAndSay(int n) {
    vector<string> a(n+1);
    a[1]="1";
    for(int j=2;j<=n;j++)
    {
        string s=a[j-1],res="";
        int i=0;
        while(i<s.size())
        {
            char a=s[i];
            int cnt=0;
            while(i<s.size() && s[i]==a){
                cnt++;
                i++;
            }
            res+=to_string(cnt)+a;
        }
        a[j]=res;
    }
    return a[n];
}