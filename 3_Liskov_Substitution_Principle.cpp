//todo 3. Liskov Substitution Principle -> If class B is subtype of class A, then we should be able to replace object of A with B without breaking the behaviour of the program.
//* Basically I have class A and there is a child class of A which is class B then we should be able to replace the object of A with B, without breaking the behaviour of the program.


#include<bits/stdc++.h>
using namespace std;

class Bike {
    public:
        void turnOnEngine();
        void accelerate();
};


class MotorCycle : public Bike {
    public:
        bool isEngineOn;
        int speed;

        void turnOnEngine() {
            //* turn on the engine
            isEngineOn = true;
        }


        void accelerate() {
            //* increse the speed 
            speed += 10;
        }
};


class Bicycle : public Bike {
    public:
        void turnOnEngine() {
            cout << "Error:: There is no Engine" << endl;
        }
        //* So this child class is not able to entend parent class functionality so it is breaking the 3rd rule, basically sub-class should entend the capability of parent class not narrow it down.

        void accelerate() {

        }
};


//? Real Life Example -> Let's suppose we are making a sweet desert and unfortunately we are out of sugar 
//* Now if we have liquid sugar or cane sugar we can offcourse use them as a replacement 
//? But can we replace them with salt....?? Offcourse not 
//* And that is what liskov principle is 


//? 2nd example is let's suppose you are planning a trip with your friends and in total you are 7 peoples and 
//* try to take a car on rent for 7 people but the car rental service doen not have 7 seater car so they can 
//? easily substitute you a 8 seater car or any other car that will take 7 people easily 
//* but never substitute a 5 seater car 