#ifndef __TREASURE_H__
#define __TREASURE_H__
#include "../object.h"

class Dragon;

class Treasure : public Object {
	const std::string type;
	const int value;
 public:
 	Treasure(std::string type, int value);
 	std::string getType() const;
    int getValue() const;
    bool isTreasure() override;
    virtual ~Treasure() = 0;
};

#endif
