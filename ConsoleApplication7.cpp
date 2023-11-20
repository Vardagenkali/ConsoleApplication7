#include <iostream>
#include <cstring>

class String {
private:
    static int count;
    char* str;
    int size;

public:
    String() : String(80) {}

    explicit String(size_t size) : size(static_cast<int>(size)), str(new char[size + 1]) {
        ++count;
    }

    String(const char* inputString) : String(strlen(inputString)) {
        strcpy_s(str, size + 1, inputString);
    }

    ~String() {
        delete[] str;
        --count;
    }

    static int getCount() {
        return count;
    }

    void inputString() {
        std::cout << "Enter a string: ";
        std::cin.getline(str, size + 1);
    }

    void printString() const {
        std::cout << "String: " << str << std::endl;
    }
};

int String::count = 0;

int main() {
    String defaultString; 
    defaultString.printString();

    String customSizeString(50);
    customSizeString.inputString();
    customSizeString.printString();

    String userInputString;  
    userInputString.inputString();
    userInputString.printString();

    std::cout << "Number of String objects created: " << String::getCount() << std::endl;

    return 0;
}
