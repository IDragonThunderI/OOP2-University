#pragma once
#include "university.h"

class UserInterface {	// Класс "Пользовательский интерфейс"
private:
	University* university = nullptr;	// Университет

	// Найти студентов по факультету
	void findStudentsByFaculty() const;
	// Найти студентов по курсу
	void findStudentsByCourse() const;
	// Найти преподавателей по факультету
	void findTeachersByFaculty() const;
	
public:
	// Конструктор
	UserInterface(University* university);

	// Вывести информацию об университете
	void showUniversityInfo() const;
	// Вывести список факультетов
	void showFacultyList() const;
	// Вывести список преподавателей
	void showTeachersList() const;
	// Вывести список студентов
	void showStudentsList() const;
	// Найти студентов по критериям
	void findStudents() const;
	// Найти преподавателей по критериям
	void findTeachers() const;
};

// Функция проверки корректности пользовательского ввода
unsigned short menuInput(size_t numberOfItems);
