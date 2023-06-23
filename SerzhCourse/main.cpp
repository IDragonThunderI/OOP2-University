#include <iostream>
#include <ctime>
#include "UI.h"

int main() {
	setlocale(LC_ALL, "ru_RU");
	srand((unsigned)time(NULL));

	University* university = new University("Тольяттинский Государственный Университет", "Криштал Михаил Михайлович");
	UserInterface* ui = new UserInterface(university);
	university->randomTeacherGen(10);
	university->randomStudentGen(30);
	
	std::array<std::string, 7> menu = {
		"Информация об университете",
		"Список факультетов",
		"Список преподавателей",
		"Полный список студентов",
		"Найти студентов",
		"Найти преподавателей",
		"Выход"
	};

	unsigned short choice = 0;
	bool exit = false;
	while (!exit) {
		std::cout << "\n*** ГЛАВНОЕ МЕНЮ ***" << std::endl;
		for (size_t i = 0; i < menu.size(); i++) {
			std::cout << i << ". " << menu.at(i) << std::endl;
		}
		choice = menuInput(menu.size() - 1);
		switch (choice) {
		case 0:
			ui->showUniversityInfo();
			break;
		case 1:
			ui->showFacultyList();
			break;
		case 2:
			ui->showTeachersList();
			break;
		case 3:
			ui->showStudentsList();
			break;
		case 4:
			ui->findStudents();
			break;
		case 5:
			ui->findTeachers();
			break;
		case 6:
			exit = true;
			break;
		}
	}

	delete university;
	delete ui;

	return 0;
}