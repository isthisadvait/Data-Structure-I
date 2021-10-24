/* Problem Link -https://codeforces.com/problemset/problem/546/C
   Platform Codeforces 
   Solution BY- Raman Mehta
*/

#include <iostream>
#include<vector>
#include<map>
using namespace std;
	   
int main() {
	int n; cin>>n;
	int k1;cin>>k1;
	vector<int>v1;
	for(int i=0;i<k1;i++){int temp;cin>>temp; v1.push_back(temp);}
	int k2;cin>>k2;
	vector<int>v2;
	for(int i=0;i<k2;i++){int temp;cin>>temp; v2.push_back(temp);}
	int count=0,win;
	map<pair<vector<int>,vector<int>>,int>m;
	int flag=0;


	while(true){
		if(v1.size()==0) {win=2; break;}
		if(v2.size()==0){win=1; break;}

		if(m[{v1,v2}]!=0){ flag=1;break;}
	    m[{v1,v2}]=1;
	    if(v1[0]>v2[0]){
			int t1=v1[0];
			v1.erase(v1.begin());
			int t2=v2[0];
			v2.erase(v2.begin());
			v1.push_back(t2);
			v1.push_back(t1);
			count++;
	     }else{
			int t1=v1[0];
			v1.erase(v1.begin());
			int t2=v2[0];
			v2.erase(v2.begin());
			v2.push_back(t1);
			v2.push_back(t2);
			count++;
	    }
	}
	(flag==1)?cout<<-1:cout<<count<<" "<<win;
	return 0;
}
