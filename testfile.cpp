#include<iostream>
#include<sstream>
#include"deck.h"

using namespace std;

int main(){
	CHandcard hdcd(DIAMOND,"A","你");
	CDeck dck;
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"2","们");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"3","这");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"4","些");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"5","愚");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"6","蠢");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,7,"无");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,8,"知");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,9,"的");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"10","人");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"J","类");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,"Q","虫");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(DIAMOND,13,"子");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
//	for(int i=1;i<=13;++i)hdcd=CHandcard(CLUB,i),cout<<hdcd.GetValue()<<endl;
//	for(int i=1;i<=13;++i)hdcd=CHandcard(HEART,i),cout<<hdcd.GetValue()<<endl;
//	for(int i=1;i<=13;++i)hdcd=CHandcard(SPADE,i),cout<<hdcd.GetValue()<<endl;
	dck.shuffle();
	cout<<endl;
	for(int i=0;i<13;++i)cout<<dck.card[i]<<endl;
}
