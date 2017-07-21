#ifndef __MERCHANT_H__
#define __MERCHANT_H__

#include "../enemy.h"

//gets two attacks against every race except drow
class Merchant: public Enemy{
public:
	static bool angry;
	Merchant();
	void attack(Player* p) override;
	void beAtkBy(Player* p) override;
};

#endif
