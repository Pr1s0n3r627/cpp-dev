#include<iostream>
using namespace std;

struct Node {
    string id;
    Node* next;
    Node(string x) : id(x), next(NULL) {}
};

int main() {
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "No activities entered\n";
    } else {
        Node *head = NULL, *tail = NULL;
        for (int i = 0; i < n; i++) {
            string act;
            cin >> act;
            Node* temp = new Node(act);
            if (!head) head = temp;
            else tail->next = temp;
            tail = temp;
        }
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *cur = head;
        while (cur) {
            cout << cur->id << " -> ";
            cur = cur->next;
        }
        cout << "NULL\n";
        cout << slow->id << '\n';
    }
    return 0;
}