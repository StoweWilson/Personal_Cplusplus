//
// Created by Stowe Danger on 10/13/24.
//
#include <iostream>
#include <sstream>
#include <cmath>
#include <complex>
#include "combine.h"
using namespace std;
/*FUnction Calling all Varibles*/
void match(double dis,double acc,double vi,double vf,double t) {
    /*Storing what to find and what not to find*/
    string to_find,dont_need;
    /*What to find*/
    cout << "what are you trying to find(Ex: time): ";
    cin >> to_find;
    /*What they dont need*/
    cout << "What is your problem not asking for: ";
    cin >> dont_need;

    /* finding velocity inital*/
    if(to_find == "vi" || to_find == " velocity inital" || to_find == "Velocity Inital" || to_find == "VI") {
        /*No distance*/
        if(dont_need== "dis") {
            cout<<"Use vf=vi+at as your equation to find vi";
            cout<< "your equation would look like this" << vf <<"="<<vi << "+" << acc*t;
            /*no veloicty final*/
        }else if  (dont_need== "vf") {
            cout << "use dis =vi*t+1/2at^2 as your equation to find vi";
            cout << "Your equation would look like this: " << dis << " = vi*" << t << " + 1/2*" << acc << "*" << t << "^2" << endl;
            /*No Time*/
        } else if (dont_need == "t") {
            cout << "Use vf^2 = vi^2 + 2*a*dis as your equation to find vi." << endl;
            cout << "Your equation would look like this: " << vf << "^2 = vi^2 + 2*" << acc << "*" << dis << endl;
            /*No Acceleration*/
        } else if (dont_need == "acc") {
            cout << "Use dis = ((vi + vf)/2)*t as your equation to find vi." << endl;
            cout << "Your equation would look like this: " << dis << " = (vi + " << vf << ")/2 * " << t << endl;
        }
        /*Finding velocity Final*/
        else if (to_find == "vf" || to_find == "velocity final"|| to_find == "Velocity Final" || to_find == "VF") {
            /*No Distance*/
            if (dont_need == "dis") {
                cout << "Use vf = vi + a*t as your equation to find vf." << endl;
                cout << "Your equation would look like this: vf = " << vi << " + " << acc << "*" << t << endl;
                /*No Time*/
            }else if(dont_need== "t") {
                cout << "Use vf^2 = vi^2 + 2a*dis" << endl;
                cout << "Your equation whould look like this: vf^2 = " << pow(vi,2) << "+" << (2 * acc)*dis;
                /*No Acceleration*/
            } else if(dont_need== "acc") {
                cout << "Use dis = 1/2(vi + vf)t to find vf" << endl;
                cout << "Your equation would look like this: " << dis << "= 1/2("<< vi << "+ vf)"<< t << endl;
                /*No Velocity Inital*/
            } else if (dont_need == "vi") {
                cout << "Use dis = vf*t - 1/2*a*t^2 as your equation to find vf." << endl;
                cout << "Your equation would look like this: " << dis << " = vf*" << t << " - 1/2*" << acc << "*" << t << "^2" << endl;
            }
        }
        /*To Find Distance*/
        else if (to_find == "dis" || to_find == "distance" || to_find == "Distance" || to_find == "D" || to_find == "d") {
            /*No Velocity Final*/
            if (dont_need == "vf") {
                cout << "Use dis = vi*t + 1/2*a*t^2 as your equation to find distance." << endl;
                cout << "Your equation would look like this: dis = " << vi << "*" << t << " + 1/2*" << acc << "*" << t << "^2" << endl;
                /*No Time*/
            }else if(dont_need== "t") {
                cout << "Use vf^2 = vi^2 + 2a*dis as your equation to find distance." << endl;
                cout << "Your equation would look like this:" <<  pow(vf,2) << "="<<pow(vi,2) << "+" << acc *2 << "* dis" << endl;
                /*No Acceleration*/
            }else if(dont_need== "acc") {
                cout << "Use dis = 1/2(vi + vf)t to find distance" << endl;
                cout << "Your equation would look like this:" << "dis =" << (.5*(vi + vf))* t << endl;
                /*No Velocity Inital*/
            }else if (dont_need == "vi") {
                cout << "Use dis = vf*t - 1/2*a*t^2 as your equation to find distance." << endl;
                cout << "Your equation would look like this: dis = " << vf << "*" << t << " - 1/2*" << acc << "*" << t << "^2" << endl;
            }
        }
        /*Finding Acceleratioin*/
        else if (to_find == "acc" || to_find == "a"||to_find == "A" || to_find == "acceleration"|| to_find == "Acceleration") {
            /*No Distance*/
            if (dont_need == "dis") {
                cout << "Use vf = vi + a*t as your equation to find acceleration." << endl;
                cout << "Your equation would look like this: " << vf << " = " << vi << " + a*" << t << endl;
                /*No Velocity Final*/
            } else if (dont_need == "vf") {
                cout << "Use dis = vi*t + 1/2*a*t^2 as your equation to find acceleration." << endl;
                cout << "Your equation would look like this: " << dis << " = " << vi << "*" << t << " + 1/2*a*" << t << "^2" << endl;
                /*No Time*/
            } else if (dont_need== "t") {
                cout << "Use equation vf^2 = vi^2 + 2a*dis to find acceleration." << endl;
                cout<< " Your equation would look like this:" << pow(vf,2) << "=" << pow(vi,2) << " + a*2" << dis << endl;
                /*No Velocity Inital*/
            } else if (dont_need== "vi") {
                cout << "Use equation dis = vf * t -1/2 * a * t^2" << endl;
                cout << "Your equation would look like this" << dis << " = " << vf << "*" << t << "-1/2*a*" << pow(t,2)<< endl;
            }
        }
        /*Finding Time*/
        else if (to_find == "time" || to_find == "t" || to_find == "Time"|| to_find == "T") {
            /*No Distance*/
            if (dont_need == "dis") {
                cout << "Use vf = vi + a*t as your equation to find time." << endl;
                cout << "Your equation would look like this: " << vf << " = " << vi << " + " << acc << "*t" << endl;
                /*No Velocity Final*/
            } else if (dont_need == "vf") {
                cout << "Use dis = vi*t + 1/2*a*t^2 as your equation to find time." << endl;
                cout << "Your equation would look like this: " << dis << " = vi*t + 1/2*a*t^2" << endl;
                /*No Acceleration*/
            } else if (dont_need== "acc") {
                cout << "Use dis = 1/2(vi + vf)t to find time";
                cout << "Your equation would look like this:" << dis<< " = 1/2(" << vi + vf << ")*t" << endl;
                /*No velocity Inital*/
            }else if(dont_need== "vi") {
                cout << "Use dis=vf * t - 1/2*a*t^2" << endl;
                cout << "Your equation would look like this:" << dis << " = " << vf << "* t"<<  acc *.5  << "*t^2"<< endl;
            }
        } else {
            cout << "Invalid input for what you're trying to find." << endl;
        }
    }
}
