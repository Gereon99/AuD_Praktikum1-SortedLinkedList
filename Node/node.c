//
// Created by Gereon on 08.11.2020.
//

#include "node.h"
#include <stdio.h>

struct Node* queueInit() {
    struct Node* ptr = calloc(sizeof(struct Node), 1);
    if (ptr == NULL) {
        exit(10);
    }
    ptr->key = INT_MAX;
    ptr->next = NULL;
    return ptr;
}

void insert(struct Node** queue, int key) {
    struct Node* head = *queue;
    struct Node* ptr = calloc(sizeof(struct Node), 1);
    if (ptr == NULL) {
        exit(10);
    }
    ptr->key = key;
    if (head->key > key) {
        ptr->next = head;
        *queue = ptr;
    } else {
        while (head->next) {
            if (head->next != NULL && head->next->key > key) {
                struct Node* temp = head->next;
                ptr->next = temp;
                head->next = ptr;
                break;
            }
            head = head->next;
        }
    }
}

int delete(struct Node** queue, int key) {
    struct Node* head = *queue;
    if (isEmpty(head)) {
        return -1;
    }
    if (!isEmpty(head) && head->key == key) {
        // Delete front node
        struct Node* temp = head;
        *queue = temp->next;
        free(head);
    } else {
        while (head->next) {
            if (head->next->key == key) {
                // Delete node in the middle or something
                struct Node* temp = head->next;
                head->next = temp->next;
                free(temp);
                return 1;
            }
            head = head->next;
        }
    }
    return -1;
}

int isEmpty(struct Node* queue) {
    return queue->next == NULL;
}

void printQueue(struct Node* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue content: ");
        while (queue->next) {
            printf(" %i", queue->key);
            queue = queue->next;
        }
        printf("\n");
    }
}