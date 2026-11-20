//splay list h

struct Node{
    int data;
    Node* left; 
    Node* right;
    Node(int d): data(d), left(nullptr), right(nullptr) {};
};

Node* zig(Node* i);

Node* zag(Node* i);

Node* splay(Node* r, int d);

Node* insert(Node* r, int d);

void preOrder(Node* r);

void inOrder(Node* r);

void postOrder(Node* r);