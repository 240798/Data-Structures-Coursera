
# include<bits/stdc++.h>

using namespace std;


struct Node {

    int key;
    Node *parent;
    vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

int Height(Node *root){
  
  if (root == NULL) return 1 ; 
  int h = 0 ;
  for(Node* child : root->children)
  {
    h = max(h,Height(child)) ;
  }

  return h+1 ;

}

int bfs(Node *root)
{
   int height=0;
   queue<Node*> q ;
   q.push(root) ;
   while(!q.empty())
   {
   	 if(q.size()==1)
   	 	height++;
     Node *node  = q.front() ; q.pop() ;

     
     for(auto x : node->children)
     {
        
        q.push(x) ;
     }

     

   }
   return height;

}


int main() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;
  int rootIndex = -1 ;
  Node *root = NULL ;
  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    
    nodes[child_index].key = child_index;
    if(parent_index == -1) root = &nodes[child_index] ;

      
  }


  // Replace this code with a faster implementation
 /* int maxHeight = 0;
  for (int leaf_index = 0; leaf_index < n; leaf_index++) {
    int height = 0;
    for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
      height++;
    maxHeight = std::max(maxHeight, height);
  }*/

  cout << Height(root) << endl ;
  return 0 ;
    
}

  
