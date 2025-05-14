#include <iostream>
#include <vector>
#include <memory>
#include <numeric>

class Observer {
public:
    virtual void update(float newGrade) = 0;
    virtual ~Observer() = default;
};

class GradeBook {
    float currentGrade = 0.0f;
    std::vector<std::shared_ptr<Observer>> observers;

public:
    void attach(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    void setGrade(float grade) {
        currentGrade = grade;
        std::cout << "Grade set to: " << grade << "\n";
        for (auto& obs : observers) {
            obs->update(currentGrade);
        }
    }
};

class Averager : public Observer {
    std::vector<float> allGrades;
public:
    void update(float newGrade) override {
        allGrades.push_back(newGrade);
        float sum = std::accumulate(allGrades.begin(), allGrades.end(), 0.0f);
        std::cout << "Average grade: " << sum / allGrades.size() << "\n";
    }
};

class Notifier : public Observer {
public:
    void update(float newGrade) override {
        if (newGrade < 60.0f) {
            std::cout << "Email sent to parent need to get a tutor.\n";
        }
    }
};

int main() {
    GradeBook book;
    auto averager = std::make_shared<Averager>();
    auto notifier = std::make_shared<Notifier>();

    book.attach(averager);
    book.attach(notifier);

    while (true) {
        float grade;
        std::cout << "\nEnter grade (-1 to quit): ";
        std::cin >> grade;
        if (grade < 0) break;
        book.setGrade(grade);
    }

    return 0;
}
