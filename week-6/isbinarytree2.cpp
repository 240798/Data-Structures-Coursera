#include<bits/stdc++.h>
#define int long
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
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

int isBST(Node* root,int min,int max){
  if(root==NULL)
    return 1;
  if(root->key < min || root->key > max)
    return 0;
  return isBST(root->left,min,root->key-1) && isBST(root->right,root->key,max);
}

int32_t main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  int n;cin>>n;
  int par[n],lc[n],rc[n];
  for(int i=0;i<n;i++)
    cin>>par[i]>>lc[i]>>rc[i];
  
  Node* root=maken(par[0]);
  maketree(par,lc,rc,n,root,0);

  
  //inorder(root);cout<<endl;
  //preorder(root);cout<<endl;
  //postorder(root);cout<<endl;
  if(isBST(root,INT_MIN, INT_MAX) || n==0)
    cout<<"CORRECT"<<endl;
  else
    cout<<"INCORRECT"<<endl;
  return 0;
  

}
int32_t main (int32_t argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

