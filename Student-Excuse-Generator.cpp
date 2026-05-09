#include <iostream>
#include <vector>
#include <string>
#include <random> // Modern random number generation
#include <ctime>

/*
   Function: replaceNamePlaceholder

   Purpose:
   Replaces all "{name}" placeholders inside the selected
   excuse template with the actual student name.

   Why pass by reference?
   Passing studentName as const reference avoids making
   an unnecessary copy of the string, which is more efficient.
*/
std::string replaceNamePlaceholder(std::string templateText, const std::string &studentName)
{
    std::string placeholder = "{name}";
    size_t position = templateText.find(placeholder);

    while (position != std::string::npos)
    {
        templateText.replace(position, placeholder.length(), studentName);
        position = templateText.find(placeholder);
    }

    return templateText;
}

int main()
{
    std::string studentName;

    // Command line GUI style intro
    std::cout << "============================================================\n";
    std::cout << "||                                                        ||\n";
    std::cout << "||           STUDENT EXCUSE GENERATOR PROGRAMME           ||\n";
    std::cout << "||                                                        ||\n";
    std::cout << "============================================================\n";
    std::cout << "|| Generates creative excuses for homework delays.        ||\n";
    std::cout << "|| A fresh excuse appears every time you run it.          ||\n";
    std::cout << "============================================================\n\n";

    std::cout << "Enter Student Name : ";
    std::getline(std::cin, studentName);

    // Excuse templates
    std::vector<std::string> excuseTemplates =
        {
            "{name} couldn't finish the assignment because the laptop installed updates for six hours.",
            "{name} was about to complete the homework when the Wi-Fi mysteriously disappeared.",
            "{name} tried finishing the assignment, but the keyboard suddenly stopped cooperating.",
            "{name} couldn't submit the homework because the file vanished into another folder.",
            "{name} was ready to study, but the power went out dramatically.",
            "{name} tried to complete the assignment, but the mouse stopped clicking.",
            "{name} couldn't finish the homework because the printer jammed in protest.",
            "{name} was nearly done when the system restarted without permission.",
            "{name} tried to submit the assignment, but the website froze like a statue.",
            "{name} couldn't complete the homework because the charger went missing.",
            "{name} was doing the assignment when the screen suddenly went black.",
            "{name} tried finishing the homework, but the internet speed became slower than a turtle."};

    /*
        Modern Random Generator (Recommended over rand())

        random_device -> gets random seed
        mt19937       -> high quality random engine
        uniform_int_distribution -> selects number in range
    */
    std::random_device seedGenerator;
    std::mt19937 randomEngine(seedGenerator());

    std::uniform_int_distribution<int> distribution(
        0,
        static_cast<int>(excuseTemplates.size()) - 1);

    int randomIndex = distribution(randomEngine);

    std::string selectedExcuse = excuseTemplates[randomIndex];

    std::string finalExcuse =
        replaceNamePlaceholder(selectedExcuse, studentName);

    std::cout << "\n============================================================\n";
    std::cout << "||                    GENERATED EXCUSE                    ||\n";
    std::cout << "============================================================\n";
    std::cout << finalExcuse << "\n";
    std::cout << "============================================================\n";

    return 0;
}
/*
PROMPTS USED
______________________________________________________________________________________________________________
_____________________________________________________________________________________________________________
PROMPT MAIN ONE
---------------
Role : Senior Sofware Developer
Language : C++
Task : build a console-based program that generates creative excuses for missing homework or assignments. The program should generate different excuses each time it runs.
Example: If the
Input is Priya, then the possible output.
• “Priya couldn’t finish the assignment because the laptop decided to install updates for six hours.”
• “Priya was about to complete the homework when the Wi-Fi mysteriously disappeared.”
• “Priya tried finishing the assignment, but the computer keyboard suddenly stopped cooperating.”
Programme Flow and Structure :
• Takes user input (student name)
• Stores multiple excuse templates
• Uses random selection to generate excuses
• Replaces placeholders like {name} with the actual input
• Displays a random excuse
Least no of templates to have : 10
Example template format / example of string format :
"{name} couldn't complete the assignment because the laptop battery died unexpectedly."
"{name} tried finishing the homework, but the internet stopped working."
"{name} was ready to submit the assignment when the file mysteriously disappeared."
( replace the variables in the brackets with the in programme variables )
How to write programme : write clean code with simple easy to understand english comments
add multiline comments explaining the difficult part of the code
use apt variables names

__________________________________________________________________________________________________
THE REFINITING / FIXING ERRORS PROMPT
-------------------------------------
Code fixes
1. Add intro and heading with formating with help of cout functionalities to introduce the user to the Student Excuse generator programme use || lines and __ lines for box formating and create a sort of command line gui
2. Instead of cstdlib use random library which is updated library for c++
3. In replaceNamePlaceholder functon pass the atudentName by refrence to avoid copying it
4. Improve the code professionality by not using namespace std
---

In case the pdf prompts are not properly visible I have added prompts as comments ...
*/