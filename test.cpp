#include <iostream>
 
int main() 
  {
    int year;
    bool digit=false;
    bool leapyear=false;
    std::cout<<"Enter a year: \n";
    std::cin>>year;
    if(year>999&&year<10000)
      digit=true;
    if(year%400==0)
    	leapyear=true;
    if(!leapyear)
    	if (year%100!=0&&year%4==0)
    		leapyear=true;
    if(leapyear)
      std::cout<<"the year is leap\n";
    else
      std::cout<<"the year isnt leap\n";
  }
