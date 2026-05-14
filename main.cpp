// COMSC-210 | Lab 37 | Christine Susic

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//function prototype
int sum_ascii(string);

int main() {
    //read the file
    ifstream fin("data.txt"); //open file
    int count = 0; //counter
    int total = 0; //initialize total to zero
    string line; //string to read from file
    
    //read codes from file
    while (getline(fin, line)) {
        count++;
        total += sum_ascii(line);
    }
    
    fin.close(); //close file
    
    //output total
    cout << "Total: " << total << endl;
    
    //testing function
    string x = "ABC";
    cout << "Sum x: " << sum_ascii(x) << endl;
    string y = "abc";
    cout << "Sum y: " << sum_ascii(y) << endl;
    
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;

    return 0;
}

//function
int sum_ascii(string x) {
    //initialize sum to zero
    int sum = 0;
    //loop to read each character
    for (char c : x) {
        //sum characters, int cast gets ASCII values
        sum += (int) c;
    }
    return sum;
};

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/