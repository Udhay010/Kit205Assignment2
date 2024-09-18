import random
import string

# Function to generate random names
def random_name(length=6):
    return ''.join(random.choices(string.ascii_uppercase, k=length))

# Function to generate random student data
def generate_student_data(num_students=10000):
    students = []
    for i in range(1, num_students + 1):
        name = random_name()
        students.append(f"{i},{name}\n")  # student_id,name
    
    with open("students_data.csv", "w") as f:
        f.writelines(students)

# Function to generate random course data
def generate_course_data(num_courses=100):
    courses = []
    for i in range(101, 101 + num_courses):
        course_name = random_name()
        courses.append(f"{i},{course_name}\n")  # course_id,name
    
    with open("courses_data.csv", "w") as f:
        f.writelines(courses)

generate_student_data()  # Generates 10,000 students
generate_course_data()  # Generates 100 courses
