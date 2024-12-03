//* 2. Open/Closed Principle -> Open for Extension and Closed for Modification 

#include<bits/stdc++.h>
using namespace std;


class Marker {
    public: 
        string name;
        string color;
        int year;
        int price;

        void Marker(string name, string color, int year, int price) {
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

        void Invoice(Marker marker, int quantity) {
            this -> marker = marker;
            this -> quantity = quantity;
        }

        //todo -> First reason to change 
        int calculateTotal() {
            int price = ((marker.price) * (this -> quantity));
            return price;
        }
};

class InvoiceDao : public Invoice {
    private: 
        Invoice invoice;

    public: 
        void InvoiceDao(Invoice invoice) {
            this -> invoice = invoice;
        }

        void saveToDataBase() {
            //* Save into the DB 
        }
};  



//* We are trying to modify this class so we can say that we are not following open/close principle 
class InvoiceDao : public Invoice {
    private: 
        Invoice invoice;

    public: 
        void InvoiceDao(Invoice invoice) {
            this -> invoice = invoice;
        }

        void saveToDataBase() {
            //* Save into the DB 
        }

        void saveToFile(string fileName) {
            //* Save invoice in the file with the given name 
        }
};


//* What we can do here is we can entend Dao Class 
class InvoiceDAO : public Invoice {
    public:
        void saveInvoice(Invoice invoice) {
            //* saving the invoice
        }
};


class DataBaseInvoiceDAO : public InvoiceDAO {
    public:
        void saveInvoiceToDB(Invoice invoice) {
            //* saving the invoice
        }
};


class FileInvoiceDAO : public InvoiceDao {
    public:
        void saveInvoiceToFile(Invoice invoice) {
            //* saving the invoice
        }  
};



// The Open/Closed Principle (OCP) is one of the SOLID principles of object-oriented design. It states that software entities (classes, modules, functions, etc.) should be open for extension but closed for modification. This means you should be able to add new functionality to a class or module without changing its existing code, thus reducing the risk of introducing bugs or breaking existing functionality.

// Real-life Example: Payment System
// Imagine you're building a payment processing system for an e-commerce platform. Initially, the system supports only one payment method—credit card. Over time, you want to extend it to support multiple payment methods, like PayPal and Bank Transfer. Using the Open/Closed Principle, you'd design the system in such a way that adding new payment methods doesn't require changing the core payment processing code. Instead, you'd extend the system by adding new components.