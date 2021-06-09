#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// 被观察对象接口
class Observer {
public:
    virtual void update() = 0;
protected:
    Observer() { }
};

// 观察者接口
class Subject {
public:
    virtual void registerObserver(Observer* po) = 0;
    virtual void removeObserver(Observer* po) = 0;
    virtual void notifyObserver() = 0;
protected:
    Subject() {}
};

// 具体的被观察类 天气信息
class WeatherData :public Subject {
public:
    WeatherData(string tm, string hm) :temp_(tm), humi_(hm) {}
    // 3个接口的实现都是与观察者结构的交互
    void registerObserver(Observer* po) {
        Observers_.push_back(po);
    }

    void removeObserver(Observer* po) {
        auto it = find(Observers_.begin(), Observers_.end(), po);
        if (it != Observers_.end()) {
            Observers_.erase(it);
        }
    }
    // 通知每个观察者，每一个观察者会更新数据
    void notifyObserver() {
        for (auto it = Observers_.begin(); it != Observers_.end(); it++)
            (*it)->update();
    }

    void getData() {
        cout << "温度为: " << temp_ << "湿度为：" << humi_ << endl;
    }

    void setData(string tm, string hm) {
        temp_ = tm;
        humi_ = hm;
        notifyObserver();
    }

private:
    // 数据成员 1-观察者（通知对象）2-观测值
    vector<Observer*> Observers_;
    string temp_;
    string humi_;
};

// 具体观察者1，pc 端
class MobileDisplay : public Observer {
public:
    void update() {
        cout << "Mobile:" << endl;
        pw->getData();
    }

    MobileDisplay(WeatherData* pwd) {
        pw = pwd;
        pw->registerObserver(this);
    }
private:
    WeatherData* pw;
};
// 具体观察者2，MObile 移动端
class PcDisplay :public Observer {
public:
    void update() {
        cout << "Pc:" << endl;
        pw->getData();
    }

    PcDisplay(WeatherData* pwd) {
        pw = pwd;
        pw->registerObserver(this);
    }
private:
    WeatherData* pw;
};


int main() {
    // 被观察对象指针完成操作
    // 数据变化自动通知给观察者，观察者自动更新信息
    // 以上就是观察者模式的要做到的核心特性

    WeatherData* pwd = new WeatherData("100", "100%");
    MobileDisplay* pmb = new MobileDisplay(pwd);
    PcDisplay* ppc = new PcDisplay(pwd);
    pwd->getData();
    cout << endl;

    pwd->setData("00", "00%");
    cout << endl;

    pwd->setData("20", "20%");
    cout << endl;

    cout << "移除 PC 端显示，数据统一设置为30" << endl;
    pwd->removeObserver(ppc);
    pwd->setData("30", "30%");

    return 0;
}
