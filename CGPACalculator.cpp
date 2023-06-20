#include <iostream>
#include <vector>
#include <cctype> 

struct Subject
{
    double credit;
    std::string grade;
};


double convertGradeToValue(const std::string &grade)
{
    if (grade == "O")
        return 10.0;
    else if (grade == "A+")
        return 9.0;
    else if (grade == "A")
        return 8.0;
    else if (grade == "B+")
        return 7.0;
    else if (grade == "B")
        return 6.0;
    else if (grade == "C")
        return 5.0;
    else if (grade == "F")
        return 0.0;
    else
        return -1.0; 
}


double calculateCGPA(const std::vector<Subject> &subjects)
{
    double totalCredits = 0.0;
    double weightedSum = 0.0;

    for (const auto &subject : subjects)
    {
        totalCredits += subject.credit;
        double gradeValue = convertGradeToValue(subject.grade);
        weightedSum += subject.credit * gradeValue;
    }

    return weightedSum / totalCredits;
}

int main()
{
    std::vector<Subject> subjects;
    bool calculated = false;

    while (true)
    {
        int choice;

        
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Semester Grades" << std::endl;
        std::cout << "2. Calculate CGPA" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            int numSubjects;
            std::cout << "Enter the number of subjects: ";
            std::cin >> numSubjects;

            for (int i = 0; i < numSubjects; i++)
            {
                Subject subject;
                std::cout << "Enter the credit for subject " << i + 1 << ": ";
                std::cin >> subject.credit;
                std::cout << "Enter the grade for subject " << i + 1 << ": ";
                std::cin >> subject.grade;

                
                for (char &c : subject.grade)
                {
                    c = std::toupper(c);
                }

                subjects.push_back(subject);
            }

            calculated = false; 
            std::cout << "Semester grades added successfully!" << std::endl;
        }
        else if (choice == 2)
        {
            if (!calculated)
            {
                if (subjects.empty())
                {
                    std::cout << "No semester grades found. Please add grades first." << std::endl;
                }
                else
                {
                    double cgpa = calculateCGPA(subjects);
                    std::cout << "CGPA: " << cgpa << std::endl;
                    calculated = true;

                    std::cout << "Press 'B' or 'b' to go back to the main menu: ";
                    char backChoice;
                    std::cin >> backChoice;
                    if (backChoice == 'B' || backChoice == 'b')
                    {
                        calculated = false;
                        subjects.clear();
                    }
                }
            }
            else
            {
                std::cout << "CGPA already calculated. Press 'B' or 'b' to go back to the main menu: ";
                char backChoice;
                std::cin >> backChoice;
                if (backChoice == 'B' || backChoice == 'b')
                {
                    calculated = false;
                    subjects.clear();
                }
            }
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
