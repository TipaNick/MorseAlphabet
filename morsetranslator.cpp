#include "morsetranslator.h"

MorseTranslator::MorseTranslator(QObject *parent) : QObject(parent)
{

}


QString MorseTranslator::fromMorse(QString message)
{
    QVector<QString> MorseChars = fromStringToVectorFromMorse(message);
    QString result = "";
    for(int i = 0; i < MorseChars.size(); i++){
        if(MorseChars[i] == " "){
            result += " ";
        } else {
            for(int j = 0; j < 46; j++){
                if(MorseChars[i] == alphabet[j][0])
                    result += alphabet[j][1];
            }
        }
    }
    return result;

}

QString MorseTranslator::toMorse(QString message)
{
    QVector<QString> toMorseChars = fromStringToVectorToMorse(message);
    QString result = "";
    for (int i = 0; i < toMorseChars.size(); i++) {
        if(toMorseChars[i] == " "){
            result += " ";
        } else {
            for (int j = 0; j < 46; j++) {
                if(toMorseChars[i] == alphabet[j][1]){
                    if(i != 0)
                        result += " ";
                    result += alphabet[j][0];
                }
            }
        }
    }
    return result;
}

QString MorseTranslator::autoTranslate(QString message)
{
    int choice = 0;
    for (int i = 0; i < message.size(); i++) {
        for (int j = 0; j < 46; j++) {
            if(j != 26 && j != 39)
                if(message[i] == alphabet[j][1]){
                    choice = 1;
                }
        }
    }
    if(choice == 0){
        return fromMorse(message);
    } else {
        return toMorse(message);
    }
}

QVector<QString> MorseTranslator::fromStringToVectorFromMorse(QString string)
{
    QVector<QString> result;
    int i = 0;
    QString temp = "";
    bool endString = false;
    while(!endString){
        if(string[i] == " "){
            if(string[i-1] == " "){
                result.append(" ");
            } else {
                result.append(temp);
            }
            temp = "";
        }
        if(string[i+1] == '\x0'){
            if(string[i] != " ")
                temp += string[i];
            if(!temp.isEmpty()){
                result.append(temp);
            }
            temp = "";
            endString = true;
        }
        else {
            if(string[i] != " ")
                temp += string[i];
        }
     i++;
    }
    return result;
}

QVector<QString> MorseTranslator::fromStringToVectorToMorse(QString string)
{
    QVector<QString> result;
    int i = 0;
    QString temp = "";
    bool endString = false;

    while(!endString){
        temp = string[i];
        result.append(temp);
        i++;
        if(string[i] == '\x0')
            endString = true;
    }
    return result;
}
