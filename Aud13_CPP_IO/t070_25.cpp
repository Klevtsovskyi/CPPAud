#include <iostream>
#include <string>
#define N 9


const std::string SNUMS[N] =
{
    "one", "two", "three", "four", "five", "six", "seven",
    "eight", "nine"
};


std::string f25(std::string inp)
{
    int j;
    for (int i = 0; i < N; i++)
    {
        while(true)
        {
            j = inp.find(SNUMS[i]);
            if (j == -1)
                break;
            inp.replace(j, SNUMS[i].length(),
                        std::to_string(i + 1));
        }
    }
    return inp;
}


int main()
{
    std::string inp;
    std::getline(std::cin, inp, ';');
    std::cout << f25(inp);
    return 0;
}
