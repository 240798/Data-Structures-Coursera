#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n;
	cin>>n;
	stack<int> v;
	stack<int> a;
	for (int i = 0; i < n; i++) {
		string query;
        cin >> query;
        if (query == "push") {
        	int x;
            cin >> x;
            v.push(x);
            if(a.size()==0 || x>= a.top())
            	a.push(x);
        }
        else if (query == "pop") {
            if(v.top()==a.top())
            	a.pop();
            v.pop();
        }
        else if (query == "max") {
        
            cout << a.top() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}