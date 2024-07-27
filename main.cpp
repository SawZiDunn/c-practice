//
// Created by User on 6/20/2023.
//

#include <iostream>
#include <vector>

using namespace std;

class Bank{
public:

    vector<string> data;

    void setter(string name, string email, string password){
        user_name = name;
        user_email = email;
        user_password = password;
    }

    vector<string> getter(){
        data.push_back(user_name);
        data.push_back(user_email);
        data.push_back(user_password);

        return data;

    }
private:
    string user_name;
    string user_email;
    string user_password;

protected:
};

int main(){
    Bank bank;
    bank.setter("ZiDunn", "zid@gmail.com", "6456");
    vector<string> data = bank.getter();

    for (auto i = data.begin(); i < data.end(); i++){
        cout<< *i << " "<<endl;
    }

    int size_of_vector = data.size();
    cout<<"Vector Size : "<<size_of_vector<<endl;

    for (auto i = 0; i<size_of_vector ; i++){
        cout<< "Data from vector : "<< data.at(i)<<endl;
    }

    return 0;
}
