#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdexcept>
#include "QuickFind.h"
#include "QuickUnion.h"

int main(int argc, char const *argv[])
{
    int N;
    std::cout << "Array length: " << std::endl;
    std::cin >> N;

    try {
        QuickFindUF UF = QuickFindUF(N);
        //UF.PrintID();
        UF.Union(4,3);
        UF.Union(4,8);
        std::cout << "Is " << (UF.IsConnected(3,8)?"":"NOT ") << "Connected" << std::endl;

        QuickUnionUF UF2 = QuickUnionUF(N);
        //UF.PrintID();
        UF2.Union(4,3);
        UF2.Union(4,8);
        std::cout << "Is " << (UF2.IsConnected(3,8)?"":"NOT ") << "Connected" << std::endl;
    }
    catch (...)
    {
        std::cout << "Exception caught. Exiting." << std::endl;
        return 1;
    }
    
    return 0;
}