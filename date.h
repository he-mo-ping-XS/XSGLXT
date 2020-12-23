//声明日期类
#ifndef DATE_H
    #define DATE_H
    #include <iostream>
	#include <string>
	using namespace std;
	class CDATE{
	public:
		CDATE();
		CDATE(unsigned short int year,unsigned short int month,unsigned short int day);
		void setDate(unsigned short int year,unsigned short int month,unsigned short int day);
		void outputDate();
		int outDy();//返回年 
		int outDm(); //返回月 
		int outDd(); //返回日 
	
		

	private:
	    unsigned short int year;
		unsigned short int month;
		unsigned short int day;
	};
#endif
