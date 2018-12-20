#include <iostream>
#include "sequence3.h"

int main()
{
    data_structures_assignment3::sequence s1;

    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    s1.insert(6);
    s1.insert(7);

    std::cout << s1.current() << std::endl;
    s1.advance();
    std::cout << s1.current() << std::endl;
    s1.advance();
    std::cout << s1.current() << std::endl;
    s1.advance();
    std::cout << s1.current() << std::endl;
    s1.advance();
    std::cout << s1.current() << std::endl;
    s1.advance();
    std::cout << s1.current() << std::endl;


    return 0;
}
