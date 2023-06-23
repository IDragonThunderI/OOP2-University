#include <iostream>
#include "person.h"

void Person::set_fullName(std::string fullName) {
    this->fullName = fullName;
}

void Person::set_gender(std::string gender) {
    this->gender = gender;
}

void Person::set_age(unsigned short age) {
    this->age = age;
}

const std::string Person::get_fullName() const {
    return this->fullName;
}

const std::string Person::get_gender() const {
    return this->gender;
}

const unsigned short Person::get_age() const {
    return this->age;
}

void Person::info() const {
    std::cout << "ФИО: " << get_fullName() << std::endl;
    std::cout << "Пол: " << get_gender() << std::endl;
    std::cout << "Возраст: " << get_age() << std::endl;
}

Teacher::Teacher(std::string fullName, std::string gender, unsigned short age, std::string faculty) {
    set_gender(gender);
    set_fullName((fullName != "") ? fullName : this->fullNameGen());
    set_age(age);
    set_faculty(faculty);
}

void Teacher::set_faculty(std::string faculty) {
    this->faculty = faculty;
}

const std::string Teacher::get_faculty() const {
    return this->faculty;
}

std::string Teacher::fullNameGen() {
    std::array<std::string, 3> buf{};
    if (this->get_gender().at(0) == 'М' or this->get_gender().at(0) == 'м') {
        buf.at(0) = surnameList.at(rand() % 5 + 10);
        buf.at(1) = maleNameList.at(rand() % 5 + 10);
        buf.at(2) = patronymicList.at(rand() % 5 + 10) + "ич";
    }
    else {
        buf.at(0) = surnameList.at(rand() % 5 + 10) + "а";
        buf.at(1) = femaleNameList.at(rand() % 5 + 10);
        buf.at(2) = patronymicList.at(rand() % 5 + 10) + "на";
    }
    return buf.at(0) + " " + buf.at(1) + " " + buf.at(2);
}

void Teacher::info() const {
    this->Person::info();
    std::cout << "Факультет: " << get_faculty() << std::endl << std::endl;
}

Student::Student(std::string fullName, std::string gender, unsigned short age, std::string faculty, unsigned short course) {
    set_gender(gender);
    set_fullName((fullName != "") ? fullName : this->fullNameGen());
    set_age(age);
    set_faculty(faculty);
    set_course(course);
}

void Student::set_faculty(std::string faculty) {
    this->faculty = faculty;
}

void Student::set_course(unsigned short course) {
    this->course = course;
}

const std::string Student::get_faculty() const {
    return this->faculty;
}

const unsigned short Student::get_course() const {
    return this->course;
}

std::string Student::fullNameGen() {
    std::array<std::string, 3> buf{};
    if (this->get_gender().at(0) == 'М' or this->get_gender().at(0) == 'м') {
        buf.at(0) = surnameList.at(rand() % 10);
        buf.at(1) = maleNameList.at(rand() % 10);
        buf.at(2) = patronymicList.at(rand() % 10) + "ич";
    }
    else {
        buf.at(0) = surnameList.at(rand() % 10) + "а";
        buf.at(1) = femaleNameList.at(rand() % 10);
        buf.at(2) = patronymicList.at(rand() % 10) + "на";
    }
    return buf.at(0) + " " + buf.at(1) + " " + buf.at(2);
}

void Student::info() const {
    this->Person::info();
    std::cout << "Факультет: " << get_faculty() << std::endl;
    std::cout << "Курс: " << get_course() << std::endl << std::endl;
}
