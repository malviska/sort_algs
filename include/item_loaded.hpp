#include<string>
#include"item.hpp"

#ifndef ITEMLOADED_H
#define ITEMLOADED_H
#define STRINGLOBAL "OF?p4*Rg},Wj8yR%]b%9vND<WG\"mmq>O20dW|gp+@\\CVJbO.gh&Q/]E/&a80TV_##_t!I\"F%^iuEgGmP10>Zm}\\%/`=?P0;m3zcN_eu!`zv'd?tPk@nG/)M?i&xV65EcL+4-,+HlAA/'z@X#`be,(NKqTEcku+jCP P\\E5e#p0*(P|,M{qYA@21!v8v#%;m?(e!=L$/"
#define DOUBLEGLOBAL 83518574139.4377568795

class ItemLoaded : public Item {
    public:
        ItemLoaded();
        void generate(int size) override;
        double 
        num1 = DOUBLEGLOBAL, 
        num2 = DOUBLEGLOBAL, 
        num3 = DOUBLEGLOBAL, 
        num4 = DOUBLEGLOBAL, 
        num5 = DOUBLEGLOBAL, 
        num6 = DOUBLEGLOBAL, 
        num7 = DOUBLEGLOBAL, 
        num8 = DOUBLEGLOBAL, 
        num9 = DOUBLEGLOBAL, 
        num10 = DOUBLEGLOBAL;

        char 
        str1[200] = STRINGLOBAL, 
        str2[200] = STRINGLOBAL, 
        str3[200] = STRINGLOBAL, 
        str4[200] = STRINGLOBAL, 
        str5[200] = STRINGLOBAL, 
        str6[200] = STRINGLOBAL, 
        str7[200] = STRINGLOBAL, 
        str8[200] = STRINGLOBAL, 
        str9[200] = STRINGLOBAL, 
        str10[200] = STRINGLOBAL, 
        str11[200] = STRINGLOBAL, 
        str12[200] = STRINGLOBAL, 
        str13[200] = STRINGLOBAL, 
        str14[200] = STRINGLOBAL, 
        str15[200] = STRINGLOBAL;
};

#endif