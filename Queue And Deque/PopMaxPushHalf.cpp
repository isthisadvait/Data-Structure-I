/*Given an array A :  1  8  3    5
  After every operation you pop the max element and insert half of if it is not zero .

              pop 8 insert 4  => 1,4,3,5
              pop 5 insert 2  =>1,4,3,2
  You do this until all element become 0.
 An element can be popped 63 times at max.
..You are given Q queries  of opeartion number and you need to print the element which is popped in that operation.
N=10^6
A[i]<63*10^6
Q<=10^6
*/




#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int>v(n);
    for(int x=0;x<n;x++) cin>>v[x];
    queue<int>q1,q2;
    sort(v.begin(),v.end(),[](int x,int y){return x>y;});
    for(int x=0;x<n;x++){
        q1.push(v[x]);
    }
    int x=q1.front();q1.pop();
    vector<int>ans;
    ans.push_back(x);
    if((x/2)!=0)
     q2.push(x/2);
    while(!q1.empty() || !q2.empty()){
         if(!q1.empty()&&!q2.empty()){
             if(q1.front()>q2.front()){
                 int y=q1.front();q1.pop();
                 ans.push_back(y);
                  if((y/2)!=0)
                    q2.push(y/2);
             }
             else{
                  int y=q2.front();q2.pop();
                  ans.push_back(y);
                  if((y/2)!=0)
                  q1.push(y/2);
             }
         }
         else if(q2.empty()&&!q1.empty()){
                 int y=q1.front();q1.pop();
                 ans.push_back(y);
                 if((y/2)!=0)
                 q2.push(y/2);
         }
         else if(q1.empty()&&!q2.empty()){
                       int y=q2.front();q2.pop();
                       ans.push_back(y);
                       if((y/2)!=0)
                       q1.push(y/2);
         }
    }
    int q;cin>>q;
    int z;
    for(int x:v) cout<<x<<" ";
    cout<<endl;
    for(int x:ans) cout<<x<<" ";
    cout<<endl;
    while(q--){
        cin>>z;
        z--;
        cout<<ans[z]<<endl;
    }
    return 0;
}
