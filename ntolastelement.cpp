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

// Function to find the nth-to-last node in the linked list
LinkedListNode* nthToLast(LinkedListNode* head, int n) {
    if (head == nullptr || n < 1) {
        return nullptr; // Invalid input
    }

    LinkedListNode* p1 = head;
    LinkedListNode* p2 = head;

    // Move p2 n-1 steps ahead
    for (int j = 0; j < n - 1; ++j) {
        if (p2 == nullptr || p2->next == nullptr) {
            return nullptr; // n is larger than the size of the list
        }
        p2 = p2->next;
    }

    // Move both p1 and p2 one step at a time until p2 reaches the end
    while (p2->next != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1; // p1 now points to the nth-to-last node
}

// Helper function to print the list
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

    int n = 2; // Example: Find 2nd-to-last element
    LinkedListNode* result = nthToLast(head, n);

    if (result != nullptr) {
        cout << "The " << n << "th-to-last element is: " << result->data << endl;
    } else {
        cout << "Invalid n or the list is too short." << endl;
    }

    return 0;
}
