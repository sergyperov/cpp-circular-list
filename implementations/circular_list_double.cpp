#include "circular_list_double.hpp"

using namespace std;

void double_list_cli_print_help() {
    cout << "'add': adds new element" << endl;
    cout << "'print': prints list" << endl;
    cout << "'remove': removes element with particular id" << endl;
    cout << "'replace': replaces element with another double" << endl;
    cout << "'duplicate': duplicates list" << endl;
    cout << "'sum': calculates the sum of elements" << endl;
    cout << "'sort': sorts list" << endl;
    cout << "'help': prints help" << endl;
    cout << "'quit': quits" << endl;
    cout << endl;
}

void double_list_cli_add(circular_list<double>* list_of_doubles) {
    cout << "Enter double: ";
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    double new_double;
    cin >> new_double;
    if (!cin) {
        cin.clear();
        cout << "Command failed: 'wrong input'." << endl << endl;
        return;
    }
    
    list_of_doubles->push_back(new_double);
    cout << "Command succeeded." << endl << endl;
}

void double_list_cli_remove(circular_list<double>* list_of_doubles) {
    cout << "Enter id: ";
    int id;
    
    cin >> id;
    if (!cin) {
        cin.clear();
        cout << "Command failed: 'wrong input'." << endl << endl;
        return;
    }
    
    if ((id >= 0) && (id < list_of_doubles->get_length())) {
        list_of_doubles->pop_by_index(id);
    } else {
        cout << "Command failed: 'id is out of range'." << endl << endl;
        return;
    }
    
    cout << "Command succeeded." << endl << endl;
}

void double_list_cli_replace(circular_list<double>* list_of_doubles) {
    cout << "Enter id: ";
    int id;
    double new_double;
    
    cin >> id;
    if (!cin) {
        cin.clear();
        cout << "Command failed: 'wrong input'." << endl << endl;
        return;
    }
    
    if ((id < 0) && (id >= list_of_doubles->get_length())) {
        cout << "Command failed: 'id is out of range'." << endl << endl;
        return;
    }
    
    cout << "Enter double: ";
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    cin >> new_double;
    if (!cin) {
        cin.clear();
        cout << "Command failed: 'wrong input'." << endl << endl;
        return;
    }
    
    list_of_doubles->push_back(new_double);
    cout << "Command succeeded." << endl << endl;
    
    list_of_doubles->pop_by_index(id);
    list_of_doubles->insert_at_index(id, new_double);
    cout << "Command succeeded." << endl << endl;
}

void double_list_cli_duplicate(circular_list<double>* list_of_doubles) {
    list_of_doubles->append(*list_of_doubles);
    cout << "Command succeeded." << endl << endl;
}

void double_list_cli_sum(circular_list<double>* list_of_doubles) {
    double result = list_of_doubles->reduce<double>([](double current_result, double current_item) {
        return current_result + current_item;
    }, 0);
    
    cout << "Result: " << result << endl;
    cout << "Command succeeded." << endl << endl;
}

void double_list_cli_sort(circular_list<double>* list_of_doubles) {
    list_of_doubles->sort([](double a, double b) {
        return (a < b);
    });
    
    cout << "Command succeeded." << endl << endl;
}

void double_list_cli_print_list(circular_list<double>* list_of_doubles) {
    cout << "Printing " << list_of_doubles->get_length() << " items:" << endl;
    for (int i = 0; i < list_of_doubles->get_length(); i++) {
        cout << "[ID = " << i << "] " << list_of_doubles->get_item(i) << endl;
    }
    cout << endl;
}

void double_list_cli() {
    circular_list<double> list_of_doubles;
    
    cout << "Welcome to Circular List \"double\" implementation." << endl;
    
    while (true) {
        cout << "Enter command: ";
        string command;
        cin >> command;
        
        if (command == "add") {
            double_list_cli_add(&list_of_doubles);
        } else if (command == "remove") {
            double_list_cli_remove(&list_of_doubles);
        } else if (command == "print") {
            double_list_cli_print_list(&list_of_doubles);
        } else if (command == "replace") {
            double_list_cli_replace(&list_of_doubles);
        } else if (command == "duplicate") {
            double_list_cli_duplicate(&list_of_doubles);
        } else if (command == "sum") {
            double_list_cli_sum(&list_of_doubles);
        } else if (command == "sort") {
            double_list_cli_sort(&list_of_doubles);
        } else if (command == "help") {
            double_list_cli_print_help();
        } else if (command == "quit") {
            break;
        } else {
            cout << "Command not found: '" << command << "'." << endl;
        }
    }
}
