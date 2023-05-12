// englmult.cpp 
// программа демонстрации множественного наследования
#include <string>
#include <iostream>
using namespace std;

class Type                                          // тип древесины
{
private:
    string dimensions;
    string grade;
public:
    Type() : dimensions("N/A"), grade("N/A")        // консруктор без параметров
        { }
                                                    // конструктор с двумя парамектрами
    Type(string di, string gr) : dimensions(di), grade(gr)
        { }
    void gettype()                                  // запрос информации от пользователя
        {
        cout << "   Enter the nominal dimensions (2x4, etc.):";
        cin >> dimensions;
        cout << "   Enter the grade(raw, bar, etc.):";
        cin >> grade;
        }   
    void showtype() const                           // показ информации
        {
        cout << "\n     Size: " << dimensions;
        cout << "\n     Variety: " << grade;
        }
};

class Distance                                      // английские меры длины
{
private:
    int feet;
    float inches;
public:                                             // конструктор без пароаметров
    Distance() : feet(0), inches(0.0)
        {   }                                       // конструктор с двумя параметрами
    Distance(int ft, float in) : feet(ft), inches(in)
        {   }
    void getdist()                                  // запрос мер длины у пользователя
        {  
        cout << "   Enter feet: "; cin >> feet;
        cout << "   Enter inches: "; cin >> inches;
        }
    void showdist() const
        { cout << feet << "\'-" << inches << '\"'; }
};

class Lumber : public Type, public Distance
{
private:
    int quantity;                                   // колчество штук
    double price;                                   // цена за штуку
public:                                             // конструктор без параметров
    Lumber() : Type(), Distance(), quantity(0), price(0.0)
        {   }
                                                    // конструктор с шестью параметрами
    Lumber(string di, string gr,                    // параметры для Type
        int ft, float in,                           // параметры для Distance
        int qu, float prc) :                        // наши собственные параметры
    Type(di, gr),                                   // Вызов конструктора Type
        Distance(ft, in),                           // Вызов конструктора Distance
        quantity(qu), price(prc)                    // Вызов наших конструкторов 
      {    } 
    void getlumber()
        {
    Type::gettype();
        Distance::getdist();
        cout << "   Enter quantity: "; cin >> quantity;
        cout << "   Enter price: "; cin >> price;
        }      
    void showlumber() const
        {
        Type::showtype();
        cout << "\n     Lenght: ";
        Distance::showdist();
        cout << "\n     Cost: " << quantity << "pieces: $" << (price * quantity) << "rub";
        }
};

int main()
{
    Lumber siding;                                  // используем конструктор без параметров

    cout << "\n Information about cladding: \n";
    siding.getlumber();                             // получаем данные от пользователя
                                                    // Используем конструктор с 6 параметрами
    Lumber studs("2x4", "const", 8, 0.0, 20, 4.34F);
                                                    // показываем информацию
    cout << "\nCladding: "; siding.showlumber();
    cout << "\nBar: ";      studs.showlumber();
    return 0;
}
