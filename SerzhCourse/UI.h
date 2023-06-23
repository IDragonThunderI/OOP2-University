#pragma once
#include "university.h"

class UserInterface {	// ����� "���������������� ���������"
private:
	University* university = nullptr;	// �����������

	// ����� ��������� �� ����������
	void findStudentsByFaculty() const;
	// ����� ��������� �� �����
	void findStudentsByCourse() const;
	// ����� �������������� �� ����������
	void findTeachersByFaculty() const;
	
public:
	// �����������
	UserInterface(University* university);

	// ������� ���������� �� ������������
	void showUniversityInfo() const;
	// ������� ������ �����������
	void showFacultyList() const;
	// ������� ������ ��������������
	void showTeachersList() const;
	// ������� ������ ���������
	void showStudentsList() const;
	// ����� ��������� �� ���������
	void findStudents() const;
	// ����� �������������� �� ���������
	void findTeachers() const;
};

// ������� �������� ������������ ����������������� �����
unsigned short menuInput(size_t numberOfItems);
