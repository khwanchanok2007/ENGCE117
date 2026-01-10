#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void showAll(struct studentNode *walk);
studentNode *addNode(studentNode **start, const char *name, int age, char sex, float gpa);
void InsNode(studentNode *now, const char *name, int age, char sex, float gpa);
void DelNode(studentNode *now);

int main() {
    studentNode *start = nullptr;
    studentNode *now;

    now = addNode(&start, "one", 6, 'M', 3.11); showAll(start);
    now = addNode(&start, "two", 8, 'F', 3.22); showAll(start);
    InsNode(now, "three", 10, 'M', 3.33); showAll(start);
    InsNode(now, "four", 12, 'F', 3.44); showAll(start);
    DelNode(now); showAll(start);

    return 0;
}

// add node function
studentNode *addNode(studentNode **start, const char *name, int age, char sex, float gpa) {
    studentNode *newNode = new studentNode;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = nullptr;

    if (*start == nullptr) {
        *start = newNode;
    } else {
        studentNode *walk = *start;
        while (walk->next != nullptr) {
            walk = walk->next;
        }
        walk->next = newNode;
    }

    return newNode;
}

// insert function
void InsNode(studentNode *now, const char *name, int age, char sex, float gpa) {
    if (now == nullptr) return;

    studentNode *newNode = new studentNode;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = now->next;
    now->next = newNode;
}

//delete node function
void DelNode(studentNode *now) {
    if (now == nullptr || now->next == nullptr) return;
    studentNode *temp = now->next;
    now->next = temp->next;
    delete temp;
}

void showAll(struct studentNode *walk) {
    while (walk != nullptr) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}