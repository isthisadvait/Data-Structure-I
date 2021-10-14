/*
  There is a grid given . Every cell contains the number of population in (I,j)th city.
   A[i][j] = population at (I,j)th city .You are given coordinates of fire and firestation .There are    
   infinite workers.Speed of fire and fireworks is same ,can move 1 cell/sec and in all four  
  direction.
   Fire is spreading in all direction .
   Let say fireworker reahes at any cell at time t1 and fire reaches at t2 . If t1<= t2 ,the population of    
   that city  can be saved ,otherwise not. Here are some cells blocked .Neither the fire neither the    
   worker can pass through it.The blocked cell contain value -1' 
   Determine the total population can be saved.
*/
#include <bits/stdc++.h>
using namespace std;
int mat[100][100];
int visited[100][100];


bool isValid(int x,int y,int n,int m){
    
    if((x>=0)&&(x<n)&&(y>=0)&&(y<m)&&(visited[x][y]==0)&&(mat[x][y]!=-1)) return true;
    else return false;
}


void solve(){
    int n,m,xf,yf,xw,yw; 
    cin>>n>>m>>xf>>yf>>xw>>yw;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{xw,yw},0});
    visited[xw][yw]=1;
    q.push({{xf,yf},1});
    visited[xf][yf]=1;
    int ps=0;
    while(!q.empty()){
        int t=q.front().second;
        int x=q.front().first.first;
        int y=q.front().first.second;
        q.pop();
        if(t==0){
            cout<<x<<" "<<y;
            cout<<endl;
             ps+=mat[x][y];
        }
    
        if(isValid(x+1,y,n,m)){
            q.push({{x+1,y},t});
            visited[x+1][y]=1;
        }
         if(isValid(x,y+1,n,m)){
             q.push({{x,y+1},t});
             visited[x][y+1]=1;
         }
         if(isValid(x-1,y,n,m)){
            q.push({{x-1,y},t});
            visited[x-1][y]=1;
        }
        if(isValid(x,y-1,n,m)){
            q.push({{x,y-1},t});
            visited[x][y-1]=1;
        }
    }
    
    
    cout<<ps<<endl;
}
int main() {
    int t; cin>>t; while(t--) solve();
    return 0;
}



