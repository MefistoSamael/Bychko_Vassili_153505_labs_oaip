#pragma once




// This functions are used in first dop without star


// Fills two-dimensional array with numbers
// entered from keybord
// если вдруг криво отработает, убери функцию check из нее
extern "C"  __declspec(dllexport) void Fill(const int&, const int& , int** );


// Out two-dimensional array
extern "C"  __declspec(dllexport)  void Out2(const int& , const int&, int** );


// Out one-dementional array
extern "C"  __declspec(dllexport) void Out(const int& , int* );


// Find production of ellements in one-dementional array
extern "C"  __declspec(dllexport) int prod(const int& , int* );


// Ipnut check
extern "C"  __declspec(dllexport) void check(int& );
