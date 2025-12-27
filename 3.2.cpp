#include <stdio.h>

struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};

void upgrade(struct student *chlid);

int main() {
    struct student aboy;
    aboy.sex = 'F';
    aboy.gpa = 2.00;
    upgrade(&aboy);
    printf("%.2f", aboy.gpa);

    return 0;
}

void upgrade(struct student *chlid) {

    if (chlid->sex == 'M') {
        chlid->gpa *= 1.1;   
    } else if (chlid->sex == 'F') {
        chlid->gpa *= 1.2;
    }
}