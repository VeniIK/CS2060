// Fig. 15.3: fig15_03.cpp
// Using an inline function to calculate the volume of a cube.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Definition of inline function cube. Definition of function appears 
// before function is called, so a function prototype is not required. 
// First line of function definition acts as the prototype.
inline double cube( const double side )                    
{                                                          
   return side * side * side; // calculate the cube of side
} 

int main()
{
   double sideValue; // stores value entered by user 

   for ( int i = 1; i <= 3; i++ ) 
   {
      cout << "\nEnter the side length of your cube: ";
      cin >> sideValue; // read value from user

      // calculate cube of sideValue and display result
      cout << "Volume of cube with side " 
         << sideValue << " is " << cube( sideValue ) << endl;
   }
}

/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
