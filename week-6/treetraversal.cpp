#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

struct Node{
	int key;
	Node* left;
	Node* right;
	
};

Node* maken(int data){
	Node* node = new Node;
	node->key=data;
	node->left=NULL;node->right=NULL;
	return node;
}

void preorder(Node* root){
	if(root==NULL)
		return;
	cout<<root->key<<" ";
	preorder(root->left);
	preorder(root->right);

}

void postorder(Node* root){
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->key<<" ";
}

void inorder(Node* root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->key<<" ";
	inorder(root->right);
}
void maketree(int k[],int l[],int r[],int n,Node* root,int i){
	if(i<n){
		if(l[i]!=-1){
			root->left=maken(k[l[i]]);
			maketree(k,l,r,n,root->left,l[i]);
		}

		if(r[i]!=-1){
			root->right=maken(k[r[i]]);
			maketree(k,l,r,n,root->right,r[i]);
		}
		
	
		
	}

}


int32_t main(){
	int n;cin>>n;
	int par[n],lc[n],rc[n];
	for(int i=0;i<n;i++)
		cin>>par[i]>>lc[i]>>rc[i];
	Node* root=maken(par[0]);
	int flag=1;
	int min=root->key;
	int max=root->key;
	maketree(par,lc,rc,n,root,0);
	
	inorder(root);cout<<endl;
	preorder(root);cout<<endl;
	postorder(root);cout<<endl;
	return 0;
	

}