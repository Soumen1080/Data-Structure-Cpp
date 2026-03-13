#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "Number of arguments (including program name): " << argc << endl;

    cout << "Arguments passed:" << endl;

    // Loop through all command line arguments
    for (int i = 0; i < argc; i++) {
        cout << "Argument " << i << ": " << argv[i] << endl;
    }
    cout << "hello" << endl;

    return 0;
}
