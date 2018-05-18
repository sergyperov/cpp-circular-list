#include "circular_list.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
circular_list<T>::circular_list() {
    length = 0;
}

template <typename T>
circular_list<T>::~circular_list() {
    clear();
}

/*
 Добавить в конец списка (то есть перед началом) объект item
 */
template <typename T>
void circular_list<T>::push_back(T item) {
    node<T>* new_node = new node<T>();
    //node<T>* new_node = (node<T>*)malloc(sizeof(node<T>));
    new_node->item = item;
    
    if (length == 0) {
        head = new_node;
        head->next = head;
        head->prev = head;
    } else {
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
    }
    
    length++;
}

/*
 Добавить в начало списка (то есть после конца) объект item
 */
template <typename T>
void circular_list<T>::push_front(T item) {
    push_back(item);
    head = head->prev;
}

template <typename T>
void circular_list<T>::insert_at_index(int index, T item) {
    if ((0 > index) || (index > length )) {
        throw std::out_of_range("Out of range");
    }
    
    node<T>* new_node = new node<T>();
    //node<T>* new_node = (node<T>*)malloc(sizeof(node<T>));
    new_node->item = item;
    
    if (length == 0) {
        head = new_node;
        head->next = head;
        head->prev = head;
    } else {
        if (index == 0) {
            push_front(item);
            return;
        } else if (index == length) {
            push_back(item);
            return;
        }
        
        node<T>* res_node = head;
        
        // разных обход в зависимости от местоположения элемента
        if (index <= length/2) {
            for (int i = 0; i < index; i++) {
                res_node = res_node->next;
            }
        } else {
            for (int i = length; i > index; i--) {
                res_node = res_node->prev;
            }
        }
        
        new_node->next = res_node;
        new_node->prev = res_node->prev;
        
        res_node->prev->next = new_node;
        res_node->prev = new_node;
    }
    
    length++;
}

template <typename T>
void circular_list<T>::pop_back() {
    if (length < 1) {
        throw std::out_of_range("Out of range");
    }
    
    node<T>* nnode = head->prev;
    
    if (length == 1) {
    } else if (length == 2) {
        head->prev = head;
        head->next = head;
    } else {
        head->prev->prev->next = head;
        head->prev = head->prev->prev;
    }
    
    delete nnode;
    
    length--;
}

template <typename T>
void circular_list<T>::pop_front() {
    if (length < 1) {
        throw std::out_of_range("Out of range");
    }
    
    node<T>* new_head = head->next;
    
    head->prev->next = head->next;
    head->next->prev = head->prev;
    
    delete head;
    head = new_head;
    
    length--;
}

template <typename T>
void circular_list<T>::pop_by_index(int index) {
    if ((0 > index) || (index >= length )) {
        throw std::out_of_range("Out of range");
    }
    
    if (index == 0) {
        pop_front();
        return;
    } else if (index == length-1) {
        pop_back();
        return;
    }
    
    node<T>* res_node = head;
    
    // разных обход в зависимости от местоположения элемента
    if (index <= length/2) {
        for (int i = 0; i < index; i++) {
            res_node = res_node->next;
        }
    } else {
        for (int i = length; i > index; i--) {
            res_node = res_node->prev;
        }
    }
    
    res_node->prev->next = res_node->next;
    res_node->next->prev = res_node->prev;
    delete res_node;

    length--;
}

template <typename T>
void circular_list<T>::clear() {
    while (length != 0) {
        pop_front();
    }
}

/*
 Добавить к текущему списку список new_list
 */
template <typename T>
void circular_list<T>::append(const circular_list<T> &new_list) {
    int list_length = new_list.get_length();
    for (int i = 0; i < list_length; i++) {
        T new_item = new_list.get_item(i);
        push_back(new_item);
    }
}

/*
 Обработать список методом reduce
 */
template <typename T>
template <typename U>U circular_list<T>::reduce(U (*reduce_function)(U,T), U initial_value) {
    if (length == 0) {
        return initial_value;
    }
    
    U current_result  = initial_value;
    
    bool loop_started;
    node<T>* i;
    for (i = head, loop_started = false; (i != head) || !loop_started; i = i->next, loop_started = true) {
        current_result = reduce_function(current_result, i->item);
    }
    
    return current_result;
}

/*
 Поменять местами элементы node_1 и node_2
 */
template <typename T>
void circular_list<T>::swap(node<T> *node_1, node<T> *node_2) {
    T tmp_item = node_1->item;
    node_1->item = node_2->item;
    node_2->item = tmp_item;
}

/*
 Сортировка списка по функции compare_function методом пузырька
 */
template <typename T>
void circular_list<T>::sort(bool (*compare_function)(T,T)) {
    if (length == 0) {
        return;
    }
    
    bool started_i = false;
    for (node<T>* i = head; (i != head) || !started_i; i = i->next) {
        started_i = true;
        bool started_j = false;
        for (node<T>* j = i; (j != head) || !started_j; j = j->next) {
            started_j = true;
            if (compare_function(i->item, j->item) == false) {
                swap(i, j);
            }
        }
    }
}

/*
 Получить длину списка
 */
template <typename T>
const int circular_list<T>::get_length() const {
    return length;
}

/*
 Получить узел (не сам элемент!) списка с идентификатором index
 */
template <typename T>
const node<T>* circular_list<T>::get_element(int index) const {
    if ((0 > index) || (index >= length )) {
        throw std::out_of_range("Out of range");
    }
    
    node<T>* res_node = head;
    
    // разных обход в зависимости от местоположения элемента
    if (index <= length/2) {
        for (int i = 0; i < index; i++) {
            res_node = res_node->next;
        }
    } else {
        for (int i = length; i > index; i--) {
            res_node = res_node->prev;
        }
    }
    
    return res_node;
}

template <typename T>
const T circular_list<T>::get_item(int index) const {
    const node<T>* res_node = get_element(index);
    
    return res_node->item;
}

// перегрузка операторов

template <typename T>
T circular_list<T>::operator[] (const int index) {
    return get_item(index);
}


