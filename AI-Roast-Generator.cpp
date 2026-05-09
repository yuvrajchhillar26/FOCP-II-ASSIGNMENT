#include <iostream>
#include <vector>
#include <string>
#include <random>

/*
   Function: replaceNamePlaceholder

   Purpose:
   Replaces every {name} inside the roast template
   with the actual user name entered by the user.

   Improvements:
   1. userName is passed by const reference to avoid copying.
   2. roastTemplate is passed by value intentionally because
      we modify and return the updated string.

   Example:
   Input:
   "{name} writes messy code."

   userName = Rahul

   Output:
   "Rahul writes messy code."
*/
std::string replaceNamePlaceholder(std::string roastTemplate, const std::string &userName)
{
    const std::string placeholder = "{name}";
    std::size_t position = 0;

    /*
        Keep finding {name} until no placeholder remains.

        find() returns position of match.
        replace(startIndex, lengthToRemove, newText)
    */
    while ((position = roastTemplate.find(placeholder, position)) != std::string::npos)
    {
        roastTemplate.replace(position, placeholder.length(), userName);
        position += userName.length();
    }

    return roastTemplate;
}

int main()
{
    std::string userName;

    std::vector<std::string> roastTemplates =
        {
            "{name} writes code so slow that even a turtle switched to Python.",
            "If procrastination were an Olympic sport, {name} would already have a gold medal.",
            "{name}'s debugging style is staring at the screen until the bug feels guilty and leaves.",
            "{name}'s code runs so slowly that even dial-up internet feels fast.",
            "If laziness had a brand ambassador, it would be {name}.",
            "{name} doesn't debug code, they negotiate with bugs.",
            "{name}'s keyboard files complaints after every coding session.",
            "{name} writes comments like mystery novels: nobody knows what happens next.",
            "Even autocorrect gave up trying to help {name}.",
            "{name}'s code has more twists than a suspense movie.",
            "{name} can turn a one-line fix into a three-day project.",
            "When {name} says 'almost done', start planning for next week."};

    std::cout << "Enter your name: ";
    std::getline(std::cin, userName);

    /*
        Modern random number generation in C++:

        random_device -> gets seed
        mt19937       -> fast Mersenne Twister engine
        uniform_int_distribution -> fair random range
    */
    std::random_device seedGenerator;
    std::mt19937 randomEngine(seedGenerator());

    std::uniform_int_distribution<int> distribution(
        0,
        static_cast<int>(roastTemplates.size()) - 1);

    int randomIndex = distribution(randomEngine);

    std::string selectedRoast = roastTemplates[randomIndex];
    std::string finalRoast = replaceNamePlaceholder(selectedRoast, userName);

    std::cout << "\nFunny Roast:\n";
    std::cout << finalRoast << std::endl;

    return 0;
}

/*
PROMPTS USED
_____________________________________________________________________________________________________________
PROMPT MAIN ONE
---
Role : Senior Sofware Developer
Language : C++
Task : to build a console based program that generates funny roasts based on a user's name. The
program should produce different roasts each time it runs by randomly selecting from multiple roast
templates
Example of roast templates/outputs : If the Input is Rahul, then the possible output can be:
• “Rahul writes code so slow that even a turtle switched to Python.”
• “If procrastination were an Olympic sport, Rahul would already have a gold medal.”
• “Rahul’s debugging style is basically staring at the screen until the bug gets embarrassed and
leaves.”
Programme Flow and Structure :
• Takes user input (name)
• Stores multiple roast templates
• Uses random selection to generate different roasts
• Replaces placeholders like {name} with the actual input
• Displays a unique roast message
Least no of templates to have : 10
Example template format / example of string format for funny roasts :
"{name}'s code runs so slowly that even dial-up internet feels fast."
"If laziness had a brand ambassador, it would be {name}."
"{name} doesn't debug code — they negotiate with bugs."
( replace the variables in the brackets with the in programme variables )
How to write programme : write clean code with simple easy to understand english comments
add multiline comments explaining the difficult part of the code
use apt variables names
__________________________________________________________________________________________________
THE REFINITING / FIXING ERRORS PROMPT
---
Code fixes
1. Instead of cstdlib use random library which is updated library for c++
2. In replaceNamePlaceholder functon pass the userName by refrence to avoid copying it
3. Improve the code professionality by not using namespace std
---

hehe I have added prompts as comments in case the pdf prompts are not properly visible ...
*/