#pragma once
#include <list>
#include "person.h"

// Список факультетов
const std::array<std::string, 5> facultiesList = { "Биологический", "Химический", "Механико-математический",
											 "Компьютерных наук", "Физический" };

class University {	// Класс "Университет"
private:
	std::string universityName = "";		// Название университета
	std::string rector = "";				// ФИО ректора
	std::list<Teacher*> teachersList = {};	// Список преподавателей
	std::list<Student*> studentsList = {};	// Список студентов

public:
	// Конструктор
	University(std::string name, std::string rector);
	// Деструктор
	~University();

	// Задать название университета
	void set_universityName(std::string name);
	// Задать ФИО ректора
	void set_rector(std::string fullName);
	// Вернуть название университета
	const std::string get_universityName() const;
	// Вернуть ФИО ректора
	const std::string get_rector() const;
	// Вернуть список преподавателей
	const std::list<Teacher*> get_teachersList() const;
	// Вернуть список студентов
	const std::list<Student*> get_studentsList() const;

	// Добавить преподавателя
	void addTeacher(Teacher* teacher);
	// Добавить студента
	void addStudent(Student* student);
	// Вывести информацию об университете
	void info() const;
	// Генератор случайных преподавателей
	void randomTeacherGen(unsigned short count);
	// Генератор случайных студентов
	void randomStudentGen(unsigned short count);
};