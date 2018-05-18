#include "tests_unit_4.hpp"

/*
 Модуль 4: Тестирование сложения списков через append()
 
 Тест 1: тестируем добавление пустого списка к пустому списку
 Тест 2: тестируем добавление непустого списка к пустому списку
 Тест 3: тестируем добавление пустого списка к непустому списку
 Тест 4: тестируем добавление списка к самому себе
 Тест 5: тестируем добавление списка к другому списку той же длины
 Тест 6: тестируем добавление списка к другому списку другой длины
 Тест 7: тестируем push_back() после добавления одного спиcка к другому
 Тест 8: тестируем push_front() после добавления одного спиcка к другому
 Тест 9: тестируем insert_at_index() после добавления одного спиcка к другому
 Тест 10: тестируем pop_by_index() после добавления одного спиcка к другому
 */
void run_tests_unit_4() {
    unit_testing unit_t(4);
    
    // Тест 1
    unit_t.run_single_test([]() {
        circular_list<int> list_1;
        circular_list<int> list_2;
        
        list_1.append(list_2);
        
        if (list_1.get_length() == 0) {
            return true;
        }
        return false;
    }, "single test 1");
    
    // Тест 2
    unit_t.run_single_test([]() {
        circular_list<int> list_1;
        circular_list<int> list_2;
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        for (int i = 0; i < 10; i++) {
            list_2.push_back(elems_arr[i]);
        }
        list_1.append(list_2);
        
        if (list_1.get_length() == 10) {
            for (int i = 0; i < 10; i++) {
                if (list_1[i] != elems_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 2");
    
    // Тест 3
    unit_t.run_single_test([]() {
        circular_list<int> list_1;
        circular_list<int> list_2;
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        for (int i = 0; i < 10; i++) {
            list_1.push_back(elems_arr[i]);
        }
        list_1.append(list_2);
        
        if (list_1.get_length() == 10) {
            for (int i = 0; i < 10; i++) {
                if (list_1[i] != elems_arr[i]) {
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
        int elems_arr[5] = {11, 22, 33, 44, 55};
        int result_arr[10] = {11, 22, 33, 44, 55, 11, 22, 33, 44, 55};
        
        for (int i = 0; i < 5; i++) {
            list.push_back(elems_arr[i]);
        }
        list.append(list);
        
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
        circular_list<int> list_1;
        circular_list<int> list_2;
        int elems_arr_1[5] = {11, 22, 33, 44, 55};
        int elems_arr_2[5] = {66, 77, 88, 99, 1010};
        int result_arr[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 1010};
        
        for (int i = 0; i < 5; i++) {
            list_1.push_back(elems_arr_1[i]);
        }
        for (int i = 0; i < 5; i++) {
            list_2.push_back(elems_arr_2[i]);
        }
        list_1.append(list_2);
        
        if (list_1.get_length() == 10) {
            for (int i = 0; i < 10; i++) {
                if (list_1[i] != result_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 5");
    
    // Тест 6
    unit_t.run_single_test([]() {
        circular_list<int> list_1;
        circular_list<int> list_2;
        int elems_arr_1[5] = {1, 4, 9, 16, 25};
        int elems_arr_2[4] = {36, 49, 64, 81};
        int result_arr[9] = {1, 4, 9, 16, 25, 36, 49, 64, 81};
        
        for (int i = 0; i < 5; i++) {
            list_1.push_back(elems_arr_1[i]);
        }
        for (int i = 0; i < 4; i++) {
            list_1.push_back(elems_arr_2[i]);
        }
        list_1.append(list_2);
        
        if (list_1.get_length() == 9) {
            for (int i = 0; i < 9; i++) {
                if (list_1[i] != result_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 6");
    
    // Тест 7
    unit_t.run_single_test([]() {
        circular_list<int> list_1;
        circular_list<int> list_2;
        int elems_arr_1[5] = {1, 4, 9, 16, 25};
        int elems_arr_2[4] = {36, 49, 64, 81};
        int result_arr[10] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 777};
        
        for (int i = 0; i < 5; i++) {
            list_1.push_back(elems_arr_1[i]);
        }
        for (int i = 0; i < 4; i++) {
            list_1.push_back(elems_arr_2[i]);
        }
        list_1.append(list_2);
        list_1.push_back(777);
        
        if (list_1.get_length() == 10) {
            for (int i = 0; i < 10; i++) {
                if (list_1[i] != result_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 7");
    
    // Тест 8
    unit_t.run_single_test([]() {
        circular_list<int> list_1;
        circular_list<int> list_2;
        int elems_arr_1[5] = {1, 4, 9, 16, 25};
        int elems_arr_2[4] = {36, 49, 64, 81};
        int result_arr[10] = {777, 1, 4, 9, 16, 25, 36, 49, 64, 81};
        
        for (int i = 0; i < 5; i++) {
            list_1.push_back(elems_arr_1[i]);
        }
        for (int i = 0; i < 4; i++) {
            list_1.push_back(elems_arr_2[i]);
        }
        list_1.append(list_2);
        list_1.push_front(777);
        
        if (list_1.get_length() == 10) {
            for (int i = 0; i < 10; i++) {
                if (list_1[i] != result_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 8");
    
    // Тест 9
    unit_t.run_single_test([]() {
        circular_list<int> list_1;
        circular_list<int> list_2;
        int elems_arr_1[5] = {1, 4, 9, 16, 25};
        int elems_arr_2[4] = {36, 49, 64, 81};
        int result_arr[10] = {1, 4, 9, 16, 777, 25, 36, 49, 64, 81};
        
        for (int i = 0; i < 5; i++) {
            list_1.push_back(elems_arr_1[i]);
        }
        for (int i = 0; i < 4; i++) {
            list_1.push_back(elems_arr_2[i]);
        }
        list_1.append(list_2);
        list_1.insert_at_index(4, 777);
        
        if (list_1.get_length() == 10) {
            for (int i = 0; i < 10; i++) {
                if (list_1[i] != result_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 9");
    
    // Тест 10
    unit_t.run_single_test([]() {
        circular_list<int> list_1;
        circular_list<int> list_2;
        int elems_arr_1[5] = {1, 4, 9, 16, 25};
        int elems_arr_2[4] = {36, 49, 64, 81};
        // {1, 4, 9, 16, 25, 36, 49, 64, 81}
        int result_arr[8] = {1, 4, 9, 16, 36, 49, 64, 81};
        
        for (int i = 0; i < 5; i++) {
            list_1.push_back(elems_arr_1[i]);
        }
        for (int i = 0; i < 4; i++) {
            list_1.push_back(elems_arr_2[i]);
        }
        list_1.append(list_2);
        list_1.pop_by_index(4);
        
        if (list_1.get_length() == 8) {
            for (int i = 0; i < 8; i++) {
                if (list_1[i] != result_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 10");
    
    unit_t.finish_testing();
}
