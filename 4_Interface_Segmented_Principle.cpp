//? 4. Interface Segmented Principle -> Interfaces should be such, that client should not implement unnecessary functions they do not need 
//* A client should never be forced to implement an interface that it doesn’t use, or clients shouldn’t be forced to depend on methods they do not use.
//* Let's understand this with an example 

#include<bits/stdc++.h>
using namespace std;

class RestaurantEmployee {
    public:
        void washDishes();
        void serveCustomers();
        void cookFood();
};

class Waiter : public RestaurantEmployee {
    public:
        void washDishes() {
            //* not my job
        }

        void serveCustomers() {
            //* Yeah, this is my job 
        }

        void cookFood() {
            //* not my job 
        }
};

//* Basically we need to divide the interfaces in small pieces so that there is no need to implement small functions by the client 

class WaiterInterface {
    public:
        void serveCustomers();
        void takeOrder();
};

class Chefinterface {
    public:
        void cookFood();
        void decideMenu();
};

//* Now if I am implementing Waiter class then Waiter class can only extends WaiterInterface
class Waiters : public WaiterInterface {
    public: 
        void serveCustomers() {
            cout << "Serving the customer" << endl;
        }

        void takeOrder() {
            cout << "Take Order" << endl;
        }
};
//* Basically jo bhi apn client bana rahe hai naa, Jaise iss case mein client(Waiters) hoga aur apn ye chahaate hai ki uss client ko koii unnecessary implementation naa krrna pade jaise ki (decide menu waiter kaa kaam nahi hai toh usko woh function implement naa krrna pade)
