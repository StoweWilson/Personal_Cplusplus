//
// Created by Stowe Danger on 10/11/24.
//
#include <iostream>
#include <sstream>
#include <cmath>
#include <complex>
#include "combine.h"
using namespace std;
/*Asking if equation has Distance*/
void find_distance(double &dis) {
    string dis_choice;
    /*While Loop*/
    while (true) {
        /*Storing yes or no for if there is distance*/
        cout<<"does your problem have distance (yes or no)?  :";
        cin>>dis_choice;
        /*if answer is yes*/
        if(dis_choice == "yes") {
            cout<<"Enter the distance between two points:  ";
            cin>>dis;
            break;
        }
        /*if answer is no*/
        else if (dis_choice == "no") {
            dis = 0;
            break;
        }
        /*if not yes or no*/
        else{
            cout<<"Invaild input. Please Enter yes/no or your varible";
        }
    }
}
/*Function to Ask if equation has distance*/
void find_acc(double &acc) {
    string acc_choice;
    /*While loop*/
    while (true) {
        /*Question for if equation has Distance*/
        cout << "does your problem have const acc?  :";
        cin>>acc_choice;
        /*if answer is yes*/
        if(acc_choice == "yes") {
            cout<<"Enter the acceleration :";
            cin>>acc;
            break;
            /*if answer is no*/
        }else if (acc_choice == "no") {
            acc = 0;
            break;
            /*if answer is nethier*/
        }else {
            cout<<"Invaild input. Please Enter yes/no or your varible";
        }
    }
}
/*Function to ask if equation has velocity*/
void find_velocity(double &vi,double &vf){
    string velocityi_choice, velocityf_choice;
    /* Inital velocity While loop*/
    while (true) {
        /*Question for if equation has inital velocity*/
        cout<<"Does your problem have velocity inital (yes or no)?  :";
        cin >> velocityi_choice;
        /*if velocity inital is yes*/
        if(velocityi_choice == "yes") {
            cout<<"Enter the velocity inital:  ";
            cin>>vi;
            break;
            /*If velocity inital is no*/
        }else if (velocityi_choice == "no") {
            vi = 0;
            break;
            /*if any other input*/
        }else {
            cout<<"Invalid input. Please enter 'yes' or 'no'.  :";
        }
    }
    /*Final velocity while loop*/
    while (true) {
        /*Final Velocity question*/
        cout<<"Does your problem have final velocity: ";
        cin >> velocityf_choice ;
        /*if Final velocity is yes*/
        if( velocityf_choice == "yes") {
            cout<<"Enter the final velocity:  ";
            cin>>vf;
            break;
            /*if final velocitu is no*/
        }else if (velocityf_choice == "no") {
            vf = 0;
            break;
            /*if any other input*/
        }else {
            cout << "Invalid input. Please enter 'yes' or 'no'  :";
        }
    }
}
/*Function for if equation has time */
void find_time(double &t){
    /*time While loop*/
    while (true) {
        string time_choice;
        /*If equation has time Question*/
        cout << "Does your problem have time (yes or no)?  :";
        cin>>time_choice;
        /*if time is yes */
        if(time_choice == "yes") {
            cout<<"Enter the time. :";
            cin >> t;
            break;
            /*if time is no*/
        }else if (time_choice == "no") {
            t = 0;
            break;
            /*if any other input*/
        }else {
            cout << "Invalid input. Please enter 'yes' or 'no'.  :" ;
        }
    }
}

/*void find_problem(double dis,double acc,double vi,double vf,double t){

    if (dis != 0 && vi != 0 && vf != 0 && acc != 0 && t==0) {
        cout<<"i would recomend useing vf^2 = vi^2 + 2aD ,to find time"<<endl;
        cout<<"your equation would look like this\n"<< pow(vf,2)<<"=="<<pow(vi,2)<<"+"<< (acc*2)*dis <<endl;
    } else if (vf != 0 && vi!= 0 && acc!=0 && t != 0  && dis == 0 ) {
        cout << "I would use vf = vi +at to find distance " << endl;
        cout<<"your equation would look like this\n"<< vf<< "="<<vi<<"+"<<acc*t <<endl;
    }else if (vf != 0 && acc !=0 && t != 0 && dis !=0 && vi ==0 ) {
        cout<< "D = vf*t -1/2at^2 to find velocity inital" << endl;
        cout<<"your equation would look like this\n"<< dis<<"="<<vf*t<<"-"<<(.5*acc) * pow(t,2) << endl;
    }else if (acc != 0  && t !=0 && vi !=0 && dis != 0 && vf == 0 ) {
        cout<< "D = vi*t + 1/2at^2 to find velocity final" << endl;
        cout<<"your equation would look like this\n"<< dis<<"="<<vi<<"+"<<(.5*acc) * pow(t,2) << endl;
    }else if (vf != 0  && t !=0 && vi !=0 && dis != 0 && acc == 0){
        cout << "D = 1/2(vi+vf)t to find acceleration"<<endl;
    cout<<"your equation would look like this\n"<< dis<<"="<<(.5*(vi+vf))* pow(t,2) << endl;
    }
    else if (dis != 0 && acc != 0 && vi == 0 && vf == 0 && t != 0) {
        cout << "First, find initial or final velocity using vi = (d - 1/2at^2) / t or vf = sqrt(vi^2 + 2ad)." << endl;
        //cout<<"your equation would look like this"<< vi,"=","(",dis,"-",(.5*acc) * pow(t,2) << endl;
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
*/
/*Function to print out all functions*/
int main(){
    /*all the equation varibles set to zero*/
    double dis = 0,acc = 0,vi = 0,vf = 0,t = 0;

    cout << "Physics Kinematic Calculator 1.0\n";

    find_distance(dis);
    find_acc(acc);
    find_velocity(vi, vf);
    find_time(t);
    match(dis,acc,vi,vf,t);

    return 0;

}