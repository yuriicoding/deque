#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
using namespace std;

template <typename Object>
class Deque 
{
  public:
    Deque()
      {  
         theCapacity = 8 ;
         objects = new Object[ theCapacity ]; 
         theSize = 0 ;
         front = 0 ; 
         back = 0 ; 
      }
      
    ~Deque( )
      { delete [ ] objects; }

    bool empty( ) const  { return size( ) == 0; }
    int size( ) const { return theSize; }
    void clear( ){
        // remove all contents and reset the capacity to it's initial value

        delete [] objects;
        theCapacity = 8;
        objects = new Object [theCapacity];
        theSize = 0;
        front = 0;
        back = 0;

    }

    void reserve( int newCapacity )
    {
        // change the capacity to newCapacity 
        // (provided it is larger than the current size)

        Object* temp = new Object [newCapacity];
        int counter = 0;
        for (int i = front; i < theCapacity; i++)
        {
          temp[counter] = objects[i];
          counter++;
        }
        for (int i = 0; i < back; i++)
        {
          temp[counter] = objects[i];
          counter++;
        }

        delete [] objects;
        objects = temp;
        front = 0;
        back = counter;
        theSize = counter;
        theCapacity = newCapacity;

    }

    // Operations 

    void enqueue( const Object & x )// Insert a new object at the back 
    {
        if( theSize == theCapacity ) reserve( 2 * theCapacity + 1 );
        objects[ back ] = x ; 
        back = (back+1) % theCapacity ;
        theSize++ ;
    }

    void jump( const Object & x )// Insert a new object at the front 
    {
        if (theSize == theCapacity) reserve (2*theCapacity+1);
        front = front-1;
        if (front < 0) front = theCapacity-1;
        objects[front] = x;
        theSize++;
    }

    Object dequeue( )// Remove and return the object at the front 
    {
        theSize--;
        Object temp = objects[front];
        front = (front+1) % theCapacity;
        return temp ;

    }

    Object eject( )// Remove and return the object at the back 
    {
          theSize--;
          Object temp = objects[back];
          if (back == 0) back = theCapacity-1;
          else back = back-1;
          return temp;

    }

    void display() const // print out the contents of the deque
    {
       // Implement this.  The output should be similar to that 
       // used in the Vector and Stack classes provided.
      if (theSize == 0)
      {
        cout << endl << "size = " << theSize << endl;
        cout << "< ... >" << endl;
      }
      else if (front >= back)
      {
        int counter = 0;
        cout << endl << "size = " << theSize << endl;
        cout << "< ";
        for (int i = front; i < theCapacity; i++)
        {
          cout << counter << "=" << objects[i] << " ";
          counter++;
        }

        for (int i = 0; i < back; i++)
        {
          cout << objects[i] << " ";
          cout << counter << "=" << objects[i] << " ";
          counter++;
        }
        cout << ">" << endl;
      }
      else
      {
        cout << endl << "size = " << theSize << endl;
        cout << "< ";
        int counter = 0;
        for (int i = front; i < back; i++) 
        {
          cout << counter << "=" << objects[i] << " ";
          counter++;
        }
        
        cout << ">" << endl;
      }
    }

    void ddisplay() const 
    // print out the contents of the objects 
    // array, and relevant variables, for debugging or verifying 
    // correctness. 
    {
        cout << "capacity = " << theCapacity << ", size = " << theSize << std::endl;

        cout << "[ " ;
        for( int i = 0; i < theCapacity; ++i ){
           cout << i << "=" << objects[i] << " " ;
        }
        cout << "]" << endl;
      
    }

    Object& operator [] (int index) const
    {
      if (front+index < theCapacity) return objects [front+index];
      else return objects [front+index - theCapacity];
    }


  private:
    int theSize;
    int front;
    int back;
    int theCapacity;
    Object * objects;
};

#endif
