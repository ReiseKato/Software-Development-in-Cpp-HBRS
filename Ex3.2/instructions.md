Compile the program surprise.cc using -w, which disables all warnings, as the only option, and test it.

What happens and why?
Now compile the code with warning options.

Warning options:

- `-Wall` makes the translator issue all Warnings (not just errors)
    --> recommended to always use this option
- `-Werror` makes the translator issue all Warnings as errors
    --> not necessarily recommended, because some warnings may be acceptable
- alternatively, consider particular warnings as errors, e.g.: `-Werror=return-type`: consider missing `return` statement an error
- `-ansi -pedantic -Wextra -Wpedantic -O0 -g`
cause even more scrutinuous reactions to flaws