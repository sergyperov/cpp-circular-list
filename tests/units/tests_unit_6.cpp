#include "tests_unit_6.hpp"

/*
 Модуль 6: Тестирование свёртки списка через reduce()
 
 Тест 1: тестируем сумму элементов пустого списка через reduce()
 Тест 2: тестируем сумму элементов списка c одним элементом через reduce()
 Тест 3: тестируем сумму элементов списка c 5 элементами через reduce()
 Тест 4: тестируем произведение элементов списка c 5 элементами через reduce()
 Тест 5: тестируем сумму арифметической прогрессии через reduce()
 */
void run_tests_unit_6() {
    unit_testing unit_t(6);
    
    // Тест 1
    unit_t.run_single_test([]() {
        circular_list<int> list;
        list.reduce<int>([](int current_number, int result){
            return result + current_number;
        }, 0);
        
        if (list.get_length() == 0) {
            return true;
        }
        return false;
    }, "single test 1");
    
    // Тест 2
    unit_t.run_single_test([]() {
        circular_list<int> list;
        int elems_arr[1] = {42};
        int result_sum = 42;
        
        for (int i = 0; i < 1; i++) {
            list.push_back(elems_arr[i]);
        }
        
        int test_sum = list.reduce<int>([](int current_number, int result){
            return result + current_number;
        }, 0);
        
        if (test_sum == result_sum) {
            return true;
        }
        return false;
    }, "single test 2");
    
    // Тест 3
    unit_t.run_single_test([]() {
        circular_list<int> list;
        int elems_arr[5] = {1, 1, 2, 3, 5};
        int result_sum = 12;
        
        for (int i = 0; i < 5; i++) {
            list.push_back(elems_arr[i]);
        }
        
        int test_sum = list.reduce<int>([](int current_number, int result){
            return result + current_number;
        }, 0);
        
        if (test_sum == result_sum) {
            return true;
        }
        return false;
    }, "single test 3");
    
    // Тест 4
    unit_t.run_single_test([]() {
        circular_list<int> list;
        int elems_arr[5] = {1, 1, 2, 3, 5};
        int result_sum = 30;
        
        for (int i = 0; i < 5; i++) {
            list.push_back(elems_arr[i]);
        }
        
        int test_sum = list.reduce<int>([](int current_number, int result){
            return result * current_number;
        }, 1);
        
        if (test_sum == result_sum) {
            return true;
        }
        return false;
    }, "single test 4");
    
    // Тест 5
    unit_t.run_single_test([]() {
        circular_list<int> list;
        int N = 100000;
        int result_sum = (1 + N) * N / 2;
        
        for (int n = 1; n <= N; n++) {
            list.push_back(n);
        }
        
        int test_sum = list.reduce<int>([](int current_number, int result){
            return result + current_number;
        }, 0);
        
        if (test_sum == result_sum) {
            return true;
        }
        return false;
    }, "single test 5");
    
    unit_t.finish_testing();
}
