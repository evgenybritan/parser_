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

    static Error parse(const QString filename/*, QByteArray byte_input*/);
     QJsonObject m_currentJsonObject;


};


#endif // PARSER_H
