#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
    public:



        T data;
        Node<T> *Next{};
        Node(T d) ;
};

#endif // NODE_H


template<class T>
Node<T>::Node(T d) : data(d)
{
    Next = nullptr;
}
