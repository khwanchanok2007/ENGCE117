#include <stdio.h>

struct student {
    char name[50];
    int age;
};

struct student data[10][10];

struct student(*GetStudent(int *room))[10];

int main() {
    int group;
    struct student (*children)[10] = GetStudent(&group);

    for (int i = 0; i < group; i++) {
        printf("\n-----Class %d-----\n", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("Student %d's name: %s, age: %d\n", j + 1, children[i][j].name, children[i][j].age);
        }
    }

    return 0;
}

struct student(*GetStudent(int *room))[10] {
    printf("Enter number of classrooms: ");
    scanf("%d", room);

    for (int i = 0; i < *room; i++) {
        printf("\n---Class %d---\n", i+1);
        for (int j = 0; j < 10; j++) {
            printf("Enter the student %d's name and age: ", j + 1);
            scanf("%s %d", data[i][j].name, &data[i][j].age);
        }
    }

    return data;
}