#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

Student* create_student(int student_id, const char* name) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    new_student->student_id = student_id;
    strcpy_s(new_student->name, sizeof(new_student->name), name);  // This is safer
    new_student->enrolled_courses = NULL; // No courses enrolled initially
    return new_student;
}

void enroll_course(Student* student, int course_id) {
    insert(&(student->enrolled_courses), course_id); // Use Linked List to store course IDs
}

void print_student_courses(Student* student) {
    printf("Student %s (ID: %d) enrolled in courses: ", student->name, student->student_id);
    print_list(student->enrolled_courses);
}
