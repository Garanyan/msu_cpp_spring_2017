#ifndef MAIL_ARMOR_H
#define MAIL_ARMOR_H

#include "Armor.h"
class MailArmor : public Armor
{
public:
    unsigned strength;
    unsigned speedPenalty;
};

#endif