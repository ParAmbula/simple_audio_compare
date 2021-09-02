#include "compareclass.h"

CompareClass::CompareClass(QObject *parent) : QObject(parent)
{

}

void CompareClass::StartCompare()
{
    first=mainsource->ResultList.begin();
    second=first+1;
    while(second!=mainsource->ResultList.end())
    {
        while(second!=mainsource->ResultList.end())
        {
            result=0;
            FuzzyCompare(first,second);
            ++second;
        }
        ++first;
        second=first+1;
    }
}

void CompareClass::FuzzyCompare(AudioFile *one, AudioFile *two)
{
    //Mamdani 2 input, 1 output, compare table, 4 valuse: 20,50,80,100.
    QString firstpart=one->AudioData.mid(0,one->AudioData.length()/4);
    QString secondpart=one->AudioData.mid(one->AudioData.length()/2,one->AudioData.length()/4);

    if(one->DataEqual(two)&&one->HashEqual(two)&&one->NameEqual(two)&&one->SizeEqual(two)&&(!one->PathEqual(two)))
    {
        result=100;
        ResultMap(one,two);
        return;
    }
    else if(one->NameEqual(two)&&(!(one->DataEqual(two)))&&(!(one->HashEqual(two)))&&(!(one->SizeEqual(two))))
    {
        result=20;
        ResultMap(one,two);
        return;
    }
    else if((!(one->NameEqual(two)))&&one->DataEqual(two)&&one->HashEqual(two))
    {
        result=80;
        ResultMap(one,two);
        return;
    }
    else if(!one->NameEqual(two)&&!one->SizeEqual(two)&&!one->HashEqual(two))
    {
        if(two->AudioData.contains(firstpart)&&two->AudioData.contains(secondpart))
        {
            result=80;
            ResultMap(one,two);
            return;
        }
        else if(two->AudioData.contains(firstpart)||two->AudioData.contains(secondpart))
        {
            result=50;
            ResultMap(one,two);
            return;
        }
    }
    else
        return;
}

void CompareClass::ResultMap(AudioFile *left, AudioFile *right)
{
    left->CompareResult.insert(right,result);
}

void CompareClass::slotCompare(MainWindow*src)
{
    mainsource=src;
    StartCompare();
    src->tmpthread.quit();
}
