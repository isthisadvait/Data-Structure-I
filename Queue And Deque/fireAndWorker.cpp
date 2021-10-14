#include <bits/stdc++.h>
using namespace std;
int mat[100][100];
int visited1[100][100];
int visited2[100][100];

bool isValid1(int x,int y,int n,int m){   // Checking for fire

    if((x>=0)&&(x<n)&&(y>=0)&&(y<m)&&(visited1[x][y]==0)&&(mat[x][y]!=-1)) return false;
    
    else return false;
}
bool isValid2(int x,int y,int n,int m){  //Checking for worker

    if((x>=0)&&(x<n)&&(y>=0)&&(y<m)&&(visited2[x][y]==0)&&(mat[x][y]!=-1)) return true;
    else return false;
}

//Solving Problem
void solve(){
    int n,m,xf,yf,xw,yw; 
    cin>>n>>m>>xf>>yf>>xw>>yw;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
  
  //calculating time of fire for each cell

    queue<pair<pair<int,int>,int>> q1;
    q1.push({{xf,yf},1});
    visited1[xf][yf]=1;
    while(!q1.empty()){
        int t=q1.front().second;
        int x=q1.front().first.first;
        int y=q1.front().first.second;
        q1.pop();
        visited1[x][y]=t;
        if(isValid1(x+1,y,n,m)){
            q1.push({{x+1,y},t+1});
        }
         if(isValid1(x,y+1,n,m)){
             q1.push({{x,y+1},t+1});
         }
         if(isValid1(x-1,y,n,m)){
            q1.push({{x-1,y},t+1});
        }
        if(isValid1(x,y-1,n,m)){
            q1.push({{x,y-1},t+1});
        }
    }

   // cal time of worker for each cell

    queue<pair<pair<int,int>,int>> q2;
    q2.push({{xw,yw},1});
    visited2[xw][yw]=1;
    while(!q2.empty()){
        int t=q2.front().second;
        int x=q2.front().first.first;
        int y=q2.front().first.second;
        q2.pop();
        visited2[x][y]=t;
        if(isValid2(x+1,y,n,m)){
            q2.push({{x+1,y},t+1});
        }
        if(isValid2(x,y+1,n,m)){
             q2.push({{x,y+1},t+1});
         }
         if(isValid2(x,y-1,n,m)){
             q2.push({{x,y-1},t+1});
         }
         if(isValid2(x-1,y,n,m)){
             q2.push({{x-1,y},t+1});
         }
         
        
    }


    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           cout<<visited1[i][j]<<" ";
       }
       cout<<endl;
       
   }
   cout<<endl;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           cout<<visited2[i][j]<<" ";
       }
        cout<<endl;
   }
    int ps=0;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if((visited2[i][j]<=visited1[i][j])&&(mat[i][j]!=-1)) ps+=mat[i][j];
       }
       
   }
   cout<<ps;
}
int main() {
    int t; cin>>t; while(t--) solve();
}

