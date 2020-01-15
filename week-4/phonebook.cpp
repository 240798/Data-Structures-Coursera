#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

int32_t main(){
	int n;cin>>n;
	unordered_map<string,string> pb;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		if(s=="add"){
			string num,name;
			cin>>num>>name;
			pb[num]=name;
		}
		else if(s=="del"){
			string num;
			cin>>num;
			pb[num]="";
		}
		else{
			string num;
			cin>>num;
			if(pb[num]!="")
				cout<<pb[num]<<endl;
			else
				cout<<"not found"<<endl;
		}
	}
	return 0;
}