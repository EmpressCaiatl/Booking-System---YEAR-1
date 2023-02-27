
/*  Isabella Maffeo Assignment 1
    September 12, 2020  */

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<vector>

using namespace std;

//Passenger class. All passengers will be stored in an array in main
class Passenger
{
public:
    void setName(string first, string last); //(first name + last name)
    string getName() const; //Returns name
    void setPassengerType(string); //Sets Veteran or Nonveteran from the Passenger choice
    string getPassengerType(); //Gets Veteran or Nonveteran from the Passenger choice

private:
    string Name; //Passenger's name (first + last)
    string passengerType; //Variable to store whether the person is a Veteran or Nonveteran. You can substitute this with an enum if you prefer
};

void Passenger::setName(string first, string last) {

    Name = first + " " + last;
}

string Passenger::getName() const {

    return Name;

}

void Passenger::setPassengerType(string status) {

    passengerType = status;
}

string Passenger::getPassengerType() {

    return passengerType;

}

//Rocket class for actual flights
class Rocket
{
public:

    void setSeats(int); //from Rocket admin
    int getSeats() const;     //for Passenger reference

    void setTicketPrice(int); //from Rocket admin
    int getTicketPrice() const; //for Passenger reference

    int checkRocketAvailability(); //Check Rocket availability for the Passengers selection. Tells if there are seats left.
    void setRocketType(string); //Sets Rocket type (cold-gas, chemical, thermoelectric, hybrid)
    string getRocketType();

    void purchaseTicket(int); //reserve seats for all selected Passengers
    int getBookedSeats() const; // show the reserved/booked seats of each Rocket

    void setVelocity(double); //set velocity
    double getVelocity() const; //get velocity

    void setFuelCapacity(int); //set fuel capacity

    void setRocketSpecs(string, double, double); // set Rocket specifications
    void printRocketSpecs() const; // get Rocket specifications

    void setTimeReq(double); //destination reaching time- travel distance/velocity; 						travelDistance=238855
    double getTimeReq() const;

    Rocket(); //constructor for initializing bookedSeat=0 (private member variable) 

private:
    int ticketPrice; //Price per ticket for this Rocket
    string rocketType; //Rocket's name
    int seats; //Total seats that the Rocket has. Should only be set once
    double timereq; //Time it takes for the Rocket to fly
    int bookedSeat; //How many seats have been booked

    //Rocket specifications (metadata, not all of these will be used in calculations!)
    string propellant;  //Fuel type
    double acceleration; //Acceleration (do not use this in calculations)
    double velocity; //Velocity. This will be used to cover distance as the rocket flies to the moon.
    double fuelCapacity; //Maximum fuel that the rocket holds (Don't worry about checking if you are running out of fuel)
    double thrust; //Thrust that the rocket has
};

void Rocket::setSeats(int seatS) {
    seats = seatS;
}

int Rocket::getSeats() const {

    return seats;
}


void Rocket::setTicketPrice(int price) {

    ticketPrice = price;
}

int Rocket::getTicketPrice() const {

    return ticketPrice;

}

//this function is for checking how many seats are available on the Rocket
int Rocket::checkRocketAvailability() {
    
    int nothing = 0;

    return nothing;

    /* I do not end up using this function, rather I use the getseats to be the availabilty checker.
       I feel this function would be redundant with my approach 
    */
}

void Rocket::setRocketType(string rName) {

    rocketType = rName;

}

string Rocket::getRocketType() {

    return rocketType;

}

//this function sets the booked seats to the amount of tickets purchased and subtracts the booked seats from availability
void Rocket::purchaseTicket(int bookedT) {

    bookedSeat = bookedT;
    seats = seats - bookedSeat;
    
}

int Rocket::getBookedSeats() const {

    return bookedSeat;
}

void Rocket::setVelocity(double rocketV) {

    velocity = rocketV;

}

double Rocket::getVelocity() const {

    return velocity;
}

void Rocket::setFuelCapacity(int fCap) {

    fuelCapacity = fCap;

}

void Rocket::setRocketSpecs(string prop, double accel, double thrusT) {

    propellant = prop;
    acceleration = accel;
    thrust = thrusT;

}

void Rocket::setTimeReq(double timeT) {

    timereq = timeT;
}

//travelDistance = 238855

double Rocket::getTimeReq() const {

    return timereq;

}

class Menu
{
public:
    Menu(string); //constructor for welcome message
    int showRocketMenu( vector<Rocket> ); //Displays the rocket menu and gets the choice from the user, then returns it. Shows the available rockets only.
private:
    int choice;
};

//displays purchasing menu for user and reads in their choices, also checks that read in is good
int Menu::showRocketMenu( vector<Rocket> object) {

    //for user menu choice
    int userChoice = 0;

    cout << "Status of seats availability" << endl;

    //displays rockets with available seats
    for (int i = 0; i < object.size(); i++) {

        cout << object[i].getRocketType() << " Rocket is available with : " << object[i].getSeats() << " seats open" << endl;
    }

    cout << endl;
    cout << "\t Rocket options are :" << endl;

    //displays rockets with price
    for (int j = 0; j < object.size(); j++) {

        cout << "\t" << j + 1 << ". " << object[j].getRocketType() << " Rocket and the ticket price is $" << object[j].getTicketPrice() << endl;
    }

    cout << endl;

    cout << "Enter your choice" << endl;

    bool readIn = true;

    //read in check
    while (readIn) {

        cin >> userChoice;

        //checks to see if user put in an invalid option that is not an INT
        if (cin.fail()) {

            cin.clear();
            cin.ignore('\n');
            cout << "Incorrect selection. Try again!" << endl;
            readIn = true;
        }
        else {
            readIn = false;

            //checks that the user picked a selection with the right bounds
            if (userChoice < 1 || userChoice > 4) {

                cout << "Incorrect selection. Try Again!" << endl;

                readIn = true;
            }
            else {

                readIn = false;

                //checks to see if user picked a fully booked rocket
                if (object[userChoice-1].getSeats() == 0) {

                    cout << "Sorry. There is no available seats on the " << object[userChoice-1].getRocketType() << " Rocket. Please try again." << endl;

                    readIn = true;
                }
                else {
                    readIn = false;
                }
            }
        }
    }

    return userChoice;


}

Rocket::Rocket()
{
    bookedSeat = 0;
}

//Prints the Rocket's Specs
void Rocket::printRocketSpecs() const
{
    cout << "Your Rocket Specs" << endl;
    cout << "Propellant Type: " << propellant << endl;
    cout << "Acceleration: " << acceleration << " m/s^2" << endl;
    cout << "Thrust: " << thrust << " Newtons" << endl;
    cout << "Fuel Capacity: " << fuelCapacity << " gallons" << endl;
    cout << "Velocity: " << velocity << " mph" << endl << endl;
}

//#########Menu constructor. Prints a start message header#########
Menu::Menu(string msg)
{
    cout << endl << endl;
    cout << "********************************" << endl;
    cout << msg << endl;
    cout << "********************************" << endl << endl;
}

const double veteranDiscount = 0.9;
const double travelDistance = 238855; // distance from earth to moon

int main()
{
    vector<Rocket> rocketInfo; //viector for displaying rocket info

    double totalprice; //price with no discount
    double topay; //final price after discount
    int choice; //choice selection from Rocket menu
    int seaT; //selection of number of seats- basically to set seats from admin
    char ch; // for yes/no option to get more tickets
    double remainingDistance; //to store the remaining distance

   //Creating Objects of Rocket class
    Rocket Obj1;
    Rocket Obj2;
    Rocket Obj3;
    Rocket Obj4;
    vector<Passenger> passengers; //Array for Passengers (optional)

    string fname, lname;    //first name last name
    int ptype = 0; //variable for passenger type vet/nonvet
    string passT;  //for setting ptype variable to string
    double time;   //variable for time calculation

    Menu menu("Welcome Admin- Set seats to \n YOU CAN FLY TO SPACE");
    
    cout << "Enter number of seats in Cold-Gas Rocket" << endl;
    cin >> seaT;
    Obj1.setSeats(seaT);

    cout << "Enter number of seats in Chemical Rocket" << endl;
    cin >> seaT;
    Obj2.setSeats(seaT);

    cout << "Enter number of seats in Thermoelectric Rocket" << endl;
    cin >> seaT;
    Obj3.setSeats(seaT);

    cout << "Enter number of seats in Hybrid Rocket" << endl;
    cin >> seaT;
    Obj4.setSeats(seaT);

    //Initializing Rockets
    Obj1.setRocketType("Cold-Gas");
    Obj2.setRocketType("Chemical");
    Obj3.setRocketType("Thermoelectric");
    Obj4.setRocketType("Hybrid");

    Obj1.setTicketPrice(10000);
    Obj2.setTicketPrice(12000);
    Obj3.setTicketPrice(15000);
    Obj4.setTicketPrice(16000);

    Obj1.setFuelCapacity(773000);
    Obj2.setFuelCapacity(759320);
    Obj3.setFuelCapacity(657200);
    Obj4.setFuelCapacity(521400);

    Obj1.setRocketSpecs("Hydrogren", 12.9, 12.1);
    Obj2.setRocketSpecs("Hypergolic", 12.1, 12.2);
    Obj3.setRocketSpecs("Hydrazine", 38.1, 15.1);
    Obj4.setRocketSpecs("Oxidizers", 90.2,35.1);

    Obj1.setVelocity(25000);
    Obj2.setVelocity(21000);
    Obj3.setVelocity(23000);
    Obj4.setVelocity(28000);

    //pushes information back into vector for menu display
    rocketInfo.push_back(Obj1);
    rocketInfo.push_back(Obj2);
    rocketInfo.push_back(Obj3);
    rocketInfo.push_back(Obj4);

    //main menu
    cout << endl << endl;
    cout << "********************************" << endl;
    cout << "Welcome to YOU CAN FLY TO SPACE"<< endl;
    cout << "********************************" << endl << endl;

    int ticketSelection = 0; //amount of tickets the user wants to purchase/book

    Passenger passTemp;

    //purchasing loop
    do {
        
        int passCount = 1;            // the amount of passengers the user is booking

        choice = menu.showRocketMenu(rocketInfo);

        cout << "You selected the " << rocketInfo[choice-1].getRocketType() << " Rocket and the price is $" << rocketInfo[choice-1].getTicketPrice() << endl;
        cout << "Checking seat availabilty..." << endl;
        cout << endl;

        cout << "Available seats are: " << rocketInfo[choice-1].getSeats() << endl;
        cout << "Enter number of tickets you want to purchase: between the range of 1 - " << rocketInfo[choice-1].getSeats() << endl;
        
        bool readClear = true;   //variable for cin check and clear

        //purchasing ticket amount
        while (readClear) {

            cin >> ticketSelection;

            //checks to see if user put in an invalid option that is not an INT
            if (cin.fail()) {

                cin.clear();
                cin.ignore('\n');
                cout << "Incorrect selection. Try again!" << endl;
                readClear = true;
            }
            else {
                readClear = false;

                //checks that the user picked a selection with the right bounds
                if ( ticketSelection > rocketInfo[choice-1].getSeats() || ticketSelection < 1 ) {

                    cout << "Number of seats entered is not within the range of available seats..." << endl;

                    readClear = true;
                }
                else {

                    readClear = false;

                }
            }
        }

        bool passClear = true;  // variable for amount of passenger info input loop 

        //passenger booking loop
        while (passClear) {

            cout << "Enter details of the passenger " << passCount << endl;
            cout << endl;

            cout << "Enter your First Name: " << endl;
            cin >> fname;

            cout << endl;

            cout << "Enter your Last Name: " << endl;
            cin >> lname;

            passTemp.setName(fname, lname);

            cout << endl;

            cout << "Saving Passenger..." << endl;

            cout << endl;

            cout << "Select your passenger type" << endl;
            cout << "1. Veteran" << endl;
            cout << "2. Nonveteran" << endl;

            bool typeClear = true;        // for cin check on passenger type

            //getting passenger type
            while (typeClear) {

                cin >> ptype;

                if (cin.fail()) {

                    cin.clear();
                    cin.ignore('\n');
                    cout << "Incorrect selection. Try again!" << endl;
                    typeClear = true;
                }
                else {
                    typeClear = false;

                    //checks that the user picked a selection with the right bounds
                    if (ptype < 1 || ptype > 2){

                        cout << "Incorrect Selection. Try Again!" << endl;
                        typeClear = true;
                    }
                    else {

                        typeClear = false;

                    }
                }

            }

            //setting passenger type
            if (ptype == 1) {

                passT = "Veteran";
            }
            else {
                passT = "Nonveteran";
            }

            passTemp.setPassengerType(passT);

            if (passTemp.getPassengerType() == "Veteran") {

                cout << endl;
                cout << "Your ticket price with 10% discount is $" << rocketInfo[choice-1].getTicketPrice() * veteranDiscount << endl;

            }
            else {

                cout << endl;
                cout << "Your ticket price is $" << rocketInfo[choice-1].getTicketPrice() << endl;
            }

            cout << endl;
            cout << "Dear " << passTemp.getName() << " - your set is reserved successfully." << endl;

            cout << endl;

            //prints specs to terminal
            rocketInfo[choice-1].printRocketSpecs();

            passClear = false;

            //will run purchase code again if the user purchased more tickets
            if (ticketSelection > passCount) {

                passCount++;

                passClear = true;

            }
            passengers.push_back(passTemp);
        }

        //updates booking status for rockets
        rocketInfo[choice - 1].purchaseTicket(ticketSelection);

        cout << "Do you want to book more seats? (y/n)" << endl;
        cin >> ch;

        cout << endl;

    } while (ch == 'y');

    //Booking status
    cout << "Booked seats for " << Obj1.getRocketType() << " Rocket: " << rocketInfo[0].getBookedSeats() << endl;
    cout << "Booked seats for " << Obj2.getRocketType() << " Rocket: " << rocketInfo[1].getBookedSeats() << endl;
    cout << "Booked seats for " << Obj3.getRocketType() << " Rocket: " << rocketInfo[2].getBookedSeats() << endl;
    cout << "Booked seats for " << Obj4.getRocketType() << " Rocket: " << rocketInfo[3].getBookedSeats() << endl;
    
    //setting up time for each rocket
    for (int n = 0; n < rocketInfo.size(); n++) {

        time = travelDistance / rocketInfo[n].getVelocity();
        rocketInfo[n].setTimeReq(time);

    }

    //setting up message for passenger
    for (int k = 0; k < rocketInfo.size(); k++) {

        if (rocketInfo[k].getBookedSeats() > 0) {

            cout << endl;
            cout << "Dear " << rocketInfo[k].getRocketType() << " Rocket passengers, your Rocket is ready to take off..." << endl;
            cout << "Distance to your destination is " << travelDistance << " miles" << endl;
            cout << "Time taking to reach your destination will be " << rocketInfo[k].getTimeReq() << " Hours" << endl;
            cout << "Wishing you a very Happy Journey" << endl;

        }
    }

    cout << endl;
 
    //loops on rocket type
    for (int b = 0; b < rocketInfo.size(); b++) {

        //if the passenger booked seats, run the loop
        if (rocketInfo[b].getBookedSeats() > 0) {

            //inner loop for running time
            for (int h = 1; h < rocketInfo[b].getTimeReq(); h++){
                cout << "Dear " << rocketInfo[b].getRocketType() << " Rocket passengers..." << endl;
                cout << "Distanced traveled after " << h << " hours is " << rocketInfo[b].getVelocity() * (h) << " miles" << endl;
                cout << "Remaining distance is " << travelDistance - (rocketInfo[b].getVelocity() * (h) ) << " miles" << endl;
            }

            cout << "Dear " << rocketInfo[b].getRocketType() << " Rocket passengers, we are landing at the destination" << endl;
            cout << endl;
        }

       
    }
    return 0;
}
