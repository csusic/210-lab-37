// COMSC-210 | Lab 38 | Christine Susic

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
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
    //initialize count and index to zero
    int count = 0, index = 0;
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
    
    //interactive menu
    int counter = 0;
    //choice for menu
    int choice;
    //input
    int searchKey, newKey, removeKey, modifyKey;
    string newValue, modifyValue;
    do {
        //menu
        cout << "\nHash Table Menu: " << endl;
        cout << "[1] Print the first 100 entries" << endl;
        cout << "[2] Search for a key" << endl;
        cout << "[3] Add a key" << endl;
        cout << "[4] Remove a key" << endl;
        cout << "[5] Modify a key" << endl;
        cout << "[0] Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    
    switch (choice) {
            //1. Print the first 100 entries
            case 1:
                //access the map using iterators
                cout << "\nFirst 100 entries:" << endl;
                for (auto it = hash_table.begin(); it != hash_table.end() 
                && counter < ENTRIES; it++) {
                    cout << setw(W1) << it->first << ": ";
                    if (!it->second.empty()) {
                        cout << setw(W2) << it->second.front() << endl;
                    }
                    counter++;
                }
                break;
            //2. Search for a key
            case 2:
                cout << "Enter key to search: ";
                cin >> searchKey;
                if (hash_table.find(searchKey) != hash_table.end()) {
                    cout << "Key found." << endl;
                }
                else {
                    cout << "Key not found." << endl;
                }
                break;
            //3. Add a key
            case 3:
                cout << "Enter new key: ";
                cin >> newKey;
                cout << "Enter new value: ";
                cin >> newValue;
                hash_table.insert({newKey, {newValue}});
                cout << "Key value inserted." << endl;
                break;
            //4. Remove a key
            case 4:
                cout << "Enter key to remove: ";
                cin >> removeKey;
                hash_table.erase(removeKey);
                cout << "Key removed." << endl;
                break;
            //5. Modify a key
            case 5:
                cout << "Enter key to modify: ";
                cin >> modifyKey;
                cout << "Enter value to modify: ";
                cin >> modifyValue;
                hash_table[modifyKey] = {modifyValue}; 
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