#include<iostream>
#include<stdexcept>
#include<type_traits>
using namespace std;
//03 November 2025
//Implement a template class for pair data type which will hold two values of same or different data types.
//over load [] for indexing
//create copy constructor and assignment operator
template<typename T, typename R>
class Pair{
private:
    T first;
    R second;
public:
    //parameterized constructor
    Pair(T a = T(), R b = R()) : first(a), second(b) {}

    //copy constructor
    //same class ke object ko dusre object mein copy krne k liye 
    Pair(const Pair<T, R> & p) {
        this->first = p.first;
        this->second = p.second;
    }

    Pair<T, R>& operator=(const Pair<T, R> & p) {
        if (this != &p) {
            this->first = p.first;
            this->second = p.second;
        }
        return *this;
    }
    auto operator[](int index) -> decltype((index == 0) ? first : second) {
        if (index == 0) {
            return first;
        } else if (index == 1) {
            return second;
        } else {
            throw out_of_range("Index out of range. Valid indices are 0 and 1.");
        }
    }

    friend ostream& operator<<(ostream& os, const Pair<T, R> &p){
        //(first, secoind ) format 
        os << "(" << p.first << ", " << p.second << ")";
        return os;
    }
    friend istream& operator>>(istream& is, Pair<T, R> &p){
        cout << "Enter first value: ";
        is >> p.first;
        cout << "Enter second value: ";
        is >> p.second;
        return is;
    }
};

int main (){
    try{
        Pair<int, double> p1(10, 20.5);
        cout << p1 << '\n';
        
        Pair<string, string> p2("Saavdhaani Hati", "Durghatna Ghati");
        Pair<string, string> p3(p2); //copy constructor kaa use
        cout << p3 << '\n';
    }catch(const exception &e){
        cout << e.what() << endl;
    }
}