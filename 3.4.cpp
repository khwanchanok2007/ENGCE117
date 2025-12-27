#include <stdio.h>

struct student {
    char name[50];
    int age;
};

void GetStudent(struct student child[][10], int *room);

int main() {
    struct student children[20][10];
    int group;
    GetStudent(children, &group);
    showResult(children, group);

    return 0;
}

void GetStudent(struct student child[][10], int *room) {
    printf("Enter number of classrooms (max 20): ");
    scanf("%d", room);

    if (*room < 1 || *room > 20) {
        printf("Invalid number of classerooms.\n");
        return;
    }

    for (int i = 0; i < *room; i++) {
        for (int j = 0; j < 10; j++) {
            printf("Student %d name: ", j+1);
            scanf("%s", child[i][j].name);
            printf("Student %d age: ", j+1);
            scanf("%d", &child[i][j].age);
        }
    }
}

void showResult(struct student child[][10], int room) {
    for (int i = 0; i < room; i++) {
        printf("\nClassroom %d:\n", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d. %s, Age: %d\n", j + 1, child[i][j].name, child[i][j].age);
        }
    }
}