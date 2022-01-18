class Node{
 public:
  Node(int data);
  void add(int data);
  Node* left;
  Node* right;
  int getData();
 private:
  int data;
}
Node::Node(int data){
 this->left = NULL;
 this->right = NULL;
 this->data = data;
}
void Node::add(int data){
 if(data < this->getData()){
  if(this->left != NULL){
   Node* temp = Node(data);
   this->left = &temp;
  }
  else{
   this->left->add(data);
  }
}
 else{
  if(this->right != NULL){
   Node* temp = Node(data);
   this->right = &temp;
  }
  else{
   this->right->add(data);
  }
 }
}