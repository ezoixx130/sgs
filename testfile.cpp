#include<iostream>
#include<sstream>
#include"deck.h"

using namespace std;

int main(){
	CHandcard hdcd(DIAMOND,"A","��");
	CDeck dck;
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"2","��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"3","��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"4","Щ");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"5","��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"6","��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,7,"��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,8,"֪");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,9,"��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"10","��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"J","��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"Q","��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,13,"��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
//	for(int i=1;i<=13;++i)hdcd=CHandcard(CLUB,i),cout<<hdcd.GetValue()<<endl;
//	for(int i=1;i<=13;++i)hdcd=CHandcard(HEART,i),cout<<hdcd.GetValue()<<endl;
//	for(int i=1;i<=13;++i)hdcd=CHandcard(SPADE,i),cout<<hdcd.GetValue()<<endl;
	dck.shuffle();
	cout<<endl;
	for(int i=0;i<13;++i)cout<<dck.card[i]<<endl;
}
