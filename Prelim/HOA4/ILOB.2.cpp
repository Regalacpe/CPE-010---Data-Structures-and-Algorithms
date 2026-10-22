#include <iostream>
#include "stackList.h"

int main(){

    std::cout<<"\n==== PUSHING 'c' 'p' 'e' ON TO THE STACK ====\n";

    push('c');
    push('p');
    push('e');

    Top<char>();

    std::cout<<"\n=== DISPLAY ALL ====\n";
    displayAll<char>();

    std::cout<<"\n==== POPPING ALL THE ELEMTENTS ====\n";

    while(!isEmpty<char>()){
        std::cout<<" Popped: "<< pop<char>() <<std::endl;
    }

    std::cout<<"\n==== TESTING THE UNDERFLOW ====\n";
    pop<char>();

    

    return 0;
}
