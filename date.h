//����������
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
		int outDy();//������ 
		int outDm(); //������ 
		int outDd(); //������ 
	
		

	private:
	    unsigned short int year;
		unsigned short int month;
		unsigned short int day;
	};
#endif
