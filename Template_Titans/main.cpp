#include <iostream>
#include<iomanip>
#include<stdlib.h>
#include<windows.h>
#include"LibraryManagementSystem.h"
using namespace std;
HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
LibraryManagementSystem<string> library;
void banner(string message) {

  cout <<"\t\t" <<setfill('-') << setw(message.length() + 4) << "-" << endl;
  cout << "\t\t"<<"| " << message << " |" << std::endl;
  cout << "\t\t"<<setfill('-') << setw(message.length() + 4) << "-" << endl;
}
void main_menu(){
    cout<<"\n\t\t \x04 Main Menu:- \n\n";
    cout<<"\t\t\t [1]- Add New Book In Library.\n";
    cout<<"\t\t\t [2]- Remove Book From Library.\n";
    cout<<"\t\t\t [3]- Search About Book In Library.\n";
    cout<<"\t\t\t [4]- Borrow Book From Library.\n";
    cout<<"\t\t\t [5]- Sorting Books In Library.\n";
    cout<<"\t\t\t [6]- Books Statistics.\n";
    cout<<"\t\t\t [7]- Books Catalog For Displaying All Books In Library.\n";
    cout<<"\t\t\t [0]- Exit.\n\n";

}
void Book_catalog(){
    system("cls");
    cout<<"\n";
    banner("Books Catalog \x02 \x02");
    library.book_catalog();
}
void add_book(){

    cout<<"\n";
    banner("Enter Book Details To Add in library");
    library.add_book();
}
void remove_book(){

    banner("Enter Book Details to remove from Library");
    BookRecord del_book;
    cin>>del_book;
    library.remove_book(del_book);
}
void search_book(){
    system("cls");
    cout<<endl;
    banner("Enter Book Title To Search About it in Library ");
    BookRecord searched_book;
    cin>>searched_book;
    library.search_book(searched_book);
}
void sorting_books(){
    library.sorting_book();
    cout<<"\n\t\tTne Books Sorted Successfully \x02\n\n";
}
void book_statistics(){
    cout<<endl;
    banner("Books Statistics");
    library.book_statistics();
}
void book_borrow(){
    cout<<endl;
    banner("Enter Info Book To Borrow :-");
    library.book_borrowing();
}


int main()
{
    SetConsoleTextAttribute(cout_handle,3);
    int choice;
    while(true){
        system("cls");
        banner("Welcome To Library Management System \x02");
        main_menu();
        cout<<"\t\t=>Enter Your Choice : ";
        cin>>choice;
        cin.ignore();
        system("cls");
        switch(choice)
        {
        case 1:
            {
                add_book();
                Sleep(3000);
                break;
            }
        case 2:
            {
                remove_book();
                Sleep(3000);
                break;
            }
        case 3:
            {
                search_book();
                Sleep(3000);
                break;
            }
        case 4:
            {
                book_borrow();
                Sleep(3000);
                break;
            }
        case 5:
            {
                sorting_books();
                Sleep(3000);
                break;
            }
        case 6:
            {
                book_statistics();
                Sleep(3000);
                break;
            }
        case 7:
            {
                Book_catalog();
                Sleep(3000);
                break;
            }
        case 0:
            {
                system("cls");
                cout<<"\n";
                banner("Thank You To Use My Library App \x04\x04");
                exit(0);
            }
        default:
            {
                system("cls");
                cout<<"\n\n";
                banner("\x04 Invalid input Try Again!!!");
                Sleep(3000);
            }
        }
    }
    return 0;
}
