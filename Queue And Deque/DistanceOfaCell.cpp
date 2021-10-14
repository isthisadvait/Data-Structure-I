/* 
 Find the distance of every cell of grid from given cell of  grid {xg,yg} using breadth first search . 
 */
#include <bits/stdc++.h>
using namespace std;
int mat[100][100];
int vis[100][100];

bool isValid(int x,int y,int n, int m){
    if((x>=0)&&(x<n) && (y>=0)&&(y<m) && (vis[x][y]==0)) return true;
    else return false;
}
void solve(){
    int n,m,xg,yg; 
    cin>>n>>m>>xg>>yg;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{xg,yg},1});
    vis[xg][yg]=1;
    while(!q.empty()){
    
        auto temp=q.front();q.pop();
        int x=temp.first.first;
        int y=temp.first.second;
        int d=temp.second;

        if(isValid(x+1,y,n,m)) {
           q.push({{x+1,y},d+1});
           vis[x+1][y]=d+1;
        }
         if(isValid(x-1,y,n,m)) {
           q.push({{x-1,y},d+1});
           vis[x-1][y]=d+1;
        }
         if(isValid(x,y+1,n,m)) {
           q.push({{x,y+1},d+1});
           vis[x][y+1]=d+1;
        }
         if(isValid(x,y-1,n,m)) {
           q.push({{x,y-1},d+1});
           vis[x][y-1]=d+1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int t; cin>>t; while(t--) solve();
    return 0;
}
