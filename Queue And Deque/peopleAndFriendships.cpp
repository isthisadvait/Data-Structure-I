/*
You are given N people  and M friendships . Freindships are not transitive .There is a party going to 
happen .A person will come to your party .  A person will come to your party if and only if there are
at least k friends of that person in the party .You need to invite people such that max. number of 
people come to party.
INPUT:

N=5
M=4

1-->2
2-->3
1-->3
2-->5

k=2


Output the maximum number of people come to party.
ANS=3

*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>v[n+1];
    int x,y;
    vector<int>deg(n+1);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<int>proc;
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++ ){
        if(v[i].size()==0) continue;
        else{
             deg[i]=v[i].size();
             if(deg[i]<k) proc.push(i);
    }
    }
    for(int x:deg) cout<<x<<" ";
    cout<<endl;
    while(!proc.empty()){
                 int t=proc.front();
                 proc.pop();
                 if(!vis[t]){
                     vis[t]=1;
                     for(int adj:v[t]){
                         deg[adj]--;
                         if(deg[adj]<k) proc.push(adj);
                     }
                 }
    }
    int ans=0;
    for(int x:deg) cout<<x<<" ";
    cout<<endl;
    for(int i=0;i<n+1;i++) if(deg[i]>=k) ans++;
    cout<<ans<<endl;
}
