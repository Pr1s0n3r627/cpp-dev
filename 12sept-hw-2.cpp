#include<iostream>
using namespace std;

struct Node {
    string id;
    Node* next;
    Node(string x) : id(x), next(NULL) {}
};

Node* mergeLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->id < l2->id) {
        l1->next = mergeLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeLists(l1, l2->next);
        return l2;
    }
}

int main() {
    int n1, n2;
    cin >> n1;
    Node *head1 = NULL, *tail1 = NULL;
    for (int i = 0; i < n1; i++) {
        string id;
        cin >> id;
        Node* temp = new Node(id);
        if (!head1) head1 = temp;
        else tail1->next = temp;
        tail1 = temp;
    }

    cin >> n2;
    Node *head2 = NULL, *tail2 = NULL;
    for (int i = 0; i < n2; i++) {
        string id;
        cin >> id;
        Node* temp = new Node(id);
        if (!head2) head2 = temp;
        else tail2->next = temp;
        tail2 = temp;
    }

    Node* merged = mergeLists(head1, head2);
    while (merged) {
        cout << merged->id << " -> ";
        merged = merged->next;
    }
    cout << "NULL\n";
    return 0;
}