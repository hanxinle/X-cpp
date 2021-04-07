#include "array.hpp"
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main () {

   Array<int, 3> arr;
   for (int i = 0; i<3; ++i) {
       arr.Set (i * 10, i);
       cout << arr.Get (i) << endl;
   }

   cout << arr.Size () << endl;

   //array<string, 3> str3 = {"hello","world","han"};
   //for (auto & v :str3) {
   //    cout << v << endl;
   //}
   return 0;
}