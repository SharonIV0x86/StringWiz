#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>

/*
 * StringWiz: A versatile string utility library offering a comprehensive set of string manipulation functions.
 * 
 * StringWiz is designed to provide developers with a wide range of string-related tools, from basic operations 
 * like concatenation and substring extraction to more advanced features such as case-insensitive comparison 
 * and formatted string creation. 
 * source https://github.com/SharonIV0x86/StringWiz/
 */

/* Function to allocate memory for a new string */
char* str_malloc(int size) {
    return (char*)malloc(size * sizeof(char));
}

/* Function to free memory allocated for a string */
void str_free(char* str) {
    free(str);
}

/* 
 * Function to concatenate two strings 
 * 
 * @param destination Pointer to original String contains the concatanated string.
 * @param source Pointer to other string to be concatanated */
char* str_concat(const char* destination, const char* source) {
    char* result = (char*)malloc((strlen(destination) + strlen(source) + 1) * sizeof(char));
    strcpy(result, destination);
    strcat(result, source);
    return result;
}

/*
 * Function to create a substring from a string
 *
 * @param str Pointer to the original string.
 * @param start Starting index of the substring.
 * @param length Length of the substring.
 * @return A pointer to the substring.
 */
char* str_substr(const char* str, int start, int length) {
    
    char* result = (char*)malloc((length + 1) * sizeof(char));
    strncpy(result, str + start, length);
    result[length] = '\0';
    return result;
}

/*
 * Function to create a substring from a string
 *
 * @param str Pointer to the original string.
 * @param old_sub pointer to old sub string.
 * @param new_sub pointer to new sub string.
 * @return A pointer to the result.
 */
char* str_replace(const char* str, const char* old_sub, const char* new_sub) {
    char* result;
    char* ins;
    char* tmp;
    int len_old = strlen(old_sub);
    int len_new = strlen(new_sub);
    int len_str = strlen(str);
    int count = 0;
    const char* p;

    for (p = strstr(str, old_sub); p != NULL; p = strstr(p + len_old, old_sub)) {
        count++;
    }

    result = (char*)malloc(len_str + count * (len_new - len_old) + 1);

    if (result == NULL) {
        return NULL;
    }

    ins = result;
    for (p = str; (tmp = strstr(p, old_sub)) != NULL; p = tmp + len_old) {
        strncpy(ins, p, tmp - p);
        ins += tmp - p;
        strncpy(ins, new_sub, len_new);
        ins += len_new;
    }
    strcpy(ins, p);
    return result;
}

/*
 * Function to create a substring from a string
 *
 * @param str Pointer to the string.
 * @return does not return anything
 */
void str_to_upper(char* str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

/*
 * Function to create a substring from a string
 *
 * @param str Pointer to the string.
 * @return void does not return anything
 */
void str_to_lower(char* str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

/*
 * Function to create a substring from a string
 *
 * @param str1 Pointer to the first string.
 * @param str2 Pointer to the second string
 * @return int look README.md 
 */
int str_cmp_ignore_case(const char* str1, const char* str2) {
    while (*str1 && *str2 && tolower(*str1) == tolower(*str2)) {
        str1++;
        str2++;
    }
    return tolower(*str1) - tolower(*str2);
}

/*
 * Function to find first occurrence of a substring in a string
 *
 * @param str Pointer to the string.
 * @param sub Pointer to substring to find
 * @return -1 if not found
 */
int str_find(const char* str, const char* sub) {
    char* ptr = strstr(str, sub);
    if (ptr == NULL) {
        return -1;
    }
    return ptr - str;
}

/* 
 * Function to find the last occurrence of a substring in a string 
 * @param str Pointer to the string.
 * @param sub Pointer to the substring
 * @return -1 if not found
 */
int str_rfind(const char* str, const char* sub) {
    char* ptr = strstr(str, sub);
    char* last_ptr = NULL;
    while (ptr != NULL) {
        last_ptr = ptr;
        ptr = strstr(ptr + 1, sub);
    }
    if (last_ptr == NULL) {
        return -1;
    }
    return last_ptr - str;
}

/* 
 * Function to convert a string to an integer 
 * @param str Pointer to the string
 * @return the converted integer
*/
int str_to_int(const char* str) {
    return atoi(str);
}

/* 
 * Function to convert a string to an floating point 
 * @param str Pointer to the string
 * @return the converted float
*/
float str_to_float(const char* str) {
    return atof(str);
}

/* 
 * Function to convert a integer to a string
 * @param num integer number to convert to string
 * @return returns the converted string
*/
char* int_to_str(int num) {
    char* str = (char*)malloc(12 * sizeof(char)); // Maximum length of an integer string is 11 characters + 1 for null terminator
    sprintf(str, "%d", num);
    return str;
}

/* 
 * Function to convert a string to an integer 
 * @param num float number to convert to str
 * @return the converted string
*/
char* float_to_str(float num) {
    char* str = (char*)malloc(32 * sizeof(char)); // Maximum length of a float string is 31 characters + 1 for null terminator
    sprintf(str, "%f", num);
    return str;
}

/* 
 * Function to reverse a string 
 * @param str Pointer to the string
 * @return void does not return anything
*/
void str_reverse(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

/* 
 * Function to trim whitespace characters from the beginning and end of a string
 * @param str Pointer to the string
 * @return void does not return anything
*/
void str_trimWHS(char* str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    while (isspace(str[start])) {
        start++;
    }
    while (end > start && isspace(str[end])) {
        end--;
    }
    str[end + 1] = '\0';
    memmove(str, str + start, end - start + 2);
}

/* Function to format a string */

/* 
 * Function to format a string
 * @param str Pointer to the string
 * @param ... variadic pack for n arguments (string)
 * @return formatted string
*/
char* str_format(const char* format, ...) {
    va_list args;
    va_start(args, format);
    int len = vsnprintf(NULL, 0, format, args);
    va_end(args);
    
    char* str = (char*)malloc((len + 1) * sizeof(char));
    va_start(args, format);
    vsnprintf(str, len + 1, format, args);
    va_end(args);
    
    return str;
}
/* Function that returns the count of number digits in the string 
 * @param str Pointer to the string
 * @return number of digits
*/
int str_num(const char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            count++;
        }
    }
    return count;
}

/* Function that returns the count of vowels in the string
 * @param str Pointer to the string
 * @return number of vowels
*/
int str_vow(const char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') {
            count++;
        }
    }
    return count;
}
/* Function that returns the count of consonants in the string
 * @param str Pointer to the string
 * @return number of consonants
*/
int str_conso(const char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') {
            count++;
        }
    }
    int p = strlen(str) - count;
    return p;
}

/* Function that returns the hash code of a string,
 * similar to hashcode() in Java, uses a rolling hash
 * @param str Pointer to the string
 * @return integer value representing the hashcode of the string
*/
int str_hashcode(const char* str){
    int n = strlen(str), hash = 0;
    int power = 1;
    for (int i = n-1; i >= 0; i--) {
        hash += str[i]*power;
        power *= 31;
    }
    return hash;
}

/* Function that returns the length of the largest word in a string
 * and also copies that word into another string
 * @param destination Pointer to original String .
 * @param source Pointer to other string that will contain the largest word.
 * @return integer value representing the length of the largest word.
*/
int str_larg_word(char * p, char * r)
{
    char * i, * index;
    int length = 0,largest = 0 ;
    while(* p!='\0')
    {
        i=p;
        for(; *p != '\0' && *p != ' '&&*p+1!=' ' ; )
        {
            length++;
            p++;
        }
        if ( length > largest )
        {
            largest = length;
            index = i;
        }
        p++;
        length=0;
    }
    p=index;
    i=p+largest;
    while(p<i)
    {
        *r=*p;
        p++;
        r++;
    }
    return largest;   
}

/* Function that returns the length of the smalles word in a string
 * and also copies that word into another string
 * @param destination Pointer to original String .
 * @param source Pointer to other string that will contain the smallest word.
 * @return integer value representing the length of the smallest word.
*/
int str_small_word(char * p, char * r)
{
    char * i,* index;

    int length = 0,smallest = 10000 ;
    while(* p!='\0')
    {
        i=p;
        for(; *p != '\0' && *p != ' '&&*p+1!=' ' ; )
        {
            length++;
            p++;
        }
        if ( length < smallest && length!=0 )
        {
            smallest = length;
            index = i;
        }
        p++;
        length=0;
    }
    p=index;
    i=p+smallest;
    while(p<i)
    {
        *r=*p;
        p++;
        r++;
    }
    return smallest;   
}

/*  * The `str_remove_whitespace` function directly modifies the original string to remove whitespaces.
    * It iterates through the characters of the string, skipping whitespaces, and updates the string in place.
    * After running the function, the modified string will have no whitespaces, and the original string will be altered.*/

void str_remove_whitespace(char str[]) {
    int src = 0;
    int dst = 0;

    while (str[src]) {
        if (!isspace((unsigned char)str[src])) {
            str[dst] = str[src];
            dst++;
        }
        src++;
    }
    str[dst] = '\0'; 
}

/* * The 'str_shuffle' function shuffles the characters in the  string str using the Fisher-Yates algorithm.
   * It seeds the random number generator using srand(time(NULL)) to ensure different seeds based on the current time,
     which enhances the randomness of the shuffling process. */

    void str_shuffle(char *str) {
    int length = strlen(str);
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
