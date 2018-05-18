#include "circular_list_string.hpp"

using namespace std;

void string_list_cli_print_help() {
    cout << "'add': adds new element" << endl;
    cout << "'print': prints list" << endl;
    cout << "'remove': removes element with particular id" << endl;
    cout << "'replace': replaces element with another string" << endl;
    cout << "'duplicate': duplicates list" << endl;
    cout << "'combine': combines all strings into one" << endl;
    cout << "'length': calculates total length of all strings in list" << endl;
    cout << "'sort': sorts list" << endl;
    cout << "'help': prints help" << endl;
    cout << "'quit': quits" << endl;
    cout << endl;
}

void string_list_cli_add(circular_list<string>* list_of_strings) {
    cout << "Enter string: ";
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    string new_str;
    getline(cin, new_str);
    list_of_strings->push_back(new_str);
    cout << "Command succeeded." << endl << endl;
}

void string_list_cli_remove(circular_list<string>* list_of_strings) {
    cout << "Enter id: ";
    int id;
    
    cin >> id;
    if (!cin) {
        cin.clear();
        cout << "Command failed: 'wrong input'." << endl << endl;
        return;
    }
    
    if ((id >= 0) && (id < list_of_strings->get_length())) {
        list_of_strings->pop_by_index(id);
    } else {
        cout << "Command failed: 'id is out of range'." << endl << endl;
        return;
    }
    
    cout << "Command succeeded." << endl << endl;
}

void string_list_cli_replace(circular_list<string>* list_of_strings) {
    cout << "Enter id: ";
    int id;
    string new_str;
    
    cin >> id;
    if (!cin) {
        cin.clear();
        cout << "Command failed: 'wrong input'." << endl << endl;
        return;
    }
    
    if ((id < 0) && (id >= list_of_strings->get_length())) {
        cout << "Command failed: 'id is out of range'." << endl << endl;
        return;
    }
    
    cout << "Enter string: ";
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    getline(cin, new_str);
    
    list_of_strings->pop_by_index(id);
    list_of_strings->insert_at_index(id, new_str);
    cout << "Command succeeded." << endl << endl;
}

void string_list_cli_duplicate(circular_list<string>* list_of_strings) {
    list_of_strings->append(*list_of_strings);
    cout << "Command succeeded." << endl << endl;
}

void string_list_cli_combine(circular_list<string>* list_of_strings) {
    string result = list_of_strings->reduce<string>([](string current_result, string current_item) {
        return current_result+current_item;
    }, "");
    cout << "Result: '" << result << "'" << endl;
    cout << "Command succeeded." << endl << endl;
}

void string_list_cli_length(circular_list<string>* list_of_strings) {
    int result = list_of_strings->reduce<int>([](int current_result, string current_item) {
        return current_result + (int)current_item.length();
    }, 0);
    
    cout << "Result: " << result << endl;
    cout << "Command succeeded." << endl << endl;
}

void string_list_cli_sort(circular_list<string>* list_of_strings) {
    list_of_strings->sort([](string a, string b) {
        return (a < b);
    });
    
    cout << "Command succeeded." << endl << endl;
}

void string_list_cli_print_list(circular_list<string>* list_of_strings) {
    cout << "Printing " << list_of_strings->get_length() << " items:" << endl;
    for (int i = 0; i < list_of_strings->get_length(); i++) {
        cout << "[ID = " << i << "] '" << list_of_strings->get_item(i) << "'" << endl;
    }
    cout << endl;
}

void string_list_cli() {
    circular_list<string> list_of_strings;
    
    cout << "Welcome to Circular List \"string\" implementation." << endl;
    
    while (true) {
        cout << "Enter command: ";
        string command;
        cin >> command;
        
        if (command == "add") {
            string_list_cli_add(&list_of_strings);
        } else if (command == "remove") {
            string_list_cli_remove(&list_of_strings);
        } else if (command == "print") {
            string_list_cli_print_list(&list_of_strings);
        } else if (command == "replace") {
            string_list_cli_replace(&list_of_strings);
        } else if (command == "duplicate") {
            string_list_cli_duplicate(&list_of_strings);
        } else if (command == "combine") {
            string_list_cli_combine(&list_of_strings);
        } else if (command == "length") {
            string_list_cli_length(&list_of_strings);
        } else if (command == "sort") {
            string_list_cli_sort(&list_of_strings);
        } else if (command == "help") {
            string_list_cli_print_help();
        } else if (command == "quit") {
            break;
        } else {
            cout << "Command not found: '" << command << "'." << endl;
        }
    }
}
