#include<iostream>
#include<memory>
using namespace std;
class bank {
public:
    virtual~bank() = default;
    virtual void excer(double amount) = 0;
};
class savebank :public bank {
public:
    void excer(double amount)override {
        cout << "balance" << amount <<"for saving"<< endl;

    }

};
class savewithdraw :public bank {
public:
    void excer(double amount)override {
        cout << "with draw" << amount << "for saving 2%" << endl;

    }

};
class cbank:public bank {
public:
    void excer(double amount)override {
        cout << "balnce" << amount << "for current" << endl;
    }
   
};
class cwith :public bank {
public:
    void excer(double amount)override {
        cout << "balnce" << amount << "for with current draw" << endl;
    }

};

class AbstractFactory {
public:
    virtual unique_ptr<bank> createPay() = 0;
    virtual unique_ptr<bank> createWithdraw() = 0;
    virtual ~AbstractFactory() = default;
};
class SavingFactory : public AbstractFactory {
public:
    unique_ptr<bank> createPay() override {
        return make_unique<savebank>();
    }
    unique_ptr<bank> createWithdraw() override {
        return make_unique<savewithdraw>();
    }
};
class cfactory:public AbstractFactory {
public:
    unique_ptr<bank>createPay()override {
        return make_unique<cbank>();

    }
    unique_ptr<bank>createWithdraw()override {
        return make_unique<cwith>();

    }
};
int main() {
    unique_ptr<AbstractFactory>factory;
    factory = make_unique<SavingFactory>();
    auto savingpay = factory->createPay();
    auto savingwith = factory->createWithdraw();
    savingpay->excer(100);
    savingwith->excer(50);
    factory = make_unique<cfactory>();
    auto cbank = factory->createPay();
    auto cwioth = factory->createWithdraw();
    cbank->excer(100);

    return 0;
}
