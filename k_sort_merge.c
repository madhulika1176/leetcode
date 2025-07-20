#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Min-heap functions
void swap(struct ListNode** a, struct ListNode** b) {
    struct ListNode* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct ListNode** heap, int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;

    if (l < n && heap[l]->val < heap[smallest]->val)
        smallest = l;
    if (r < n && heap[r]->val < heap[smallest]->val)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void buildMinHeap(struct ListNode** heap, int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(heap, n, i);
}

// Merge function
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode** heap = (struct ListNode**)malloc(sizeof(struct ListNode*) * listsSize);
    int heapSize = 0;

    for (int i = 0; i < listsSize; i++) {
        if (lists[i]) heap[heapSize++] = lists[i];
    }

    buildMinHeap(heap, heapSize);

    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (heapSize > 0) {
        struct ListNode* minNode = heap[0];
        tail->next = minNode;
        tail = tail->next;

        if (minNode->next)
            heap[0] = minNode->next;
        else {
            heap[0] = heap[--heapSize];
        }

        heapify(heap, heapSize, 0);
    }

    free(heap);
    return dummy.next;
}

// Helper to print the linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Sample usage
int main() {
    // Creating 3 linked lists: [1,4,5], [1,3,4], [2,6]
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(4);
    list1->next->next = createNode(5);

    struct ListNode* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);

    struct ListNode* list3 = createNode(2);
    list3->next = createNode(6);

    struct ListNode* lists[] = {list1, list2, list3};

    struct ListNode* merged = mergeKLists(lists, 3);
    printList(merged);

    return 0;
}
