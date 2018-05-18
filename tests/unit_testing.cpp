#include "unit_testing.hpp"

#include <iostream>

using namespace std;

/*
 Модуль 1: Тестирование создания списка
 Модуль 2: Тестирование добавления элементов списка через push_front(), push_back(), insert_at_index(), получения длины списка через get_length(), а также получение элементов списка через оператор []
 Модуль 3: Тестирование удаления элементов списка через pop_by_index(), clear()
 Модуль 4: Тестирование сложения списков через append()
 Модуль 5: Тестирование сортировки списка через sort()
 Модуль 6: Тестирование свёртки списка через reduce()
 */
void run_tests() {
    run_tests_unit_1();
    run_tests_unit_2();
    run_tests_unit_3();
    run_tests_unit_4();
    run_tests_unit_5();
    run_tests_unit_6();
}

template <typename form_data>
void unit_testing::run_test_group(test_group<form_data> current_test_group) {
    if (is_aborted) {
        return;
    }
    
    for (int i = 0; i < current_test_group.data_set.size(); i++) {
        current_test_id++;
        
        cout << "[UNIT TESTING] TEST #" << current_test_id << ":";
        int spaces_count = test_output_padding - (int)to_string(current_test_id).length();
        for (int i = 0; i < spaces_count; i++) {
            cout << " ";
        }
        
        bool test_result = current_test_group.test_function(current_test_group.data_set[i]);
        if (test_result == true) {
            cout << "OK." << endl;
        } else {
            cout << "FAILED." << endl;
            abort_testing(current_test_group.group_name, i);
            break;
        }
    }
}

void unit_testing::run_single_test(bool (*test_function)(), string group_name) {
    if (is_aborted) {
        return;
    }
    
    current_test_id++;
    
    cout << "[UNIT TESTING] TEST #" << current_test_id << ":";
    int spaces_count = test_output_padding - (int)to_string(current_test_id).length();
    for (int i = 0; i < spaces_count; i++) {
        cout << " ";
    }
    
    bool test_result = test_function();
    if (test_result == true) {
        cout << "OK." << endl;
    } else {
        cout << "FAILED." << endl;
        abort_testing(group_name, 0);
    }
}

void unit_testing::abort_testing(string group_name, int group_data_id) {
    is_aborted = true;
    
    cout << "[UNIT TESTING] Testing failed on group \"" << group_name << "\", test " << group_data_id << endl;
    cout << "[UNIT TESTING] Aborting..." << endl << endl;
}

void unit_testing::start_testing() {
    cout << "[UNIT TESTING] Starting UNIT " << unit_number << " testing." << endl;
}

void unit_testing::finish_testing() {
    if (!is_aborted) {
        cout << "[UNIT TESTING] Testing UNIT " << unit_number << " passed." << endl << endl;
    }
}
