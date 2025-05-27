#include<iostream>
using namespace std;

class Parent{
public:
    virtual void print(string msg){
        cout << "Parent: " << msg << endl;
    }
};

class Child : public Parent{
public:
    void print(string msg) override{
        cout << "Child: " << msg << endl;
    }
};

class Client{
private:
    Parent* p;

public: 
    Client(Parent* p){
        this->p = p;
    }

    void printMsg(){
        p->print("Manoj");
    }
};

int main(){
    Parent* parent = new Parent();
    Parent* child = new Child();
    // Client* client = new Client(child);
    Client* client = new Client(parent);
    client->printMsg();
    return 0;
}