#include <iostream>
using namespace std;

class GeomLik{
public:
    virtual float povrsina();
    virtual void ispis();
};

class Trokut : public GeomLik{
private:
    float a,b,c;
public:
    Trokut(float x, float y, float z): a(x), b(y), c(z){}
    float povrsina(){
        return (a*b)/2;
    }
    void ispis(){
        cout << "Povrsina trokuta: " << povrsina() << endl;
    }
};

class Krug : public GeomLik{
private:
    float r; //polumjer
public:
    Krug(float a):r(a){}
    float povrsina(){
        return 2*r*3.16;
    }
    void ispis(){
        cout << "Povrsina kruga: " << povrsina() << endl;
    }
};

class Pravokutnik : public GeomLik{
private:
    float a, b;
public:
    Pravokutnik(float x, float y):a(x), b(y){}
    float povrsina(){
        return a*b;
    }
    void ispis(){
        cout << "Povrsina pravokutnika: " << povrsina() << endl;
    }
};

int main()
{
    GeomLik* A[10];
    A[0] = new Trokut(3, 4, 5);
    A[1] = new Pravokutnik(2, 4);
    A[2] = new Krug(10);
    A[3] = new Trokut(2, 2, 3);
    A[4] = new Krug(3);
    A[5] = new Krug(5);
    A[6] = new Pravokutnik(1, 10);
    A[7] = new Trokut(2, 4, 5);
    A[8] = new Krug(1);
    A[9] = new Pravokutnik(2, 2);
    return 0;
}
