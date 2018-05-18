#include "tests_unit_2.hpp"

/*
 Модуль 2: Тестирование добавления элементов списка через push_front(), push_back(), insert_at_index(), получения длины списка через get_length(), а также получение элементов списка через оператор []
 
 Тест 1: добавляем 1 элемент через push_front()
 Тест 2: добавляем 10 элементов через push_front()
 Тест 3: добавляем 1 элемент через push_back()
 Тест 4: добавляем 10 элементов через push_back()
 Тест 5: добавляем 1 элемент через insert_at_index()
 Тест 6: добавляем в середину 10 элементов через insert_at_index()
 Тест 7: добавляем 1 элемент через push_front(), 1 элемент через push_back()
 Тест 8: добавляем 1 элемент через push_back(), 1 элемент через push_front()
 Тест 9: поочерёдно добавляем элементы через push_front(), push_back()
 Тест 10: поочерёдно добавляем элементы через push_back(), push_front()
 Тест 11: проверяем, что после изменения уже добавленного элемента в списке он не изменится
 */
void run_tests_unit_2 () {
    unit_testing unit_t(2);
    
    // Тест 1
    unit_t.run_single_test([]() {
        circular_list<int> list;
        list.push_front(42);
        
        if ((list.get_length() == 1) && (list[0] == 42)) {
            return true;
        }
        return false;
    }, "single test 1");
    
    // Тест 2
    unit_t.run_single_test([]() {
        int test_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        circular_list<int> list;
        
        for (int i = 0; i < 10; i++) {
            list.push_front(test_arr[i]);
        }
        
        if (list.get_length() == 10) {
            for (int i = 0; i < 10; i++) {
                if (list[i] != test_arr[9-i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 2");
    
    // Тест 3
    unit_t.run_single_test([]() {
        circular_list<int> list;
        list.push_back(42);
        
        if ((list.get_length() == 1) && (list[0] == 42)) {
            return true;
        }
        return false;
    }, "single test 3");
    
    // Тест 4
    unit_t.run_single_test([]() {
        int test_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        circular_list<int> list;
        
        for (int i = 0; i < 10; i++) {
            list.push_back(test_arr[i]);
        }
        
        if (list.get_length() == 10) {
            for (int i = 0; i < 10; i++) {
                if (list[i] != test_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }, "single test 4");
    
    // Тест 5
    unit_t.run_single_test([]() {
        circular_list<int> list;
        
        int new_elem = 42;
        list.insert_at_index(0, new_elem);
        if ((list.get_length() == 1) && (list[0] == new_elem)) {
            return true;
        }
        
        return false;
    }, "single test 5");
    
    // Тест 6
    unit_t.run_single_test([]() {
        circular_list<int> list;
        int elems_arr[10] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
        int result_elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 0; i < 10; i++) {
            list.insert_at_index(list.get_length()/2, elems_arr[i]);
        }
        
        if (list.get_length() == 10) {
            for (int i = 0; i < 10; i++) {
                if (list[i] !=  result_elems_arr[i]) {
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
        
        int new_elem_1 = 111;
        int new_elem_2 = 222;
        list.push_front(new_elem_1);
        list.push_back(new_elem_2);
        if ((list.get_length() == 2) && (list[0] == new_elem_1) && (list[1] == new_elem_2)) {
            return true;
        }
        
        return false;
    }, "single test 7");
    
    // Тест 8
    unit_t.run_single_test([]() {
        circular_list<int> list;
        
        int new_elem_1 = 111;
        int new_elem_2 = 222;
        list.push_back(new_elem_1);
        list.push_front(new_elem_2);
        if ((list.get_length() == 2) && (list[0] == new_elem_2) && (list[1] == new_elem_1)) {
            return true;
        }
        
        return false;
    }, "single test 8");
    
    // Тест 9
    unit_t.run_single_test([]() {
        circular_list<int> list;
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int result_elems_arr[10] = {9, 7, 5, 3, 1, 2, 4, 6, 8, 10};
        
        for (int i = 0; i < 10; i++) {
            if (i%2 == 0) {
                list.push_front(elems_arr[i]);
            } else {
                list.push_back(elems_arr[i]);
            }
        }
        
        if (list.get_length() == 10) {
            for (int i = 0; i < 10; i++) {
                if (list[i] !=  result_elems_arr[i]) {
                    return false;
                }
            }
            
            return true;
        }
        
        return false;
    }, "single test 9");
    
    // Тест 10
    unit_t.run_single_test([]() {
        circular_list<int> list;
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int result_elems_arr[10] = {10, 8, 6, 4, 2, 1, 3, 5, 7, 9};
        
        for (int i = 0; i < 10; i++) {
            if (i%2 == 0) {
                list.push_back(elems_arr[i]);
            } else {
                list.push_front(elems_arr[i]);
            }
        }
        
        if (list.get_length() == 10) {
            for (int i = 0; i < 10; i++) {
                if (list[i] !=  result_elems_arr[i]) {
                    return false;
                }
            }
            
            return true;
        }
        
        return false;
    }, "single test 10");
    
    // Тест 11
    unit_t.run_single_test([]() {
        circular_list<int> list;
        int result = 42;
        int elem = result;
        
        list.push_back(elem);
        elem *= 100;
        
        if ((list.get_length() == 1) && (list[0] == result)) {
            return true;
        }
        
        return false;
    }, "single test 11");
    
    unit_t.finish_testing();
}
