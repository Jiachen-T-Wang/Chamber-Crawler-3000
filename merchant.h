#ifndef __MERCHANT_H__
#define __MERCHANT_H__

#include "enemy.h"

//gets two attacks against every race except drow
class Merchant: public Enemy{
public:
	static bool angry;
	Merchant();
	void attack(std::shared_ptr<Player> p) override;
	void beAtkBy(std::shared_ptr<Player> p) override;
    char symbol() override;
};

#endif
