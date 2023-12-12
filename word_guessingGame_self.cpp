#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main(){
    string words[] = {"about","above","abuse","actor","acute","admit","adopt","adult",
                      "after","again","agent","agree","ahead","alarm","album","alert",
                      "alike","alive","allow","alone","along","alter","among","anger",
                      "began","begin","begun","being","below","civil","claim","class",
                      "clean","drawn","dream","dress","drill","drink","drive","drove",
                      "dying","error","event","every","flash","fleet","floor","fluid",
                      "group","grown","guard","guess","hotel","house","index","inner",
                      "input","issue","joint","jones","judge","known","stone","stood",
                      "valid","value","video","virus","visit","vital","voice","write"};

    int size = sizeof(words) / sizeof(words[0]);
    cout<<"\tWord Guessing Game\t\n";
    cout<<"You can quit anytime by entering \"quit\""<<endl;

    srand(time(NULL));
    string ans;
    int count = 0;


    while (true){
        int index = rand() % size;

        int p1 = rand() % 5;
        int p2 = rand() % 5;

        if (p2 == p1){
            p2 = rand() % 5;
        }

        string change_str = words[index];
        string original_str = change_str;
        change_str[p1] = '*';
        change_str[p2] = '*';

        cout<<"Word :"<<change_str<<endl;

        cout<<"Enter your guess word :";
        cin>>ans;

        if (ans == original_str){
            cout<<"Your answer is correct."<<endl;
            count++;

        }else if (ans.compare("quit") == 0){
            cout<<"Your total correct answers :"<< count<<endl;
            exit(1);

        }else{
            cout<<"Incorrect Answer!"<<endl;
            cout<<"Correct answer is "<<original_str<<endl;
        }

    }
    return 0;
}
