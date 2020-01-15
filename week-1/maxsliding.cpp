#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

int32_t main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int m;
	cin>>m;
	deque<int> q;
	for(int i=0;i<m;i++){
		while(!q.empty() && arr[i]>=arr[q.back()])
			q.pop_back();
		q.push_back(i);
	}
	cout<<arr[q.front()]<<" ";
	for(int i=m;i<n;i++)
	{	while(!q.empty() && q.front()<=i-m)
			q.pop_front();
		while(!q.empty() && arr[i]>=arr[q.back()])
			q.pop_back();
		q.push_back(i);
		cout<<arr[q.front()]<<" ";
		
	}
	return 0;

}