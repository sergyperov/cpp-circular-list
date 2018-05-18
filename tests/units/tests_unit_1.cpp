#include "tests_unit_1.hpp"

/*
 Модуль 1: Тестирование создания списка
 
 Тест 1: тестируем создание списка
 */
void run_tests_unit_1() {
    unit_testing unit_t(1);
    
    // Тест 1
    unit_t.run_single_test([]() {
        circular_list<int> list;
        if (list.get_length() == 0) {
            try {
                list[0];
            } catch (std::out_of_range exep) {
                return true;
            }
            return false;
        } else {
            return false;
        }
        return false;
    }, "single test 1");
    
    unit_t.finish_testing();
}
