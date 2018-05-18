#include "tests_unit_3.hpp"

/*
 Модуль 3: Тестирование удаления элементов списка через pop_by_index(), clear()
 
 Тест 1: проверяем, что нельзя удалить несуществующий элемент
 Тест 2: добавляем 1 элемент через push_back(), затем удаляем его же через pop_by_index()
 Тест 3: добавляем 3 элемента через push_back(), затем удаляем первый элемент через pop_by_index()
 Тест 4: добавляем 3 элемента через push_back(), затем удаляем последний элемент через pop_by_index()
 Тест 5: добавляем 100 элементов, затем удаляем все элементы через pop_by_index()
 Тест 6: добавляем 100 элементов, затем удаляем все элементы через clear()
 Тест 7: удаляем элементы через clear(), затем проверяем работоспособность push_back()
 Тест 8: тестируем все методы вместе
 Тест 9: проверяем замену элемента через pop_by_index() и insert_at_index()
 */
void run_tests_unit_3() {
    unit_testing unit_t(3);
    
    // Тест 1
    unit_t.run_single_test([]() {
        circular_list<int> list;
        try {
            list.pop_by_index(0);
        } catch (std::out_of_range exep) {
            return true;
        }
        return false;
    }, "single test 1");
    
    // Тест 2
    unit_t.run_single_test([]() {
        circular_list<int> list;
        list.push_back(42);
        list.pop_by_index(0);
        
        if (list.get_length() == 0) {
            return true;
        }
        return false;
    }, "single test 2");
    
    // Тест 3
    unit_t.run_single_test([]() {
        circular_list<int> list;
        list.push_back(0);
        list.push_back(1);
        list.push_back(2);
        list.pop_by_index(0);
        
        if ((list.get_length() == 2) && (list[0] == 1) && (list[1] == 2)) {
            return true;
        }
        return false;
    }, "single test 3");
    
    // Тест 4
    unit_t.run_single_test([]() {
        circular_list<int> list;
        list.push_back(0);
        list.push_back(1);
        list.push_back(2);
        list.pop_by_index(list.get_length()-1);
        
        if ((list.get_length() == 2) && (list[0] == 0) && (list[1] == 1)) {
            return true;
        }
        return false;
    }, "single test 4");
    
    // Тест 5
    unit_t.run_single_test([]() {
        circular_list<int> list;
        
        for (int i = 0; i < 100; i++) {
            list.push_back(i*10);
        }
        while(list.get_length() != 0) {
            list.pop_by_index(0);
        }
        
        if ((list.get_length() == 0)) {
            return true;
        }
        return false;
    }, "single test 5");
    
    // Тест 6
    unit_t.run_single_test([]() {
        circular_list<int> list;
        
        for (int i = 0; i < 100; i++) {
            list.push_back(i*10);
        }
        
        list.clear();
        
        if ((list.get_length() == 0)) {
            return true;
        }
        return false;
    }, "single test 6");
    
    // Тест 7
    unit_t.run_single_test([]() {
        circular_list<int> list;
        
        for (int i = 0; i < 100; i++) {
            list.push_back(i*10);
        }
        
        list.clear();
        list.push_back(1);
        
        if ((list.get_length() == 1) && (list[0] == 1)) {
            return true;
        }
        return false;
    }, "single test 7");
    
    // Тест 8
    unit_t.run_single_test([]() {
        circular_list<int> list;
        
        list.push_back(1);              // 1
        list.push_back(2);              // 1,2
        list.push_back(3);              // 1,2,3
        list.pop_by_index(1);           // 1,3
        list.push_back(4);              // 1,3,4
        list.pop_by_index(1);           // 1,4
        list.insert_at_index(1, 5);     // 1,5,4
        
        if ((list.get_length() == 3) && (list[0] == 1) && (list[1] == 5) && (list[2] == 4)) {
            return true;
        }
        return false;
    }, "single test 8");
    
    // Тест 9
    unit_t.run_single_test([]() {
        circular_list<int> list;
        
        list.push_back(1);              // 1
        list.push_back(2);              // 1,2
        list.push_back(3);              // 1,2,3
        list.push_back(4);              // 1,2,3,4
        list.pop_by_index(2);           // 1,2,4
        list.insert_at_index(2, 42);    // 1,2,42,4
        
        if ((list.get_length() == 4) && (list[0] == 1) && (list[1] == 2) && (list[2] == 42) && (list[3] == 4)) {
            return true;
        }
        return false;
    }, "single test 9");
    
    unit_t.finish_testing();
}
