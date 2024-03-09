# String Wiz
### A strings utility library providing basic to advanced string functions.

## Table of Contents
- [Installation](#installation)
- [Contributing](#contributing)
- [Developer's Note](#developers-note)
- [Library Overview](#library-overview)
- [Documentation and Features](#documentation)

# Installation
The library for now is single-header only and does not require any prior set up.
just download/copy and include the header file into your code and read the docs on usage.

# Contributing
Contributors are welcomed add more strings related functions.
- Raise an issue about the about feature you want to add and wait for it to assigned to you.
- Or check any existing issue if you want to work on them [Issues](https://github.com/SharonIV0x86/StringWiz/issues) 
- Edit your code and open the PR, documentation will be taken care of. 
- Make sure to add block comments above your function.

### Requirements
1. ) Basics of C.
2. ) Basics of Git/Github and pull request, forking.
3. ) Passing string to function and returning string from functions.
4. ) Basic of header files in C. 

If you have any questions you can reach out to me on [discord](https://discord.com/users/1011937653203144715) or raise an issue.

## Developer's Note
This project represents a small endeavor aimed at enhancing skills in string manipulation and memory allocation. It's intended to be a long-term project with ongoing maintenance and the addition of new features. While there may be some inconsistencies in the current codebase, future updates will address these and introduce even more functionality.

Your contributions and feedback are highly appreciated as they play a crucial role in shaping the evolution of this project. Thank you for your support and stay tuned for exciting new features in the future!

## Library Overview

- str_malloc(int size)
- str_free(char* str)
- str_concat(const char* destination, const char* source)
- str_substr(const char* str, int start, int length)
- str_replace(const char* str, const char* old_sub, const char* new_sub)
- str_to_upper(char* str)
- str_to_lower(char* str)
- str_cmp_ignore_case(const char* str1, const char* str2)
- str_find(const char* str, const char* sub)
- str_rfind(const char* str, const char* sub)
- str_to_int(const char* str)
- str_to_float(const char* str)
- int_to_str(int num)
- float_to_str(float num)
- str_reverse(char* str)
- str_trimWHS(char* str
- str_format(const char* format, ...)
- str_num(const char* str)
- str_vow(const char* str)
- str_conso(const char* str)
# Documentation

## char* str_malloc(int size)
Allocates memory for a new string.
    
    Parameters:
    size: The size of the memory to allocate.
    Returns: A pointer to the allocated memory block.


## void str_free(char* str)
Frees memory allocated for a string.
    
    Parameters:
        str: Pointer to the string to be freed.


## char* str_concat(const char* str1, const char* str2)
Concatenates two strings.
    
    Parameters:
        str1: Pointer to the first string.
        str2: Pointer to the second string.
    Returns:
        A pointer to the concatenated string.

Usage:
```c
char* result = str_concat("Hello, ", "world!");
printf("%s\n", result); // Output: Hello, world!
str_free(result);
```
## char* str_substr(const char* str, int start, int length)
Creates a substring from a string.

    Parameters:
        str: Pointer to the original string.
        start: Starting index of the substring.
        length: Length of the substring.
    Returns:
        A pointer to the substring.
Usage:

```c
char* substring = str_substr("Hello, world!", 7, 5);
printf("%s\n", substring); // Output: world
str_free(substring);
```
## char* str_replace(const char* str, const char* old_sub, const char* new_sub)
Replaces occurrences of a substring in a string.

    Parameters:
        str: Pointer to the original string.
        old_sub: Pointer to the substring to be replaced.
        new_sub: Pointer to the replacement substring.
    Returns:
        A pointer to the modified string.

Usage:
```c
char* replaced = str_replace("Hello, world!", "world", "universe");
printf("%s\n", replaced); // Output: Hello, universe!
str_free(replaced);
```
## void str_to_upper(char* str)
Converts a string to uppercase.

    Parameters:
        str: Pointer to the string to be converted.

Usage:
```c
char str[] = "hello, world!";
str_to_upper(str);
printf("%s\n", str); // Output: HELLO, WORLD!
```

## void str_to_lower(char* str)
Converts a string to lowercase.

    Parameters:
        str: Pointer to the string to be converted.

Usage:
```c
char str[] = "HELLO, WORLD!";
str_to_lower(str);
printf("%s\n", str); // Output: hello, world!
```


## int str_cmp_ignore_case(const char* str1, const char* str2)
Performs a case-insensitive string comparison.

    Parameters:
        str1: Pointer to the first string.
        str2: Pointer to the second string.
    Returns:
        Negative value if str1 is less than str2.
        Positive value if str1 is greater than str2.
        Zero if str1 is equal to str2.
        
        Difference between the ASCII values if str1 and str2 are different
        the first character that is encountered different in the two string,
        it's difference is returned. Brace for unexpected output :) 
Usage:

```c
int result = str_cmp_ignore_case("Hello", "hello");
printf("%d\n", result); // Output: 0
```
## int str_find(const char* str, const char* sub)
Finds the first occurrence of a substring in a string.

    Parameters:
        str: Pointer to the original string.
        sub: Pointer to the substring to search for.
    Returns:
        Index of the first occurrence of sub in str.
        -1 if sub is not found in str.
Usage:

```c
int index = str_find("hello, world!", "world");
printf("%d\n", index); // Output: 7
```

## int str_rfind(const char* str, const char* sub)
Finds the last occurrence of a substring in a string.

    Parameters:
        str: Pointer to the original string.
        sub: Pointer to the substring to search for.
    Returns:
        Index of the last occurrence of sub in str.
        -1 if sub is not found in str.

Usage:
```c
int index = str_rfind("hello, world!", "o");
printf("%d\n", index); // Output: 8
```

## int str_to_int(const char* str)
Converts a string to an integer.

    Parameters:
        str: Pointer to the string to be converted.
    Returns:
        The integer value represented by the string.

Usage:

```c
int num = str_to_int("123");
printf("%d\n", num); // Output: 123
```

## float str_to_float(const char* str)
Converts a string to a float.

    Parameters:
        str: Pointer to the string to be converted.
    Returns:
        The floating-point value represented by the string.

Usage:
```c
float num = str_to_float("3.14");
printf("%f\n", num); // Output: 3.140000
```

## char* int_to_str(int num)

    Converts an integer to a string.
    Parameters:
        num: The integer to be converted.
    Returns:
        A pointer to the string representation of the integer.

Usage:
```c
char* str = int_to_str(123);
printf("%s\n", str); // Output: 123
str_free(str);
```

## char* float_to_str(float num)
Converts a float to a string.

    Parameters:
        num: The float to be converted.
    Returns:
        A pointer to the string representation of the float.

Usage:
```c
char* str = float_to_str(3.14);
printf("%s\n", str); // Output: 3.140000
str_free(str);
```
## void str_reverse(char* str)
Reverses a string.

    Parameters:
        str: Pointer to the string to be reversed.

Usage:
```c
char str[] = "hello, world!";
str_reverse(str);
printf("%s\n", str); // Output: !dlrow ,olleh
```

## void str_trim(char* str)
Trims whitespace characters from the beginning and end of a string.

    Parameters:
        str: Pointer to the string to be trimmed.

Usage:
```c
char str[] = "  hello, world!  ";
str_trim(str);
printf("%s\n", str); // Output: hello, world!
```
## char* str_format(const char* format, ...)
Formats a string using a format string and variable arguments.

    Parameters:
        format: The format string.
        ...: Variable arguments to be formatted.
    Returns:
        A pointer to the formatted string.

Usage:
```c
char* formatted = str_format("%s %d %.2f", "Hello", 123, 3.14159);
printf("%s\n", formatted); // Output: Hello 123 3.14
str_free(formatted);
```
## int str_num(const char *str)
Functions that returns the count of vowels in the string.

    Parameters:
        str: The string to find numbers in.
    Returns:
        Count of numbers in the string.
Usage:
```c
char strin = "This is a test string 1234";
int num = num_str(strin);
printf("Count of numbers: %d", num);
```

## int str_vow(const char *str)
Function that returns the vowels in the string

    Parameters:
        str: The string to find vowels in.
    Returns:
        Count of vowels in the string.
Usage:
```c
char strin = "This is a test string 1234";
int vowels = str_vow(strin);
```

## str_conso(const char *str)
Function that returns the count of consonants in the string.

    Parameters:
        str: The string to find consonants in.
    Returns:
        Count of number of consonants in the string.

Usage:
```c
char strin = "This is a test string 1235";
int consonants = str_conso(strin);
```