//
// Created by IButskhrikidze on 9/10/19.
//

#include <bits/stdc++.h>

#define ll long long

using namespace std;

//class of Binary Search tree with template T
template<typename T>
class BST {
private:
    //BST node structure which contains references of right and left child and key value
    struct Node {
        Node *right;
        Node *left;
        T key;

        Node() {
            right = nullptr;
            left = nullptr;
        }
    };

    //declare root of BST
    Node *Root;

    void Insert(T val, Node *&root) {
        if (root == nullptr) {
            root = new Node;
            root->key = val;
        } else {
            if (root->key <= val) {
                Insert(val, root->right);
            } else {
                Insert(val, root->left);
            }
        }
    }

    Node *Find_min(Node *root) {
        if (root == nullptr) {
            return root;
        } else if (root->left == nullptr) {
            return root;
        } else {
            return Find_min(root->left);
        }
    }

    Node *Find_max(Node *root) {
        if (root == nullptr) {
            return root;
        } else if (root->right == nullptr) {
            return root;
        } else {
            return Find_max(root->right);
        }
    }

    Node *Search(T val, Node *&root) {
        if (root == nullptr) {
            return root;
        }

        if (root->key == val) {
            return root;
        }

        if (root->key <= val) {
            return Search(val, root->right);
        } else {
            return Search(val, root->left);
        }
    }

    void Inorder(Node *root) {
        if (root == nullptr) {
            return;
        }
        Inorder(root->left);
        //apply root, prints in this case;
        cout << root->key << ' ';
        Inorder(root->right);
    }

    void Preorder(Node *root) {
        if (root == nullptr) {
            return;
        }

        //apply root, prints in this case;
        cout << root->key << ' ';

        Preorder(root->left);
        Preorder(root->right);
    }

    void Postorder(Node *root) {
        if (root == nullptr) {
            return;
        }
        Postorder(root->left);
        Postorder(root->right);

        //apply root, prints in this case;
        cout << root->key << ' ';

    }

    void Delete(T val, Node *&root) {
        if (root->key == val) {
            if (root->left == nullptr && root->right == nullptr) {
                root = nullptr;
            } else if (root->left == nullptr && root->right != nullptr) {
                root = root->right;
            } else if (root->left != nullptr && root->right == nullptr) {
                root = root->left;
            } else {
                Node *mx = Find_max(root->left);
                root->key = mx->key;
                mx = nullptr;
            }
        } else {
            if (root->key <= val) {
                Delete(val, root->right);
            } else {
                Delete(val, root->left);
            }
        }
    }

public:
    BST() {
        Root = nullptr;
    }

    //insert element in BST
    void insert(T x) {
        Insert(x, Root);
    }

    //delete element from BST
    void del(T x) {
        Delete(x, Root);
    }

    //search element in BST returns true or false
    bool search(T x) {
        return Search(x, Root) != nullptr;
    }

    //prints BST elements inorder
    void inorder() {
        Inorder(Root);
    }

    //prints BST elements preorder
    void preorder() {
        Preorder(Root);
    }

    //prints BST elements postorder
    void postorder() {
        Postorder(Root);
    }

    //returns max element of BST
    T max() {
        return Find_max(Root)->key;
    }

    //returns min element of BST
    T min() {
        return Find_min(Root)->key;
    }
};

int main() {
    int n;
    cin >> n;
    BST<int> T;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        T.insert(x);
    }
    T.del(5);
    cout << T.max() << ' ' << T.min();
    return 0;
}
