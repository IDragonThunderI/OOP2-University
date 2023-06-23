#pragma once
#include <string>
#include <array>

// ������ ������� ��� ��� ����������
const std::array<std::string, 15> maleNameList = { "������", "������", "����", "������", "�����",
											 "�������", "����", "���������", "�������", "������",
											 "�����", "�����", "�����", "����������", "������" };
// ������ ������� ��� ��� ����������
const std::array<std::string, 15> femaleNameList = { "����", "���������", "���������", "�������", "������",
											   "�����", "����", "���������", "�������", "��������",
											   "�����", "������", "������", "��������", "���������" };
// ������ ������� ��� ���������� (��� ������� �������� '�')
const std::array<std::string, 15> surnameList = { "��������", "��������", "��������", "��������", "���������",
											"��������", "������", "��������", "������", "��������",
											"������", "�����", "�������", "�������", "�����" };
// ������ ������� ��� ���������� (��� ������� �������� '��', ��� ������� - '��')
const std::array<std::string, 15> patronymicList = { "�������", "�������", "�������", "������", "������",
											   "�������", "������", "����������", "����������", "��������",
											   "������", "��������", "��������", "�������", "��������" };

class Person {	// ����������� ����� "�������"
protected:
	std::string fullName = "";	// ���
	std::string gender = "";	// ���
	unsigned short age = 0;		// �������

public:
	// ������ ���
	virtual void set_fullName(std::string fullName);
	// ������ ���
	virtual void set_gender(std::string gender);
	// ������ ��������
	virtual void set_age(unsigned short age);
	// ������� ���
	virtual const std::string get_fullName() const;
	// ������� ���
	virtual const std::string get_gender() const;
	// ������� �������
	virtual const unsigned short get_age() const;

	// ��������� ��������� ���
	virtual	std::string fullNameGen() = 0;
	// ������� ���������� � ��������
	virtual void info() const;
};

class Teacher : public Person {	// ����� "�������������"
private:
	std::string faculty;	// ���������

public:
	// �����������
	Teacher(std::string fullName, std::string gender, unsigned short age, std::string faculty);

	// ������ ���������
	void set_faculty(std::string faculty);
	// ������� ���������
	const std::string get_faculty() const;

	// ��������������� ����� ���������� ��� ��� ��������������
	std::string fullNameGen() override;
	// ������� ���������� � �������������
	void info() const override;
};

class Student : public Person {	// ����� "�������"
private:
	std::string faculty;	// ���������
	unsigned short course;	// ����

public:
	// �����������
	Student(std::string fullName, std::string gender, unsigned short age, std::string faculty, unsigned short course);

	// ������ ���������
	void set_faculty(std::string faculty);
	// ������ ����
	void set_course(unsigned short course);
	// ������� ���������
	const std::string get_faculty() const;
	// ������� ����
	const unsigned short get_course() const;

	// ��������������� ����� ���������� ��� ��� ���������
	std::string fullNameGen() override;
	// ������� ���������� � ��������
	void info() const override;
};