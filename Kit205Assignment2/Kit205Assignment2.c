#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "course.h"
#include "bst.h"
#include "hashtable.h"
#include "heap.h"

#define MAX_STUDENTS 10
#define MAX_COURSES 10

int main() {
    // 1. Course Management using BST
    BSTNode* course_root = NULL;
    course_root = insert_bst(course_root, create_course(101, "Mathematics")->course_id);
    course_root = insert_bst(course_root, create_course(102, "Physics")->course_id);
    course_root = insert_bst(course_root, create_course(103, "Chemistry")->course_id);

    printf("Courses (Inorder):\n");
    inorder_bst(course_root); // Will print in sorted order by course ID

    // 2. Student Management using Hash Table
    HashNode* student_table[TABLE_SIZE] = { NULL };

    Student* student1 = create_student(1, "Alice");
    Student* student2 = create_student(2, "Bob");
    Student* student3 = create_student(3, "Charlie");

    insert_hash(student_table, student1->student_id, (int)student1);
    insert_hash(student_table, student2->student_id, (int)student2);
    insert_hash(student_table, student3->student_id, (int)student3);

    printf("\nEnrolling Students into Courses:\n");
    enroll_course(student1, 101); // Alice in Mathematics
    enroll_course(student1, 102); // Alice in Physics
    enroll_course(student2, 103); // Bob in Chemistry
    enroll_course(student3, 101); // Charlie in Mathematics

    printf("\nStudents and their enrolled courses:\n");
    print_student_courses(student1);
    print_student_courses(student2);
    print_student_courses(student3);

    // 3. Heap for Course Popularity (to track most enrolled courses)
    MinHeap* course_popularity = create_minheap();

    insert_heap(course_popularity, 101); // Mathematics
    insert_heap(course_popularity, 102); // Physics
    insert_heap(course_popularity, 103); // Chemistry

    printf("\nHeap of most popular courses:\n");
    print_heap(course_popularity); // Min-heap will show least popular at root

    return 0;
}
