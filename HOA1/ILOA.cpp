#include <iostream>

void displaySum(int num1, int num2);
bool isGreater(int a, int b);
bool logicalOperations(bool x, bool y);

int main() {
    int num1, num2;
    int a, b;
    bool x, y;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    displaySum(num1, num2);

    std::cout << "\nEnter two numbers to compare: ";
    std::cin >> a >> b;

    if (isGreater(a, b)) {
        std::cout << "A is greater than B." << std::endl;
    } else {
        std::cout << "A is not greater than B." << std::endl;
    }

    std::cout << "\nEnter two boolean values (0 for false, 1 for true): ";
    std::cin >> x >> y;

    if (logicalOperations(x, y)) {
        std::cout << "Function executed successfully." << std::endl;
    }

    return 0;
}


void displaySum(int num1, int num2) {
    std::cout << "Sum = " << num1 + num2 << std::endl;
}

bool isGreater(int a, int b) {
    return a > b;
}

bool logicalOperations(bool x, bool y) {
    std::cout << "AND: " << (x && y) << std::endl;
    std::cout << "OR: " << (x || y) << std::endl;
    std::cout << "NOT x: " << (!x) << std::endl;
    std::cout << "NOT y: " << (!y) << std::endl;
    return true;
}


//CODE ANALYSIS 
//This code shows the use of function prototypes by declaring the functions before the main() and defining them afterward. 
//It has three functions one that displays the sum of two numbers, one that checks if the first number is greater than the second, 
//and one that performs basic logical operations on two Boolean values. 
//The main() function gathers user input and calls each function to perform its assigned task. 
//  The program follows the basic C++ code structure while keeping the functions organized and easy to understand.