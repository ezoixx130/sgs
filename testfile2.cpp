#include<iostream>
#include"person.h"

using namespace std;

int main(){
	CPerson person("�ź�",4);
	CSkill skill("��","�ǳ���");
	person.add_skill(skill);
	skill=CSkill("��","�ǳ���");
	person.add_skill(skill);
	cout<<person;
}
