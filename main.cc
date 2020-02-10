/*
BITWISE ENCRYPTION by Antioch
02:35am , 10/02/2020
*/

#include "headers.h"
#include <iostream>
#include <cstring>

using namespace std;


int main(){
    int key;
    char user_input;
    cout << "Please input key (0-255): ";
    cin >> key;
    cout << "Input from File or Commandline? (F/C): ";
    cin >> user_input;
    if((user_input=='C')||(user_input=='c')){
        CL_input(key);
    }
    else if((user_input=='F')||(user_input=='f')){
        file_input(key);
    }
    else{
        cerr << "ERR: Invalid user input" << endl;
    }
return 0;
}
