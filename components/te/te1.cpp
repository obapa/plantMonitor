#include <iostream>
#include "te1.h" // Need the declaration here too

// Definition: We use the scope resolution operator (::) 
// to define the function belonging to MyObject.
void Test1::doNothing() {
    std::cout << "hi";
    // This function body is empty. It does nothing.
}
