#include<bits/stdc++.h>
using namespace std;



int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return -1;
        vector<int>p(n+1);
        for(int i=0;i<n;i++){
            p[i+1]=nums[i]+p[i];
        }
       // for (int x:p) cout<<x<<" ";
        int ans=INT_MAX;
        deque<int>dq;
        for(int i=0;i<=n;i++){
            while(!dq.empty()&&p[i]<=p[dq.back()]) dq.pop_back();
            while(!dq.empty()&&(p[i]-p[dq.front()])>=k) {
                ans =min(ans,i-dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
        }
        return (ans==INT_MAX)?-1:ans;
    }

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        cout<<shortestSubarray(v,k)<<endl;
    }
}