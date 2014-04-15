#include<iostream>
#include<windows.h>
//functions for the main parameters
int get_d(int a,int M){
    if((19*a+M)%30==28||(19*a+M)%30==29){
         return ((19*a+M)%30)-1;
    }
    else{
         return (19*a+M)%30;
    }
}
int get_e(int b,int c,int d,int N){
    return (2*b+4*c+6*d+N)%7;
}
int get_a(int input){
    return input%19;
}
int get_b(int input){
    return input%4;
}
int get_c(int input){
    return input%7;
}
//catch function
bool test_support(int input){
    int i=0;
    while(input<=1899||input>=2100){
         if(i>=10){
              std::cout<<"\n\nEXIT\n";
              return false;
         }
         std::cout<<"Sorry, your input must be in the 20th or 21st century. Please try again:";
         std::cin>>input;
         i++;
    }
    return true;
}
//configuration function
int to_month_n_cout(int e,int d){
    int spring_begin=21;//March
    int spring_begin_month_length=31;//For march
    int prop_eastern_month_length=30;//Propably in April
    
    if(e+d+1<=spring_begin_month_length-spring_begin){                                       
         std::cout<<static_cast<int>(spring_begin+d+e+1)<<" "<<"March\n";
    }
    else if(e+d+1>spring_begin_month_length-spring_begin){
         //eastern wouldnt be in May
         if((spring_begin_month_length-spring_begin+prop_eastern_month_length)-(e+d+1)>0){
              std::cout<<"Eastern is in May, this programm isnt yet initialized for this situation";
              return 0;
         }
         std::cout<<static_cast<int>((e+d+1+spring_begin)-spring_begin_month_length)<<" "<<"April\n";
    }
    else{
         std::cout<<"\nunexpected catch";
    }
}
int main(){
    //make an first alert to insert
    std::cout<<"Please type the number of the year you want to know:\n";
    //initialize variables
    int input;
    //For the 20th and 21st century
    int M=24;
    int N=5;
    //catch this out
    std::cin>>input;
    if(!test_support(input))
         return 0;
    //initialize parameters
    int d=get_d(get_a(input),M);
    std::cout<<"d is "<<d<<"\n";
    int e=get_e(get_b(input),get_c(input),get_d(get_a(input),M),N);
    std::cout<<"e is "<<e<<"\n";
    //Get configurations for the month stuff
    to_month_n_cout(e,d);
    //Let five seconds left
    std::cout<<"\n\n"<<"exit in 5 seconds";
    Sleep(5000);
}
