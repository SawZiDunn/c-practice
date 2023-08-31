#include<iostream>
using namespace std;

class Arrow{
public:
    int myage;
    string mycolor;
    int myArray[10];

    Arrow(int age1,string colour1){
        cout<<"Hello, this is from class constructor."<<endl;
        myage=age1;
        mycolor=colour1;

    }

    void bank(){
        cout<<bankID<<endl;
    }

    int bank1(){
        return bankID;
    }

    void banker(int id,string namae){
        bankID=id;
        username=namae;
    }
private:
    int bankID;
    string username;

protected://Can only be accessed through derives classes...
    string words="This is protected";
};


//derived class
class Hello:public Arrow{
public:
    string nani="How_are_you?";
    string retirement_case="old_age";

    Hello(int age1, string colour1) : Arrow(age1, colour1) {
        cout<<words<<endl;
    }
};

int main(){

    Arrow obj1(19,"blue");
    cout<<obj1.mycolor<<"\n"<<obj1.myage<<endl;
    obj1.banker(456,"ZiDunn");
    obj1.bank();

    Hello obj2(0, std::string());

    return 0;
}