#include <iostream>
#include <sstream>
#include <string>


int f2(std::string inp)
{
    std::stringstream inps;
    inps << inp;
    std::string s;
    int count = 0;
    while (true)
    {
        inps >> s;
        if (inps.fail())
            break;
        if (s[0] == s[s.length() - 1])
            count++;
    }
    return count;
}


int main()
{
    std::string inp;
    std::getline(std::cin, inp);
    std::cout << f2(inp);
    return 0;
}
