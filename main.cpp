#include <iostream>
using namespace std;

#include i8080.hpp

int main() 
{
    cout << "Test!" << endl;
    int rc = run();
    cout << "exit " << rc << endl;
    return rc;
}