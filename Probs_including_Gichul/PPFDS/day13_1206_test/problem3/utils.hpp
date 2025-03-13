#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class utils {
public:
    static void insert(Node*& root, int value) {
        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->left == nullptr) {
                curr->left = newNode;
                return;
            } else {
                q.push(curr->left);
            }

            if (curr->right == nullptr) {
                curr->right = newNode;
                return;
            } else {
                q.push(curr->right);
            }
        }
    }

    static void print(Node*& dllHead) {
        Node* curr = dllHead;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->right;
        }
        cout << endl;
    }
    // static void print(Node*& dllHead) {
    //     Node* curr = dllHead;
    //     if (curr==nullptr)
    //     {
    //         cout << "Invaild DLL";
    //     }
        
    //     while (curr != nullptr) {
    //         cout << curr->data << " ";
    //         if (curr->right != nullptr)
    //         {
    //             curr = curr->right;
    //         }
    //         else {break;}
    //     }
    //     while (curr != nullptr) {
    //         cout << curr->data << " ";
    //         curr = curr->left;
    //     }
    //     cout << endl;
    // }
};