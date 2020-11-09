//
// Created by Gereon on 08.11.2020.
//

#ifndef AUD_PRAKTIKUM1_NODE_H
#define AUD_PRAKTIKUM1_NODE_H

#include <stdlib.h>
#include <limits.h>

struct Node {
    int key;
    struct Node* next;
};

struct Node* queueInit();
void insert(struct Node** queue, int key);
int delete(struct Node** queue, int key);
int isEmpty(struct Node* queue);
void printQueue(struct Node* queue);

#endif //AUD_PRAKTIKUM1_NODE_H
