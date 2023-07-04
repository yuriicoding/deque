#include <iostream>
#include "deque.h"

int main()
{
    Deque<int> numberArr;
    for (int i = 0; i < 15; i++) numberArr.enqueue(i+2);
    numberArr.display();


    cout << "Zero element of numberArr (index 0): " << numberArr[0] << endl;
    cout << "Tenth element of numberArr (index 10): " << numberArr[10] << endl;

    cout << endl << "Changing zero element (index 0) to 500 and tenth element (index 10) to 1000" << endl;

    numberArr[0] = 500;
    numberArr[10] = 1000;
    numberArr.display();


    cout << endl << "Changing all elements of numberArr to 1" << endl;

    for (int i = 0; i < numberArr.size(); i++) numberArr[i] = 1;
    numberArr.display();




    Deque<char> letterArr;
    for (char i = 'a'; i < 'm'; i++) letterArr.enqueue(i);
    letterArr.display();

    cout << "Second element of letterArr (index 2): " << letterArr[2] << endl;
    cout << "Sixth element of letterArr (index 6): " << letterArr[6] << endl;

    cout << endl << "Changing third element (index 3) to 'z' and eleventh element (index 11) to 'z'" << endl;

    letterArr[3] = 'z';
    letterArr[11] = 'z';
    letterArr.display();

    cout << endl << "Changing all elements of letterArr to 'a'" << endl;

    for (int i = 0; i < letterArr.size(); i++) letterArr[i] = 'a';
    letterArr.display();
    
    return 0;
}
