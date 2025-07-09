#include <stdio.h>
#include <stdlib.h>

// Define the structure of a linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to remove duplicates from a sorted linked list
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *current = head;

    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            // Duplicate found, skip the next node
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return head;
}

// Helper functions for testing:

// Function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Sample usage
int main() {
    // Create list: 1 -> 1 -> 2
    struct ListNode* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);

    printf("Original list:\n");
    printList(head);

    head = deleteDuplicates(head);

    printf("List after removing duplicates:\n");
    printList(head);

    return 0;
}
