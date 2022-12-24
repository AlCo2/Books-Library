#include <iostream>
#include "book.h"
#include <iomanip>
using namespace std;

void showBooks();
void editBook();
int main()
{
    showBooks();
    return 0;
}


void showBooks(){
    ifstream file;
    file.open("bookslist.txt");
    int id = 1;
    string name, author;
    int prix;
    cout <<"___________________________________________"<< endl;
    cout << "|   Book:"<<setw(8) << "|"<< setw(8) << " Author:" <<setw(8) << "|"<< setw(8)<<" Price:"<< setw(3) << "|"<< endl;
    cout << "--------------------------------------------" << endl;
    while(file >> name >> author >> prix){
        Book book = Book(name, author, prix);
        cout <<"| " <<id << "-";
        book.introBook();
        id++;
    }
    cout <<"___________________________________________";
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
        if(line==id){
            writefile << newname << " " << newauthor << " " << newprice << endl;
        }else{
            writefile << name<< " " << author << " " << prix << endl;
        }
        id++;
    }
    writefile.close();
    file.close();
    remove("bookslist.txt");
    rename("newbookslist.txt", "bookslist.txt");
}

