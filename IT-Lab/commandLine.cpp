#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    // argc = argument count
    // argv = argument values (array of C-strings)

    cout << "Number of arguments: " << argc << endl;

    cout << "Arguments passed:" << endl;
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "] = " << argv[i] << endl;
    }

    return 0;
}
