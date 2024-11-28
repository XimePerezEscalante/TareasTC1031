//
//  bst.h
//  TareaBST
//
//  Created by Ximena Perez Escalante on 02/10/24.
//

#ifndef bst_h
#define bst_h

#include <string>
#include <sstream>

template <class T>
class BST;

template <class T>
class TreeNode{
private:
    T value;
    TreeNode<T> *left;
    TreeNode<T> *right;
public:
    TreeNode(int);
    TreeNode(int, TreeNode<T> *,TreeNode<T> *);
    void add(int);
    void inorder(std::stringstream &) const;
    void preorder(std::stringstream &) const;
    void levelorder(std::stringstream &) const;
    
    friend class BST<T>;
};

template <class T>
TreeNode<T>::TreeNode(int val){
    value = val;
    left = 0;
    right = 0;
}

template <class T>
TreeNode<T>::TreeNode(int val,TreeNode<T> *le,TreeNode<T> *ri){
    val = value;
    left = le;
    right = ri;
}


template <class T>
void TreeNode<T>::inorder(std::stringstream &aux) const{
    if (left != 0){
        left->inorder(aux);
    }
    
    aux << value << " ";

    if (right != 0){
        right->inorder(aux);
    }
}


template <class T>
void TreeNode<T>::preorder(std::stringstream &aux) const
{
    aux << value;
    
    if (left != 0){
        aux << " ";
        left->preorder(aux);
    }
    
    if (right != 0){
        aux << " ";
        right->preorder(aux);
    }
}

template <class T>
void TreeNode<T>::levelorder(std::stringstream &aux) const
{
    
    if (left != 0){
        aux << " ";
        left->preorder(aux);
    }
    
    if (right != 0){
        aux << " ";
        right->preorder(aux);
    }
}


template <class T>
void TreeNode<T>::add(int val){
    if (val > value){
        if (right == 0){
            right = new TreeNode<T>(val);
            //std::cout << "[" + std::to_string(right->value) + "]" << std::endl;
        }
        else{
            right->add(val);
        }
    }
    
    else{
        if (left == 0){
            left = new TreeNode<T>(val);
            //std::cout << "[" + std::to_string(left->value) + "]" << std::endl;
        }
        else{
            left->add(val);
        }
    }
}

template <class T>
class BST{
private:
    TreeNode<T> *root;
public:
    BST();
    ~BST();
    void add(int);
    bool searchAncestors(TreeNode<T> *, int, std::stringstream &) const;
    std::string ancestors(int);
    int calculateHeight(TreeNode<T> *);
    int height();
    std::string visit();
    int whatlevelamI(int);
    int search(int, TreeNode<T>*, int);
    void postorder(std::stringstream &, TreeNode<T>*) const;

};

template <class T>
BST<T>::BST(){
    root = 0;
}

template <class T>
BST<T>::~BST(){
    root = 0;
}

template <class T>
void BST<T>::postorder(std::stringstream &aux, TreeNode<T>* p) const{
    
    if (p != 0) {
        postorder(aux, p->left);

        postorder(aux, p->right);

        aux << p->value << " ";
    }
}

template <class T>
std::string BST<T>::visit(){
    std::stringstream aux;
    
    //pre-order
    aux << "[";
    if (root != 0){
        root->preorder(aux);
    }
    aux << "]";

    //in-order
    aux << "\n[";
    if (root != 0){
        root->inorder(aux);
    }
    aux.seekp(aux.str().length()-1);
    aux << "]";
    
    //post-order
    aux << "\n[";
    if (root != 0){
        postorder(aux, root);
    }
    aux.seekp(aux.str().length()-1);
    aux << "]";
    
    
    //level-order
    aux << "\n[";
    if (root != 0)
    {
        aux << root->value;
        root->levelorder(aux);
    }
    aux << "]";
    
    return aux.str();
    
}



template <class T>
void BST<T>::add(int val){
    if (root == 0){
        
        root = new TreeNode<T>(val);
        //std::cout << "root = " << root->value << std::endl;
        
    }
    else{
        root->add(val);
        //std::cout << "leaves:" << std::endl;
        /*
        if (root->left != 0){
            std::cout << "root's left: " << root->left->value << std::endl;
        }
        if (root->right != 0){
            std::cout << "root's right: " << root->right->value  << std::endl;
        }
         */

    }
}

template <class T>
bool BST<T>::searchAncestors(TreeNode<T>* p, int val, std::stringstream& aux) const {
    if (p == nullptr) {
        return false;
    }

    if (p->value == val) {
        return true;
    }

    if (searchAncestors(p->left, val, aux) || searchAncestors(p->right, val, aux)) {
        if (aux.tellp() > 1) {
            aux << ", ";
        }
        aux << p->value;
        return true;
    }

    return false;
}

template <class T>
std::string BST<T>::ancestors(int val){
    std::stringstream aux;
    aux << "[";
    if (root != 0){
        searchAncestors(root, val, aux);
    }
    aux << "]";
    
    return aux.str();
}

template <class T>
int BST<T>::calculateHeight(TreeNode<T> *p){
    int leftHeight;
    int rightHeight;
    
    if (p == 0) {
         return -1;
     }
    
    leftHeight = calculateHeight(p->left);
    rightHeight = calculateHeight(p->right);
    
    if (leftHeight > rightHeight){
        return leftHeight + 1;
    }
    else{
        return rightHeight + 1;
    }
}

template <class T>
int BST<T>::height(){
    return calculateHeight(root) + 1;
}

template <class T>
int BST<T>::search(int val, TreeNode<T> *p, int cont) {
    if (p == 0) {
        return -1;
    }

    if (val == p->value) {
        return cont;
    }

    if (val < p->value) {
        return search(val, p->left, cont + 1);
    }

    if (val > p->value) {
        return search(val, p->right, cont + 1);
    }

    return 0;
}


template <class T>
int BST<T>::whatlevelamI(int val){

    if (root != 0){
        return search(val, root, 1);
    }
    else{
        return -1;
    }
    
}


#endif /* bst_h */
