#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"

Course* create_course(int course_id, const char* course_name) {
    Course* new_course = (Course*)malloc(sizeof(Course));
    new_course->course_id = course_id;
    strcpy(new_course->course_name, course_name);
    return new_course;
}

void print_course(Course* course) {
    printf("Course ID: %d, Course Name: %s\n", course->course_id, course->course_name);
}
