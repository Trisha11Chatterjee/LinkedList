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

// Function to add two linked lists recursively
LinkedListNode* addLists(LinkedListNode* l1, LinkedListNode* l2, int carry) {
    if (l1 == nullptr && l2 == nullptr && carry == 0) {
        return nullptr; // Base case: no more digits and no carry
    }

    int value = carry; // Start with carry from the previous addition
    if (l1 != nullptr) {
        value += l1->data; // Add data from the first list
    }
    if (l2 != nullptr) {
        value += l2->data; // Add data from the second list
    }

    // Create a new node with the sum's last digit
    LinkedListNode* result = new LinkedListNode(value % 10);

    // Recursively calculate the next digit
    LinkedListNode* more = addLists(
        l1 == nullptr ? nullptr : l1->next, // Move to the next node in l1
        l2 == nullptr ? nullptr : l2->next, // Move to the next node in l2
        value >= 10 ? 1 : 0                 // Pass carry if value >= 10
    );

    // Link the result node to the next digit
    result->next = more;

    return result; // Return the result node
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
    // Create first number: 7 -> 1 -> 6 (represents 617)
    LinkedListNode* l1 = new LinkedListNode(7);
    l1->next = new LinkedListNode(1);
    l1->next->next = new LinkedListNode(6);

    // Create second number: 5 -> 9 -> 2 (represents 295)
    LinkedListNode* l2 = new LinkedListNode(5);
    l2->next = new LinkedListNode(9);
    l2->next->next = new LinkedListNode(2);

    cout << "First List: ";
    printList(l1);
    cout << "Second List: ";
    printList(l2);

    // Add the two numbers
    LinkedListNode* result = addLists(l1, l2, 0);

    cout << "Resultant List: ";
    printList(result);

    return 0;
}
