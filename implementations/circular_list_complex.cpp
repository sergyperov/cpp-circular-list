#include "circular_list_complex.hpp"
#include "string"

using namespace std;

string get_complex_formatted(complex k) {
    string res = "";
    if (k.a != 0) {
        res += (to_string(k.a) + "i");
    }
    
    if (k.b > 0) {
        if (k.a != 0) {
            res += "+";
        }
        res += to_string(k.b);
    } else if (k.b < 0) {
        res += "-" + to_string(k.b*(-1));
    }
    
    if (res == "") {
        res = "0";
    }
    
    return res;
}

void complex_list_cli_print_help() {
    cout << "'add': adds new element" << endl;
    cout << "'print': prints list" << endl;
    cout << "'remove': removes element with particular id" << endl;
    cout << "'replace': replaces element with another complex" << endl;
    cout << "'duplicate': duplicates list" << endl;
    cout << "'sum': calculates the sum of elements" << endl;
    cout << "'multiplicate': calculates the multiplication of elements" << endl;
    cout << "'sort_с': sorts list by complex number coefficients" << endl;
    cout << "'sort_l': sorts list by complex number length" << endl;
    cout << "'help': prints help" << endl;
    cout << "'quit': quits" << endl;
    cout << endl;
}

void complex_list_cli_add(circular_list<complex>* list_of_complexes) {
    cout << "Enter complex (format [a b] as 'ai+b'): ";
    
    int a, b;
    cin >> a;
    if (!cin) {
        cin.clear();
        cout << "Command failed: 'wrong input'." << endl << endl;
        return;
    }
    cin >> b;
    if (!cin) {
        cin.clear();
        cout << "Command failed: 'wrong input'." << endl << endl;
        return;
    }
    
    complex new_complex(a, b);
    
    list_of_complexes->push_back(new_complex);
    cout << "Command succeeded." << endl << endl;
}

void complex_list_cli_remove(circular_list<complex>* list_of_complexes) {
    cout << "Enter id: ";
    int id;
    
    cin >> id;
    if (!cin) {
        cin.clear();
        cout << "Command failed: 'wrong input'." << endl << endl;
        return;
    }
    
    if ((id >= 0) && (id < list_of_complexes->get_length())) {
        list_of_complexes->pop_by_index(id);
    } else {
        cout << "Command failed: 'id is out of range'." << endl << endl;
        return;
    }
    
    cout << "Command succeeded." << endl << endl;
}

void complex_list_cli_replace(circular_list<complex>* list_of_complexes) {
    cout << "Enter id: ";
    int id;
    
    cin >> id;
    if (!cin) {
        cin.clear();
        cout << "Command failed: 'wrong input'." << endl << endl;
        return;
    }
    
    if ((id < 0) && (id >= list_of_complexes->get_length())) {
        cout << "Command failed: 'id is out of range'." << endl << endl;
        return;
    }
    
    cout << "Enter complex (format [a b] as 'ai+b'): ";
    
    int a, b;
    cin >> a;
    if (!cin) {
        cin.clear();
        cout << "Command failed: 'wrong input'." << endl << endl;
        return;
    }
    cin >> b;
    if (!cin) {
        cin.clear();
        cout << "Command failed: 'wrong input'." << endl << endl;
        return;
    }
    
    complex new_complex(a, b);
    
    list_of_complexes->pop_by_index(id);
    list_of_complexes->insert_at_index(id, new_complex);
    cout << "Command succeeded." << endl << endl;
}

void complex_list_cli_duplicate(circular_list<complex>* list_of_complexes) {
    list_of_complexes->append(*list_of_complexes);
    cout << "Command succeeded." << endl << endl;
}

void complex_list_cli_sum(circular_list<complex>* list_of_complexes) {
    complex result = list_of_complexes->reduce<complex>([](complex current_result, complex current_item) {
        int a = current_result.a + current_item.a;
        int b = current_result.b + current_item.b;
        return complex(a, b);
    }, complex(0, 0));
    
    cout << "Result: '" << get_complex_formatted(result) << "', |" << result.length() << "|" << endl;
    cout << "Command succeeded." << endl << endl;
}

void complex_list_cli_multiplicate(circular_list<complex>* list_of_complexes) {
    complex result = list_of_complexes->reduce<complex>([](complex current_result, complex current_item) {
        int a = current_result.a*current_item.b + current_result.b*current_item.a;
        int b = current_result.a*current_item.a - current_result.b*current_item.b;
        return complex(a, b);
    }, complex(1, 1));
    
    cout << "Result: '" << get_complex_formatted(result) << "', |" << result.length() << "|" << endl;
    cout << "Command succeeded." << endl << endl;
}

void complex_list_cli_sort_c(circular_list<complex>* list_of_complexes) {
    list_of_complexes->sort([](complex a, complex b) {
        return ((a.a < b.a) && (a.b < b.b));
    });
    
    cout << "Command succeeded." << endl << endl;
}

void complex_list_cli_sort_l(circular_list<complex>* list_of_complexes) {
    list_of_complexes->sort([](complex a, complex b) {
        return (a.length() < b.length());
    });
    
    cout << "Command succeeded." << endl << endl;
}

void complex_list_cli_print_list(circular_list<complex>* list_of_complexes) {
    cout << "Printing " << list_of_complexes->get_length() << " items:" << endl;
    for (int i = 0; i < list_of_complexes->get_length(); i++) {
        complex item = list_of_complexes->get_item(i);
        double complex_length = item.length();
        
        cout << "[ID = " << i << "] '" << get_complex_formatted(item) << "', |" << complex_length << "|" << endl;
    }
    cout << endl;
}

void complex_list_cli() {
    circular_list<complex> list_of_complexes;
    
    cout << "Welcome to Circular List \"complex\" implementation." << endl;
    
    while (true) {
        cout << "Enter command: ";
        string command;
        cin >> command;
        
        if (command == "add") {
            complex_list_cli_add(&list_of_complexes);
        } else if (command == "remove") {
            complex_list_cli_remove(&list_of_complexes);
        } else if (command == "print") {
            complex_list_cli_print_list(&list_of_complexes);
        } else if (command == "replace") {
            complex_list_cli_replace(&list_of_complexes);
        } else if (command == "duplicate") {
            complex_list_cli_duplicate(&list_of_complexes);
        } else if (command == "sum") {
            complex_list_cli_sum(&list_of_complexes);
        } else if (command == "multiplicate") {
            complex_list_cli_multiplicate(&list_of_complexes);
        } else if (command == "sort_c") {
            complex_list_cli_sort_c(&list_of_complexes);
        } else if (command == "sort_l") {
            complex_list_cli_sort_l(&list_of_complexes);
        } else if (command == "help") {
            complex_list_cli_print_help();
        } else if (command == "quit") {
            break;
        } else {
            cout << "Command not found: '" << command << "'." << endl;
        }
    }
}
