#include "point.h"
#include "usecount.h"

class Handle {
public:
    Handle() :p(new Point) { }
    Handle(int x, int y) :p(new Point(x, y)) { }
    ~Handle() { if (uc.IsOnly())  delete p; }

    Handle(const Point& other) :p(new Point(other)) { }
    Handle(const Handle& other) :p(other.p), uc(other.uc) { }

    //Handle& operator=(const Handle& other) {
    //    if (uc.ReAttach(other.uc))
    //        delete p;
    //    p = other.p;
    //    return *this;
    //}

    // 重新实现，将ReAttach操作统一接口 operator=
    Handle& operator=(const Handle& other) {
        uc = other.uc;
        p = other.p;
        return *this;
    }
    //获取值
    int x() const { return p->x(); }
    int y() const { return p->y(); }

    //设置值
    Handle& SetX(int x) { p->setX(x); return *this; }
    Handle& SetY(int y) { p->setY(y); return *this; }
    Handle& SetXY(int x, int y) { p->setXY(x, y); return *this; }
private:
    Point* p;
    UseCount uc;
};