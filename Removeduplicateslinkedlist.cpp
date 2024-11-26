/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for a node in the linked list
struct LinkedListNode {
    int data;
    LinkedListNode* next;

    LinkedListNode(int data) : data(data), next(nullptr) {}
};

// Function to remove duplicates from the linked list
void deleteDups(LinkedListNode* head) {
    unordered_set<int> seen; // Stores unique elements
    LinkedListNode* previous = nullptr; // Tracks the previous node
    LinkedListNode* current = head; // Tracks the current node

    while (current != nullptr) {
        if (seen.find(current->data) != seen.end()) {
            // If data is a duplicate, bypass the current node
            previous->next = current->next;
        } else {
            // Otherwise, add the data to the set and update the previous pointer
            seen.insert(current->data);
            previous = current;
        }
        current = current->next; // Move to the next node
    }
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
    // Creating a linked list: 1 -> 2 -> 1 -> 3
    LinkedListNode* head = new LinkedListNode(1);
    head->next = new LinkedListNode(2);
    head->next->next = new LinkedListNode(1);
    head->next->next->next = new LinkedListNode(3);

    cout << "Original List: ";
    printList(head);

    deleteDups(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
