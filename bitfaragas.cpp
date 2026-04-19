#include<bits/stdc++.h>
using namespace std;int main(){string t;getline(cin,t);string y(t.rbegin(),t.rend());cout<<(t==y?"Igen\n":"Nem\n");int n;cin>>n;int a[n];for(int&v:a)cin>>v;sort(a,a+n);for(int v:a)cout<<v<<" ";}
