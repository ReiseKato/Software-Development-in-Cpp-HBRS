#include <iostream>
#include <optional>

int strcmp(char const* s1, char const* s2)
{
    while (*s1 && (*s1 == *s2))
    {
        ++s1;
        ++s2;
    }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

char const* strrchr(char const* s, int c)
{
    char const* last = nullptr;
    while(*s)
    {
        if (*s == (char)c)
        {
            last = s;
        }
        ++s;
    }
    return last;
}

char const* strstr(char const* s, char const* t)
{
    if (!*t) return s; // If t is empty, return s
    for (; *s; ++s)
    {
        const char* p1 = s;
        const char* p2 = t;
        while (*p1 && *p2 && (*p1 ==  *p2))
        {
            ++p1;
            ++p2;
        }
        if (!*p2)
        {
            return s; // Found the substring t in s
        }
    }
    return nullptr; // Not found
}

// c++ Versions below

int cc_strcmp(const std::string& s1, const std::string& s2)
{
    return s1.compare(s2);
}

std::optional<std::size_t> cc_strchr(const std::string& s, char c)
{
    size_t pos = s.rfind(c);
    return pos == std::string::npos ? std::nullopt : std::optional<size_t>{pos};
}

std::optional<std::size_t> cc_strstr(const std::string& s, const std::string& t)
{
    size_t pos = s.find(t);
    return pos == std::string::npos ? std::nullopt : std::optional<size_t>{pos};
}


int main()
{
    char const* s = "hello";
    for (; *s; ++s) {
        std::cout << *s << std::endl; // Prints each character of the string
    }

    // Example usage of the functions
    std::cout << "strcmp: " << strcmp("abc", "abd") << std::endl;
    std::cout << "strrchr: " << (strrchr("hello world", 'o') ? strrchr("hello world", 'o') : "not found") << std::endl;
    std::cout << "strstr: " << (strstr("hello world", "world") ? strstr("hello world", "world") : "not found") << std::endl;

    return 0;
}