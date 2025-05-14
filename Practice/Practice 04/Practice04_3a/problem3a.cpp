#include <iostream>
#include <list>
#include <string>

void addTask(std::list<std::string>& tasks);
void removeTask(std::list<std::string>& tasks);
void showTasks(const std::list<std::string>& tasks);

int main() {
    std::list<std::string> tasks;
    int choice;

    do {
        std::cout << "\n1. Add Task\n2. Remove Task\n3. Show Tasks\n4. Exit\nChoice: ";
        std::cin >> choice;
        std::cin.ignore(); // To handle newline character

        switch (choice) {
        case 1:
            addTask(tasks);
            break;
        case 2:
            removeTask(tasks);
            break;
        case 3:
            showTasks(tasks);
            break;
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

void addTask(std::list<std::string>& tasks) {
    std::string task;
    std::cout << "Enter task: ";
    std::getline(std::cin, task);
    tasks.push_back(task);
    std::cout << "Task added!\n";
}

void removeTask(std::list<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to remove.\n";
        return;
    }

    showTasks(tasks);
    int taskNumber;
    std::cout << "Enter task number to remove: ";
    std::cin >> taskNumber;
    std::cin.ignore(); // Handle newline character

    if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        std::cout << "Invalid task number.\n";
        return;
    }

    auto it = tasks.begin();
    std::advance(it, taskNumber - 1);
    tasks.erase(it);
    std::cout << "Task removed!\n";
}

void showTasks(const std::list<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }

    std::cout << "Tasks:\n";
    int index = 1;
    for (const auto& task : tasks) {
        std::cout << index++ << ". " << task << "\n";
    }
}
