#include<iostream>
#include<memory>
#include<string>
#include<vector>
using namespace std;
class filee {
public:
    virtual void show(int d = 0) = 0;
    virtual~filee() = default;
};
class file :public filee {
private:
    string name;
public:
    file(const string&n):name(n){}
    void show(int d=0) override{
        cout << string(d, '-') << "file:" << name << endl;
    }
};
class dic :public filee {
private:
    string name;
    vector<shared_ptr<filee>>cheldrin;
public:
    dic(const string&name):name(name){}
    void add(shared_ptr<filee>ss) {
        cheldrin.push_back(ss);
    }
    void show(int d = 0) {
        cout << string(d, '-') << "Dir: " << name << "\n";
        for (auto c : cheldrin) {
            c->show(d + 2);
        }
    }
};
int main() {
    auto root = make_shared<dic>("root");
    auto pics = make_shared<dic>("pics");
    auto docs = make_shared<dic>("docs");
    pics->add(make_shared<file>("png 1"));
    pics->add(make_shared<file>("png 2"));
    docs->add(make_shared<file>("resume pdf"));
    docs->add(make_shared<file>("notes.text"));
    root->add(pics);
    root->add(docs);
    root->show();
 

    return 0;
}
