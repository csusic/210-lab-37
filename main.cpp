// COMSC-210 | Lab 37 | Christine Susic

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
using namespace std;

//function prototypes
int gen_hash_index(string x);
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
    
    //hash table map comprised of int (key) and list (values)
    std::map<int, list<string>> hash_table;
    
    //display first 100 entries
    
    //testing function
    string x = "ABC";
    cout << "Sum x: " << sum_ascii(x) << endl;
    string y = "abc";
    cout << "Sum y: " << sum_ascii(y) << endl;

    return 0;
}

//function to generate hash index
int gen_hash_index(string x) {
    //initialize sum to zero
    int sum = 0;
    //loop to read each character
    for (char c : x) {
        //sum characters, int cast gets ASCII values
        sum += (int) c;
    }
    return sum;
};

//function to get sum of ascii values
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