#include <iostream>
#include "university.h"

University::University(std::string name, std::string rector) {
    set_universityName(name);
    set_rector(rector);
}

University::~University() {
    for (auto& teacher : teachersList) {
        delete teacher;
    }
    for (auto& student : studentsList) {
        delete student;
    }
}

void University::set_universityName(std::string name) {
    this->universityName = name;
}

void University::set_rector(std::string fullName) {
    this->rector = fullName;
}

const std::string University::get_universityName() const {
    return this->universityName;
}

const std::string University::get_rector() const {
    return this->rector;
}

const std::list<Teacher*> University::get_teachersList() const {
    return this->teachersList;
}

const std::list<Student*> University::get_studentsList() const {
    return this->studentsList;
}

void University::addTeacher(Teacher* teacher) {
    this->teachersList.emplace_back(teacher);
}

void University::addStudent(Student* student) {
    this->studentsList.emplace_back(student);
}

void University::info() const {
    std::cout << "Название университета: " << get_universityName() << std::endl;
    std::cout << "ФИО ректора: " << get_rector() << std::endl;
}

void University::randomTeacherGen(unsigned short count) {
    for (unsigned short i = 0; i < count; i++) {
        this->addTeacher(new Teacher("", (rand() % 2) ? "Мужской" : "Женский", rand() % 31 + 30, facultiesList.at(rand() % 5)));
    }
}

void University::randomStudentGen(unsigned short count) {
    for (unsigned short i = 0; i < count; i++) {
        unsigned short age = rand() % 5 + 17;
        unsigned short course = age - (rand() % 2 + 16);
        if (course == 5) {
            course--;
        }
        this->addStudent(new Student("", (rand() % 2) ? "Мужской" : "Женский", age, facultiesList.at(rand() % 5), course ? course : course + 1));
    }
}
