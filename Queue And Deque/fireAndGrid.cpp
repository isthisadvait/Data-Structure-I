#include <bits/stdc++.h>
using namespace std;
int mat[100][100];
void solve(){
    int n,m,xf,yf,xw,yw; 
    cin>>n>>m>>xf>>yf>>xw>>yw;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int ps=0,d1,d2;
    
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            d1=abs(yf-j)+abs(xf-i);
            d2=abs(yw-j)+abs(xw-i);
            if(d2<=d1) ps+=mat[i][j];
        }
     }
  
   cout<<ps<<endl;
}
int main() {
    int t; cin>>t; while(t--) solve();
    return 0;
}
