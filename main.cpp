// COMSC-210 | Lab 38 | Christine Susic

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
    
    //interactive menu
    //choice for menu
    int choice;
    do {
        //menu
        cout << "\nHash Table Menu: " << endl;
        cout << "[1] " << endl;
        cout << "[2]  " << endl;
        cout << "[3]  " << endl;
        cout << "[4]  " << endl;
        cout << "[5]  " << endl;
        cout << "[0] " << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    
    switch (choice) {
            //1. Print the first 100 entries
            case 1:
                
                break;
            //2. Search for a key
            case 2:
                
                break;
            //3. Add a key
            case 3:
                
                break;
            //4. Remove a key
            case 4:
                
                break;
            //5. Modify a key
            case 5:
               
                break;
            //0. Exit
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != 0);

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