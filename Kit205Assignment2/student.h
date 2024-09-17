#ifndef STUDENT_H
#define STUDENT_H

#include "linkedlist.h"

typedef struct Student {
    int student_id;
    char name[50];
    Node* enrolled_courses; // Linked List of course IDs
} Student;

Student* create_student(int student_id, const char* name);
void enroll_course(Student* student, int course_id);
void print_student_courses(Student* student);

#endif // STUDENT_H
