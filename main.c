#include <stdio.h>
#include "Node/node.h"

int main() {
    int action;
    int element;
    struct Node* queue = queueInit();
    while (1) {
        printf("Menu:\n"
               "(1) Add an element to the queue\n"
               "(2) Delete and print an element by key\n"
               "(3) Print the queue\n"
               "(4) Exit\n\n");
        scanf("%i", &action);
        switch (action) {
            case 1:
                printf("Enter an element you want to add to the queue:\n");
                scanf("%i", &element);
                insert(&queue, element);
                printf("\n");
                break;
            case 2:
                printf("What element do you want to delete?\n");
                scanf("%i", &action);
                if (!isEmpty(queue)) {
                    int success = delete(&queue, action);
                    if (success == 1) {
                        printf("Element %i was removed.\n\n", action);
                    } else {
                        printf("Element wasn't found in the queue.\n\n");
                    }
                } else {
                    printf("No elements were removed, because the queue is empty.\n\n");
                }
                break;
            case 3:
                printQueue(queue);
                break;
            case 4:
                printf("You're about to exit the program. Are you sure? (Y/N)\n");
                char exitAction;
                scanf(" %c", &exitAction);
                if (exitAction == 'y' || exitAction == 'Y') {
                    printf("Exiting...\n");
                    while (!isEmpty(queue)) {
                        delete(&queue, queue->key);
                    }
                    free(queue);
                    return 0;
                } else if (exitAction == 'n' || exitAction == 'N') {
                    printf("Aborting.\n");
                }
            default:
                printf("Please enter a valid option.\n\n");
        }
    }
}
