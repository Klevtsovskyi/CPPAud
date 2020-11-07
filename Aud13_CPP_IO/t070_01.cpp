#include <iostream>
#include <string>


std::string f1(std::string inp)
{
    std::string out, buffer;
    out = "";
    int i = 0, j = 0;
    while (j < inp.length())
    {
        j = inp.find(" ", j);
        if (j == -1)
            j = inp.length() - 1;
        buffer = inp.substr(i, j - i + 1);
        if (buffer != " ")
        {
            int k = 0;
            char c = buffer[0];
            while (k != -1)
            {
                buffer.erase(k, 1);
                k = buffer.find(c);
            }
        }
        out.append(buffer);
        i = ++j;
    }
    return out;
}


int main()
{
    std::string inp;
    std::getline(std::cin, inp);
    std::cout << f1(inp);
    return 0;
}
