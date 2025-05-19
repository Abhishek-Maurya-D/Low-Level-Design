#include<iostream>
#include<string>
using namespace std;

// Base Car class
class Car{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    Car(string b, string m){
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        this->currentSpeed = 0;
    }

    // Common methods for all cars.
    void startEngine(){
        isEngineOn = true;
        cout << brand << " " << model << " : Engine started." << endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }

    virtual void accelerate() = 0;  // abstract method for dynamic polymorphism
    virtual void brake() = 0;       // abstract method for dynamic polymorphism
    virtual ~Car() {}               // virtual destructor
};

class ManualCar : public Car{
private:
    int currentGear;

public:
    ManualCar(string b, string m) : Car(b, m){
        this->currentGear = 0;
    }

    // Specalised method for Manual Car
    void shiftGear(int gear){
        currentGear = gear;
        cout << brand << model << " : Shifted to gear. " << currentGear << endl;
    }

    // Overriding accelerate - Dynamic Polymorphism
    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h " << endl;
    }

    // Overriding brake -- Dynamic Polymorphism
    void brake(){
        currentSpeed -= 20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h " << endl;
    }
};

class ElectricCar : public Car{
private:
    int batteryLevel;

public:
    ElectricCar(string b, string m) : Car(b, m){
        this->batteryLevel = 100;
    }

    // specialized method for Electric Car
    void chargedBattery(){
        batteryLevel = 100;
        cout << brand << " " << model << " : Battery fully charged! " << endl;
    }

    // Overriding accelerate - Dynamic Polymorphism
    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        if(batteryLevel <= 0){
            cout << brand << " " << model << " : Battery dead! Cannot accelerate. " << endl;
            return;
        }
        batteryLevel -= 10;
        currentSpeed += 15;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h. Battery at " << batteryLevel << "%." << endl;
    }

    void brake(){
        currentSpeed -= 15;
        if(currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Regenerative braking! Speed is now " << currentSpeed << " km/h. Battery at " << batteryLevel << " %." << endl;
    }
};

int main(){
    Car* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();

    cout << " ------------------------------------------------------------------------ " << endl;

    Car* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();

    // Clearup
    delete myManualCar;
    delete myElectricCar;

    return 0;
}