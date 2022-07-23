#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include<string>

using namespace std;

class ExceptionHandling:public logic_error
{
public:
    int errNo;
    string msg;
    ExceptionHandling():errNo(0),logic_error("")
    {

    }

    ExceptionHandling(int errNo,string msg):logic_error(msg),errNo(errNo)
    {

    }
};

class Booking
{
public:
    int bookingId;
    string source;
    string destination;
    string bookingStatus;
    int noOfSeats;
    ExceptionHandling eh;
    Booking():bookingId(0),source(""),destination(""),noOfSeats(0)
    {

    }

    Booking(int bookingId,string source,string destination,int noOfSeats):
        bookingId(bookingId),source(source),destination(destination),
        noOfSeats(noOfSeats)
    {

    }

    virtual void confirmBooking()=0;

    virtual void cancelBooking()
    {

    }
    virtual void computeTotalCost()
    {

    }
    virtual void displayBooking()
    {
        cout << "Booking ID: " << bookingId << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Seats: " << noOfSeats << endl;
        cout << "Booking Status: " << bookingStatus << endl;
    }
};

class BusBooking:public Booking
{
public:
    string busName;
    int busNumber;
    //int availableSeats;
    float totalCost;
    //int seatNumber;
    BusBooking():busName(""),busNumber(0),totalCost(0.0f)
    {

    }

    BusBooking(int bookingId,string source,string destination,int noOfSeats,
               string busName,int busNumber):
        Booking(bookingId,source,destination,noOfSeats),busName(busName),
        busNumber(busNumber)
    {

    }

    void confirmBooking()
    {
        //bookingStatus="Booking under payment";
        cout << "Your Booking for Bus has been confirmed\n Booking Details\n";
        //displayCustomer();
        Booking::displayBooking();
        displayBooking();
    }
    void cancelBooking()
    {

    }
    void computeTotalCost()
    {
        int temp=500;
        totalCost=temp*noOfSeats;

    }
    void displayBooking()
    {
        cout << "Bus Name: " << busName<<endl;
        cout << "Bus Number: " << busNumber<<endl;
        cout << "Total Cost: " << totalCost<<endl;
        cout<<"Booking Status: "<<bookingStatus<<endl;
    }
};

class CarBooking:public Booking
{
public:
    string carName;
    int carNumber;
    float totalCost;
    float kms;

    CarBooking():carName(""),carNumber(0),totalCost(0.0f),kms(0.0f)
    {

    }
    CarBooking(int bookingId,string source,string destination,int noOfSeats,
               string carName,int carNumber,float kms):Booking(bookingId,source,destination,
                           noOfSeats),carName(carName),carNumber(carNumber),
        kms(kms)
    {

    }

    void confirmBooking()
    {
        //bookingStatus="Booking under payment";
        cout << "Your Booking for Car has been confirmed\n Booking Details\n";
        //displayCustomer();
        Booking::displayBooking();
        displayBooking();
    }
    void cancelBooking()
    {

    }
    void computeTotalCost()
    {
        int costperkm;
        if(noOfSeats<=4)
        {
            costperkm = 9;
            totalCost = costperkm * kms;
        }
        else if(noOfSeats==6 || noOfSeats==5)
        {
            costperkm = 10.5;
            totalCost = costperkm * kms;
        }
        else
        {
            costperkm = 12;
            totalCost = costperkm * kms;
        }

    }
    void displayBooking()
    {

        cout << "Car Name: " << carName << endl;
        cout << "Car Number: " << carNumber << endl;
        cout << "Kilometers: " << kms << endl;
        cout << "Total Cost: " << totalCost << endl;
        cout<<"Booking Status: "<<bookingStatus<<endl;
    }
};

class TrainBooking:public Booking
{
public:
    string trainName;
    int trainNo;
    //int availableSeats;
    float totalCost;

    TrainBooking():trainName(""),trainNo(0),totalCost(0.0f)
    {

    }
    TrainBooking(int bookingId,string source,string destination,int noOfSeats,
                 string trainName,int trainNo):
                 Booking(bookingId,source,destination,noOfSeats),trainName(trainName),
                 trainNo(trainNo)
    {

    }
    void confirmBooking()
    {
        //bookingStatus="Booking under payment";
        cout << "Your Booking for Train has been confirmed\n\tBooking Details\n";
        //displayCustomer();
        Booking::displayBooking();
        displayBooking();

    }
    void cancelBooking()
    {

    }
    void computeTotalCost()
    {
        int temp=250;
        totalCost=temp*noOfSeats;

    }
    void displayBooking()
    {
        cout << "Train Name: " << trainName << endl;
        cout << "Train Number: " << trainNo << endl;
        cout << "Total Cost: " << totalCost << endl;
        cout<<"Booking Status: "<<bookingStatus<<endl;

    }
};

class FlightBooking:public Booking
{
public:
    string flightName;
    int flightNo;
    //int availableSeats;
    //string seatNo;
    float totalCost;

    FlightBooking():flightName(""),flightNo(0),totalCost(0.0f)
    {

    }
    FlightBooking(int bookingId,string source,string destination,int noOfSeats,
                  string flightName,int flightNo):Booking(bookingId,
                  source,destination,noOfSeats),flightName(flightName),flightNo(flightNo)
    {

    }
    void confirmBooking()
    {
        //bookingStatus="Booking under payment";
        cout << "Your Booking for Flight has been confirmed\n\tBooking Details\n";
        //displayCustomer();
        Booking::displayBooking();
        displayBooking();

    }
    void cancelBooking()
    {

    }
    void computeTotalCost()
    {
        int temp=1500;
        totalCost=temp*noOfSeats;

    }
    void displayBooking()
    {
        cout << "Flight Name: " << flightName << endl;
        cout << "Flight Number: " << flightNo << endl;
        cout << "Total Cost: " << totalCost << endl;
        cout<<"Booking Status: "<<bookingStatus<<endl;

    }
};

class Payment
{
public:
    long int accNo;
    string accHolderName;

    Payment():accNo(0),accHolderName("")
    {

    }
    Payment(long int accNo,string accHolderName):accNo(accNo),accHolderName(accHolderName)
    {

    }
    virtual void makePayment()
    {

    }
    virtual void printPayment()
    {

    }
};

class CardPayment:public Payment
{
public:
    long int cardNo;
    string cardHolderName;
    int cvvNo;
    int expiryMonth;
    int expiryYear;

    CardPayment():Payment(),cardNo(0),cardHolderName(""),cvvNo(0),expiryMonth(0),expiryYear(0)
    {

    }
    CardPayment(long int accNo,string accHolderName,long int cardNo,string cardHolderName,int cvvNo,
                int expiryMonth,int expiryYear):Payment(accNo,accHolderName),cardNo(cardNo),
        cardHolderName(cardHolderName),cvvNo(cvvNo),expiryMonth(expiryMonth),expiryYear(expiryYear)
    {

    }
    void makePayment()
    {
        cout << "Enter AccountNo.: ";
        cin >> accNo;
        cout << "Enter account holder name: ";
        cin >> accHolderName;
        cout << "Enter card number: ";
        cin >> cardNo;
        cout << "Enter card holder name: ";
        cin >> cardHolderName;
        cout << "Enter CVV No.: ";
        cin >> cvvNo;
        cout << "Enter ExpiryMonth: ";
        cin >> expiryMonth;
        cout << "Enter ExpiryYear: ";
        cin >> expiryYear;
    }
    void printPayment()
    {
        cout << "Payment Method: CARD" << endl;
        cout << "AccountNo: " << accNo << endl;
        cout << "AccountHolderName: " << accHolderName << endl;
        cout << "CardNo: " << cardNo << endl;
        cout << "CardHolderName: " << cardHolderName << endl;
        cout << "CvvNo: " << cvvNo << endl;
        cout << "ExpiryMonth: " << expiryMonth << endl;
        cout << "ExpiryYear: " << expiryYear << endl;
    }
};

class UpiPayment:public Payment
{
public:
    string upiId;

    UpiPayment():Payment(),upiId("")
    {

    }
    UpiPayment(long int accNo,string accHolderName,string upiId):Payment(accNo,accHolderName),upiId(upiId)
    {

    }
    void makePayment()
    {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Account holder name: ";
        cin >> accHolderName;
        cout << "Enter UPI ID: ";
        cin >> upiId;
        cout << "Payment successfull.\n Booking confirmed.";

    }
    void printPayment()
    {
        cout << "Payment Method: UPI" << endl;
        cout << "AccountNo: " << accNo << endl;
        cout << "AccountHolderName: " << accHolderName << endl;
        cout << "UPI ID: " << upiId << endl;
        cout << "Payment successfull.\n Booking confirmed.";
    }
};


class TravelAgency
{
public:
    string taName;
    Booking* booking[4];
    static TravelAgency *instance;
    private:

    TravelAgency():taName("")
    {

    }
    TravelAgency(string taName):taName(taName)
    {

    }
public:

   static  TravelAgency *getInstance(string taName)
    {
        if (!instance)
            instance = new TravelAgency(taName);
        return instance;
    }
};

class Customer
{
public:
    int custId;
    string custName;
    string custAddress;
    long long int custPhone;
    string custEmail;
    //char gender;
    //Payment pa;
    TravelAgency* ta;

    Customer():custId(0),custName(""),custAddress(""),custPhone(0),custEmail("")
    {

    }
    Customer(int custId,string custName,string custAddress,long long int custPhone,string custEmail,TravelAgency*  ta):
        custId(custId),custName(custName),custAddress(custAddress),custPhone(custPhone),custEmail(custEmail),ta(ta)
    {

    }

    void displayCustomer()
    {
        cout << "CustID: " << custId << endl;
        cout << "Name: " << custName << endl;
        cout << "Address: " << custAddress << endl;
        cout << "Phone: " << custPhone << endl;
        cout << "Email: " << custEmail << endl;
    }
};


TravelAgency* TravelAgency::instance = 0;
int main()
{
    int custId;
    string custName;
    string custAddress;
    long long int custPhone;
    string custEmail;
    long int accNo;
    string accHolderName;
    string upiId;
    int choice;

    Booking* b;
    // CarBooking cB;
    BusBooking bB;
    TrainBooking tB;
    FlightBooking fB;
    Payment* pmt;
    UpiPayment upi;
    CardPayment card;

    //char gender;
    //string userName;
    //string pwd;
    //TravelAgency *t = t->getInstance();
    TravelAgency* t=TravelAgency::getInstance("KLE");
    cout << "Welcome To "<<t->taName<<" Travel Agency" << endl;



    cout << "--------------------------------" << endl;




    try
    {
        cout << "Enter your details" << endl;
        cout << "Name: ";
        cin >> custName;
        if(custName=="")
            throw ExceptionHandling(1,"Enter name");

        cout << "Phone Number: ";
        cin >> custPhone;
        int temp=to_string(custPhone).length();
        if(temp==0 || temp<10||temp>10)
            throw ExceptionHandling(2,"Enter valid phone number");

        cout << "Address: ";
        cin >> custAddress;
        if(custAddress=="")
            throw ExceptionHandling(3,"Enter Address");

        cout << "Email: ";
        cin >> custEmail;
        if(custEmail=="")
            throw ExceptionHandling(4,"Enter Email");
    }
    catch(ExceptionHandling& eh)
    {
        cout << eh.what();
        exit(0);
    }



    Customer c1(rand()%99999,custName,custAddress,custPhone,custEmail,t);
    cout << "Registered successfully...." << endl;

    sleep(1);

    system("CLS");
    cout << "Welcome " << custName << " please select the Options for booking\n";
    while(1)
    {
        cout << "\tOptions" << endl;

        cout << "---------------------------------" <<endl;
        cout << "1. CAR BOOKING" << endl;
        cout << "2. BUS BOOKING" << endl;
        cout << "3. TRAIN BOOKING" << endl;
        cout << "4. FLIGHT BOOKING" << endl;
        cout << "5. EXIT" << endl;
        cout << "---------------------------------" <<endl;
        cout << "ENTER CHOICE:-" << endl;
        cin >> choice;

        switch(choice)
        {
        case 1:
        {
            system("CLS");
            try{
            cout << "CAR BOOKING" << endl;
            cout<<"************"<<endl;

            cout << "Enter CarName: ";
            string carName;
            cin >> carName;
            int temp=carName.length();



            int carNumber = rand()%9999;
            cout << "Enter Source: ";
            string source;
            cin >> source;
            cout << "Enter Destination: ";
            string destination;
            cin >> destination;
            cout << "Enter num of seats: ";
            int noOfSeats;
            cin >> noOfSeats;
            if(noOfSeats<=0)
                throw ExceptionHandling(11,"Enter Number of seats properly");

            cout << "Enter Kilometers: ";
            float kms;
            cin >> kms;
            if(kms<=0)
                throw ExceptionHandling(12,"Enter Kilometer properly");



            t->booking[0]=new CarBooking(rand()%190999,source,destination,noOfSeats,carName,carNumber,kms);
            t->booking[0]->computeTotalCost();
            system("CLS");
            t->booking[0]->bookingStatus="Booking under payment";
            t->booking[0]->confirmBooking();
        }
             catch(ExceptionHandling& eh)
            {
            cout << eh.what();
        exit(0);
            }
            while(1)
            {
                cout << "---------------------------------" <<endl;
                cout << "1. PAYMENT" << endl;
                cout << "2. EXIT" << endl;
                cout << "Enter Choice: "<<endl;
                cin >> choice;

                switch(choice)
                {
                case 1:
                {
                    system("CLS");

                    cout << "PAYMENT GETWAY\n*******************" << endl;
                    while(1)
                    {
                        cout << "---------------------------------" << endl;
                        cout << "1. UPI PAYMENT" << endl;
                        cout << "2. CARD PAYMENT" << endl;
                        cout << "Enter Choice: " << endl;
                        cin >> choice;

                        switch(choice)
                        {
                        case 1:
                        {
                            upi.makePayment();
                            system("CLS");
                            t->booking[0]->bookingStatus="booked";
                            t->booking[0]->confirmBooking();
                            cout << "Payment Details" << endl;
                            upi.printPayment();

                            exit(0);
                        }
                        break;

                        case 2:
                        {
                            card.makePayment();
                            system("CLS");
                            t->booking[0]->bookingStatus="booked";
                            t->booking[0]->confirmBooking();
                            cout << "Payment Details" <<endl;
                            card.printPayment();

                            exit(0);
                        }
                        break;
                        default:
                            cout << "****Invalid Choice****" << endl;
                        }
                    }

                    exit(0);
                }
                break;

                case 2:
                {
                    system("CLS");
                    cout << "Payment canceled\n*******************" << endl;
                    t->booking[0]->bookingStatus="cancelled";
                    t->booking[0]->displayBooking();
                    exit(0);
                }
                break;
                default:
                    cout << "****Invalid Choice****" << endl;
                }
            }
            //b->computeTotalCost();
            //b->confirmBooking();
        }
        break;

        case 2:
        {
            string busName;
            string source;
            string destination;
            int noOfSeats;

            system("CLS");
            cout << "BUS BOOKING" << endl;
            cout << "************" << endl;
            cout << "Enter Bus Name: ";
            cin >> busName;
            cout << "Enter Source: ";
            cin >> source;
            cout << "Destination: ";
            cin >> destination;
            cout << "Enter num of seats: ";
            cin >> noOfSeats;

            t->booking[1]=new BusBooking(rand()%99999,source,destination,noOfSeats,busName,rand()%9999);
            t->booking[1]->computeTotalCost();
            t->booking[1]->bookingStatus="Booking under payment";
            t->booking[1]->confirmBooking();

            while(1)
            {
                cout << "---------------------------------" <<endl;
                cout << "1. PAYMENT" << endl;
                cout << "2. EXIT" << endl;
                cout << "Enter Choice: " << endl;
                cin >> choice;

                switch(choice)
                {
                case 1:
                {
                    system("CLS");

                    cout<<"PAYMENT GETWAY\n*******************"<<endl;
                    while(1)
                    {
                        cout << "---------------------------------" <<endl;
                        cout << "1. UPI PAYMENT" << endl;
                        cout << "2. CARD PAYMENT" << endl;
                        cout<<"Enter Choice: "<<endl;
                        cin>>choice;

                        switch(choice)
                        {
                        case 1:
                        {
                            upi.makePayment();
                            system("CLS");
                            t->booking[1]->bookingStatus="booked";
                            t->booking[1]->confirmBooking();
                            cout << "Payment Details" << endl;
                            upi.printPayment();

                            exit(0);
                        }
                        break;

                        case 2:
                        {
                            card.makePayment();
                            system("CLS");
                            t->booking[1]->bookingStatus="booked";
                            t->booking[1]->confirmBooking();
                            cout << "Payment Details" <<endl;
                            card.printPayment();

                            exit(0);
                        }
                        break;
                        default:
                            cout << "****Invalid Choice****" << endl;

                        }
                    }

                    exit(0);
                }
                break;

                case 2:
                {
                    system("CLS");
                    cout<<"Payment canceled\n*******************"<<endl;
                    t->booking[1]->bookingStatus="cancelled";
                    t->booking[1]->displayBooking();
                    exit(0);

                }
                break;
                default:
                    cout << "****Invalid Choice****" << endl;

                }
            }
        }
        break;

        case 3:
        {
            string trainName;
            string source;
            string destination;
            int noOfSeats;

            system("CLS");

            cout << "TRAIN BOOKING" << endl;
            cout << "************" << endl;
            cout << "Enter Train Name: ";
            cin >> trainName;
            cout << "Enter Source: ";
            cin >> source;
            cout << "Destination: ";
            cin >> destination;
            cout << "Enter num of seats: ";
            cin >> noOfSeats;

            t->booking[2]=new TrainBooking(rand()%99999,source,destination,noOfSeats,trainName,rand()%9999);
            t->booking[2]->computeTotalCost();
            t->booking[2]->bookingStatus="Booking under payment";
            t->booking[2]->confirmBooking();

            while(1)
            {
                cout << "---------------------------------" <<endl;
                cout << "1. PAYMENT" << endl;
                cout << "2. EXIT" << endl;
                cout << "Enter Choice: " << endl;
                cin >> choice;

                switch(choice)
                {
                case 1:
                {
                    system("CLS");

                    cout << "PAYMENT GETWAY\n*******************" << endl;
                    while(1)
                    {
                        cout << "---------------------------------" << endl;
                        cout << "1. UPI PAYMENT" << endl;
                        cout << "2. CARD PAYMENT" << endl;
                        cout << "Enter Choice: " << endl;
                        cin >> choice;

                        switch(choice)
                        {
                        case 1:
                        {
                            upi.makePayment();
                            system("CLS");
                            t->booking[2]->bookingStatus="booked";
                            t->booking[2]->confirmBooking();
                            cout << "Payment Details" << endl;
                            upi.printPayment();

                            exit(0);
                        }
                        break;

                        case 2:
                        {
                            card.makePayment();
                            system("CLS");
                            t->booking[2]->bookingStatus="booked";
                            t->booking[2]->confirmBooking();
                            cout << "Payment Details" <<endl;
                            card.printPayment();

                            exit(0);
                        }
                        break;
                        default:
                            cout << "****Invalid Choice****" << endl;

                        }
                    }

                    exit(0);
                }
                break;

                case 2:
                {
                    system("CLS");
                    cout << "Payment canceled\n*******************" << endl;
                    t->booking[2]->bookingStatus="cancelled";
                    t->booking[2]->displayBooking();
                    exit(0);

                }
                break;
                default:
                    cout << "****Invalid Choice****" << endl;

                }
            }
        }
        break;

        case 4:
        {
            string flightName;
            int flightNo,noOfSeats;
            string source;
            string destination;
            float totalCost;


            system("CLS");
            cout << "FLIGHT BOOKING" << endl;
            cout << "************" << endl;
            cout << "Enter Flight Name: ";
            cin >> flightName;
            cout << "Enter Source: ";
            cin >> source;
            cout << "Destination: ";
            cin >> destination;
            cout << "Enter num of seats: ";
            cin >> noOfSeats;

            t->booking[3]=new FlightBooking(rand()%99999,source,destination,noOfSeats,flightName,rand()%9999);
            t->booking[3]->computeTotalCost();
            t->booking[3]->bookingStatus="Booking under payment";
            t->booking[3]->confirmBooking();

            while(1)
            {
                cout << "---------------------------------" << endl;
                cout << "1. PAYMENT" << endl;
                cout << "2. EXIT" << endl;
                cout << "Enter Choice: "<< endl;
                cin >> choice;

                switch(choice)
                {
                case 1:
                {
                    system("CLS");

                    cout << "PAYMENT GETWAY\n*******************" << endl;
                    while(1)
                    {
                        cout << "---------------------------------" << endl;
                        cout << "1. UPI PAYMENT" << endl;
                        cout << "2. CARD PAYMENT" << endl;
                        cout << "Enter Choice: " << endl;
                        cin >> choice;

                        switch(choice)
                        {
                        case 1:
                        {
                            upi.makePayment();
                            system("CLS");
                            t->booking[3]->bookingStatus="booked";
                            t->booking[3]->confirmBooking();
                            cout << "Payment Details" << endl;
                            upi.printPayment();



                            exit(0);
                        }
                        break;

                        case 2:
                        {
                            card.makePayment();
                            system("CLS");
                            t->booking[3]->bookingStatus="booked";
                            t->booking[3]->confirmBooking();
                            cout << "Payment Details" << endl;
                            card.printPayment();

                            exit(0);
                        }
                        break;
                        default:
                            cout << "****Invalid Choice****" << endl;

                        }
                    }

                    exit(0);
                }
                break;

                case 2:
                {
                    system("CLS");
                    cout << "Payment canceled\n*******************" << endl;
                    t->booking[3]->bookingStatus="cancelled";
                    t->booking[3]->displayBooking();
                    exit(0);

                }
                break;
                default:
                    cout << "****Invalid Choice****" << endl;

                }
            }
        }
        break;

        case 5:
            exit(0);
            break;

        default:
            cout << "****Invalid Choice****" << endl;
        }
    }

    return 0;
}
