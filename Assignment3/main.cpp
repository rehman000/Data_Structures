#include <iostream>
#include "sequence2.h"
#include <cstdlib>  // Provides size_t

int main()
{
    data_structures_assignment_3::sequence sequence1;
    std::cout << "Your code compiled while declaring a sequence object." << std::endl;
    std::cout << "Compile the exam script separately to check your class more fully." << std::endl;

    data_structures_assignment_3::sequence S1, S2, S3;

     S1.insert(10); // 5     -- using attach it will reverse this trend!!! :D
     S1.insert(23); // 4
     S1.insert(45); // 3
     S1.insert(5); // 2
     S1.insert(87); // 1
     S1.insert(9999); // 0


     std::cout << S1[0] << std::endl;


    return 0;
}