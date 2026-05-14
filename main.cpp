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

//number of entries to display
const int ENTRIES = 100;

int main() {
    //read the file
    ifstream fin("data.txt"); //open file
    //initialize count, total, and index to zero
    int count = 0, total = 0, index = 0;
    string code; //string to read from file
    
    //hash table map comprised of int (key) and list (values)
    std::map<int, std::list<string>> hash_table;
    
    //read codes from file
    while (getline(fin, code)) {
        count++;
        total += sum_ascii(code);
        index += gen_hash_index(code);
        hash_table[index].push_back(code);
    }
    
    fin.close(); //close file
    
    //output total
    cout << "Total: " << total << endl << endl;
    
    //display first 100 entries
    //access the map using iterators
    cout << "Display first 100 entries:" << endl;
    for (auto it = hash_table.begin(); it != hash_table.end() 
    && count < ENTRIES; it++) {
    cout << it->first << ": ";
        if (!it->second.empty()) {
            cout << it->second.front() << endl;
        }
    }

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
    return sum % 1000;
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