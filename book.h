#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include <fstream>
#include <iomanip>
using namespace std;

class Book{
private:
    string name;
    string author;
    int prix;
public:
    Book(){}
    Book(string name, string author,int prix){
        this->name = name;
        this->author = author;
        this-> prix = prix;
    }
    //set and get:

    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }
    void setAuthor(string auhor){
        this->author = author;
    }
    string getAuthor(){
        return author;
    }
    void setPrix(int prix){
        this->prix = prix;
    }
    int getPrix(){
        return prix;
    }

    //function:
    void addBook(){
        ofstream file;
        file.open("bookslist.txt", ios::app);
        file << name << " " << author << " " << prix << endl;
        file.close();
    }
    void introBook(){
        cout << name << setw(8) << "|"<< setw(8)<< author << setw(8) << "|"<< setw(8) << prix <<"  |"<< endl;
    }
    void editBook(string name, string author, int prix){
        this->name = name;
        this->author = author;
        this->prix = prix;
    }
};





#endif // BOOK_H_INCLUDED
