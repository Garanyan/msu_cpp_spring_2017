#pragma once


string translate(string sequense)
{

        vector <string> vecTranslate;
        //
        vecTranslate.push_back("9999");
        vecTranslate.push_back("999");
        vecTranslate.push_back("99");
        vecTranslate.push_back("9");
        vecTranslate.push_back("888");
        vecTranslate.push_back("88");
        vecTranslate.push_back("8");
        vecTranslate.push_back("7777");
        vecTranslate.push_back("777");
        vecTranslate.push_back("77");
        vecTranslate.push_back("7");
        vecTranslate.push_back("666");
        vecTranslate.push_back("66");
        vecTranslate.push_back("6");
        vecTranslate.push_back("555");
        vecTranslate.push_back("55");
        vecTranslate.push_back("5");
        vecTranslate.push_back("444");
        vecTranslate.push_back("44");
        vecTranslate.push_back("4");
        vecTranslate.push_back("333");
        vecTranslate.push_back("33");
        vecTranslate.push_back("3");
        vecTranslate.push_back("222");
        vecTranslate.push_back("22");
        vecTranslate.push_back("2");
        vecTranslate.push_back("0");
        //

        string help;
        string add;

        for (unsigned int i = 0; i < sequense.size(); i++)
        {
            if (sequense.at(i)==' ') add='0';
            else add=vecTranslate['z'-sequense.at(i)];

            if (help[help.size()-1]!=add[0]) help=help+add;
            else help=help+' '+add;

        }
        return help;


};


