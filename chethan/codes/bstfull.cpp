
#include<iostream>
#include <cstdlib>
using namespace std;

typedef struct tree {
    int data;
    struct tree *left;
    struct tree *right;
} TREE;

class binarysearchtree {
    public:
    TREE *insert_to_bst(TREE*, int);
    void inorder_traversal(TREE*);
    void preorder_traversal(TREE*);
    void postorder_traversal(TREE*);
    TREE *delete_from_bst(TREE*, int);
    void inandout(TREE*);
    int edge_node(TREE*);
    TREE *treesearch(int, TREE*);
    TREE *less_num_del(int, TREE*);
    TREE *great_num_del(int, TREE*);
    int inOrderPredecessor(int, TREE*);
    int inOrdersuccessor(int, TREE*);
    int least_value(TREE*);
    int max_value(TREE*);
    int count_ext(TREE*);
    void array_insert(int array[], TREE*);
    TREE *deleteDuplicateNodes(TREE*);
    int memorytree(TREE*);
    int less_num_count(int, TREE*);
    int great_num_count(int, TREE*);
    int comp_search(int, TREE*);
    void root_max(TREE*);
    TREE* duplicate_tree(TREE*);
    int num_leaf(TREE*);
};

TREE *binarysearchtree::insert_to_bst(TREE *root, int data) {
    TREE *newnode = new TREE();
    newnode->data = data;
    newnode->left = newnode->right = NULL;

    if (root == NULL) {
        return newnode;
    }

    TREE *curr = root;
    TREE *parent = NULL;

    while (curr != NULL) {
        parent = curr;
        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (data < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;

    return root;
}

void binarysearchtree::inorder_traversal(TREE *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        cout << root->data << " ";
        inorder_traversal(root->right);
    }
}

void binarysearchtree::preorder_traversal(TREE *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void binarysearchtree::postorder_traversal(TREE *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->data << " ";
    }
}

TREE *binarysearchtree::delete_from_bst(TREE *root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
        root->left = delete_from_bst(root->left, data);
    else if (data > root->data)
        root->right = delete_from_bst(root->right, data);
    else {
        if (root->left == NULL) {
            TREE *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            TREE *temp = root->left;
            delete root;
            return temp;
        }

        TREE *succParent = root;
        TREE *succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        root->data = succ->data;
        delete succ;
    }

    return root;
}

void binarysearchtree::inandout(TREE *root) {
    if (root->left == NULL && root->right == NULL)
        cout << "Out degree of the root node is 0\n";
    else if (root->left != NULL && root->right != NULL)
        cout << "Out degree of the root node is 2\n";
    else
        cout << "Out degree of the root node is 1\n";
}

int binarysearchtree::edge_node(TREE *root) {
    if (root == NULL) return 0;
    return 1 + edge_node(root->left) + edge_node(root->right);
}

TREE *binarysearchtree::treesearch(int data, TREE *root) {
    if (root == NULL || root->data == data) return root;
    if (data < root->data) return treesearch(data, root->left);
    return treesearch(data, root->right);
}

TREE* binarysearchtree::less_num_del(int reqdata, TREE* root) {
    if (root == NULL) return NULL;
    root->left = less_num_del(reqdata, root->left);
    root->right = less_num_del(reqdata, root->right);
    if (root->data < reqdata) {
        TREE* temp = root->right;
        delete root;
        return temp;
    }
    return root;
}

TREE* binarysearchtree::great_num_del(int reqdata, TREE* root) {
    if (root == NULL) return NULL;
    root->left = great_num_del(reqdata, root->left);
    root->right = great_num_del(reqdata, root->right);
    if (root->data > reqdata) {
        TREE* temp = root->left;
        delete root;
        return temp;
    }
    return root;
}
int binarysearchtree::inOrderPredecessor(int reqdata, TREE *root) {
    TREE *curr = treesearch(reqdata, root);
    if (curr == NULL) {
        return -1;
    }

    if (curr->left != NULL) {
        curr = curr->left;
        while (curr->right != NULL) {
            curr = curr->right;
        }
        return curr->data;
    }

    TREE *predecessor = NULL;
    TREE *ancestor = root;
    while (ancestor != curr) {
        if (curr->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return (predecessor != NULL) ? predecessor->data : -1;
}

int binarysearchtree::inOrdersuccessor(int reqdata, TREE *root) {
    TREE *curr = treesearch(reqdata, root);
    if (curr == NULL) {
        return -1;
    }
    if (curr->right != NULL) {
        curr = curr->right;
        while (curr->left != NULL) {
            curr = curr->left;
        }
        return curr->data;
    }
    TREE *successor = NULL;
    TREE *ancestor = root;
    while (ancestor != curr) {
        if (curr->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return (successor != NULL) ? successor->data : -1;
}
int binarysearchtree::least_value(TREE *root) {
    while (root && root->left) root = root->left;
    return root ? root->data : -1;
}

int binarysearchtree::max_value(TREE *root) {
    while (root && root->right) root = root->right;
    return root ? root->data : -1;
}

int binarysearchtree::count_ext(TREE *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return count_ext(root->left) + count_ext(root->right);
}

void binarysearchtree::array_insert(int array[], TREE *root) {
    static int i = 0;
    if (root != NULL) {
        array_insert(array, root->left);
        array[i++] = root->data;
        array_insert(array, root->right);
    }
}

TREE *binarysearchtree::deleteDuplicateNodes(TREE *root) {
    if (root == NULL) return NULL;
    root->left = deleteDuplicateNodes(root->left);
    root->right = deleteDuplicateNodes(root->right);
    if (root->left && root->data == root->left->data) {
        TREE *temp = root->left;
        root->left = root->left->left;
        delete temp;
    }
    if (root->right && root->data == root->right->data) {
        TREE *temp = root->right;
        root->right = root->right->right;
        delete temp;
    }
    return root;
}

int binarysearchtree::memorytree(TREE *root) {
    if (root == NULL) return 0;
    return sizeof(TREE) + memorytree(root->left) + memorytree(root->right);
}

int binarysearchtree::less_num_count(int reqdata, TREE *root) {
    if (root == NULL) return 0;
    return (root->data < reqdata) + less_num_count(reqdata, root->left) + less_num_count(reqdata, root->right);
}

int binarysearchtree::great_num_count(int reqdata, TREE *root) {
    if (root == NULL) return 0;
    return (root->data > reqdata) + great_num_count(reqdata, root->left) + great_num_count(reqdata, root->right);
}

int binarysearchtree::comp_search(int data, TREE *root) {
    if (root == NULL) return 0;
    if (root->data == data) return 1;
    return 1 + (data < root->data ? comp_search(data, root->left) : comp_search(data, root->right));
}

void binarysearchtree::root_max(TREE *root) {
    int count = 0;
    while (root && root->right) {
        root = root->right;
        count++;
    }
    cout << "The number of edges between root node and max node is " << count << endl;
}

TREE *binarysearchtree::duplicate_tree(TREE *root) {
    if (root == NULL) return NULL;
    TREE *newnode = new TREE();
    newnode->data = root->data;
    newnode->left = duplicate_tree(root->left);
    newnode->right = duplicate_tree(root->right);
    return newnode;
}

int binarysearchtree::num_leaf(TREE *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return num_leaf(root->left) + num_leaf(root->right);
}
int main() {
    binarysearchtree tree;
    TREE *root;
    root=NULL;
    int choice=0,data=0;

    while(1) {
        cout<<"\n*******************************************************************\n";
        cout<<"*                         MENU                                    *\n";
        cout<<"*******************************************************************\n";
        cout<<"1--Insert a node in binary tree                                   *\n";
        cout<<"2--Inorder traversal                                              *\n";
        cout<<"3--Preorder traversal                                             *\n";
        cout<<"4--Postorder traversal                                            *\n";
        cout<<"5--Delete a node                                                  *\n";
        cout<<"(1)6--Print the in degree of root node                            *\n";
        cout<<"(2)7--Print the out degree of root node                           *\n";
        cout<<"(3)8--Searching in binary search tree                             *\n";
        cout<<"(4)9--Print Number of edges in tree                               *\n";
        cout<<"(5)10--Print Number of modes in tree                              *\n";
        cout<<"(6)11--Delete the nodes which are less than a number k            *\n";
        cout<<"(7)12--Delete the nodes which are greater than a number k         *\n";
        cout<<"(8)13--Count the nodes which are less than a number k             *\n";
        cout<<"(9)14--Count the nodes which are greater than a number k          *\n";
        cout<<"(10)15--Print the inorder precedessor a node                      *\n";
        cout<<"(11)16--print the inorder successor a node                        *\n";
        cout<<"(12)17--Find the minimum valued node in tree                      *\n";
        cout<<"(13)18--Find the maximum valued node in tree                      *\n";
        cout<<"(14)19--Find the number of external nodes in tree                 *\n";
        cout<<"(15)20--Print the adress of the root node                         *\n";
        cout<<"(16)21--Number of comparisios made to search a number             *\n";
        cout<<"(17)22--Number of nodes at level 1                                *\n";
        cout<<"(18)23--Count the number of leaf nodes                            *\n";
        cout<<"(19)24--Memory occupied by tree in bytes                          *\n";
        cout<<"(20)25--Total number of edges between root and max node           *\n";
        cout<<"(21)26--Total number of outdegrees of all leaf nodes              *\n";
        cout<<"(22)27--Find and Delete the all duplicate nodes                   *\n";
        cout<<"(23)28--Make the duplicate of given node                          *\n";
        cout<<"(24)29--Number of comparisios made to search a maximum element    *\n";
        cout<<"(25)30--Insert nodes in array and print                           *\n";
        cout<<"0--EXIT                                                           *\n";
        cout<<"*******************************************************************\n";

        cout<<"enter your choice\n";
        cin>>choice;

        if(choice==1) {
            cout<<"enter the data to insert\n";
            cin>>data;
            root=tree.insert_to_bst(root,data);
        }
        else if(choice==2) {
            if(root==NULL) {
                cout<<"tree is empty\n";
            }
            else {
                cout<<"inorder traversal is...";
                tree.inorder_traversal(root);
                cout << endl;
            }
        }
        else if(choice==3) {
            if(root==NULL) {
                cout<<"tree is empty\n";
            }
            else {
                cout<<"preorder traversal is...";
                tree.preorder_traversal(root);
                cout << endl;
            }
        }
        else if(choice==4) {
            if(root==NULL) {
                cout<<"tree is empty\n";
            }
            else {
                cout<<"postorder traversal is...";
                tree.postorder_traversal(root);
                cout << endl;
            }
        }
        else if(choice==5) {
            cout<<"enter the node to be deleted\n";
            cin>>data;
            root=tree.delete_from_bst(root, data);
            cout << endl;
        }
        else if (choice==6) {
            cout<<"In-degree of the root node is "<<0<<endl;
        }
        else if (choice==7) {
            tree.inandout(root);
        }
        else if(choice==8) {
            int data;
            TREE *temp=NULL;
            cout<<"enter the node to be searched\n";
            cin>>data;
            temp=tree.treesearch(data,root);
            if(temp!=NULL)cout<<temp->data<<" node found suuccessfully\n";
        }
        else if(choice==9) {
            int nodes=0;
            nodes=tree.edge_node(root);
            cout<<"number of nodes in tree\n";
            cout<<nodes<<endl;
        }
        else if(choice==10) {
            int edges=0;
            edges=tree.edge_node(root);
            cout<<"number of edges in tree\n";
            cout<<edges-1<<endl;
        }
        else if(choice==11) {
            int val;
            cout<<"enter the node to be searched (K)\n";
            cin>>val;
            root=tree.less_num_del(val,root);
            cout<<"nodes deleted succussfully\n";
        }
        else if(choice==12) {
            int val;
            cout<<"enter the node to be searched(K)\n";
            cin>>val;
            root=tree.great_num_del(val,root);
            cout<<"nodes deleted succussfully\n";
        }
        else if(choice==13) {
            int count1,data;
            cout<<"enter the value of number\n";
            cin>>data;
            count1=tree.less_num_count(data,root);
            cout<<"nodes smaller than a given number...";
            cout<<count1<<endl;
        }
        else if(choice==14) {
            int count2,data;
            cout<<"enter the value of number\n";
            cin>>data;
            count2=tree.great_num_count(data,root);
            cout<<"nodes greater than a given number...";
            cout<<count2<<endl;
        }
        else if(choice==15) {
            int value,pred;
            cout<<"enter the node\n";
            cin>>value;
            pred=tree.inOrderPredecessor(value,root);
            cout<<"inorder predecesor is\n";
            cout<<pred<<endl;
        }
        else if(choice==16) {
            int value,succ;
            cout<<"enter the node\n";
            cin>>value;
            succ=tree.inOrdersuccessor(value,root);
            cout<<"inorder successor is\n";
            cout<<succ<<endl;
        }
        else if(choice==17) {
            int least;
            least=tree.least_value(root);
            cout<<"minimum value of the tree\n";
            cout<<least<<endl;
        }
         else if(choice==18) {
            int max;
            max=tree.max_value(root);
            cout<<"maximum value of the tree\n";
            cout<<max<<endl;
        }
        else if(choice==19) {
            int value;
            value=tree.count_ext(root);
            cout<<"number of external nodes are\n";
            cout<<value<<endl;
        }
        else if(choice==20) {
            cout<<"address of the root node\n";
            if(root != NULL) cout<<root<<endl;
            else cout<<"root is empty\n";
        }
        else if(choice==21) {
            int data,count;
            cout<<"enter the node to be searched\n";
            cin>>data;
            count=tree.comp_search(data,root);
            cout<<"number of comparasions made to search the node\n";
            cout<<count<<endl;
        }
        else if(choice==22) {
            cout<<"Number of nodes at level 1... ";
            if(root->left==NULL && root->right==NULL) cout<<0<<endl;
            else if(root->left!=NULL && root->right!=NULL) cout<<2<<endl;
            else cout<<1<<endl;
        }
        else if(choice==23) {
            int value;
            value=tree.num_leaf(root);
            cout<<"number of leaf nodes are\n";
            cout<<value<<endl;
        }
        else if(choice==24) {
            int size;
            size=tree.memorytree(root);
            cout<<"total memory occupied by tree\n";
            cout<<size<<endl;
        }
        else if(choice==25) {
            tree.root_max(root);
        }
        else if(choice==26) {
            cout<<"total number of outdegrees of all leaf nodes... "<<0<<endl;
        }
        else if(choice==27) {
            root=tree.deleteDuplicateNodes(root);
            cout<<"same nodes are deleted\n";
        }
        else if(choice==28) {
            TREE *root2;
            root2=tree.duplicate_tree(root);
            cout<<"postorder traversal is...";
            tree.inorder_traversal(root2);
            cout << endl;
        }
        else if(choice==29) {
            cout << "Total number of comparision made in finding maximum element is " << tree.comp_search(tree.max_value(root), root) << endl;
        }
        else if(choice==30) {
            int array[5],nodes;
            nodes=tree.edge_node(root);
            tree.array_insert(array,root);
            for(int i=0;i<nodes;i++) {
                cout<<array[i]<<'\t';
            }
        }
        else if (choice==0) {
            exit(0);
        }
        else {
            cout<<"you have entered the wrong choice\n";
        }
    }
    return 0;
}



