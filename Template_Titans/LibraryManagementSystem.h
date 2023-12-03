#include<iostream>
#include<string>
#include"CustomContainer.h"
#ifndef LIBRARYMANAGEMENTSYSTEM_H
#define LIBRARYMANAGEMENTSYSTEM_H



enum status
{
    available=0,
    borrowed=1
};
struct BookRecord
{
    string m_title;
    string m_author;
    string m_ISBN;
    string m_genre;
    status status_book;
    BookRecord(){
        m_title="";
        m_author="";
        m_ISBN="";
        m_genre="";
        status_book=available;
    }
    friend ostream &operator<<(ostream &COUT, const BookRecord &b);
    friend istream &operator>>(istream &CIN, BookRecord &b);
    bool operator>(const BookRecord &b1)
    {
        return m_title > b1.m_title;
    }
    bool operator<(const BookRecord &b1)
    {
        return m_title < b1.m_title;
    }
    bool operator==(const BookRecord &b1)
    {
        return (m_title == b1.m_title) ;
    }
    bool operator==(string key)
    {
        return (m_title == key) ;
    }
};
ostream &operator<<(ostream &COUT, const BookRecord &b)
{
    COUT << "\t\t~>Book Title = " << b.m_title << "\t\t |";
    COUT << "~>Book Author = " << b.m_author << endl;
    COUT << "\t\t~>Book ISBN = " << b.m_ISBN << "\t\t |";
    COUT << "~>Book Genre = " << b.m_genre << endl;
    COUT << "\t\t~>Book Status = ";
    if ((b.status_book == available))
    {
        COUT << "Available :)\n";
    }
    else
    {
        COUT << "Borrowed :(\n";
    }
    return COUT;
}
istream &operator>>(istream &CIN, BookRecord &b)
{

    string title, author, ISBN, genre;
    int stat_book = 0;
    cout << "\t\tEnter Book Title: ";

    getline(CIN, b.m_title);

    cout << "\t\tEnter Book Author: ";
    getline(CIN, b.m_author);

    cout << "\t\tEnter Book ISBN: ";
    getline(CIN, b.m_ISBN);

    cout << "\t\tEnter Book Genre: ";
    getline(CIN, b.m_genre);

    cout << "\t\tEnter Book Status (1->Borrowed , 0->Available): ";
    cin >> stat_book;
    if (stat_book == borrowed)
    {
        b.status_book = borrowed;
    }
    else
    {
        b.status_book = available;
    }
    return CIN;
}
template <typename T>
class LibraryManagementSystem
{
private:
    CustomContainer<BookRecord, LinkedList<BookRecord>> books;
    size_t n_books;



public:
    LibraryManagementSystem() : n_books(0)
    {
    }
    ~LibraryManagementSystem()
    {
    }
    void add_book()
    {
        BookRecord newbook;
        cin >> newbook;
        cin.ignore();
        books.Insert_back(newbook);
        cout<<"\n\t\t\x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \n\n";

        n_books++;

    }
    void remove_book(BookRecord del_book)
    {
        if(n_books<1){
            cout<<"\n\t\tNo Books In Library To remove!!\n";
            return ;
        }
        if(books.remove(del_book)){
            cout<<"\n\t\tThe Book was Removed successfully\x02\n";
            n_books--;

        }else{
            cout<<"\n\t\tThe Book was Not Exist to Remove!!!\n";
        }
        cout<<"\t\t\x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \n\n";
    }
    void search_book(BookRecord key)
    {
        if(n_books<1){
            cout<<"\n\t\t=>The Library Is Empty!!\n";
            return ;
        }
        if (books.Find(key))
            cout << "\n\t\t=>Founded\x02 .\n" << key << endl;
        else
            cout << "\n\t\t=>Sorry, Book was Not Founded :(\n";
        cout<<"\t\t\x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04\x04 \x04 \x04 \x04 \n";
    }
    void sorting_book()
    {
        if(n_books<1){
            cout<<"\t\tThe Library Is Empty!!\n";
            return ;
        }
        books.sort();
    }
    void book_borrowing()
    {
        if(n_books==0){
            cout<<"\n\t\t=>No Books Exist To Borrow!!\n";
            return ;
        }
        BookRecord b;
        cin>>b;
        bool is_borrow=false;
        for(size_t i=1;i<=n_books;i++){
            if(b==books[i]){
                books[i].status_book=borrowed;
                is_borrow=true;
                break;
            }
        }
        if(is_borrow){
            cout<<"\t\tThe Book is Borroweded Successfully\x02 \n";
        }else
            cout<<"\t\tThe Book Not Exist!!!\n";
        cout<<"\t\t\x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \n";
    }
    void book_statistics()
    {
        size_t n_borrowded=0,n_available=0;
        for(size_t i=1;i<=n_books;i++){
            if(books[i].status_book==available){
                n_available++;
            }else{
                n_borrowded++;
            }
        }
        cout << "\t\t1-The Total Number of Books = " << n_books << endl;
        cout << "\t\t2-The Number of Borrowed Books = " << n_borrowded << endl;
        cout << "\t\t3-The Number of Available Books = " << n_available << endl;
        cout << "\t\t=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n\n\n";
    }
    void book_catalog()
    {
        if(n_books==0){
            cout<<"\n\t=>No Books In Catalog , Catalog is Empty!!";
            return ;
        }

        for (size_t i = 1; i <= n_books; i++)
        {
            cout << "\t\t\x04 The Book Number : " << i << endl;
            cout << books[i] << endl;
            cout << "\t\t=============================\n\n\n";
        }
    }
};

#endif // LIBRARYMANAGEMENTSYSTEM_H
