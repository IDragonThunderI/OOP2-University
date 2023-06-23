#include <iostream>
#include "UI.h"

void UserInterface::findStudentsByFaculty() const {
    std::cout << "\n*** Список факультетов ***" << std::endl;
    std::array<std::string, facultiesList.size() + 1> menu;

    for (size_t i = 0; i < facultiesList.size(); i++) {
        menu.at(i) = facultiesList.at(i);
    }
    menu.at(menu.size() - 1) = "Вернуться в меню";
    for (size_t i = 0; i < menu.size(); i++) {
        std::cout << i << ". " << menu.at(i) << std::endl;
    }

    std::cout << "Выберите факультет: ";
    unsigned short choice = menuInput(menu.size() - 1);

    if (choice == menu.size() - 1) {
        return;
    }

    std::cout << "\nСписок студентов: " << std::endl;
    for (auto& student : university->get_studentsList()) {
        if (student->get_faculty() == menu.at(choice)) {
            student->info();
        }
    }
    system("pause");
}

void UserInterface::findStudentsByCourse() const {
    std::cout << "\n*** Список курсов ***" << std::endl;
    std::array<std::string, 5> menu = { "Первый", "Второй", "Третий", "Четвёртый", "Вернуться в меню" };

    for (size_t i = 0; i < menu.size(); i++) {
        std::cout << i << ". " << menu.at(i) << std::endl;
    }

    std::cout << "Выберите курс: ";
    unsigned short choice = menuInput(menu.size() - 1);

    if (choice == menu.size() - 1) {
        return;
    }

    std::cout << "\nСписок студентов: " << std::endl;
    for (auto& student : university->get_studentsList()) {
        if (student->get_course() == choice + 1) {
            student->info();
        }
    }
    system("pause");
}

void UserInterface::findTeachersByFaculty() const {
    std::cout << "\n*** Список факультетов ***" << std::endl;
    std::array<std::string, facultiesList.size() + 1> menu;

    for (size_t i = 0; i < facultiesList.size(); i++) {
        menu.at(i) = facultiesList.at(i);
    }
    menu.at(menu.size() - 1) = "Вернуться в меню";
    for (size_t i = 0; i < menu.size(); i++) {
        std::cout << i << ". " << menu.at(i) << std::endl;
    }

    std::cout << "Выберите факультет: ";
    unsigned short choice = menuInput(menu.size() - 1);

    if (choice == menu.size() - 1) {
        return;
    }

    std::cout << "\nСписок преподавателей: " << std::endl;
    for (auto& teacher : university->get_teachersList()) {
        if (teacher->get_faculty() == menu.at(choice)) {
            teacher->info();
        }
    }
    system("pause");
}

UserInterface::UserInterface(University* university) {
    this->university = university;
}

void UserInterface::showUniversityInfo() const {
    std::cout << "\n*** Информация об университете ***" << std::endl;
    university->info();
    system("pause");
}

void UserInterface::showFacultyList() const {
    std::cout << "\n*** Список факультетов ***" << std::endl;
    for (auto& faculty : facultiesList) {
        std::cout << faculty << std::endl;
    }
    system("pause");
}

void UserInterface::showTeachersList() const {
    std::cout << "\n*** Список преподавателей ***" << std::endl;
    for (auto& teacher : university->get_teachersList()) {
        teacher->info();
    }
    system("pause");
}

void UserInterface::showStudentsList() const {
    std::cout << "\n*** Полный список студентов ***" << std::endl;
    for (auto& student : university->get_studentsList()) {
        student->info();
    }
    system("pause");
}

void UserInterface::findStudents() const {
    std::cout << "\n*** Найти студентов ***" << std::endl;
    std::array<std::string, 3> menu = { "По факультету", "По курсу", "Вернуться в меню"};

    for (size_t i = 0; i < menu.size(); i++) {
        std::cout << i << ". " << menu.at(i) << std::endl;
    }

    std::cout << "Выберите критерий поиска: ";
    unsigned short choice = menuInput(menu.size() - 1);

    if (choice == menu.size() - 1) {
        return;
    }

    switch (choice) {
    case 0:
        findStudentsByFaculty();
        break;
    case 1:
        findStudentsByCourse();
        break;
    }
}

void UserInterface::findTeachers() const {
    findTeachersByFaculty();
}

unsigned short menuInput(size_t numberOfItems) {
    short choice = 0;
    while (true) {
        try {
            if (!(std::cin >> choice) or choice > numberOfItems) {
                throw std::invalid_argument("Недопустимое значение параметра");
            }
            return choice;
        }
        catch (const std::invalid_argument& error) {
            std::cerr << "Ошибка: " << error.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
