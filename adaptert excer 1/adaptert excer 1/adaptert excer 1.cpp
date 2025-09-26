#include<iostream>
#include<string>
#include<memory>
using namespace std;
class rec {
public:
    virtual~rec() = default;
    virtual void draw() = 0;
};
class oldrec {
public:
    void drawrec(int x1, int y1, int x2, int y2) {
        cout << "drawing the rectangle from" << "(" << x1 << "," << y1 << ")" << "to" << "(" << x2 << "," << y2 << ")"<<endl;
    }
};
class recadapter :public rec {
private:
    unique_ptr<oldrec>o;
public:
    recadapter(unique_ptr<oldrec>od):o(move(od)){}
    void draw()override {
        o->drawrec(0, 0, 10, 10);
    }
};
int main() {
    unique_ptr<oldrec> ol = make_unique<oldrec>();
    rec* rect = new recadapter(move(ol));
    rect->draw();
    delete rect;
    return 0;
}
