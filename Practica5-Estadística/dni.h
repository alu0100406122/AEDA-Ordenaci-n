#ifndef _DNI_H
#define _DNI_H

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std; 

class DNI{
    private:
        int num_;
        
    public:
        //Variable estática para contabilizar el número de comparaciones.
        static int comp;
        
        DNI();
        DNI(int num);
        ~DNI();
        void set_Dni(int num);
        int get_Dni();
        bool operator==(DNI& dni_);
        bool operator<(DNI &dni_);
        bool operator>(DNI &dni_);
        bool operator<=(DNI &dni_);
        bool operator>=(DNI &dni_);
        friend ostream& operator<<(ostream &salida ,const DNI &a);
};

int DNI::comp = 0;

DNI::DNI(){
    num_=0;
}

DNI::~DNI(){}

void DNI::set_Dni(int num){
    num_=num;
}

int DNI::get_Dni(){
    return num_;
}

bool DNI::operator==(DNI &dni_){
    if(num_ == dni_.get_Dni())
        return true;
    else
        return false;
}

bool DNI::operator<(DNI &dni_){
    comp++;
    if(num_ < dni_.get_Dni())
        return true;
    else
        return false;
}

bool DNI::operator>(DNI &dni_){
    comp++;
    if(num_ > dni_.get_Dni())
        return true;
    else
        return false;
}

bool DNI::operator<=(DNI &dni_){
    comp++;
    if(num_ <= dni_.get_Dni())
        return true;
    else
        return false;
}

bool DNI::operator>=(DNI &dni_){
    comp++;
    if(num_ >= dni_.get_Dni())
        return true;
    else
        return false;
}

ostream& operator<<(ostream &salida , const DNI &a){
  salida << a.num_ ;
  return salida;
}

#endif