//
// File: wl.h
// 
//  Description: Add stuff here ... 
//  Student Name: Add stuff here .. 
//  UW Campus ID: Add stuff here .. 
//  enamil: Add stuff here .. 

#ifndef WL_H
#define WL_H

#include <iostream>
#include <string>
using namespace std;

struct TreeNode
{
    string words;
    TreeNode *leftChild;
    TreeNode *rightChild;
    int wordLocation;
};

//class TreeNode {
//
//
//public:
//    TreeNode (string item, int pos);
//    // followings are fields
//    string words;
//    TreeNode *leftChild;
//    TreeNode *rightChild;
//    int wordLocation;
//
//    // followings are methods
//    int setLeftChild (TreeNode *lChild);
//    int setRightChild (TreeNode *rChild);
//    TreeNode * getRight ();
//    TreeNode * getLeft();
//    string getData();
//    int getWordLocation();
//
//
//};
//
//TreeNode::TreeNode (string item, int pos) {
//    words = item;
//    wordLocation = pos;
//    leftChild = NULL;
//    rightChild = NULL;
//
//}
//int TreeNode::setLeftChild (TreeNode *lChild) {
//    leftChild = lChild;
//    return 0 ;
//}
//int TreeNode::setRightChild (TreeNode *rChild ) {
//    rightChild = rChild;
//    return 0;
//}
//TreeNode* TreeNode::getLeft () {
//    return leftChild;
//}
//
//TreeNode* TreeNode::getRight () {
//    return rightChild;
//}
//
//string TreeNode::getData () {
//    return words;
//}
//
//int TreeNode::getWordLocation() {
//    return wordLocation;
//}




class stringBST {

private:
    TreeNode *root;
    TreeNode *insert (TreeNode *n, string data, int pos);
    void nodeDeletion (TreeNode *node);
public:
    stringBST ();
    void insert (string data, int pos);
    TreeNode* search (string value);
    TreeNode* searchNode (TreeNode *node, string key);
    void clearReset();
    ~stringBST();
};


stringBST::stringBST() {
    root = NULL;
}

TreeNode*  stringBST::insert (TreeNode  * n, string data, int pos) {

    if (n == NULL) {
        n = new TreeNode;
        n->words = data;
        n->wordLocation = pos;
        n->leftChild = NULL;
        n->rightChild = NULL;


    } else {

        if ( data < (n->words)) {


             n->leftChild = insert(n->leftChild, data, pos);
         //   n->setLeftChild(insert(n->getLeft(), data, pos));

        }

        else {

           // n->setRightChild(insert(n->getRight(), data,pos));
            n->rightChild = insert(n->rightChild, data,pos);
        }
    }

 //   cout<< "\nnode inserted is "<<n->words<< " position number is "<<n->wordLocation<<endl;
    return n;
}


TreeNode* stringBST::searchNode (TreeNode *node, string key) {

    bool nodeFound = false;
    TreeNode* potentialCandidate = NULL;

    if (node ==NULL) {
        cout<<"---null node---";
    }
    while ((node != NULL) && (nodeFound ==false) && (potentialCandidate==NULL)) {

       // string nodeData = node->getData();
        string nodeData = node->words;


        if (key<nodeData) {
           // node = node->getLeft();
            node = node->leftChild;
        } else if (key > nodeData) {

           // node = node->getRight();
            node = node->rightChild;
        } else {
            nodeFound = true;
            potentialCandidate = node;
            break;
        }

        potentialCandidate= searchNode(node, key);

    }

    return potentialCandidate;
}

void stringBST::nodeDeletion(TreeNode  *node) {

    if(node == NULL) {
        return;
    }

    if ((node->rightChild!=NULL) || (node->leftChild !=NULL)){
//        nodeDeletion(node->getRight());
//        nodeDeletion(node->getLeft());
        nodeDeletion(node->rightChild);
        nodeDeletion(node->leftChild);

        delete node;
    } else {
        delete node;
    }

}


void stringBST::insert (string data, int pos){
    root = insert(root, data,pos);
}

TreeNode* stringBST::search (string value) {
    return searchNode(root, value);
}


void stringBST::clearReset () {
    nodeDeletion(root);
}

stringBST::~stringBST() {
    nodeDeletion(root);
}



#endif