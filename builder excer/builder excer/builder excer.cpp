#include<iostream>
#include<string>
using namespace std;
class house {
public:
    string door;
    string window;
    string garage;
    void show() {
        cout <<"house with:" << door << ","
            << window << ","
            << garage << endl;
    }
};
class housebuilder {
public:
    virtual~housebuilder() {}
    virtual void builddoor() = 0;
    virtual void buildwindow() = 0;
    virtual void buildgarage() = 0;
    virtual house* gethouse() = 0;

};

class simplehousebulder :public housebuilder {
private:
    house* hous;
public:
    simplehousebulder(){ hous = new house(); }
    void builddoor() {
        hous->door = "wodeen door";
    }
    void buildwindow()override{
        hous->window = "glass";
    }
    void buildgarage()override {
        hous->garage = "open";
    }
    house* gethouse()override {
        return hous;
    }
};
class derect {
private:
    housebuilder* bild;
public:
    derect(housebuilder*b):bild(b){}
    house* construct() {
        bild->builddoor();
        bild->buildwindow();
        bild->buildgarage();
        return bild->gethouse();
    }
};
int main() {
    simplehousebulder b;
    derect derect(&b);
    house* myhouse = derect.construct();
    myhouse->show();
    delete myhouse;
    return 0;
}
