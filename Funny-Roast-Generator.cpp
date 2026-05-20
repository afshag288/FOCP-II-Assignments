
#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

int main() {

    // Variable to store user name
    string userName;

    // Ask user to enter name
    cout << "Enter your name: ";
    getline(cin, userName);

    /*
       Array of funny roast templates.
       {name} will be replaced later.
    */
    string roasts[] = {
        "{name} types so slow that keyboard gets sleepy.",
        "{name} code is so confusing even calculator gave up.",
        "If laziness had fan club, {name} is president.",
        "{name} debugs by looking at screen and hoping.",
        "{name} runs code like turtle in traffic.",
        "{name} writes comments more than actual code.",
        "{name} clicks Run and prays for miracle.",
        "Even WiFi disconnects after seeing {name}'s code.",
        "{name} makes bugs feel professionally trained.",
        "{name} opens IDE just to take a break.",
        "{name}'s coding speed depends on snack availability.",
        "Compiler sees {name}'s code and requests vacation."
    };

    // Total number of roast templates
    int totalRoasts = sizeof(roasts) / sizeof(roasts[0]);

    // Generate random number
    srand(time(0));
    int randomIndex = rand() % totalRoasts;

    // Pick one random roast
    string selectedRoast = roasts[randomIndex];

    /*
       Replace {name} with entered user name
    */
    size_t position = selectedRoast.find("{name}");

    while (position != string::npos) {
        selectedRoast.replace(position, 6, userName);
        position = selectedRoast.find("{name}");
    }

    // Display final roast
    cout << "\nFunny Roast:\n";
    cout << selectedRoast << endl;

    return 0;
}
