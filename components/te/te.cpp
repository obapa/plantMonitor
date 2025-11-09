#include <iostream>
#include "te.h" // Need the declaration here too

// Definition: We use the scope resolution operator (::) 
// to define the function belonging to MyObject.
void Test::doNothing() {
    std::cout << "hi";
    // This function body is empty. It does nothing.
}
