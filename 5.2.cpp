#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void showAll(studentNode **walk);
void InsNode(studentNode **now, const char *name, int age, char sex, float gpa);
void GoNext(studentNode ***now);
void DelNode(studentNode **now);

int main() {
    studentNode *start, **now;
    start = NULL;
    now = &start;

    InsNode(&start, "one", 6, 'M', 3.11); showAll(&start);
    InsNode(&start, "two", 8, 'F', 3.22); showAll(&start);
    GoNext(&now);
    InsNode(now, "three", 10, 'M', 3.33); showAll(&start);
    InsNode(now, "four", 12, 'F', 3.44); showAll(&start);
    GoNext(&now);
    DelNode(now); showAll(&start);

    return 0;
}

void InsNode(studentNode **now, const char *name, int age, char sex, float gpa) {
    studentNode *newNode = new studentNode;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    newNode->next = *now;
    *now = newNode;
}

void GoNext(studentNode ***now) {
    if (**now != nullptr) {
        *now = &((**now)->next);
    }
}

void DelNode(studentNode **now) {
    if (*now == nullptr) return;

    studentNode *temp = *now;
    *now = temp->next;
    delete temp;
}

void showAll(struct studentNode **walk) {
    while ((*walk) != nullptr) {
        printf("%s ", (*walk)->name);
        walk = &(*walk)->next;
    }
    printf("\n");
}