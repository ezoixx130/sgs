#include<iostream>
#include<sstream>
#include"deck.h"

using namespace std;

int main(){
	CHandcard hdcd(diamond,"A","你");
	CDeck dck;
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"2","们");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"3","这");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"4","些");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"5","愚");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"6","蠢");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,7,"无");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,8,"知");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,9,"的");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"10","人");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"J","类");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,"Q","虫");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
	hdcd=CHandcard(diamond,13,"子");
	cout<<hdcd<<endl;
	dck.card.push_back(hdcd);
//	for(int i=1;i<=13;++i)hdcd=CHandcard(club,i),cout<<hdcd.GetValue()<<endl;
//	for(int i=1;i<=13;++i)hdcd=CHandcard(heart,i),cout<<hdcd.GetValue()<<endl;
//	for(int i=1;i<=13;++i)hdcd=CHandcard(spade,i),cout<<hdcd.GetValue()<<endl;
	dck.shuffle();
	cout<<endl;
	for(int i=0;i<13;++i)cout<<dck.card[i]<<endl;
}
