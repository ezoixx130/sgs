#include<iostream>
#include<string>
#include<conio.h>
#include"player.h" 

using namespace std;

inline void cls(){system("cls");}

inline void HideTheCursor(){
	CONSOLE_CURSOR_INFO cciCursor;
	HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
	if(GetConsoleCursorInfo(hStdOut,&cciCursor)){
		cciCursor.bVisible=FALSE;
		SetConsoleCursorInfo(hStdOut,&cciCursor);
	}
}

inline void ShowTheCursor(){
	CONSOLE_CURSOR_INFO cciCursor;
	HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
	if(GetConsoleCursorInfo(hStdOut,&cciCursor)){
		cciCursor.bVisible=TRUE;
		SetConsoleCursorInfo(hStdOut,&cciCursor);
	}
}

int LineDistance(int ps1,int ps2,int total){
	if(ps1<ps2)return min(ps1+total-ps2,ps2-ps1);
	return min(ps2+total-ps1,ps1-ps2);
}

bool Respond_WX(int total,int user,string str_card,int tab,CPlayer player[],int your_turn,CDeck& discard_deck){
	int i_no;
	CPlayer *you=&player[your_turn];
	for(int i=1;i<=total;++i){
		for(vector<CHandcard>::iterator iter=player[i].handcard.card.begin();
			iter!=player[i].handcard.card.end();++iter){
			if(i==your_turn&&iter->name=="��и�ɻ�"){
				for(int j=1;j<=tab;++j)SlowDisplay("\t",5);
				SlowDisplay("���",5);
				cout<<user;
				SlowDisplay("ʹ��"+str_card+"���Ƿ�Ҫʹ����и�ɻ���\n",5);
				you->PrintCard(1);
				SlowDisplay("\n",5);
				for(int j=1;j<=tab;++j)SlowDisplay("\t",5);
				SlowDisplay("0 ��ʹ����и�ɻ�\n",5);
				wx_rechoose:
				cin>>i_no;
				if(i_no==0)break;
				if(you->handcard.card[i_no-1].name=="��и�ɻ�"){
					for(int j=1;j<=tab;++j)SlowDisplay("\t",5);
					SlowDisplay("��ʹ������и�ɻ���\n",5);
					you->PlayCard(i_no,discard_deck);
					if(Respond_WX(total,i,"��и�ɻ�",tab+1,player,your_turn,discard_deck))return false;
					return true;
				}else{
					for(int j=1;j<=tab;++j)SlowDisplay("\t",5);
					SlowDisplay("������ѡ��\n",5);
					goto wx_rechoose;
				}
			}else
				if(iter->name=="��и�ɻ�"&&user!=i){
					for(int j=1;j<=tab;++j)SlowDisplay("\t",5);
					SlowDisplay("���",5);
					cout<<i;
					SlowDisplay("ʹ����и�ɻ���\n",5);
					player[i].PlayCard(iter,discard_deck);
					if(Respond_WX(total,i,"��и�ɻ�",tab+1,player,your_turn,discard_deck))return false;
					return true;
				}
			}
	}
	return false;
}


void m_1v1(){
	cls();
	CDeck deck,discard_deck;
	deck.Configure();
	CPlayer player[3],*you;
	int p_left=2,now_turn=0,your_turn;
	srand(time(0));
	player[1].Health()=4;
	player[2].Health()=4;
	player[1].MaxHealth()=4;
	player[2].MaxHealth()=4;
	player[1].identity=RED_CAMP;
	player[2].identity=BLUE_CAMP;
	player[1].DrawCard(deck,4);
	player[2].DrawCard(deck,4);
	your_turn=rand()%2+1;
	you=player+your_turn;
	while(p_left>1){
		now_turn%=2;
		++now_turn;
		if(deck.Size()<2){
			deck=discard_deck;
			discard_deck.Clear();
			deck.Shuffle();
		}
		player[now_turn].DrawCard(deck,2);
		if(now_turn==your_turn){
			while(1){
				cls();
				if(!(you->handcard.Size())){
					SlowDisplay("���ƿɳ����Զ������غ�\n",5);
					Sleep(500);
					break;
				}
				for(int i=1;i<=2;++i)if(i!=your_turn){
					SlowDisplay("���",5);
					cout<<i<<"   ";
					player[i].PrintSituation();
					SlowDisplay("����",5);
					cout<<max(0,LineDistance(i,your_turn,2)+player[i].c_horse2-you->c_horse1);
					SlowDisplay("\n\n",5);
				}
				SlowDisplay("��   ",5);
				you->PrintSituation();
				SlowDisplay("������ƣ�\n",5);
				you->PrintCard();
//				discard_deck.PrintCard();
				int u_no=0,i_no=0;
				CHandcard u_card,d_card;
				CPlayer *target;
				CWeapon t_weapon;
				int i_target,c_target,t_handcard_s,wx_user;
				SlowDisplay("\n0 �����غ�",5);
				rechoose:
				SlowDisplay("\n��ѡ����Ҫ�������\n",5);
				cin>>u_no;
				if(!u_no)break;
				if(u_no<0||u_no>you->handcard.Size()){
					SlowDisplay("������ѡ��",5);
					Sleep(500);
					continue;
				}
				u_card=you->handcard.card[u_no-1];
				{
					if(u_card.name=="ɱ"){
						SlowDisplay("��ѡ��Ŀ�꣨�����ţ�\n",5);
						cin>>i_target;
						if(i_target==your_turn){
							SlowDisplay("ɱ���ܶ��Լ�ʹ�ã�\n",5);
							goto rechoose;
						}
						if(LineDistance(your_turn,i_target,2)>you->weapon.range){
							SlowDisplay("���벻�㣡\n",5);
							goto rechoose;
						}
						SlowDisplay("��ʹ����"+u_card.GetValue()+"ɱ\n",5);
						u_card=you->PlayCard(u_no,discard_deck);
						target=&player[i_target];
						for(vector<CHandcard>::iterator iter=target->handcard.card.begin();
							iter!=target->handcard.card.end();++iter){
							if(iter->name=="��"){
								SlowDisplay("\tĿ��ʹ��"+iter->GetValue()+"��",5);
								target->PlayCard(iter,discard_deck);
								goto end_play;
							}
						}
						--target->Health();
						SlowDisplay("\tɱ����Ŀ�꣡\n",5);
						if(target->Health()<=0){
							target->Die();
							--p_left;
							if(p_left==1)goto win;
						}
						goto end_play;
					}
					if(u_card.name=="��"){
						SlowDisplay("����������ʹ�ã�\n",5);
						goto rechoose;
					}
					if(u_card.name=="��"){
						if(you->Health()>=you->MaxHealth()){
							SlowDisplay("��Ѫ������������ʹ���ң�\n",5);
							goto rechoose;
						}
						SlowDisplay("��ʹ����"+u_card.GetValue()+"��\n",5);
						u_card=you->PlayCard(u_no,discard_deck);
						++you->Health();
						goto end_play;
					}
					if(u_card.name=="���Ӳ���"){
						SlowDisplay("��ѡ��Ŀ�꣨�����ţ�\n",5);
						cin>>i_target;
						if(i_target==your_turn){
							SlowDisplay("���Ӳ��Ų��ܶ��Լ�ʹ�ã�\n",5);
							goto rechoose;
						}
						target=&player[i_target];
						SlowDisplay("��ʹ����"+u_card.GetValue()+"���Ӳ���\n",5);
						u_card=you->PlayCard(u_no,discard_deck);
						if(Respond_WX(2,your_turn,"���Ӳ���",1,player,your_turn,discard_deck))goto rechoose;
						SlowDisplay("\t��ѡ��Ŀ���һ��������:",5);
						t_handcard_s=target->handcard.Size();
						for(int i=1;i<=t_handcard_s;++i)cout<<i<<' '<<"����  ";
						SlowDisplay("\n",5);
						if(target->weapon.name()!="")
							SlowDisplay("41 ���� "+target->weapon.card.GetValue()+target->weapon.name()+"  ",5);
						if(target->armor.name!="")
							SlowDisplay("42 ���� "+target->armor.GetValue()+target->armor.name+"  ",5);
						if(target->c_horse1!=false)
							SlowDisplay("43 ������ "+target->horse1.GetValue()+target->horse1.name+"  ",5);
						if(target->c_horse2!=false)
							SlowDisplay("44 ������ "+target->horse2.GetValue()+target->horse2.name+"  ",5);
						SlowDisplay("\n\t",5);
						rechoose_GH_dis:
						cin>>c_target;
						if(c_target>0&&c_target<=target->handcard.Size()){
							d_card=target->PlayCard(c_target,discard_deck);
							SlowDisplay("\t��������Ŀ���"+d_card.GetValue()+d_card.name+'\n',5);
						}else
						if(c_target==41&&target->weapon.name()!=""){
							t_weapon=target->weapon;
							target->weapon=CWeapon();
							discard_deck.AddCard(t_weapon.card);
							SlowDisplay("\t��������Ŀ�������"+t_weapon.card.GetValue()+t_weapon.name()+'\n',5);
						}else
						if(c_target==42&&target->armor.name!=""){
							d_card=target->armor;
							target->armor=CHandcard();
							discard_deck.AddCard(d_card);
							SlowDisplay("\t��������Ŀ��ķ���"+d_card.GetValue()+d_card.name+'\n',5); 
						}else
						if(c_target==43&&target->c_horse1){
							d_card=target->horse1;
							target->horse1=CHandcard();
							discard_deck.AddCard(d_card);
							SlowDisplay("\t��������Ŀ��Ľ�����"+d_card.GetValue()+d_card.name+'\n',5);
						}else
						if(c_target==44&&target->c_horse2){
							d_card=target->horse2;
							target->horse2=CHandcard();
							discard_deck.AddCard(d_card);
							SlowDisplay("\t��������Ŀ��ķ�����"+d_card.GetValue()+d_card.name+'\n',5);
						}else{
							SlowDisplay("\t������ѡ��\n",5);
							goto rechoose_GH_dis;
						}
					}
					if(u_card.name=="˳��ǣ��"){
						SlowDisplay("��ѡ��Ŀ�꣨�����ţ�\n",5);
						cin>>i_target;
						if(i_target==your_turn){
							SlowDisplay("˳��ǣ���ܶ��Լ�ʹ�ã�\n",5);
							goto rechoose;
						}
						target=&player[i_target];
						SlowDisplay("��ʹ����"+u_card.GetValue()+"˳��ǣ��\n",5);
						u_card=you->PlayCard(u_no,discard_deck);
						if(Respond_WX(2,your_turn,"˳��ǣ��",1,player,your_turn,discard_deck))goto rechoose;
						SlowDisplay("\t��ѡ��Ŀ���һ���ƻ��:",5);
						t_handcard_s=target->handcard.Size();
						for(int i=1;i<=t_handcard_s;++i)cout<<i<<' '<<"����  ";
						if(target->weapon.name()!="")
							SlowDisplay("41 ���� "+target->weapon.card.GetValue()+target->weapon.name()+"  ",5);
						if(target->armor.name!="")
							SlowDisplay("42 ���� "+target->armor.GetValue()+target->armor.name+"  ",5);
						if(target->c_horse1!=false)
							SlowDisplay("43 ������ "+target->horse1.GetValue()+target->horse1.name+"  ",5);
						if(target->c_horse2!=false)
							SlowDisplay("44 ������ "+target->horse2.GetValue()+target->horse2.name+"  ",5);
						SlowDisplay("\n\t",5);
						rechoose_SS_dis:
						cin>>c_target;
						if(c_target>0&&c_target<=target->handcard.Size()){
							d_card=target->PlayCard(c_target,you->handcard);
							SlowDisplay("\t������Ŀ���"+d_card.GetValue()+d_card.name+'\n',5);
						}else
						if(c_target==41&&target->weapon.name()!=""){
							t_weapon=target->weapon;
							target->weapon=CWeapon();
							you->handcard.AddCard(t_weapon.card);
							SlowDisplay("\t������Ŀ�������"+t_weapon.card.GetValue()+t_weapon.name()+'\n',5);
						}else
						if(c_target==42&&target->armor.name!=""){
							d_card=target->armor;
							target->armor=CHandcard();
							you->handcard.AddCard(d_card);
							SlowDisplay("\t������Ŀ��ķ���"+d_card.GetValue()+d_card.name+'\n',5); 
						}else
						if(c_target==43&&target->c_horse1){
							d_card=target->horse1;
							target->horse1=CHandcard();
							you->handcard.AddCard(d_card);
							SlowDisplay("\t������Ŀ��Ľ�����"+d_card.GetValue()+d_card.name+'\n',5);
						}else
						if(c_target==44&&target->c_horse2){
							d_card=target->horse2;
							target->horse2=CHandcard();
							you->handcard.AddCard(d_card);
							SlowDisplay("\t������Ŀ��ķ�����"+d_card.GetValue()+d_card.name+'\n',5);
						}else{
							SlowDisplay("\t������ѡ��\n",5);
							goto rechoose_GH_dis;
						}
					}
					if(u_card.name=="����"){
						SlowDisplay("��ѡ��Ŀ�꣺�������ţ�\n",5);
						cin>>i_target;
						if(i_target==your_turn){
							SlowDisplay("�������ܶ��Լ�ʹ�ã�",5);
							goto rechoose;
						}
						target=&player[i_target];
						SlowDisplay("��ʹ����"+u_card.GetValue()+"����\n",5);
						while(1){
							for(vector<CHandcard>::iterator iter=target->handcard.card.begin();
								iter!=target->handcard.card.end();++iter){
									if(iter->name=="ɱ"){
										d_card=target->PlayCard(iter,discard_deck);
										SlowDisplay("\t�Է�ʹ����"+d_card.GetValue()+"ɱ\n",5);
										goto JD_user_turn;
									}
										
								}
							SlowDisplay("\t�����������Է��ܵ�һ���˺���\n",5);
							--target->Health();
							if(target->Health()<=0){
								target->Die();
								--p_left;
								if(p_left==1)goto win;
							}
							goto JD_end;
							JD_user_turn:
							for(vector<CHandcard>::iterator iter=you->handcard.card.begin();
								iter!=you->handcard.card.end();++iter){
									if(iter->name=="ɱ"){
										SlowDisplay("\t�����У�Ŀ�����",5);
										cout<<i_target;
										SlowDisplay("���Ƿ�ʹ��ɱ��\n",5);
										you->PrintCard(1);
										SlowDisplay("\t0 ��ʹ��ɱ\n\t",5);
										JD_rechoose:
										cin>>u_no;
										if(u_no==0)break;
										if(you->handcard.card[u_no].name!="ɱ"){
											SlowDisplay("������ѡ��\n",5);
											goto JD_rechoose;
										}
									}
								}
							--you->Health();
							if(you->Health()<=0){
								you->Die();
								--p_left;
								goto lose;
							}
							goto JD_end;
							JD_next:;
						}
						JD_end:;
					}
					
					end_play:;
				}
				Sleep(1000);
			}
		}else{
			SlowDisplay("���ֻغ�!",5);
			Sleep(500);
		}
	}
	win:
	MessageBox(0,"��Ӯ�ˣ�","��Ӯ�ˣ�",0);
	return;
	lose:
	MessageBox(0,"�����ˣ�","�����ˣ�",0);
}


int main(){
	system("mode con cols=300 lines=300");
	HideTheCursor();
	while(1){
		cls();
		SlowDisplay("1�����˳�   2�����˳�   3������˫��   4��1V1   5��3V3   6��1V3���ι�   0���˳�\n",5);
		switch(getch()-48){
			case 0:return 0; 
//			case 1:m_five();break;
//			case 2:m_eight();break;
//			case 3:m_eight2();break;
			case 4:m_1v1();break;
//			case 5:m_3v3();break;
//			case 6:m_1v3();break;
		}
	}
}
//https://www.zybang.com/question/d8e029da469ad7f1adcf1a9be81ac8cf.html
