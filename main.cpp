// COMSC-210 | Lab 37 | Christine Susic

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <list>
using namespace std;

//function prototype
int gen_hash_index(string x);

//hash table size
const int HASH_SIZE = 1997;
//number of entries to display
const int ENTRIES = 100;
//column widths
const int W1 = 4, W2 = 12;

int main() {
    //read the file
    ifstream fin("data.txt"); //open file
    //initialize count, total, index, and counter to zero
    int count = 0, index = 0, counter = 0;
    string code; //string to read from file
    
    //hash table map comprised of int (key) and list (values)
    std::map<int, std::list<string>> hash_table;
    
    //read codes from file
    while (getline(fin, code)) {
        index = gen_hash_index(code);
        //push codes into hash table
        hash_table[index].push_back(code);
        count++;
    }
    
    fin.close(); //close file
    
    //display first 100 entries
    //access the map using iterators
    cout << "First 100 entries:" << endl;
    for (auto it = hash_table.begin(); it != hash_table.end() 
    && counter < ENTRIES; it++) {
        cout << setw(W1) << it->first << ": ";
        if (!it->second.empty()) {
            cout << setw(W2) << it->second.front() << endl;
        }
        counter++;
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
    return sum % HASH_SIZE;
};