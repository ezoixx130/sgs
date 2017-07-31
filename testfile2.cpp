#include<iostream>
#include"person.h"

using namespace std;

int main(){
	CPerson person("张涵",4);
	CSkill skill("软","非常软");
	person.add_skill(skill);
	skill=CSkill("肥","非常肥");
	person.add_skill(skill);
	cout<<person;
}
