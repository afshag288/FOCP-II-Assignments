#include <iostream>
#include <vector>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

using namespace std;

int main() {

    // Variable for student name
    string studentName;

    // Ask user name
    cout << "Enter student name: ";
    getline(cin, studentName);

    /*
        List of funny excuses
        {name} will be replaced later
    */
    vector<string> excuses = {
        "{name} could not finish homework because laptop battery died.",
        "{name} was ready to submit work but file disappeared.",
        "{name} tried to do homework but internet stopped working.",
        "{name} opened assignment but keyboard stopped helping.",
        "{name} wanted to study but system started updating forever.",
        "{name} accidentally submitted brain instead of homework.",
        "{name} was doing homework but the dog sat on the notebook.",
        "{name} studied all night but forgot where homework was saved.",
        "{name} could not complete assignment because WiFi went on vacation.",
        "{name} almost finished homework but computer restarted suddenly."
    };

    // Random number setup
    srand(time(0));

    // Pick random excuse
    int randomIndex = rand() % excuses.size();

    // Store selected excuse
    string finalExcuse = excuses[randomIndex];

    /*
        Replace {name} with actual student name
    */
    size_t position = finalExcuse.find("{name}");

    if (position != string::npos) {
        finalExcuse.replace(position, 6, studentName);
    }

    // Show final excuse
    cout << "\nFunny Excuse:\n";
    cout << finalExcuse << endl;

    return 0;
}