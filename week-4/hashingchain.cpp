#include<bits/stdc++.h>
//#define int long long 
#define endl '\n'
using namespace std;

struct Node{
    string s;
    Node* next;
    Node(string data){
        this->next=NULL;
        this->s=data;
    }
};


int main(){
    int p=1000000007;
    int m,n;cin>>m>>n;
    unordered_map<int,Node*> hash;
    for(int i=0;i<n;i++){
        string inst;cin>>inst;
        if(inst=="add"){
            string w;cin>>w;
            long long h=0;
            for(int j=w.length()-1;j>=0;j--){
                h=(h*263 + w[j])%p;
            }
            h=h%m;
            Node* a=hash[h];
            int f=0;
            while(a){
                if(a->s==w){
                    f=1;
                    break;
                }
                
                a=a->next;
            }
            if(f)
                continue;
            Node* nn=new Node(w);
            if(hash[h]==NULL)
                hash[h]=nn;
            else{
                nn->next=hash[h];
                hash[h]=nn;
            }
            
        }
        else if(inst=="del"){
            string w;cin>>w;
            long long h=0;
            for(int j=w.length()-1;j>=0;j--){
                h=(h*263 + w[j])%p;
            }
            h=h%m;
            Node *prev=NULL,*curr=hash[h];
            if(hash[h] && hash[h]->s==w)
                hash[h]=hash[h]->next;
            else{
                while(curr){
                    prev=curr;
                    curr=curr->next;
                    if(curr&&curr->s==w){
                        prev->next=curr->next;
                        curr->next=NULL;
                        break;
                    }
                }
            }
        }
        else if(inst=="check"){
            int num;cin>>num;
            if(hash[num]==NULL)
                cout<<endl;
            else{
                Node* a=hash[num];
                while(a){
                    cout<<a->s<<" ";
                    a=a->next;
                }
                cout<<endl;
            }
        }
        else{
            string w;cin>>w;
            long long h=0;
            for(int j=w.length()-1;j>=0;j--){
                h=(h*263 + w[j])%p;
            }
            h=h%m;
            Node* a=hash[h];
            int fl=1;
            while(a){
                if(a->s==w)
                {
                    cout<<"yes"<<endl;
                    fl=0;
                    break;
                }
                a=a->next;
            }
            if(fl)
                cout<<"no"<<endl;

        }

    }
    return 0;
}