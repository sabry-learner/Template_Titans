#include<iostream>
#include"LinkedList.h"
using namespace std;
#ifndef CUSTOMCONTAINER_H
#define CUSTOMCONTAINER_H


template <typename T, typename l = LinkedList<T>>
class CustomContainer
{
private:
    size_t Size;
    LinkedList<T> List;

public:
    CustomContainer() : Size(0)
    {
    }
    ~CustomContainer()
    {
    }
    void Insert_begin(T val)
    {
        List.Insert_front(val);
        Size++;
    }
    void Insert_back(T val)
    {
        List.Push_back(val);
        Size++;
    }
    void Insert_at(T val, size_t i)
    {
        List.Insert_at(val, i);
        Size++;
    }
    bool remove(T item)
    {
        if(List.remove_element(item)){
            Size--;
            return true;
        }
        return false;
    }
    void remove_begin()
    {
        List.remove_front();
        Size--;
    }
    bool Find(T val)
    {
        return List.Find(val);
    }
    void sort()
    {
        List.sorted();
    }
    void reverse()
    {
        List.reverse();
    }
    void print()
    {
        List.print();
    }
    T &operator[](size_t i)
    {
        return List[i];
    }
    class Iterator
    {
    private:
        Node<T> *current{};

    public:
        Iterator(Node<T> *cur)
        {
            current = cur;
        }

        Node<T> *Prev()
        {

            return List.previos_node(current);
        }
        T get_data() const
        {
            return current->data;
        }
        Node<T> *Next()
        {

            return current->Next;
        }

        Node<T> *Begin()
        {
            return List[1];
        }
        Node<T> *End()
        {
            return List[Size];
        }
    };
};
#endif // CUSTOMCONTAINER_H
