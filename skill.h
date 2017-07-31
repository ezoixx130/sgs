#include<cstring>
#include<string>

using namespace std;


#ifndef CSkill
struct CSkill;


struct CSkill{
	string name,discription;
	CSkill():name(""),discription(""){}
	CSkill(string nm,string dsp):name(nm),discription(dsp){}
	friend ostream& operator<<(ostream& os,CSkill skl){
		os<<(skl.name+':')<<skl.discription;
		return os;
	}
};
#endif
