#include<iostream>
#include<sstream>
#include"deck.h"

using namespace std;

int main(){
	CHandcard hdcd(diamond,"A","��");
	CDeck dck;
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"2","��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"3","��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"4","Щ");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"5","��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"6","��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,7,"��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,8,"֪");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,9,"��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"10","��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"J","��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"Q","��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,13,"��");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
//	for(int i=1;i<=13;++i)hdcd=CHandcard(club,i),cout<<hdcd.GetValue()<<endl;
//	for(int i=1;i<=13;++i)hdcd=CHandcard(heart,i),cout<<hdcd.GetValue()<<endl;
//	for(int i=1;i<=13;++i)hdcd=CHandcard(spade,i),cout<<hdcd.GetValue()<<endl;
	dck.shuffle();
	cout<<endl;
	for(int i=0;i<13;++i)cout<<dck.card[i]<<endl;
}
