#include<iostream>
#include<assert.h>

using namespace std;
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
struct Node
{
    T data;
    Node<T> *Next{};
    Node(T d) : data(d)
    {
        Next = nullptr;
    }
    ~Node()
    {
        // cout << data;
        // cout << " was deleted:( " << this << endl;
    }
};
template <typename T>
class LinkedList
{
private:
    Node<T> *Head;
    Node<T> *Tail;
    size_t length;

public:
    LinkedList() : length(0)
    {
        Head = nullptr;
        Tail = nullptr;
    }
    ~LinkedList()
    {
        while (Head)
        {
            Node<T> *current = Head->Next;
            delete Head;
            Head = current;
        }
    }
    T &operator[](size_t i)
    {
        assert(i >= 1 && i <= length);
        size_t c = 1;
        for (Node<T> *cur = Head; c <= length; cur = cur->Next, c++)
        {
            if (c == i)
            {
                return cur->data;
            }
        }
    }
    Node<T> *Find(T val)
    {
        Node<T> *cur = Head;
        while (cur)
        {
            if (cur->data == val)
            {
                return cur;
            }
            cur = cur->Next;
        }
        return nullptr;
    }

    Node<T> *get_nth(size_t n)
    {
        assert(n >= 1 && n <= length);
        size_t cnt = 0;
        for (Node<T> *cur = Head; cur; cur = cur->Next)
            if (++cnt == n)
                return cur;

        return nullptr;
    }
    Node<T> *previos_node(Node<T> *current)
    {
        Node<T> *temp = Head;
        while (temp)
        {
            if (temp->Next)
            {
                if (temp->Next->data == current->data)
                {
                    return temp;
                }
            }
            temp = temp->Next;
        }
    }
    bool isEmpty()
    {
        return Head == nullptr;
    }
    void Push_back(T val)
    {
        Node<T> *newnode = new Node<T>(val);
        if (isEmpty())
        {
            Head = Tail = newnode;
            Tail->Next = nullptr;
        }
        else
        {
            Tail->Next = newnode;
            Tail = newnode;
            Tail->Next = nullptr;
        }
        length++;
    }
    void Insert_at(T val, size_t i)
    {
        assert(i >= 1 && i <= length);
        if (i == 1)
        {
            Insert_front(val);
        }
        else
        {
            Node<T> *prev = get_nth(i - 1);
            Node<T> *newnode = new Node<T>(val);
            newnode->Next = prev->Next;
            prev->Next = newnode;
            length++;
        }
    }
    void Insert_front(T val)
    {
        Node<T> *newnode = new Node<T>(val);
        if (isEmpty())
        {
            Head = Tail = newnode;
            Tail->Next = nullptr;
        }
        else
        {
            newnode->Next = Head;
            Head = newnode;
        }
        length++;
    }
    void print()
    {
        for (Node<T> *cur = Head; cur; cur = cur->Next)
            cout << cur->data << " ";

        cout << endl;
    }
    void remove_front()
    {
        assert(length);
        Node<T> *cur = Head->Next;
        --length;
        delete Head;
        Head = cur;

        if (length <= 1)
            Tail = Head;
    }


    bool remove_element(T val){
        if(isEmpty()){
            return false;
        }

        if(Head->data==val){
            remove_front();
        }else{
            Node<T>* cur=Head->Next;
            Node<T>* prv=Head;
            while(cur){
                if(cur->data==val)
                    break;
                prv=cur;
                cur=cur->Next;
            }
            if(cur==nullptr)
                return false;
            else{
                prv->Next = cur->Next;
                if(Tail==cur)
                    Tail=prv;
                delete cur;
                length--;
                return true;
            }
        }

    }
    void reverse()
    {
        if (length <= 1)
            return;

        Tail = Head;
        Node<T> *prv = Head;
        Head = Head->Next;
        while (Head)
        {

            Node<T> *next = Head->Next;
            Head->Next = prv;

            prv = Head;
            Head = next;
        }

        Head = prv;
        Tail->Next = nullptr;
    }

    void sorted()
    {
        if(length<=1)
        {
            return ;
        }
        for (Node<T> *cur = Head; cur->Next; cur = cur->Next)
        {
            for (Node<T> *temp = cur->Next; temp; temp = temp->Next)
            {

                if (cur->data > temp->data)
                    swap(cur->data, temp->data);

            }
        }
    }
};

#endif // LINKEDLIST_H
