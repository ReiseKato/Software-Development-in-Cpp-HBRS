Implement the following C-style(!) functions (of the C standard libray), using pointer arithmetic:

- int strcmp(char const* s1, char const* s2);
    
    returns a negative value if s1 is lexicographically “less” than s2, 0 if they are equal, and a positive value if s1 is “greater” than s2
- char const* strrchr(char const* s, int c);
    
    returns a pointer to the last occurrence of character c in string s, or a NULL pointer if s does not contain c
- char const* strstr(char const* s, char const* t);
    returns a pointer to the first occurrence of string t in string s, or a NULL pointer if s does not contain t

Note: Strings have a special character at their end, the null character '\0'. To traverse a string from the beginning to the end, it is not necessary to know its length, but just to check the „current“ character whether it is the null character.

How should these concepts, function declarations, and specifications be formed in a C++-style implementation?

# Solution

## `int strcmp(char const* s1, char const* s2)`

- It compares characters until it finds a difference or the null terminator.

- We cast to `unsigned char` to avoid issues with signed character values.

## Tips

The statement `for (; *s; ++s)` is a compact for loop commonly used in C and C++ to iterate through a null-terminated string (char const* s). Here's how it works:

Breakdown:

1. Initialization (;):
The first part of the for loop is empty, meaning no initialization is done in the loop itself. It assumes that the pointer s is already initialized before the loop starts.

2. Condition (*s):
The loop continues as long as the value pointed to by s (*s) is not 0 (or '\0', the null terminator in a C-style string).

    - *s dereferences the pointer s to get the current character in the string.
    - When the null terminator ('\0') is encountered, the condition evaluates to false, and the loop ends.

3. Increment (++s):
After each iteration, the pointer s is incremented (++s), moving it to the next character in the string.