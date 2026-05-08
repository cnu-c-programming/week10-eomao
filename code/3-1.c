#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int score;
    struct Student *next;
};

void add_student(struct Student **head, char *name, int score) {
    struct Student *new_node = (struct Student *)malloc(sizeof(struct Student));

    strcpy(new_node->name, name);
    new_node->score = score;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Student *cur = *head;

    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = new_node;
}

void delete_student(struct Student **head, char *name) {
    struct Student *cur = *head;
    struct Student *prev = NULL;

    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            if (prev == NULL) {
                *head = cur->next;
            } else {
                prev->next = cur->next;
            }

            free(cur);
            return;
        }

        prev = cur;
        cur = cur->next;
    }
}

void print_students(struct Student *head) {
    struct Student *cur = head;

    while (cur != NULL) {
        printf("%s %d\n", cur->name, cur->score);
        cur = cur->next;
    }
}

void free_students(struct Student *head) {
    struct Student *cur = head;

    while (cur != NULL) {
        struct Student *temp = cur;
        cur = cur->next;
        free(temp);
    }
}

int main() {
    struct Student *head = NULL;
    char command[20];
    char name[50];
    int score;

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            add_student(&head, name, score);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete_student(&head, name);
        } else if (strcmp(command, "print") == 0) {
            print_students(head);
        } else if (strcmp(command, "quit") == 0) {
            free_students(head);
            break;
        }
    }

    return 0;
}
