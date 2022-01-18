
class Node{
 public:
  void add(double val);
  void print();
  void remove();
  Node* getNext();
 private:
  Node(double dat);
  Node* next;
  double data;
 Node(double data){
  this->next = NULL;
  this->data = data;
 }
 
 Node* getNext(){
  return this->next;
 }
 void add(double val){
  if(this->next == NULL){
   this->next = Node(val);
  }
  else(){
   this->next.add(val);
  }
 }
 void print(){
  cout << this->data;
  if(this->next == NULL){
   return;
  }
  else(){
   this->next.print();
  }
 }
}