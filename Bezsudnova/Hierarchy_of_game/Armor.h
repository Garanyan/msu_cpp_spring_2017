#ifndef ARMOR_H_INCLUDED
#define ARMOR_H_INCLUDED

class QArmor
{
    public:
        int protectionFromHammer; //�����
        int protectionFromShovel; //������
        int protectionFromSword; // ���
        int protectionFromBow; //���
        int mulctOfSpeed; // ����� �� ��������

};

class Plate: public QArmor //����
{
    void create()
    {
        protectionFromHammer=0; //�����
        protectionFromShovel=0; //������
        protectionFromSword=0; // ���
        protectionFromBow=0; //���
        mulctOfSpeed=0; //

    }

};

class Panoply: public Qarmor //�������
{
    void create()
    {
        protectionFromHammer=0; //�����
        protectionFromShovel=0; //������
        protectionFromSword=0; // ���
        protectionFromBow=0; //���
        mulctOfSpeed=0; //

    }


};


#endif // ARMOR_H_INCLUDED
