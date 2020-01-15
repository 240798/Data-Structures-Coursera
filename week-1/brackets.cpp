#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

int isBalanced(string s){
	stack<pair<char,int>> st;

	for(int i=0;i<s.length();i++){
		if(s[i]=='('|| s[i]=='[' || s[i]=='{')
			st.push({s[i],i});
		else if(s[i]==')' || s[i]==']' || s[i]=='}')
		{
			if(st.empty())
				return i+1;
			else
			{
				char topo=st.top().first ;  st.pop() ;
				if((s[i]==')' && topo!='(') || (s[i]==']'&& topo!='[') || (s[i]=='}' && topo!='{') )
					return i+1;
			}		

	
		}
	}
	if(st.empty())
		return 0;
	else
		return st.top().second+1;
}


int32_t main(){
	string s;
	cin>>s;
	if(isBalanced(s))
		cout<<isBalanced(s)<<endl;
	else
		cout<<"Success"<<endl;

	

	return 0;

	
}