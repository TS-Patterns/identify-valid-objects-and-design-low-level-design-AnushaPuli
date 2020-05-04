#include<iostream>

using namespace std;

class Pizza
{
public:
    virtual void CreatePizza() = 0;
};

class Exotica : public Pizza 
{
public:
    void CreatePizza() {  }
    Exotica() { cout << "Exotica pizza created..." << endl; }
};
class VegItalica : public Pizza 
{
public:
    void CreatePizza() {  }
    VegItalica() { cout << "VegItalica pizza created..." << endl; }
};

// Abstract class
class PizzadDecorator : public Pizza
{
private:
    Pizza* piz;
public:
    void CreatePizza() {};
    PizzadDecorator(Pizza * p)
    {
        piz = p;
    }
};
class Cheesy :public PizzadDecorator
{
public:
    Cheesy(Pizza * p) :PizzadDecorator(p) {}
    void CreatePizza() 
    {
        AddCheese();
    }
    void AddCheese() { cout << "Added cheese to the Pizza" << endl; }
};

class Spicy : public PizzadDecorator {
public:
    Spicy(Pizza * p) :PizzadDecorator(p) {}
    void CreatePizza()
    {
        AddSpiciness();
    }
    void AddSpiciness() { cout << "Added spices to the Pizza" << endl; }
};



int main()
{
    Pizza* exotica = new Exotica();  //  Base exotica
    exotica->CreatePizza();
    exotica = new Cheesy(exotica);
    exotica->CreatePizza();
    exotica = new Spicy(exotica);
    exotica->CreatePizza();
}