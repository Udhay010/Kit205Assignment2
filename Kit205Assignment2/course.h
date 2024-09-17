#ifndef COURSE_H
#define COURSE_H

typedef struct Course {
    int course_id;
    char course_name[50];
} Course;

Course* create_course(int course_id, const char* course_name);
void print_course(Course* course);

#endif // COURSE_H
