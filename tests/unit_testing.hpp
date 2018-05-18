#ifndef unit_testing_hpp
#define unit_testing_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "tests_unit_1.hpp"
#include "tests_unit_2.hpp"
#include "tests_unit_3.hpp"
#include "tests_unit_4.hpp"
#include "tests_unit_5.hpp"
#include "tests_unit_6.hpp"

using namespace std;

template <typename form_data>
struct test_group {
    string group_name;
    
    bool (*test_function)(form_data);
    vector<form_data> data_set;
};


/*
 Own class to perform unit testing
 
 A new class object should be inited for each unit of tests
 Constructor works like: unit_testing (UNIT_NUMBER)
 
 Testing will start right afer object creation
 
 Call run_single_test() to run a test case for a particular function
 Call run_test_group() to run a group of test data for one particular function
 After the last test call finish_testing()
 */
class unit_testing {
private:
    int unit_number;
    int current_test_id = 0;
    
    bool is_aborted = false;
    string aborted_group_name;
    int aborted_group_data_id;
    
    int test_output_padding = 3;
    
    void start_testing();
    void abort_testing(string group_name, int group_data_id);
public:
    unit_testing(int _unit_number) {
        unit_number = _unit_number;
        start_testing();
    }
    
    template <typename form_data>
    void run_test_group(test_group<form_data>);
    void run_single_test(bool (*test_function)(), string group_name);
    void finish_testing();
};

void run_tests();

#endif /* unit_testing_hpp */
