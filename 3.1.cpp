#include <stdio.h>

struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};

void upgrade(struct student *person);

int main() {
    struct student aboy;
    aboy.sex = 'F';
    aboy.gpa = 3.00;

    upgrade(&aboy); 

    printf("%.2f", aboy.gpa); 

    return 0;
}

void upgrade(struct student *person) {
    if (person->sex == 'M') {
        person->gpa *= 1.1;   
    } else if (person->sex == 'F') {
        person->gpa *= 1.2;
    }
}