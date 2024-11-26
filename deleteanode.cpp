/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

// Definition for a node in the linked list
struct LinkedListNode {
    int data;
    LinkedListNode* next;

    LinkedListNode(int data) : data(data), next(nullptr) {}
};

// Function to delete a given node in the linked list (excluding the tail)
bool deleteNode(LinkedListNode* n) {
    if (n == nullptr || n->next == nullptr) {
        return false; // Failure: null node or no next node (can't delete tail node)
    }

    LinkedListNode* next = n->next; // Get the next node
    n->data = next->data;           // Copy data from the next node to the current node
    n->next = next->next;           // Bypass the next node
    delete next;                    // Delete the next node
    return true;
}

// Helper function to print the linked list
void printList(LinkedListNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    LinkedListNode* head = new LinkedListNode(1);
    head->next = new LinkedListNode(2);
    head->next->next = new LinkedListNode(3);
    head->next->next->next = new LinkedListNode(4);
    head->next->next->next->next = new LinkedListNode(5);

    cout << "Original List: ";
    printList(head);

    // Delete the node with value 3 (middle node)
    LinkedListNode* nodeToDelete = head->next->next; // Node with value 3
    if (deleteNode(nodeToDelete)) {
        cout << "List after deleting node with value 3: ";
        printList(head);
    } else {
        cout << "Failed to delete the node." << endl;
    }

    return 0;
}
