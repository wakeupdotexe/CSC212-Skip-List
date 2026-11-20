#include "splay-list.h"
#include <iostream>



Node* zig(Node* i){
    Node* j = i->left;
    i->left = j->right;
    j->right = i;
    return j;
};

Node* zag(Node* i){
    Node* j = i->right;
    i->right = j->left;
    j->left = i;
    return j;
};

Node* splay(Node* r, int d){
    if(r == nullptr){
        return r;
    }

    if(r->data > d){
        if(r->left == nullptr){
            return r;
        }
        if(r->left->data > d){
            r->left->left = splay(r->left->left, d);
            r = zig(r);
        } else if(r->left->data < d){
            r->left->right = splay(r->left->right, d);
            if(r->left->right != nullptr){
                r->left = zag(r->left);
            }
        }
        if(r->left == nullptr){
            return r;
        } else {
            return zig(r);
        }
    } else {
        if(r->right == nullptr){
            return r;
        }
        if(r->right->data > d){
            r->right->left = splay(r->right->left, d);
            if(r->right->left != nullptr){
                r->right = zig(r->right);
            } 
        } else if(r->right->data < d){
            r->right->right = splay(r->right->right, d);
            r = zag(r);
        }
        if(r->right == nullptr){
            return r;
        } else {
            return zag(r);
        }   
    }
};

Node* insert(Node* r, int d){
    if(r == nullptr){
        r = new Node(d);
        return r;
    }

    r = splay(r, d);

    Node* i = new Node(d);
    if(r->data > d){
        i->right = r;
        i->left = r->left;
        r->left = nullptr;
    } else {
        i->left = r;
        i->right = r->right;
        r->right = nullptr;
    }
    return i;
}

int main(){
    Node* root = nullptr;
    return 0;
}