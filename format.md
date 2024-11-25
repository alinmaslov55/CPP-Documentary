# ```<format>```

- powerful and type-safe way to create formatted strings

## Basic Usage of ```std::format```

```cpp
#include <format>
#include <iostream>

int main() {
    int value = 42;
    double pi = 3.14159;

    // Basic formatting
    std::string formatted_str = std::format("Value: {}, Pi: {:.2f}", value, pi);

    std::cout << formatted_str << std::endl;
    return 0;
}
```

## Format Placeholders

```cpp
{index_or_name:format_spec}
```

1. General
    - ```{}``` - Default format.
    - ```{:<N}``` - Left-align within N spaces.
    - ```{:>N}``` - Right-align within N spaces.
    - ```{:^N}``` - Center-align within N spaces.
    - ```{:#}``` - Include base prefix for integers (e.g., 0x for hex).
2. Integers
    - ```{:+}``` - Show a sign for positive and negative numbers.
    - ```{:#x}``` - Hexadecimal with 0x prefix.
    - ```{:#o}``` - Octal with 0o prefix.
    - ```{:#b}``` - Binary with 0b prefix.
3. Floating Point
    - ```{:.Nf}``` - Fixed-point with N decimal places.
    - ```{:.Ne}``` - Scientific notation with N decimal places.
    - ```{:%}``` - Multiply by 100 and display as a percentage.
4. Strings
    - ```{:.N}``` - Limit string to N characters.

## Advanced Features

1. Argument Indexing

```cpp
std::format("{2} {1} {0}", "first", "second", "third"); // Output: "third second first"
```

2. Named Arguments (with std::format API only)
    - ```std::format_to```, ```std::format_args``` for named arguments
        ```cpp
        std::cout << std::vformat("{name} is {age} years old.", 
            std::make_format_args("name"_a="Alice", "age"_a=30));
        ```
3. Local-Aware Formatting
    - ```std::format(std::locale, ...)``` for locale-specific formatting
4. Custom formatters
    - Extend ```std::formatter``` to enable formatting of user-defined types