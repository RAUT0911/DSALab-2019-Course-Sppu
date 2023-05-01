//Assignment no. 3

/*Problem statement :
Beginning with an empty binary search tree, Construct
binary search tree by inserting the values in the order
given. After constructing a binary tree
i. Insert new node
ii. Find number of nodes in longest path
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right
pointers are swapped at every node
v. Search a value
*/


//Input Code :

#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    Node *leftnode, *rightnode;
};

class Binary_Tree{
    public:
    Node *root;
    Node *createRoot(int key){
        root = new Node();
        root->key = key;
        root->leftnode = root->rightnode = NULL;
        return root;
    }

    void insertNode(int key, Node *root){
        
        Node *node = new Node();
        node->key = key;
        if(root->key < key)
        {
            if(root->rightnode == NULL)
            {
                root->rightnode = node;
            }
            else{
                insertNode(key, root->rightnode);
            }
        }
        else if(root->key > key)
        {
            if(root->leftnode == NULL)
            {
                root->leftnode = node;
            }
            else{
                insertNode(key, root->leftnode);
            }
        }
        else{
            cout<<"\n Duplicate No. are not allowed!!!";
        }
    }

    void displayInorderTree(Node *root){
        if(root != NULL){
            displayInorderTree(root->leftnode);
            cout<<root->key<<", ";
            displayInorderTree(root->rightnode);
        }
    }
    void displayPreorderTree(Node *root){
        if(root != NULL){
            cout<<root->key<<", ";
            displayPreorderTree(root->leftnode);
            displayPreorderTree(root->rightnode);
        }
    }
    void displayPostorderTree(Node *root){
        if(root != NULL){
            displayPostorderTree(root->leftnode);
            displayPostorderTree(root->rightnode);
            cout<<root->key<<", ";
        }
    }

    void searchNode(int key, Node *root){
        if(root->key==key)
            cout<<"\nElement found at root node";

        else if(root->key < key)
        {
            if(root->rightnode->key == key)
            {
                cout<<"\nElement Found at right!!!";
            }
            else{
                searchNode(key, root->rightnode);
            }
        }
        else if(root->key > key)
        {
            if(root->leftnode == NULL){
                cout<<"\nElement is not present in tree";
            }
            else if(root->leftnode->key == key)
            {
                cout<<"\nElement Found at left!!!";
            }
            else{
                searchNode(key, root->leftnode);
            }
        }
        else{
            cout<<"\nNode Element not found!!!";
        }
    }

    int longestPath(Node *root){
        if(root == NULL)
            return 0;
        int l = longestPath(root->leftnode);
        int r = longestPath(root->rightnode);
        if( l > r){
            return(l+1);
        }
        else{
            return(r+1);
        }
    }

    void displayMinElement(Node *root){
        while(root->leftnode != NULL){
            root = root->leftnode;
        }
        cout<<"\nMinimum Element of Binary tree is = "<<root->key;
    }

    Node *swapNodes(Node *root){
        Node *temp;
        if(root == NULL){
            cout<<"\nTree is empty!!!";
        }
        temp = root->leftnode;
        root->leftnode = root->rightnode;
        root->rightnode = temp;

        swapNodes(root->leftnode);
        swapNodes(root->rightnode);
        return 0;
    }
};

int main(){
    Binary_Tree b;
    Node *root;
    int ch;
    do{
        cout<<"\n1.Create\n2.Insert\n3.Display\n4.Search\n5.Longest Path\n6.Minimum Element\n7.Swap Nodes\n8.Exit";
        cout<<"\nEnter your choice = ";
        cin>>ch;
        switch(ch){
            case 1:
                int key;
                cout<<"\nEnter the root value = ";
                cin>>key;
                root = b.createRoot(key);
                break;
            case 2:
                int key1;
                cout<<"\nEnter the node value = ";
                cin>>key1;
                b.insertNode(key1, root);
                break;
            case 3:
                cout<<"Inorder Traversal = ";
                b.displayInorderTree(root);
                cout<<"\nPreorder Traversal = ";
                b.displayPreorderTree(root);
                cout<<"\nPostorder Traversal = ";
                b.displayPostorderTree(root);
                break;
            case 4:
                int key2;
                cout<<"\nEnter Node element to be found = ";
                cin>>key2;
                b.searchNode(key2, root);
                break;
            case 5:
                cout<<"\nLongest Path is = "<<b.longestPath(root);
                break;
            case 6:
                b.displayMinElement(root);
                break;
            case 7:
                cout<<"\nElement of Tree are swapped!!\n";
                b.swapNodes(root);
                //b.displayInorderTree(root);
                break;
            case 8:
                exit(0);
                break;
        }
    }while(ch<=8);
}

