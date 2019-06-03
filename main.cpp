#include <iostream>
using namespace std;

int run();

int main() 
{
    cout << "Test!" << endl;
    int rc = run();
    cout << "exit " << rc << endl;
    return rc;
}