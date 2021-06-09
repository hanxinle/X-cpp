#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;
// 保存表达式求解中间结果
class Context {
public:
    int val_;
    char oper_;
    Context() :val_(0), oper_('\0') {}
};

class IExpression {
public:
    virtual void Eval(Context* p) = 0;
};

class Operator :public IExpression {
public:
    Operator(char op) {
        this->op_ = op;
    }

    void Eval(Context* p) {
        p->oper_ = op_;
    }
private:
    char op_;
};


class Operand : public IExpression {
public:
    Operand(int num) {
        this->num_ = num;
    }
    void Eval(Context* p) {
        switch (p->oper_) {
        case '\0':p->val_ = num_; break;
        case '+':p->val_ += num_; break;
        case '-':p->val_ -= num_; break;
        default:
            break;
        }
    }
private:
    int num_;
};

class Calculator {
public:
    int Calc(string expression) {
        Context* p = new Context;
        vector <IExpression*> tree;
        for (int i = 0; i < expression.size(); i++) {
            if ((expression[i]) == '+' || (expression[i] == '-')) {
                tree.push_back(new Operator(expression[i]));
            }
            else {
                tree.push_back(new Operand(static_cast<int>(expression[i] - '0')));
            }
        }

        for (auto it = tree.begin(); it != tree.end(); ++it) {
            (*it)->Eval(p);
            printf("Context(val = %d,oper = %c)\n", p->val_, p->oper_);
        }
        return p->val_;
    }
};

int main() {
    Calculator* pC = new Calculator;
    cout << "3+4-2=" << pC->Calc("3+4-2") << endl;
    system("pause");
    return 0;
}
