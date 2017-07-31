#include<string>
#include<cstring>
#include<iostream>

#include"classtype.h" 

using namespace std;


#ifndef CHandcard
struct CHandcard;


struct CHandcard{
	colortype color;
	int number;
	string name;
	CHandcard():color(null),number(0),name(""){}
	CHandcard(colortype clr,int nmb,string nm=""):color(clr),number(nmb),name(nm){}
	CHandcard(colortype clr,string _str,string nm=""):color(clr),name(nm){
		if(_str=="A")number=1;
		if(_str=="J")number=11;
		if(_str=="Q")number=12;
		if(_str=="K")number=13;
		char ch=_str[0];
		if(ch>'1'&&ch<='9')number=ch-48;
		if(_str=="10")number=10;
	}
	friend ostream& operator<<(ostream& os,CHandcard hdcd){
		os<<hdcd.GetValue()<<hdcd.name;
		return os;
	}
	string GetValue(){
		string str_val;
		switch(color){
			case diamond:str_val+=(char)4;break;
			case club:str_val+=(char)5;break;
			case heart:str_val+=(char)3;break;
			case spade:str_val+=(char)6;break;
			default:break;
		}
		switch(number){
			case 1:str_val+='A';break;
			case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:str_val+=(char)(number+48);break;
			case 10:str_val+="10";break;
			case 11:str_val+='J';break;
			case 12:str_val+='Q';break;
			case 13:str_val+='K';break;
		}
		return str_val;
	}
};
#endif
