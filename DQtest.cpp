#include <iostream>
#include "deque.h"

int main()
{
    // int-type deque testing
    Deque<int> intArr;

    for (int i = 0; i < 1001; i++) intArr.enqueue(i+10);
    intArr.display();
    if (intArr.empty()) cout << "Array is empty" << endl;
    else cout << "Array is not empty" << endl;

    intArr.clear();
    intArr.display();
    if (intArr.empty()) cout << "Array is empty" << endl;
    else cout << "Array is not empty" << endl;

    for (int i = 1; i < 301; i++) 
    {
        intArr.enqueue(i);
        intArr.jump(i);
    }
    intArr.display();

    for (int i = 0; i < 100; i++)
    {
        intArr.dequeue();
        intArr.eject();
    }
    intArr.display();


    //char-type deque testing
    Deque<char> charArr;

    for (int i = 'a'; i <= 'z'; i++) charArr.enqueue(i);
    charArr.display();
    if (charArr.empty()) cout << "Array is empty" << endl;
    else cout << "Array is not empty" << endl;

    charArr.clear();
    charArr.display();
    if (charArr.empty()) cout << "Array is empty" << endl;
    else cout << "Array is not empty" << endl;

    charArr.enqueue('a');
    charArr.jump('a');
    charArr.display();

    for (int i = 'a'; i <= 'p'; i++) 
    {
        charArr.enqueue(i);
        charArr.jump(i);
    }
    charArr.display();

    for (int i = 0; i < 10; i++)
    {
        charArr.dequeue();
        charArr.eject();
    }
    charArr.display();

    charArr.dequeue();
    charArr.eject();
    charArr.display();

    //float-type deque testing
    Deque<double> floatArr;
    double counter = 0;
    for (int i = 0; i < 1000; i++) floatArr.enqueue((counter+i)/2);
    floatArr.display();
        if (floatArr.empty()) cout << "Array is empty" << endl;
    else cout << "Array is not empty" << endl;

    floatArr.clear();
    floatArr.display();
    if (floatArr.empty()) cout << "Array is empty" << endl;
    else cout << "Array is not empty" << endl;

    counter = 0;
    for (int i = 1; i < 301; i++) 
    {
        floatArr.enqueue((counter+i)/3);
        floatArr.jump((counter+i)/3);
    }
    floatArr.display();

    for (int i = 0; i < 100; i++)
    {
        floatArr.dequeue();
        floatArr.eject();
    }
    floatArr.display();

    return 0;
}