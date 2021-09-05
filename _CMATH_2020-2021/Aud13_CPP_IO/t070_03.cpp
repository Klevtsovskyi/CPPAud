#include <iostream>
#include <string>


const std::string VOWELS = "aouie";


std::string f3(std::string inp)
{
    char c = inp[inp.length() - 1];
    for (int i = 0; i < VOWELS.length(); i++)
    {
        if (c == VOWELS[i])
        {
            if (i == 0)
                c = VOWELS[VOWELS.length() - 1];
            else
                c = VOWELS[i - 1];
            inp[inp.length() - 1] = c;
            break;
        }
    }
    return inp;
}


int main()
{
    std::string inp;
    std::cin >> inp;
    std::cout << f3(inp) << std::endl;
    std::cout << inp << std::endl;
    return 0;
}
