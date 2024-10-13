//
// Created by Stowe Danger on 10/11/24.
//
#include <iostream>
#include <sstream>
#include <cmath>
#include <complex>
using namespace std;
void find_distance(double &dis) {
    string dis_choice;
    while (true) {
        cout<<"does your problem have distance (yes or no)?"<<endl;
        cin>>dis_choice;

        if(dis_choice == "yes") {
            cout<<"Enter the distance between two points: "<<endl;
            cin>>dis;
            break;
        }
        else if (dis_choice == "no") {
            dis = 0;
            break;
        }
        else{
            cout<<"Invaild input. Please Enter yes/no or your varible";
        }
    }
}

void find_acc(double &acc) {
    string acc_choice;
    while (true) {
        cout << "does your problem have const acc?"<<endl;
        cin>>acc_choice;
        if(acc_choice == "yes") {
            cout<<"Enter the acceleration"<<endl;
            cin>>acc;
            break;
        }else if (acc_choice == "no") {
            acc = 0;
            break;
        }else {
            cout<<"Invaild input. Please Enter yes/no or your varible";
        }
    }
}

void find_velocity(double &vi,double &vf){
    string velocityi_choice, velocityf_choice;
    while (true) {
        cout<<"Does your problem have velocity inital (yes or no)?"<<endl;
        cin >> velocityi_choice;

        if(velocityi_choice == "yes") {
            cout<<"Enter the velocity inital:  ";
            cin>>vi;
            break;
        }else if (velocityi_choice == "no") {
            vi = 0;
        }else {
            cout<<"Invalid input. Please enter 'yes' or 'no'."<<endl;
        }
    }
    while (true) {
        cout<<"Does your problem have final velocity: ";
        cin >> velocityf_choice ;
        if( velocityf_choice == "yes") {
            cout<<"Enter the final velocity:  ";
            cin>>vf;
            break;
        }else if (velocityf_choice == "no") {
            vf = 0;
            break;
        }else {
            cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
        }
    }
}

void find_time(double &t){
    while (true) {
        string time_choice;
        cout << "Does your problem have time (yes or no)?"<<endl;
        cin>>time_choice;
        if(time_choice == "yes") {
            cout<<"Enter the time"<<endl;
            cin >> t;
            break;
        }else if (time_choice == "no") {
            t = 0;
            break;
        }else {
            cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
        }
    }
}

void find_problem(double dis,double acc,double vi,double vf,double t){
    if (dis != 0 && vi != 0 && vf != 0 && acc != 0 && t==0) {
        cout<<"i would recomend useing vf^2 = vi^2 + 2aD ,to find time"<<endl;
    } else if (vf != 0 && vi!= 0 && acc!=0 && t != 0  && dis == 0 ) {
        cout << "I would use vf = vi +at to find distance " << endl;
    }else if (vf != 0 && acc !=0 && t != 0 && dis !=0 && vi ==0 ) {
        cout<< "D = vf*t -1/2at^2 to find velocity inital" << endl;
    }else if (acc != 0  && t !=0 && vi !=0 && dis != 0 && vf == 0 ) {
        cout<< "D = vi*t + 1/2at^2 to find velocity final" << endl;
    }else if (vf != 0  && t !=0 && vi !=0 && dis != 0 && acc == 0){
        cout << "D = 1/2(vi+vf)t to find acceleration"<<endl;
    }
    else if (dis != 0 && acc != 0 && vi == 0 && vf == 0 && t != 0) {
        cout << "First, find initial or final velocity using vi = (d - 1/2at^2) / t or vf = sqrt(vi^2 + 2ad)." << endl;
    } else if (dis != 0 && acc != 0 && vi != 0 && vf == 0 && t == 0) {
        cout << "First, find final velocity using vf^2 = vi^2 + 2ad, then use vf = vi + at to find time." << endl;
    } else if (dis == 0 && acc == 0 && vi != 0 && vf != 0 && t != 0) {
        cout << "Use vf = vi + at to solve for acceleration." << endl;
    } else if (dis == 0 && acc != 0 && vi != 0 && vf != 0 && t == 0) {
        cout << "Use vf^2 = vi^2 + 2ad to find distance." << endl;
    }else {
        cout << "Not enough data to suggest a formula." << endl;
    }
}
int main(){
    double dis = 0,acc = 0,vi = 0,vf = 0,t = 0;

    cout << "Physics Kinematic Calculator 1.0\n";

    find_distance(dis);
    find_acc(acc);
    find_velocity(vi, vf);
    find_time(t);

    find_problem(dis,acc,vi,vf,t);
    return 0;

}