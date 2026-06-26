#include "RPN.hpp"
#include <stdexcept>

int main(int ac, char *av[])
{
    if (ac != 2)
        std::cerr << "Error" << std::endl;
    else
    {
        try{
            RPN rpn;
            rpn.process_input(av[1]);
        }
        catch (std::exception &e){
            std::cerr << e.what() << std::endl;
        }
    }
}