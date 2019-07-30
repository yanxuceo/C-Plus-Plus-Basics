#include <iostream>
#include <string>



/**
 * An example passing-value-by-reference
 *
 * @param str1 a reference to a pointer pointing to const char
 * 
 */
void addSpaces(const char * &str1) { 
    char *temp = new char(sizeof(str1)*2);
    char *start = temp;
    // moving our pointer to the end of array of character
    while(*str1 != '\0'){
        *temp++ = *str1++;
        *temp++ = ' ';
    }
  
    str1 = start;
}

int main() {
    std::string str = "Hello World";
    const char* ptr = str.c_str();
    std::cout << "string is: "<< ptr << std::endl;

    addSpaces(ptr);
    std::cout<<"string is: "<<ptr<<std::endl;
    
    return 0;
}
