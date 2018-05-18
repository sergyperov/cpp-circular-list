#ifndef circular_list_hpp
#define circular_list_hpp

#include <stdio.h>
#include <stdlib.h>

/*
 Структура элемента, использующаяся в реализации списка
 */
template <typename T>
struct node {
    T item;
    node* next;
    node* prev;
};

/*
 Основной класс цикличного списка
 Предназначен только для изменения списка
 */
template <typename T>
class circular_list {
private:
    node<T>* head;
    int length;
    
    void swap(node<T> *node_1, node<T> *node_2);
    const node<T>* get_element(int index) const;
    
    void pop_back();
    void pop_front();
    
public:
    circular_list();
    ~circular_list();
    
    const T get_item(int index) const;
    
    void push_back(T item);
    void push_front(T item);
    void insert_at_index(int index, T item);
    
    void pop_by_index(int index);
    
    void clear();
    
    void append(const circular_list<T> &new_list);
    void sort(bool (*compare_function)(T,T));
    template <typename U> U reduce(U (*reduce_function)(U,T), U initial_value);
    
    const int get_length() const;
    T operator[] (const int index);
};

#include "circular_list.cpp"

#endif /* circular_list_hpp */
