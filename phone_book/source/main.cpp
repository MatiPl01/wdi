#include <iostream>

// Uncomment line with "#define DEBUG" if you want to see your hashtable.
// But rememeber to send only solutions with debug turned off!
#define DEBUG 1 

using namespace std;

enum states {
    EMPTY = 0,
    OCCUPIED = 1,
    STH_WAS_HERE = 2
};

struct Slot
{
    string name;
    string phone;
    states state;
};

uint hashfunc(string name) {
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
    uint hash = 0;
    for ( int i = 0 ; i < name.length(); i++)
    {
         hash += name[i];
    }
    return hash;
}

void add_to_hashtable(Slot** hashtable, int n, string name, string phone) {
    uint hash = hashfunc(name) % n;
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
    // find a good spot for placing this entry!
    // You may use this:
    // uint hash = ???;
    // while (hashtable[hash]->state == ???) {
    //     hash = ???;
    // }

    while (hashtable[hash]->state == OCCUPIED)
        hash += 1;

    hashtable[hash]->state = OCCUPIED;
    hashtable[hash]->name = name;
    hashtable[hash]->phone = phone;
}

string get_number(Slot** hashtable, int n, string name) {
    if (n == 0) return ""; 
    uint hash = hashfunc(name) % n;
    int i = 0;
    while (
        /**********************
        * PLACE FOR YOUR CODE *
        **********************/
        hash < n-1 &&
        hashtable[hash]->name != name
    ) {
        /**********************
        * PLACE FOR YOUR CODE *
        **********************/
        hash += 1;
    }
    if (hashtable[hash]->state == EMPTY) {
        return "";
    }
    return hashtable[hash]->phone;
}

void remove_from_hashtable(Slot** hashtable, int n, string name) {
    uint hash = hashfunc(name) % n;
    while (
        /**********************
        * PLACE FOR YOUR CODE *
        **********************/
        hashtable[hash]->name != name
    ) {
        /**********************
        * PLACE FOR YOUR CODE *
        **********************/
        hash += 1;
    }
    hashtable[hash]->state = STH_WAS_HERE;
}


void free_memory(Slot** hashtable, int n) {
    for (int i = 0; i < n; i++) {
        delete(hashtable[i]);
    }
    delete[](hashtable);
}

void debug_print_hashtable(Slot** hashtable, int n) {
    #ifdef DEBUG
        for (int i = 0; i < n; i++) {
            cout << i << ": [" << hashtable[i]->state << "] " <<  hashtable[i]->name << endl;
        }
        cout << endl;
    #endif
}

int main() {
    ios::sync_with_stdio(false);
    int Z;
    cin >> Z;

    while (Z--) {
        int n, d, k;
        char op;
        string tmp_name, tmp_phone;

        cin >> n;
        cin >> k;

        int size = n*2; // What will be good size for our phonebook?

        Slot** hashtable = new Slot*[size]();

        for (int i = 0; i < size; i++) {
            hashtable[i] = new Slot();
            hashtable[i]->state = EMPTY;
        }

        for (int i = 0; i < k; i++) {
            cin >> op;
            switch(op) {
                case 'a':
                    cin >> tmp_name;
                    cin >> tmp_phone;
                    add_to_hashtable(hashtable, size, tmp_name, tmp_phone);
                    break;
                case 'r':
                    cin >> tmp_name;
                    remove_from_hashtable(hashtable, size, tmp_name);
                    break;
                case 'g':
                    cin >> tmp_name;
                    cout << get_number(hashtable, size, tmp_name) << endl;
                    break;
            }
            debug_print_hashtable(hashtable, size);
        }

        free_memory(hashtable, size);

    }

}
