#include"deck.h"

struct Game
{
	CDeck deck;
	Game()
	{
		deck.card.push_back(CHandcard(spade,7,"É±"));
		for(int i=8;i<=10;++i)
		{
			deck.card.push_back(CHandcard(spade,i,"É±"));
			deck.card.push_back(CHandcard(spade,i,"É±"));
			deck.card.push_back(CHandcard(club,i,"É±"));
			deck.card.push_back(CHandcard(club,i,"É±"));
		}
		for(int i=2;i<=7;++i)
		{
			deck.card.push_back(CHandcard(club,i,"É±"));
		}
		deck.card.push_back(CHandcard(club,11,"É±"));
		deck.card.push_back(CHandcard(club,11,"É±"));
		deck.card.push_back(CHandcard(heart,10,"É±"));
		deck.card.push_back(CHandcard(heart,10,"É±"));
		deck.card.push_back(CHandcard(heart,11,"É±"));
		for(int i=6;i<=10;++i)
		{
			deck.card.push_back(CHandcard(diamond,i,"É±"));
		}
		deck.card.push_back(CHandcard(diamond,13,"É±"));

		deck.card.push_back(CHandcard(heart,2,"ÉÁ"));
		deck.card.push_back(CHandcard(heart,2,"ÉÁ"));
		deck.card.push_back(CHandcard(heart,13,"ÉÁ"));
		for(int i=2;i<=11;++i)
		{
			deck.card.push_back(CHandcard(diamond,i,"ÉÁ"));
		}
		deck.card.push_back(CHandcard(diamond,2,"ÉÁ"));
		deck.card.push_back(CHandcard(diamond,11,"ÉÁ"));

		for(int i=3;i<=9;++i)
		{
			if(i!=5)
				deck.card.push_back(CHandcard(heart,i,"ÌÒ"));
		}
		deck.card.push_back(CHandcard(heart,12,"ÌÒ"));
		deck.card.push_back(CHandcard(diamond,12,"ÌÒ"));


		deck.card.push_back(CHandcard(spade,1,"¾ö¶·"));
		deck.card.push_back(CHandcard(club,1,"¾ö¶·"));
		deck.card.push_back(CHandcard(diamond,1,"¾ö¶·"));

		deck.card.push_back(CHandcard(spade,3,"¹ýºÓ²ðÇÅ"));
		deck.card.push_back(CHandcard(spade,4,"¹ýºÓ²ðÇÅ"));
		deck.card.push_back(CHandcard(spade,12,"¹ýºÓ²ðÇÅ"));
		deck.card.push_back(CHandcard(heart,12,"¹ýºÓ²ðÇÅ"));
		deck.card.push_back(CHandcard(club,3,"¹ýºÓ²ðÇÅ"));
		deck.card.push_back(CHandcard(club,4,"¹ýºÓ²ðÇÅ"));

		deck.card.push_back(CHandcard(spade,3,"Ë³ÊÖÇ£Ñò"));
		deck.card.push_back(CHandcard(spade,4,"Ë³ÊÖÇ£Ñò"));
		deck.card.push_back(CHandcard(spade,11,"Ë³ÊÖÇ£Ñò"));
		deck.card.push_back(CHandcard(diamond,3,"Ë³ÊÖÇ£Ñò"));
		deck.card.push_back(CHandcard(diamond,4,"Ë³ÊÖÇ£Ñò"));

		deck.card.push_back(CHandcard(heart,7,"ÎÞÖÐÉúÓÐ"));
		deck.card.push_back(CHandcard(heart,8,"ÎÞÖÐÉúÓÐ"));
		deck.card.push_back(CHandcard(heart,9,"ÎÞÖÐÉúÓÐ"));
		deck.card.push_back(CHandcard(heart,11,"ÎÞÖÐÉúÓÐ"));

		deck.card.push_back(CHandcard(club,12,"½èµ¶É±ÈË"));
		deck.card.push_back(CHandcard(club,13,"½èµ¶É±ÈË"));

		deck.card.push_back(CHandcard(spade,11,"ÎÞÐ¸¿É»÷"));
		deck.card.push_back(CHandcard(club,12,"ÎÞÐ¸¿É»÷"));
		deck.card.push_back(CHandcard(club,13,"ÎÞÐ¸¿É»÷"));
		deck.card.push_back(CHandcard(diamond,12,"ÎÞÐ¸¿É»÷"));

		deck.card.push_back(CHandcard(spade,7,"ÄÏÂùÈëÇÖ"));
		deck.card.push_back(CHandcard(spade,13,"ÄÏÂùÈëÇÖ"));
		deck.card.push_back(CHandcard(club,7,"ÄÏÂùÈëÇÖ"));

		deck.card.push_back(CHandcard(heart,1,"Íò¼ýÆë·¢"));

		deck.card.push_back(CHandcard(heart,1,"ÌÒÔ°½áÒå"));

		deck.card.push_back(CHandcard(heart,3,"Îå¹È·áµÇ"));
		deck.card.push_back(CHandcard(heart,4,"Îå¹È·áµÇ"));

		deck.card.push_back(CHandcard(spade,6,"ÀÖ²»Ë¼Êñ"));
		deck.card.push_back(CHandcard(heart,6,"ÀÖ²»Ë¼Êñ"));
		deck.card.push_back(CHandcard(club,6,"ÀÖ²»Ë¼Êñ"));

		deck.card.push_back(CHandcard(spade,1,"ÉÁµç"));
		deck.card.push_back(CHandcard(heart,12,"ÉÁµç"));


		deck.card.push_back(CHandcard(club,1,"Öî¸ðÁ¬åó"));
		deck.card.push_back(CHandcard(diamond,1,"Öî¸ðÁ¬åó"));

		deck.card.push_back(CHandcard(spade,6,"ÇàâG½£"));

		deck.card.push_back(CHandcard(spade,2,"´ÆÐÛË«¹É½£"));

		deck.card.push_back(CHandcard(diamond,5,"¹áÊ¯¸«"));

		deck.card.push_back(CHandcard(spade,5,"ÇàÁúÙÈÔÂµ¶"));

		deck.card.push_back(CHandcard(spade,12,"ÕÉ°ËÉßÃ¬"));

		deck.card.push_back(CHandcard(diamond,12,"·½Ìì»­êª"));

		deck.card.push_back(CHandcard(heart,5,"÷è÷ë¹­"));


		deck.card.push_back(CHandcard(heart,5,"³àÍÃ"));
		deck.card.push_back(CHandcard(diamond,13,"×ÏóU"));
		deck.card.push_back(CHandcard(spade,13,"´óÍð"));

		deck.card.push_back(CHandcard(heart,13,"×¦»Æ·Éµç"));
		deck.card.push_back(CHandcard(club,5,"µÄÂ¬"));
		deck.card.push_back(CHandcard(spade,5,"¾øÓ°"));


		deck.card.push_back(CHandcard(spade,2,"°ËØÔÕó"));
		deck.card.push_back(CHandcard(club,2,"°ËØÔÕó"));


		deck.shuffle();
	}
};
