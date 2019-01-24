#ifndef PARSER_H
#define PARSER_H


#include <QString>
#include <QJsonObject>

class Parser
{
public:
    Parser();

    enum Error{
        NO_ERRORS       = 0,
        FILE_NOT_FOUND  = 1,
        INVALID_PACKET  = 2
    };

    static Error parse_json(const QByteArray& inputBuffer);
     QJsonObject m_currentJsonObject;
    static Error parse(const QByteArray& inputBuffer, QString &outString, QString& outType);

};


#endif // PARSER_H
