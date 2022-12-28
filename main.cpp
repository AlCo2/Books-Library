#include <iostream>
#include "book.h"
#include <iomanip>
using namespace std;

bool start = true;

void showBooks();
void editBook();

int main()
{
    int choice;
    while(start){
        cout << "1-add a Book\n2-edit a book\n3-show All Books\n4-Stop The App\n:";
        cin >> choice;
        switch(choice){
    case 1:
        {
            string name;
            string author;
            int price;
            cout << "Book Name: ";
            cin >> name;
            cout << "author: ";
            cin >> author;
            cout << "price: ";
            cin >> price;
            Book book = Book(name, author, price);
            book.addBook();
            cout << book.getName() <<" added to the Books list" << endl;
        }
        break;
    case 2:
        {
            showBooks();
            editBook();
        }
        break;
    case 3:
        showBooks();
        break;
    case 4:
        start = false;
        break;
    default:
        cout << "error in choice!" << endl;
        }
    }

    return 0;
}


void showBooks(){
    ifstream file;
    file.open("bookslist.txt");
    int id = 1;
    string name, author;
    int prix;
    cout <<" ______________________________________________________________________________"<< endl;
    cout << "| Book:"<<setw(30) << "| Author:" <<setw(30) << "| Price:"<< endl;
    while(file >> name >> author >> prix){
        Book book = Book(name, author, prix);
        cout <<"| " <<id << "-";
        book.introBook();
        id++;
    }
    cout <<"-------------------------------------------------------------------------------" << endl;
}

void editBook(){
    ifstream file;
    ofstream writefile;
    file.open("bookslist.txt");
    writefile.open("newbookslist.txt");
    int id = 1;
    string name;
    string author;
    int prix;
    string newname;
    string newauthor;
    int newprice;
    int line;
    cout << "book number: ";
    cin >> line;
    cout << "new name: ";
    cin >> newname;
    cout << "new author: ";
    cin >> newauthor;
    cout << "new prix: ";
    cin >> newprice;
    while(file >> name >> author >> prix){
        Book book = Book(name, author, prix);
        if(line==id){
            book.editBook(newname, newauthor, newprice);
            writefile << book.getName()<< " " << book.getAuthor() << " " << book.getPrix() << endl;
        }else{
            writefile << book.getName()<< " " << book.getAuthor() << " " << book.getPrix() << endl;
        }
        id++;
    }
    writefile.close();
    file.close();
    remove("bookslist.txt");
    rename("newbookslist.txt", "bookslist.txt");
}

