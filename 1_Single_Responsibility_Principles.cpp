//* The first 5 principles of Object Oriented Design 


//? 1. Single Responsibility Principles -> A class should have only one reason to change

#include<bits/stdc++.h>
using namespace std;

class Marker {
    public: 
        string name;
        string color;
        int year;
        int price;

        Marker(string name, string color, int year, int price) {
            this -> name = name;
            this -> color = color;
            this -> year = year;
            this -> price = price;
        }
};

class Invoice : public Marker {
    public : 
        Marker marker;
        int quantity;

        Invoice(Marker marker, int quantity) {
            this -> marker = marker;
            this -> quantity = quantity;
        }

        //todo -> First reason to change 
        int calculateTotal() {
            int price = ((marker.price) * (this -> quantity));
            return price;
        }

        //todo -> Second reason to change
        void printInvoice() {
            //* print the invoice
        }

        //todo -> Third reason to change
        void saveToDataBase() {
            //* save to database
        }
};

//* Basically we need to make a class in such a manner that it should have only one reason to change
//* Basically each class has single responsibility 



class InvoiceDao : public Invoice {
    private: 
        Invoice invoice;

    public: 
        InvoiceDao(Invoice invoice) {
            this -> invoice = invoice;
        }

        void saveToDataBase() {
            //* Save into the DB 
        }
};


class InvoicePrinter : public Invoice {
    private:
        Invoice invoice;

    public:
        InvoicePrinter(Invoice invoice) {
            this -> invoice = invoice;
        }

        void printInvoice() {
            //* Print the invoice 
        }
};



//? Advantages of following these Principles :
//* Help us to write better code :
//todo -> Avoid duplicate code 
//todo -> Easy to maintain 
//todo -> Easy to understand
//todo -> Flexible software 
//todo -> Reduce complexity 




//* Real Life Eample -> Let's suppose these is a iPhone case with a bottle opener behind it
//? But let's think about it -> Why would anyone ever need a bottle opener in an iPhone case
//* So if you think about it, you will be notice that it will be breaking the 1st SOLID Principle i.e. 
//? Single Responsibility Principle 
//* Because personally if i was buying an iPhone case i will never imagine a need to have a bottle opener in there
//? In order to make that implements SINGLE RESPONSIBILITY PRINCIPLE an iPhone case should just be an iPhone case and a bottle opener should be a bottle opener 