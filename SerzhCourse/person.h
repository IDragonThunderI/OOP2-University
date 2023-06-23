#pragma once
#include <string>
#include <array>

// Список мужских имён для генератора
const std::array<std::string, 15> maleNameList = { "Сергей", "Андрей", "Иван", "Данила", "Роман",
											 "Виталий", "Юрий", "Александр", "Алексей", "Никита",
											 "Антон", "Игорь", "Павел", "Константин", "Максим" };
// Список женских имён для генератора
const std::array<std::string, 15> femaleNameList = { "Анна", "Анастасия", "Валентина", "Наталья", "Марина",
											   "Ольга", "Юлия", "Екатерина", "Татьяна", "Светлана",
											   "Ирина", "Полина", "Оксана", "Виктория", "Елизавета" };
// Список фамилий для генератора (для женских добавить 'а')
const std::array<std::string, 15> surnameList = { "Анисимов", "Астафьев", "Измайлов", "Безруков", "Винокуров",
											"Воронцов", "Галкин", "Гончаров", "Зайцев", "Дьяконов",
											"Егоров", "Жуков", "Дроздов", "Захаров", "Ильин" };
// Список отчеств для генератора (для мужских добавить 'ич', для женских - 'на')
const std::array<std::string, 15> patronymicList = { "Абрамов", "Андреев", "Денисов", "Иванов", "Олегов",
											   "Елисеев", "Игорев", "Владимиров", "Вячеславов", "Максимов",
											   "Глебов", "Тимофеев", "Игнатьев", "Борисов", "Степанов" };

class Person {	// Абстрактный класс "Человек"
protected:
	std::string fullName = "";	// ФИО
	std::string gender = "";	// Пол
	unsigned short age = 0;		// Возраст

public:
	// Задать ФИО
	virtual void set_fullName(std::string fullName);
	// Задать пол
	virtual void set_gender(std::string gender);
	// Задать возрасть
	virtual void set_age(unsigned short age);
	// Вернуть ФИО
	virtual const std::string get_fullName() const;
	// Вернуть пол
	virtual const std::string get_gender() const;
	// Вернуть возраст
	virtual const unsigned short get_age() const;

	// Генератор случайных имён
	virtual	std::string fullNameGen() = 0;
	// Вывести информацию о человеке
	virtual void info() const;
};

class Teacher : public Person {	// Класс "Преподаватель"
private:
	std::string faculty;	// Факультет

public:
	// Конструктор
	Teacher(std::string fullName, std::string gender, unsigned short age, std::string faculty);

	// Задать факультет
	void set_faculty(std::string faculty);
	// Вернуть факультет
	const std::string get_faculty() const;

	// Переопределённый метод генератора имён для преподавателей
	std::string fullNameGen() override;
	// Вывести информацию о преподавателе
	void info() const override;
};

class Student : public Person {	// Класс "Студент"
private:
	std::string faculty;	// Факультет
	unsigned short course;	// Курс

public:
	// Конструктор
	Student(std::string fullName, std::string gender, unsigned short age, std::string faculty, unsigned short course);

	// Задать факультет
	void set_faculty(std::string faculty);
	// Задать курс
	void set_course(unsigned short course);
	// Вернуть факультет
	const std::string get_faculty() const;
	// Вернуть курс
	const unsigned short get_course() const;

	// Переопределённый метод генератора имён для студентов
	std::string fullNameGen() override;
	// Вывести информацию о студенте
	void info() const override;
};