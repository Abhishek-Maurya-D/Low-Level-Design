#include<iostream>
#include<string>

using namespace std;

class SportsCar{
private:
    // characters
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyre;
    
public:
    // constructor
    SportsCar(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;   // neutral
        tyre = "MRF";
    }

    // getters & setters
    int getCurrentSpeed(){
        return this->currentSpeed;
    }

    string getTyre(){
        return this->tyre;
    }

    void setTyre(string tyre){
        // validation 
        this->tyre = tyre;
    }

    // behaviour
    void startEngine(){
        isEngineOn = true;
        cout << brand << " " << " : Engine starts with a rear!" << endl;
    }

    // behaviour
    void shiftGear(int gear){
        if(!isEngineOn){
            cout << brand << " " << " : Engine is off! Cannot shift Gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " : shifted to gear " << currentGear << endl;
    }

    // behaviour
    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << " : Engine is off! Cannot shift Gear." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h " << endl;
    }

    // behaviour
    void brake(){
        currentSpeed -=20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Breaking! Speed is now " << currentSpeed << " km/h " << endl;
    }

    // behaviour
    void stopEngine(){
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }
};

int main(){
    SportsCar* mySportsCar = new SportsCar("ford", "Mustang");

    mySportsCar->startEngine();
    mySportsCar->shiftGear(1);
    mySportsCar->accelerate();
    mySportsCar->shiftGear(2);
    mySportsCar->accelerate();
    mySportsCar->brake();
    mySportsCar->stopEngine();

    // selecting arbitary value to speed.

    // mySportsCar->currentSpeed = 500;
    // cout << "Current Speed of My Sports Car is set to " << mySportsCar->currentSpeed << endl;

    cout<< mySportsCar->getCurrentSpeed();
    delete mySportsCar;
    return 0;
}