#include "tests_unit_5.hpp"

/*
 Модуль 5: Тестирование сортировки списка через sort()
 
 Тест 1: тестируем сортировку пустого списка через sort()
 Тест 2: тестируем сортировку списка с одним элементом через sort()
 Тест 3: тестируем сортировку по возрастанию через sort()
 Тест 4: тестируем сортировку по убыванию через sort()
 Тест 5: тестируем сортировку произвольного типа (строка) через sort()
 Тест 6: тестируем push_back() после сортировки списка через sort()
 Тест 7: тестируем push_front() после сортировки списка через sort()
 Тест 8: тестируем insert_at_index() после сортировки списка через sort()
 Тест 9: тестируем pop_by_index() после сортировки списка через sort()
 */
void run_tests_unit_5() {
    unit_testing unit_t(5);
    
    // Тест 1
    unit_t.run_single_test([]() {
        circular_list<int> list;
        list.sort([](int a, int b){
            return (a > b);
        });
        
        if (list.get_length() == 0) {
            return true;
        }
        return false;
    }, "single test 1");
    
    // Тест 2
    unit_t.run_single_test([]() {
        circular_list<int> list;
        
        list.push_back(42);
        list.sort([](int a, int b){
            return (a > b);
        });
        
        if ((list.get_length() == 1) && (list[0] == 42)) {
            return true;
        }
        return false;
    }, "single test 2");
    
    // Тест 3
    unit_t.run_single_test([]() {
        circular_list<int> list;
        int elems_arr[10] = {4, 6, 8, 1, 9, 2, 5, 3, 7, 10};
        int result_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        for (int i = 0; i < 10; i++) {
            list.push_back(elems_arr[i]);
        }
        
        list.sort([](int a, int b){
            return (a < b);
        });
        
        if (list.get_length() == 10) {
            for (int i = 0; i < 10; i++) {
                if (list[i] != result_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 3");
    
    // Тест 4
    unit_t.run_single_test([]() {
        circular_list<int> list;
        int elems_arr[10] = {4, 6, 8, 1, 9, 2, 5, 3, 7, 10};
        int result_arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        
        for (int i = 0; i < 10; i++) {
            list.push_back(elems_arr[i]);
        }
        
        list.sort([](int a, int b){
            return (a > b);
        });
        
        if (list.get_length() == 10) {
            for (int i = 0; i < 10; i++) {
                if (list[i] != result_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 4");
    
    // Тест 5
    unit_t.run_single_test([]() {
        circular_list<string> list;
        string elems_arr[3] = {"ac", "ab", "a"};
        string result_arr[3] = {"a", "ab", "ac"};
        
        for (int i = 0; i < 3; i++) {
            list.push_back(elems_arr[i]);
        }
        
        list.sort([](string a, string b){
            return (a < b);
        });
        
        if (list.get_length() == 3) {
            for (int i = 0; i < 3; i++) {
                if (list[i] != result_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 5");
    
    // Тест 6
    unit_t.run_single_test([]() {
        circular_list<int> list;
        int elems_arr[10] = {4, 6, 8, 1, 9, 2, 5, 3, 7, 10};
        int result_arr[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 42};
        
        for (int i = 0; i < 10; i++) {
            list.push_back(elems_arr[i]);
        }
        
        list.sort([](int a, int b){
            return (a < b);
        });
        
        list.push_back(42);
        
        if (list.get_length() == 11) {
            for (int i = 0; i < 11; i++) {
                if (list[i] != result_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 6");
    
    // Тест 7
    unit_t.run_single_test([]() {
        circular_list<int> list;
        int elems_arr[10] = {4, 6, 8, 1, 9, 2, 5, 3, 7, 10};
        int result_arr[11] = {42, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        for (int i = 0; i < 10; i++) {
            list.push_back(elems_arr[i]);
        }
        
        list.sort([](int a, int b){
            return (a < b);
        });
        
        list.push_front(42);
        
        if (list.get_length() == 11) {
            for (int i = 0; i < 11; i++) {
                if (list[i] != result_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 7");
    
    // Тест 8
    unit_t.run_single_test([]() {
        circular_list<int> list;
        int elems_arr[10] = {4, 6, 8, 1, 9, 2, 5, 3, 7, 10};
        int result_arr[11] = {1, 2, 3, 4, 42, 5, 6, 7, 8, 9, 10};
        
        for (int i = 0; i < 10; i++) {
            list.push_back(elems_arr[i]);
        }
        
        list.sort([](int a, int b){
            return (a < b);
        });
        
        list.insert_at_index(4, 42);
        
        if (list.get_length() == 11) {
            for (int i = 0; i < 11; i++) {
                if (list[i] != result_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 8");
    
    // Тест 9
    unit_t.run_single_test([]() {
        circular_list<int> list;
        int elems_arr[10] = {4, 6, 8, 1, 9, 2, 5, 3, 7, 10};
        // {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
        int result_arr[9] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
        
        for (int i = 0; i < 10; i++) {
            list.push_back(elems_arr[i]);
        }
        
        list.sort([](int a, int b){
            return (a < b);
        });
        list.pop_by_index(4);
        
        if (list.get_length() == 9) {
            for (int i = 0; i < 9; i++) {
                if (list[i] != result_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 9");
    
    unit_t.finish_testing();
}
