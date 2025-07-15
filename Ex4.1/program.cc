#include <iostream>

bool myand(bool a, bool b);
bool myshortcircuitand(bool a, bool b);

bool myand(bool a, bool b)
{
    int result = a + b;
    std::cout << result << std::endl;
    if (result > 1)
    {
        return true;
    }
    return false;
}

bool myshortcircuitand(bool a, bool b)
{
    if (a)
    {
        if (b)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    bool a  = true;
    bool b = true;
    bool result = myand(a, b);
    bool result2 = myshortcircuitand(a, b);

    std::cout << result << std::endl;
    std::cout << result2 << std::endl;
}