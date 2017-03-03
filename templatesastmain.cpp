#include <iostream>
#include <functional>
#include <string>
using namespace std;

#include "templatesast.h"

#include "templatesast.cpp" // this is where the eval functions should be

// instantiate the AST template and try it

int add(int x, int y) { return x + y; }
int multint(int x, int y) { return x * y; }

float mult(float x, float y) { return x * y; }

string merge(string s1, string s2) {return s1 + s2; }

char addchar(char ch1, char ch2) {return ch1;}
int main(int argc, const char *argv[])
{
    operators<int> intops = { add, 0 };
    operators<int> multi = { multint, 1 };
    operators<string> str = { merge, ""};
    operators<char> charOp = { addchar, 'q'};
//
//    ExpList<int> *l = nullptr;
//    l = new ExpList<int>(new Constant<int>(30), l);
//    l = new ExpList<int>(new Constant<int>(12), l);
//    Exp<int> *e = new OpApp<int>(intops, l);
//    cout << e->eval(nullptr) << endl; // should print 0 + 12 + 30 = 42
//
//    Exp<int> *e1 = new OpApp<int>(intops, nullptr);
//    cout << e1->eval(nullptr) << endl; // should print 0
//
//    operators<float> floatops = { mult, 1.0 };
//
//    ExpList<float> *l2 = nullptr;
//    l2 = new ExpList<float>(new Constant<float>(.222), l2);
//    l2 = new ExpList<float>(new Constant<float>(3.0), l2);
//    Exp<float> *e2 = new OpApp<float>(floatops, l2);
//    cout << e2->eval(nullptr) << endl; // should print 0.666 = 1.0 * 3.0 * .222

//

//    Exp<int> *e1 ,*e2;
//    ExpList<int> *l = nullptr;
//
//  l = nullptr;
//  l =  new ExpList<int>(new Constant<int>(5), l);
//  l =  new ExpList<int>(new Constant<int>(3), l);
//  l =  new ExpList<int>(new Constant<int>(2), l);
//  e1 = new OpApp<int>(intops, l);
//
//  l = nullptr;
//  l = new ExpList<int>(new Var<int>("x"), l);
//  l = new ExpList<int>(new Var<int>("x"), l);
//  l = new ExpList<int>(new Var<int>("x"), l);
//  e2 = new OpApp<int>(multi, l);
//
//  e1 = new Let<int>("x", e1, e2);
//    cout << e1->eval(nullptr) << endl; //should print 1000


//    Exp<int> *e1 ,*e2, *e3;
//    ExpList<int>  *l;
//
//    l = nullptr;
//    l = new ExpList<int>(new Constant<int>(5), l);
//    l = new ExpList<int>(new Constant<int>(3), l);
//    l = new ExpList<int>(new Constant<int>(2), l);
//    e1 = new OpApp<int>(intops, l);
//
//    l = nullptr;
//    l = new ExpList<int>(new Var<int>("x"), l);
//    l = new ExpList<int>(new Var<int>("x"), l);
//    e3 =new OpApp<int>(intops, l);
//    l = nullptr;
//    l = new ExpList<int>(e3, l);
//    l = new ExpList<int>(new Var<int>("x"), l);
//    l = new ExpList<int>(new Var<int>("x"), l);
//    e2 = new OpApp<int>(multi, l);
//
//    e1 = new Let<int>("x", e1, e2);
//
//    cout << e1->eval(nullptr) << endl; // should print  2000

//    Exp<int> *e1 ,*e2, *e3;
//    ExpList<int> *l;
//
//    l = nullptr;
//    l = new ExpList<int>(new Var<int>("y"), l);
//    e2 = new Let<int>("x",new Constant<int>(10) , new Var<int>("x"));
//    l = new ExpList<int>(e2, l);
//    l = new ExpList<int>(new Var<int>("y"), l);
//    e3 = new OpApp<int>(intops, l);
//    e1 = new Let<int>("y",new Constant<int>(2) , e3);
//
//    cout << e1->eval(nullptr) << endl;// should print  14


//        Exp<int> *e1 ,*e2;
//    ExpList<int> *l, *l2;
//
//    l = nullptr;
//    l = new ExpList<int>(new Constant<int>(4), l);
//    l = new ExpList<int>(new Constant<int>(2), l);
//    l = new ExpList<int>(new Constant<int>(1), l);
//    e1 = new OpApp<int>(multi, l); //e1 = 7
//
//    l = nullptr;
//    l = new ExpList<int>(new Constant<int>(3), l);
//    l = new ExpList<int>(new Constant<int>(3), l);
//
//    l2 = nullptr;
//    l2 = new ExpList<int>(new Constant<int>(2), l2);
//    l2 = new ExpList<int>(new Constant<int>(1), l2);
//    l2 = new ExpList<int>(new Constant<int>(3), l2);
//    e2 = new OpApp<int>(multi, l2); //e2 = 6
//
//    l = new ExpList<int>(e2, l);// 6 3 3
//    l = new ExpList<int>(new Constant<int>(1), l);//1 6 3 3
//    e2 = new OpApp<int>(intops, l);// e2 = 13
//
//    l2 = nullptr;
//    l2 = new ExpList<int>(e1, l2);// 7
//    l2 = new ExpList<int>(e2, l2);// 13 7
//    l2 = new ExpList<int>(new Constant<int>(2), l2);//2 13 7
//    l2 = new ExpList<int>(new Constant<int>(2), l2);//2 2 13 7
//    l2 = new ExpList<int>(new Constant<int>(5), l2);//5 2 2 13 7
//    e2 = new OpApp<int>(intops, l2);// e2 =
//
//    cout << e2->eval(nullptr) << endl; //should print 30

//     Exp<int> *e1, *e2,*e3;
//     ExpList<int> *l;
//
//     l = nullptr;
//     l = new ExpList<int>(new Var<int>("x"), l);
//     l = new ExpList<int>(new Var<int>("y"), l);
//     e3 = new OpApp<int>(intops, l);
//
//     e1 = new Let<int>("x", new Constant<int>(2), new Var<int>("x"));
//     e2 = new Let<int>("y", new Var<int>("x"),e3);
//     e3 = new Let<int>("x",e1,e2);
//
//     cout << e3->eval(nullptr) << endl; // should print  4

    Exp<string> *e1, *e2,*e3;
    ExpList<string> *l, *l2;




    l = nullptr;
    l = new ExpList<string>(new Constant<string>("as"), l);
    l = new ExpList<string>(new Constant<string>("lab"), l);
    e3 = new OpApp<string>(str, l);

    l2 = nullptr;
    l2 = new ExpList<string>(new Var<string>("y"), l2);
    l2 = new ExpList<string>(new Var<string>("y"), l2);
    e2 = new OpApp<string>(str, l2);

    e1 = new Let<string>("y", e3, e2);

    l2 = nullptr;
    l2 = new ExpList<string>(new Var<string>("x"), l2);
    l2 = new ExpList<string>(new Var<string>("x"), l2);
    l2 = new ExpList<string>(new Constant<string>("YES"), l2);
    e2 = new OpApp<string>(str, l2);

    e3 = new Let<string>("x", e1, e2);
    cout << e3->eval(nullptr) << endl; // should print labas

//    Exp<char> /**e1, *e2,*/*e3;
//    ExpList<char> *l;
//
//    l = nullptr;
//     l = new ExpList<char>(new Constant<char>('a'), l);
//     l = new ExpList<char>(new Constant<char>('b'), l);
//     e3 = new OpApp<char>(charOp, l);
//    cout << e3->eval(nullptr) << endl; // should print labas

    return 0;
}
