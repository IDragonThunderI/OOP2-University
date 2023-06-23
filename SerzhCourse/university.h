#pragma once
#include <list>
#include "person.h"

// ������ �����������
const std::array<std::string, 5> facultiesList = { "�������������", "����������", "��������-��������������",
											 "������������ ����", "����������" };

class University {	// ����� "�����������"
private:
	std::string universityName = "";		// �������� ������������
	std::string rector = "";				// ��� �������
	std::list<Teacher*> teachersList = {};	// ������ ��������������
	std::list<Student*> studentsList = {};	// ������ ���������

public:
	// �����������
	University(std::string name, std::string rector);
	// ����������
	~University();

	// ������ �������� ������������
	void set_universityName(std::string name);
	// ������ ��� �������
	void set_rector(std::string fullName);
	// ������� �������� ������������
	const std::string get_universityName() const;
	// ������� ��� �������
	const std::string get_rector() const;
	// ������� ������ ��������������
	const std::list<Teacher*> get_teachersList() const;
	// ������� ������ ���������
	const std::list<Student*> get_studentsList() const;

	// �������� �������������
	void addTeacher(Teacher* teacher);
	// �������� ��������
	void addStudent(Student* student);
	// ������� ���������� �� ������������
	void info() const;
	// ��������� ��������� ��������������
	void randomTeacherGen(unsigned short count);
	// ��������� ��������� ���������
	void randomStudentGen(unsigned short count);
};