#include <cstring>
#include <istream>
#include <fstream>
#include <iostream>
using namespace std;

void crypto(int key, char message[]){
    unsigned char c; //ciphertext char
    unsigned char ckey = key; //key char (byte)

    string translated = ""; //will eventually be output

    cout << "Key = " << (int)ckey << endl;
    cout << "\t Translating..." << endl;

    for (int i=0; i < strlen(message); i++){
        c = message[i];
        unsigned char a = c^ckey;
        translated += a;
    }
    ofstream file("output.txt");
    file << translated;
    cout << "\tSuccess!" << endl;
    cout << "\t(Result saved to 'output.txt')" << endl;
}

void file_input(int key){
    string messagestr;
    string filename;

    cout << "Enter filename: ";
    cin >> filename;
    ifstream file(filename.c_str());
    if ( !file.is_open() ) {
        std::cout << "Failed to open file: " << filename << "." << std::endl;
    }
    file >> messagestr;
    file.close();

    //convert string to char array
    int n = messagestr.length();
    char charin[n+1];
    messagestr.copy(charin, n);
//  strcpy(charin, messagestr.c_str());

    crypto(key, charin);
}

void CL_input(int key){
    int MAX_COMMANDLINE_LENGTH = 512;
    char charin[MAX_COMMANDLINE_LENGTH];
    //ask user to input a message on the command line
    cout << "Enter text: ";

    //clear cin buffer to remove lingering newline
    cin.clear();
    fflush(stdin);

    //get message from CL input
    cin.getline(charin,256);
    cout << endl;
    crypto(key,charin);
}
