	/* No of ways to make a pair such that A[i]=A[j] 
        Author - Raman Mehta

    */
    
    #include<iostream>
    #include<vector>
	#include<unordered_map>
	using namespace std;
	int main() { 
	    int t; cin>>t;
        while(t--){ 
        int n; cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];

	    unordered_map<int,int>m;
	    int ans=0;
	    for(int i=0;i<n;i++){
	        ans+=m[v[i]];
	        m[v[i]]++;
	    }
	    
	     cout<<ans<<endl;
        }
	    return 0;
	}
