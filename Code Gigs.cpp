/*

OBJECT ORIENTED  PROGRAMMING 1 (C++)
Scenario:
You are tasked with designing and developing a unique and innovative system (of your choice) using C++ that addresses a real-world problem or need.
Your system should demonstrate a clear understanding of object-oriented programming (OOP) principles and apply them effectively in the design and implementation.

Objective:
The goal of this project is to assess your understanding of object-oriented programming (OOP) principles and apply them effectively in designing and developing a unique and innovative system using C++.
The system should address a real-world problem or need and demonstrate a clear grasp of OOP concepts following the key areas below;
    ==> Your system should encompass the basics of C++, including the structure of a C++ program, data types, operators, and input/output statements.
 	==> Incorporate control structures in your system, implementing sequential, selection (using IF statements, Switch/Case statements, and the Question Mark/Colon operator), and iteration (using looping constructs such as for, while, do-while, and integrating break and continue statements).
 	==> Ensure that your system involves the manipulation of arrays, strings, and pointers. Include single and two-dimensional arrays, introduce pointers with definitions, declarations, initialization, and showcase pointer arithmetic through practical examples.
 	==> Delve into the concept of classes, designing them with appropriate data members and member functions. Explore inheritance by incorporating access modifiers and defining relationships between parent and derived classes. Implement different types of inheritance within your system to demonstrate a comprehensive understanding.
 	==> Highlight polymorphism in your system, emphasizing operator overloading and function overloading as key elements. Implement constructors and destructors, showcasing various types of constructors and illustrating their implementation in practical scenarios.
 	==> Integrate exception handling into your system, emphasizing the importance of this concept, utilizing keywords, and effectively implementing exception handling in C++. Your unique C++ system should stand out from your peers' projects, showcasing creativity and a solid grasp of the specified concepts.

Evaluation Criteria:
Your project will be evaluated based on the following criteria:
    1)	Uniqueness and Innovation: The originality and creativity of your system in addressing the identified problem or need.
    2)	Problem-Solving Effectiveness: The effectiveness of your system in addressing the real-world problem or need.
    3)	OOP Design and Implementation: The soundness, efficiency, and adherence to OOP principles in your system's design and implementation.
    4)	Coding Quality and Practices: The quality of your code, adherence to coding standards, and use of appropriate data structures and algorithms.
    5)	Testing Comprehensiveness: The thoroughness and effectiveness of your testing procedures.
    6)	Documentation Clarity: The comprehensiveness, clarity, and organization of your system documentation.
    7)	Presentation Effectiveness: The clarity, professionalism, and persuasiveness of your project presentation.

Additional Requirements:
    ==> Uniqueness and Innovation: The system should be unique, innovative, and significantly different from previous projects or colleagues' work.
    ==> Real-World Problem Solving: The system should address a real-world problem or need, demonstrating its practical application and potential impact.
    ==> Effective OOP Design: The system should apply OOP principles effectively in the design, demonstrating a clear understanding of encapsulation, inheritance, polymorphism, and abstraction.


Remember, the goal of this capstone project is to showcase your understanding of OOP principles, your ability to solve real-world problems using C++, and your creativity and innovation in developing unique and effective software solutions.
*/


/*
System: Code Gigs
Description: System where programmers can get temporary coding jobs on the side as gigs with the skills they have on different programming languages

Programming Languages Based on Use Case:
1) System Programming Languages. Used for operating systems, drivers, and embedded systems.
        => C, C++, Rust, Assembly
2) Web Development Languages. Used for front-end and back-end development.
        => HTML, CSS, JavaScript (Front-end)
        => PHP, Node.js, Python, Ruby (Back-end)
3) Database Query Languages. Used for database management and querying.
        => SQL, MongoDB Query Language
4) Game Development Languages. High-performance languages used for game engines.
        => C++, C#, Python (for scripting in Unity, Unreal Engine)
5) Data Science & AI Languages. Used for machine learning, AI, and data analysis.
        => Python, R, MATLAB, Julia


        class ProgrammingLanguageAccountant {
            virtual void compensation_calculation(int years_experience, int base_hourly_rate) = 0;
        }

        if(years_experience > 2){
            // int final_hourly_rate = base_hourly_rate * (years_experience * 0.5);
        }else{
            final_hourly_rate = base_hourly_rate;
        }

        // auto& project_total = final_hourly_rate * int project_duration;
        // auto& project_deposit = project_total * 0.75;

        class SystemsDeveloper inherit ProgrammingLanguageAccountant {}

        class BackEndDeveloper inherit ProgrammingLanguageAccountant{}

        class FrontEndDeveloper inherit ProgrammingLanguageAccountant{}

        class FullStackWebDeveloper inherit BackEndDeveloper, inherit FrontEndDeveloper {}

        class GameDeveloper inherit ProgrammingLanguageAccountant{}

        class DataScienceAIDeveloper inherit ProgrammingLanguageAccountant{}


        // Create a list of gigs
        // Gig should have 
        class Gigs {};

        // Create a list of developers or have the user input their skill details (years of experience dictates hourly rate range and how long the project will take)
        // Show which projects are available to the developer in the system
        // Let the developer choose the system they want to work on
        // How the developer how long they have to work on the system, deposit they'll be paid, and total they'll be paid
        class Developers {};



*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ProgrammingLanguageAccountant {
public:
    virtual double compensationCalculator(double project_budget) = 0;
    virtual ~ProgrammingLanguageAccountant() = default; // Ensure proper polymorphic deletion
};

class Developer : public ProgrammingLanguageAccountant {
private:
    string dev_name;
    double hourly_rate, rate_multiplier, estimated_expenses;
    int years_experience;

public:
    // Constructor to initialize developer details
    Developer(const string& name, double time_rate, double rate_multi, int experience)
        : dev_name(name), hourly_rate(time_rate), rate_multiplier(rate_multi), years_experience(experience) {}

    // Estimate expenses based on budget and rate multiplier
    double calculateEstimatedExpenses(double project_budget) {
        return project_budget / (rate_multiplier + 1.5);
    }

    // Compensation calculation
    double compensationCalculator(double project_budget) override {
        return project_budget - estimated_expenses;
    }

    // Calculate estimated project duration
    double calculateProjectDuration(double project_budget) {
        return ((project_budget - estimated_expenses) / hourly_rate) - (years_experience * 8); 
    }

    // Calculate deposit (40% of total compensation)
    double calculateDeposit(double project_budget) {
        return (project_budget - estimated_expenses) * 0.40;
    }

    // Display project details
    void displayProjectDetails(double project_budget, const string& project_type) {
        estimated_expenses = calculateEstimatedExpenses(project_budget);
        double total_compensation = compensationCalculator(project_budget);
        double duration = calculateProjectDuration(project_budget);
        double deposit = calculateDeposit(project_budget);

        cout << "\n--- Project Details for " << dev_name << " ---\n";
        cout << "Project Type: " << project_type << "\n";
        cout << "Years of Experience: " << years_experience << "\n";
        cout << "Hourly Rate: KES " << hourly_rate << "/hr\n";
        cout << "Estimated Expenses: KES " << estimated_expenses << "\n";
        cout << "Estimated Duration: " << duration << " hours\n";
        cout << "Total Compensation: KES " << total_compensation << "\n";
        cout << "Deposit (To Start): KES " << deposit << "\n";
    }
};

int main() {
    int project_type_int;
    string developer_name;
    double hourly_rate, project_budget, rate_multiplier;
    int years_experience;

    const vector<string> project_types = {
        "Operating system, Drivers, or an Embedded system",
        "Front-end Development",
        "Database management and querying",
        "Game Development",
        "Machine learning, AI, or Data analysis",
        "Unspecified"
    };

    // Display project type options
    cout << "Which type of project are you working on? Enter the number:\n";
    for (size_t i = 0; i < project_types.size(); i++) {
        cout << i + 1 << " => " << project_types[i] << "\n";
    }

    cin >> project_type_int;
    cin.ignore(); // Clear newline character from input buffer

    // Validate project type selection
    if (project_type_int < 1 || project_type_int > 5) {
        project_type_int = 6; // Default to "Unspecified"
    }

    // Get developer details
    cout << "Enter the Developer's Name: ";
    getline(cin, developer_name);

    cout << "Enter Years of Experience: ";
    cin >> years_experience;

    cout << "Enter Hourly Rate (KES/hr): ";
    cin >> hourly_rate;

    cout << "Enter Project Budget (KES): ";
    cin >> project_budget;

    // Assign rate multiplier based on project type
    switch (project_type_int) {
        case 1: rate_multiplier = 1.5; break; // High complexity
        case 2: rate_multiplier = 0.8; break; // Low complexity
        case 3: rate_multiplier = 1.2; break; // Medium complexity
        case 4: rate_multiplier = 1.7; break; // High complexity
        case 5: rate_multiplier = 2.0; break; // Very high complexity
        default: rate_multiplier = 1.0; // Unspecified
    }

    // Create Developer object and display project details
    Developer dev(developer_name, hourly_rate, rate_multiplier, years_experience);
    dev.displayProjectDetails(project_budget, project_types[project_type_int - 1]);

    return 0;
}




/*
// Modifications for later
// class BackEndDeveloper: public ProgrammingLanguageAccountant{};
// class FrontEndDeveloper: public ProgrammingLanguageAccountant{};
// class FullStackWebDeveloper: public BackEndDeveloper, public FrontEndDeveloper {};
// class GameDeveloper: public ProgrammingLanguageAccountant{};
// class DataScienceAIDeveloper: public ProgrammingLanguageAccountant{};
*/