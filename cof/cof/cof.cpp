#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
struct reqhotel
{
public:
    string city;
    string hotel;
    int nights;
    bool paid;


};
class handel {
protected:
    handel* next;
public:
    virtual~handel() {}
    handel() :next(nullptr) {}
        void setnext(handel * h) {
            next = h;
        }
        void handle(const reqhotel& req) {
            if (canhandle(req)) {
                pro(req);
                if (next != nullptr) {
                    next->handle(req);
                }
              
                }  else {
                    cout << "reject" << stepname() << endl;
                }
        }
        virtual bool canhandle(const reqhotel& req) = 0;
        virtual void pro(const reqhotel& req) = 0;
        virtual string stepname() = 0;
   
};
class handlecity :public handel {
public:
    bool canhandle(const reqhotel& req)override{
        return req.city == "cairo" || req.city == "alex";
}
    void pro(const reqhotel& req)override {
        cout << "city is done" << req.city << endl;
    }
    string stepname()override{
        return "city check";
    }
};
class handlehotel :public handel {
public:
    bool canhandle(const reqhotel& req)override {
        if (req.city == "cairo" && req.hotel == "nile hotel")return true;
        if (req.city == "alex" && req.hotel == "sea view")return true;
        return false;
    }
    void pro(const reqhotel& req)override {
        cout << "city is done" << req.city <<"hotel is done "<<req.hotel<< endl;
    }
    string stepname()override {
        return "check hotel or city";
    }
};
class handlepay :public handel {
public:
    bool canhandle(const reqhotel& req)override {
        return req.paid;
    }
    void pro(const reqhotel& req)override {
        cout << "paid is done for:" << req.nights << "nightes" << endl;
    }
    string stepname()override {
        return "check your paid";
    }
};
int main() {
    handlecity c;
    handlehotel h;
    handlepay p;
    c.setnext(&h);
    h.setnext(&p);
    reqhotel r1 = { "cairo","nile hotel",2,true };
    c.handle(r1);
    return 0;
}
