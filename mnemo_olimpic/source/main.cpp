#include <iostream>

// Uncomment line with "#define DEBUG" if you want to see your hashtable.
// But rememeber to send only solutions with debug turned off!
#define DEBUG 1 

using namespace std;


struct Node
{
    string text;
    Node *next;
};

uint hashfunc(string txt) {
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
    uint hash = 0;
    for ( int i = 0 ; i < txt.length(); i++)
    {
         hash += txt[i];
    }
    return hash;
}

void add_to_hashtable(Node** hashtable, int n, string txt) {
    uint hash = hashfunc(txt) % n;
    Node ** p_to_p_node = hashtable + hash;
    cout << "DUPA2" << endl;
    while (*p_to_p_node != NULL)
    {
        cout << "DUPA3" << endl;
        p_to_p_node = &(*p_to_p_node)->next;
        cout << "DUPA4" << endl;
    }

    cout << "DUPA1" << endl;

    Node * p_new_node = new Node();
    p_new_node->text = txt;
    p_new_node->next = NULL;
    *p_to_p_node = p_new_node;
}

bool check_if_exists(Node** hashtable, int n, string txt) {
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
    uint hash = hashfunc(txt) % n;
    Node * p_first_node = hashtable[hash];

    while(p_first_node != NULL)
    {
        if(p_first_node->text == txt)
            return true;
        else
            p_first_node = p_first_node->next;
    }
    return false;
}

void free_memory(Node** hashtable, int n) {
    Node *ptr, *nxt;    
    for (int i = 0; i < n; i++) {
        ptr = hashtable[i];
        while (ptr != NULL) {
            /**********************
            * PLACE FOR YOUR CODE *
            **********************/
            nxt = ptr->next;
            delete ptr;
            ptr = nxt;
        }
    }
    delete[](hashtable);
}

void debug_print_hashtable(Node** hashtable, int n) {
    #ifdef DEBUG
        Node* ptr;  
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            ptr = hashtable[i];
            while (ptr != NULL) {
                cout << ptr->text << " | ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    #endif
}

int main() {
    ios::sync_with_stdio(false);
    int Z;
    cin >> Z;

    while (Z--) {
        int n, k;
        string tmp;

        cin >> n;
        cin >> k;

        Node** hashtable = new Node*[n]();

        for (int i = 0; i < n; i++)
            hashtable[i] = NULL;

        for (int i = 0; i < n; i++) {
            cin >> tmp;
            add_to_hashtable(hashtable, n, tmp);
            cout << "DUPA" << endl;
        }

        debug_print_hashtable(hashtable, n);

        for (int i = 0; i < k; i++) {
            cin >> tmp;
            if (check_if_exists(hashtable, n, tmp)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

        free_memory(hashtable, n);

    }

}