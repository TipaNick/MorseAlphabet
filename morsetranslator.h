#ifndef MORSETRANSLATOR_H
#define MORSETRANSLATOR_H

#include <QObject>
#include <QVector>

class MorseTranslator : public QObject
{
    Q_OBJECT
public:
    explicit MorseTranslator(QObject *parent = nullptr);

private:
    QString alphabet[46][2] = {
        {".-", "A"},
        {"-...", "B"},
        {"-.-.","C"},
        {"-..","D"},
        {".","E"},
        {"..-.","F"},
        {"--.","G"},
        {"....","H"},
        {"..","I"},
        {".---","J"},
        {"-.-","K"},
        {".-..","L"},
        {"--","M"},
        {"-.","N"},
        {"---","O"},
        {".--.","P"},
        {"--.-","Q"},
        {".-.","R"},
        {"...","S"},
        {"-","T"},
        {"..-","U"},
        {"...-","V"},
        {".--","W"},
        {"-..-","X"},
        {"-.--","Y"},
        {"--..","Z"},
        {".-.-.-","."},
        {"--..--",","},
        {"..--..","?"},
        {".----.","`"},
        {"-.-.--","!"},
        {"-..-.","/"},
        {"-.--.","("},
        {"-.--.-",")"},
        {".-...","&"},
        {"---...",":"},
        {"-.-.-.",";"},
        {"-...-","="},
        {".-.-.","+"},
        {"-....-","-"},
        {"..--.-","_"},
        {".-..-.","\""},
        {"...-..-","$"},
        {".--.-.","@"}
    };

signals:

public slots:
    QString fromMorse(QString message);
    QString toMorse(QString message);
    QString autoTranslate(QString message);

private slots:
    QVector<QString> fromStringToVectorFromMorse(QString string);
    QVector<QString> fromStringToVectorToMorse(QString string);

};

#endif // MORSETRANSLATOR_H
