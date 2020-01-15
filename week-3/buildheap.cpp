#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;


void sdown(int arr[],int n,vector<pair<int,int>> &v,int &count){
	for(int i=(n/2 -1 );i>=0;i--)
	{	
		int a=n;
		int mini=i;
		while(mini!=a){
			
			a=mini;
			if( 2*a+1<n && arr[mini]>arr[2*a+1])
				mini=2*a+1;
		
			if( 2*a+2<n && arr[mini]>arr[2*a+2] )
				mini=2*a+2;
			if(mini!=a){
				v.push_back(pair<int,int>(a,mini));
				int temp=arr[a];
				arr[a]=arr[mini];
				arr[mini]=temp;
				count++;
			}
					
		
		}
		
	}
}



int32_t main(){
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	vector<pair<int,int>> v;
	int count=0;

	sdown(arr,n,v,count);
	cout<<count<<endl;
	for(auto x:v)
		cout<<x.first<<" "<<x.second<<endl;
	return 0;

}