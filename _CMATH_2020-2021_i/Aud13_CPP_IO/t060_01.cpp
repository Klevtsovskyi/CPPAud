#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <string>


int main()
{
    double a;
    std::ifstream finp;
    finp.open("input.txt");

    //std::stringstream strs;
    //strs.setf(std::ios::fixed);
    //strs.precision(4);

    std::string out = "";
    std::string s;

    while (!finp.eof())
    {
        finp >> a;
        if (finp.fail())
            break;
        //s = std::to_string(sqrt(a)) + "\n";
        char buffer[100];
        sprintf(buffer, "%.4lf\n", sqrt(a));
        s = buffer;
        out.insert(0, s);
        //strs << sqrt(a) << std::endl;
    }

    std::cout << out;
    //std::cout << strs.str();

    return 0;
}
