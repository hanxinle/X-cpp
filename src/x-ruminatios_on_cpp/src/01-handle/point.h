class Point {
public:
    Point() { this->x_ = 0; this->y_ = 0; }
    Point(int x, int y) { this->x_ = x; this->y_ = y; }
    Point(const Point& other) { this->x_ = other.x_; this->y_ = other.y_; }
    Point& operator= (const Point& other) { this->x_ = other.x_; this->y_ = other.y_; return *this; }
    // 获取坐标值
    int x() const { return this->x_; }
    int y() const { return this->y_; }
    // 设置坐标值
    Point& setX(int x) { this->x_ = x; return *this; }
    Point& setY(int y) { this->y_ = y; return *this; }
    Point& setXY(int x, int y) { this->x_ = x; this->y_ = y; return *this; }
private:
    int x_;
    int y_;
};