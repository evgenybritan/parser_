#include "parser.h"
#include <stdlib.h>
#include <QString>
#include <QFile>
#include <QObject>
#include <QVector>
#include <QByteArray>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>
#include <QApplication>
#include <QtCore>
#include <QtWidgets>

using namespace std;

const char *arr_type[]= {"Reserved",
                         "HDMI packet ",
                         "I2C packet ",
                         "HPD packet ",
                         "CEC packet ",
                         "DisplayPort AUX packet ",
                         "DisplayPort secondary data packet ",
                         "DisplayPort MSA packet ",
                         "DisplayPort VB-ID packet ",
                         "USB-C packet ",
                         "F/W formatted diagnostic message ",
                         "DisplayPort MSA change  ",
                         "DisplayPort VB-ID change  "
};

Parser::Parser()
{
}

Parser::Error Parser::parse(const QByteArray &inputBuffer, QString &outString, QString &outType)
{
    QByteArray byte;
    //    QFile fileIn(filename);
    //    if(fileIn.open(QIODevice::ReadOnly))
    //    {

    //        bool ok;
    //        int i=0;
    //        QString Byte;
    //        Byte=fileIn.read(2);
    //        byte[0]=Byte.toInt(&ok,16);
    //        i++;

    //           while (!fileIn.atEnd())
    //           {
    //               Byte=fileIn.read(3);
    //               byte[i]=Byte.toInt(&ok,16);
    //               i++;

    //           }

    //    }
    //    else
    //    {
    //           return FILE_NOT_FOUND;
    //    }

        byte=inputBuffer;







        long TIMESTAMP= byte[0] | byte[1]<<8 | byte[2]<<16 | byte[3]<<24 ;
        long TIMESTAMP2= byte[4] | byte[5]<<8 | byte[6]<<16 | byte[7]<<24 ;
        outString+="TIMESTAMP[31:0] = "+ QString::number(TIMESTAMP);
        outString+="TIMESTAMP[64:32]  = "+ QString::number(TIMESTAMP2);
        long packet_ID = byte[8];

        outType=arr_type[packet_ID];
        long device_ID = byte[9]&0x0f;
        long flags = (byte[9]&0xf0)>>4;
        long data_lenght = byte[10] | byte[11]<<8;
        long HB0 = byte[12];
        long HB1 = byte[13];
        long HB2 = byte[14];
        long Data_4 = byte[15];
        long PB0 = byte[16];
        long PB1 = byte[17];
        long PB7 = byte[18];
        long PB8 = byte[19];
        long PB14 = byte[20];
        long PB15 = byte[21];
        long PB21 = byte[22];
        long PB22 = byte[23];
        long PB2 = byte[24];
        long PB3 = byte[25];
        long PB9 = byte[26];
        long PB10 = byte[27];
        long PB16 = byte[28];
        long PB17 = byte[29];
        long PB23 = byte[30];
        long PB24 = byte[31];
        long PB4 = byte[32];
        long PB5 = byte[33];
        long PB11 = byte[34];
        long PB12 = byte[35];
        long PB18 = byte[36];
        long PB19 = byte[37];
        long PB25 = byte[38];
        long PB26 = byte[39];
        long PB6 = byte[40];
        long BCH0 = byte[41];
        long PB13 = byte[42];
        long BCH1 = byte[43];
        long PB20 = byte[44];
        long BCH2 = byte[45];
        long PB27 = byte[46];
        long BCH3 = byte[47];






        switch (packet_ID) {
        case 1:{
            outString+="Device ID= "+ QString::number(device_ID) + "\n";
            outString+="Flags= "+ QString::number(flags)+" (Should be 0)\n";
            outString+="Data lenght= "+QString::number(data_lenght)+" (Should be 36)\n";

            outString+="HB0="+QString::number(HB0)+"\n";
            outString+="HB1="+QString::number(HB1)+"\n";
            outString+="HB2="+QString::number(HB2)+"\n";
            outString+="(Data 4)="+QString::number(Data_4) + " (should be 0) \n";
            outString+="PB0="+QString::number(PB0)+"\n";
            outString+="PB1="+QString::number(PB1)+"\n";
            outString+="PB7="+QString::number(PB7)+"\n";
            outString+="PB8="+QString::number(PB8)+"\n";
            outString+="PB14="+QString::number(PB14)+"\n";
            outString+="PB15="+QString::number(PB15)+"\n";
            outString+="PB21="+QString::number(PB21)+"\n";
            outString+="PB22="+QString::number(PB22)+"\n";
            outString+="PB2="+QString::number(PB2)+"\n";
            outString+="PB3="+QString::number(PB3)+"\n";
            outString+="PB9="+QString::number(PB9)+"\n";
            outString+="PB10="+QString::number(PB10)+"\n";
            outString+="PB16="+QString::number(PB16)+"\n";
            outString+="PB17="+QString::number(PB17)+"\n";
            outString+="PB23="+QString::number(PB23)+"\n";
            outString+="PB24="+QString::number(PB24)+"\n";
            outString+="PB4="+QString::number(PB4)+"\n";
            outString+="PB5="+QString::number(PB5)+"\n";
            outString+="PB11="+QString::number(PB11)+"\n";
            outString+="PB12="+QString::number(PB12)+"\n";
            outString+="PB18="+QString::number(PB18)+"\n";
            outString+="PB19="+QString::number(PB19)+"\n";
            outString+="PB25="+QString::number(PB25)+"\n";
            outString+="PB26="+QString::number(PB26)+"\n";
            outString+="PB6="+QString::number(PB6)+"\n";
            outString+="BCH0="+QString::number(BCH0)+"\n";
            outString+="PB13="+QString::number(PB13)+"\n";
            outString+="BCH1="+QString::number(BCH1)+"\n";
            outString+="PB20="+QString::number(PB20)+"\n";
            outString+="BCH2="+QString::number(BCH2)+"\n";
            outString+="PB27="+QString::number(PB27)+"\n";
            outString+="BCH3="+QString::number(BCH3)+"\n";

        break;}
        case 2:{
            outString+="Device ID= "+ QString::number(device_ID) + "\n";
            if(flags<=7){
                switch (flags) {
            case 0:
                outString+="Flags= "+ QString::number(flags)+" (DTA_START)\n";
                outString+="Data lenght= "+QString::number(data_lenght)+" (may be up to 65535)\n";
                break;
            case 1:
                outString+="Flags= "+ QString::number(flags)+" (DTA_STOP)\n";
                outString+="Data lenght= "+QString::number(data_lenght)+" (Should be 0)\n";
                break;
            case 2:
                outString+="Flags= "+ QString::number(flags)+" (ERR_START)\n";
                outString+="Data lenght= "+QString::number(data_lenght)+" (may be up to 65535)\n";
                break;
            case 3:
                outString+="Flags= "+ QString::number(flags)+" (ERR_STOP)\n";
                outString+="Data lenght= "+QString::number(data_lenght)+" (Should be 0)\n";
                break;
            case 4:
                outString+="Flags= "+ QString::number(flags)+" (ERR_OVERRUN )\n";
                outString+="Data lenght= "+QString::number(data_lenght)+" (Should be 0)\n";
                break;
            case 5:
                outString+="Flags= "+ QString::number(flags)+" (DTA_RESTART)\n";
                outString+="Data lenght= "+QString::number(data_lenght)+" (may be up to 65535)\n";
                break;
            default:
                outString+="Flags= "+ QString::number(flags)+" (*RESERVED*)\n";
                outString+="Data lenght= "+QString::number(data_lenght)+" ()\n";
                break;
            }
            }
            else{
                int ack=flags&0x08;
                switch (ack) {
                case 0:
                    outString+="Flags= Acknowledge:"+ QString::number(ack)+" ( =ACK)\n";
                    break;
                case 1:
                    outString+="Flags= Acknowledge: "+ QString::number(ack)+" ( =NACK)\n";
                    break;
                default:
                    outString+="Flags= "+ QString::number(flags)+" (*RESERVED*)\n";
                    break;
                }
                outString+="Data lenght= "+QString::number(data_lenght)+" (Should be 0)\n";
            }
            for (int k=12;k<=data_lenght+12;k++){
                outString+="data"+QString::number(byte[k])+"\n";
            };

            break;}
        case 3:{
            switch (device_ID) {
            case 0:
                outString+="Device ID= "+ QString::number(device_ID) + "(HDMI RX)\n";
                outString+="HDP Level= "+ QString::number(flags&0x01)+" \n";
                outString+=" +5V Level= "+ QString::number((flags&0x02)>>1)+" \n";
                break;
            case 1:
                outString+="Device ID= "+ QString::number(device_ID) + "(DisplayPort RX)\n";
                outString+="HDP Level= "+ QString::number(flags&0x01)+" \n";
                outString+="PWR Level= "+ QString::number((flags&0x02)>>1)+" \n";
                outString+="CD Level= "+ QString::number((flags&0x04)>>2)+" \n";
                break;
            default:
                break;
            }
            outString+="Data lenght= "+QString::number(data_lenght)+" (Should be 0)\n";
            break;
        }
        case 5:{
            outString+="Device ID= "+ QString::number(device_ID) + "\n";
            int sw=flags&0x07;
            switch (sw) {
            case 0:{
                outString+="Flags= "+ QString::number(sw) + "(Data message) \n";
                break;}
            case 1:{
                outString+="Flags= "+ QString::number(sw) + "(Data message combined to eDP PHY wake message) \n";
                break;}
            case 2:{
                outString+="Flags= "+ QString::number(sw) + "(eDP PHY Wake message) \n";
                break;}
            case 3:{
                outString+="Flags= "+ QString::number(sw) + "(eDP PHY Wake acknowledge message ) \n";
                break;}
            case 7:{
                int e=12;
                long err=byte[e];
                e++;
                while (e<=19) {
                   err=err | byte[e]<<(8*(e-12));
                   e++;
                }
                outString+="Flags= "+ QString::number(sw) + "(Error, Data[7:0] gives error code. ) Error code: " + QString::number(err);
                switch (err) {
                case 1:
                    outString+=" (Illegel sync pattern)\n";
                    break;
                case 2:
                    outString+=" (Illegal stop)  \n";
                    break;
                case 3:
                    outString+=" (Illegel sync pattern)  \n";
                    break;
                case 32:
                    outString+=" (Output fifo was full and 1 or more packets were lost) \n";
                    break;
                default:
                    outString+=" (*RESERVED*) \n";
                    break;
                }
                break;}
            default:{
                outString+="Flags= "+ QString::number(sw) + "(*RESERVED*) \n";
                break;}
            }
            break;
        }
        case 6:{
            outString+="Device ID= "+ QString::number(device_ID) + "\n";
            switch (flags) {
            case 0:
                outString+="Flags= "+QString::number(flags)+" Normal size packe\n";
                break;
            case 1:
                outString+="Flags= "+QString::number(flags)+" Shrinked packet(length is less that it should be)\n";
                break;
            default:
                outString+="Flags= "+QString::number(flags)+" *RESERVED*\n";
                break;
            }
            outString+="Data lenght= "+QString::number(data_lenght)+"\n";


            outString+="HB0= "+QString::number(HB0)+"\n";
            outString+="HB1= "+QString::number(HB1)+"\n";
            outString+="HB2= "+QString::number(HB2)+"\n";
            outString+="HB3= "+QString::number(Data_4)+"\n";

            int b;
            int pb=0,p;
            int db=0,d;

            for (b=16;b<=data_lenght+16;b++){

                for (p=0;p<=3;p++){
                    if (b<=data_lenght+16){
                    outString+="PB"+QString::number(pb)+" = "+QString::number(byte[b])+"\n";

                    pb++;
                    b++;}

                };

                for(d=0;d<=15;d++){
                    if (b<=data_lenght+16){
                    outString+="DB"+QString::number(db)+" = "+ QString::number(byte[b])+"\n";
                    db++;
                    b++;}
                };
                b=b-1;
            };


            break;
        }
        case 7:{
            outString+="Device ID= "+ QString::number(device_ID) + "\n";
            outString+="Stream ID= "+QString::number(flags&0x03)+"\n";
            outString+="Data lenght= "+QString::number(data_lenght)+"(Should be 24)\n";
            for (int k=12;k<=data_lenght+12;k++){
                outString+="data"+QString::number(byte[k])+"\n";
            };
            break;
        }
        case 8:{
            outString+="Device ID= "+ QString::number(device_ID) + "\n";
            outString+="Stream ID= "+QString::number(flags&0x03)+ "\n";
            outString+="Data lenght= "+QString::number(data_lenght)+"(Should be 3)\n";
            long vb_id = byte[12];
            long mvid = byte[13];
            long maud = byte[14];
            outString+="VB-ID= "+ QString::number(vb_id)+ "\n";
            outString+="Mvid= "+ QString::number(mvid)+ "\n";
            outString+="Maud= "+ QString::number(maud)+ "\n";
            break;
        }
        default:{
            outString+="Device ID= "+ QString::number(device_ID) + "\n";
            outString+="Flags= "+ QString::number(flags)+" \n";
            outString+="Data lenght= "+QString::number(data_lenght)+"\n";
            for (int k=12;k<=data_lenght+12;k++){
                outString+="data"+QString::number(byte[k])+"\n";
            };
            break;}
        }



        return NO_ERRORS;

}

Parser::Error Parser::parse_json(const QByteArray& inputBuffer)
{   QByteArray byte;
//    QFile fileIn(filename);
//    if(fileIn.open(QIODevice::ReadOnly))
//    {

//        bool ok;
//        int i=0;
//        QString Byte;
//        Byte=fileIn.read(2);
//        byte[0]=Byte.toInt(&ok,16);
//        i++;

//           while (!fileIn.atEnd())
//           {
//               Byte=fileIn.read(3);
//               byte[i]=Byte.toInt(&ok,16);
//               i++;

//           }

//    }
//    else
//    {
//           return FILE_NOT_FOUND;
//    }

    byte=inputBuffer;




    QFile saveFile("C://Users/Public/Documents/jn.json");
            if (!saveFile.open(QIODevice::WriteOnly))
            {
                qWarning("Couldn't open save file.");
            }

            QJsonObject json;





    long TIMESTAMP= byte[0] | byte[1]<<8 | byte[2]<<16 | byte[3]<<24 ;
    long TIMESTAMP2= byte[4] | byte[5]<<8 | byte[6]<<16 | byte[7]<<24 ;
    json["TIMESTAMP[31:0] = "]= QString::number(TIMESTAMP);
    json["TIMESTAMP[64:32]  = "]= QString::number(TIMESTAMP2);
    long packet_ID = byte[8];
    json["packet_ID"]=arr_type[packet_ID];
    long device_ID = byte[9]&0x0f;
    long flags = (byte[9]&0xf0)>>4;
    long data_lenght = byte[10] | byte[11]<<8;
    long HB0 = byte[12];
    long HB1 = byte[13];
    long HB2 = byte[14];
    long Data_4 = byte[15];
    long PB0 = byte[16];
    long PB1 = byte[17];
    long PB7 = byte[18];
    long PB8 = byte[19];
    long PB14 = byte[20];
    long PB15 = byte[21];
    long PB21 = byte[22];
    long PB22 = byte[23];
    long PB2 = byte[24];
    long PB3 = byte[25];
    long PB9 = byte[26];
    long PB10 = byte[27];
    long PB16 = byte[28];
    long PB17 = byte[29];
    long PB23 = byte[30];
    long PB24 = byte[31];
    long PB4 = byte[32];
    long PB5 = byte[33];
    long PB11 = byte[34];
    long PB12 = byte[35];
    long PB18 = byte[36];
    long PB19 = byte[37];
    long PB25 = byte[38];
    long PB26 = byte[39];
    long PB6 = byte[40];
    long BCH0 = byte[41];
    long PB13 = byte[42];
    long BCH1 = byte[43];
    long PB20 = byte[44];
    long BCH2 = byte[45];
    long PB27 = byte[46];
    long BCH3 = byte[47];






    switch (packet_ID) {
    case 1:{
        json["Device ID= "]= QString::number(device_ID) + "";
        json["Flags= "]= QString::number(flags)+" (Should be 0)";
        json["Data lenght= "]=QString::number(data_lenght)+" (Should be 36)";

        json["HB0="]=QString::number(HB0)+"";
        json["HB1="]=QString::number(HB1)+"";
        json["HB2="]=QString::number(HB2)+"";
        json["(Data 4)="]=QString::number(Data_4) + " (should be 0) ";
        json["PB0="]=QString::number(PB0)+"";
        json["PB1="]=QString::number(PB1)+"";
        json["PB7="]=QString::number(PB7)+"";
        json["PB8="]=QString::number(PB8)+"";
        json["PB14="]=QString::number(PB14)+"";
        json["PB15="]=QString::number(PB15)+"";
        json["PB21="]=QString::number(PB21)+"";
        json["PB22="]=QString::number(PB22)+"";
        json["PB2="]=QString::number(PB2)+"";
        json["PB3="]=QString::number(PB3)+"";
        json["PB9="]=QString::number(PB9)+"";
        json["PB10="]=QString::number(PB10)+"";
        json["PB16="]=QString::number(PB16)+"";
        json["PB17="]=QString::number(PB17)+"";
        json["PB23="]=QString::number(PB23)+"";
        json["PB24="]=QString::number(PB24)+"";
        json["PB4="]=QString::number(PB4)+"";
        json["PB5="]=QString::number(PB5)+"";
        json["PB11="]=QString::number(PB11)+"";
        json["PB12="]=QString::number(PB12)+"";
        json["PB18="]=QString::number(PB18)+"";
        json["PB19="]=QString::number(PB19)+"";
        json["PB25="]=QString::number(PB25)+"";
        json["PB26="]=QString::number(PB26)+"";
        json["PB6="]=QString::number(PB6)+"";
        json["BCH0="]=QString::number(BCH0)+"";
        json["PB13="]=QString::number(PB13)+"";
        json["BCH1="]=QString::number(BCH1)+"";
        json["PB20="]=QString::number(PB20)+"";
        json["BCH2="]=QString::number(BCH2)+"";
        json["PB27="]=QString::number(PB27)+"";
        json["BCH3="]=QString::number(BCH3)+"";

    break;}
    case 2:{
        json["Device ID= "]= QString::number(device_ID) + "";
        if(flags<=7){
            switch (flags) {
        case 0:
            json["Flags= "]= QString::number(flags)+" (DTA_START)";
            json["Data lenght= "]=QString::number(data_lenght)+" (may be up to 65535)";
            break;
        case 1:
            json["Flags= "]= QString::number(flags)+" (DTA_STOP)";
            json["Data lenght= "]=QString::number(data_lenght)+" (Should be 0)";
            break;
        case 2:
            json["Flags= "]= QString::number(flags)+" (ERR_START)";
            json["Data lenght= "]=QString::number(data_lenght)+" (may be up to 65535)";
            break;
        case 3:
            json["Flags= "]= QString::number(flags)+" (ERR_STOP)";
            json["Data lenght= "]=QString::number(data_lenght)+" (Should be 0)";
            break;
        case 4:
            json["Flags= "]= QString::number(flags)+" (ERR_OVERRUN )";
            json["Data lenght= "]=QString::number(data_lenght)+" (Should be 0)";
            break;
        case 5:
            json["Flags= "]= QString::number(flags)+" (DTA_RESTART)";
            json["Data lenght= "]=QString::number(data_lenght)+" (may be up to 65535)";
            break;
        default:
            json["Flags= "]= QString::number(flags)+" (*RESERVED*)";
            json["Data lenght= "]=QString::number(data_lenght)+" ()";
            break;
        }
        }
        else{
            int ack=flags&0x08;
            switch (ack) {
            case 0:
                json["Flags= Acknowledge:"]= QString::number(ack)+" ( =ACK)";
                break;
            case 1:
                json["Flags= Acknowledge: "]= QString::number(ack)+" ( =NACK)";
                break;
            default:
                json["Flags= "]= QString::number(flags)+" (*RESERVED*)";
                break;
            }
            json["Data lenght= "]=QString::number(data_lenght)+" (Should be 0)";
        }
        for (int k=12;k<=data_lenght+12;k++){
            json["data"]=QString::number(byte[k])+"";
        };

        break;}
    case 3:{
        switch (device_ID) {
        case 0:
            json["Device ID= "]= QString::number(device_ID) + "(HDMI RX)";
            json["HDP Level= "]= QString::number(flags&0x01)+" ";
            json[" +5V Level= "]= QString::number((flags&0x02)>>1)+" ";
            break;
        case 1:
            json["Device ID= "]= QString::number(device_ID) + "(DisplayPort RX)";
            json["HDP Level= "]= QString::number(flags&0x01)+" ";
            json["PWR Level= "]= QString::number((flags&0x02)>>1)+" ";
            json["CD Level= "]= QString::number((flags&0x04)>>2)+" ";
            break;
        default:
            break;
        }
        json["Data lenght= "]=QString::number(data_lenght)+" (Should be 0)";
        break;
    }
    case 5:{
        json["Device ID= "]= QString::number(device_ID) + "";
        int sw=flags&0x07;
        switch (sw) {
        case 0:{
            json["Flags= "]= QString::number(sw) + "(Data message) ";
            break;}
        case 1:{
            json["Flags= "]= QString::number(sw) + "(Data message combined to eDP PHY wake message) ";
            break;}
        case 2:{
            json["Flags= "]= QString::number(sw) + "(eDP PHY Wake message) ";
            break;}
        case 3:{
            json["Flags= "]= QString::number(sw) + "(eDP PHY Wake acknowledge message ) ";
            break;}
        case 7:{
            int e=12;
            long err=byte[e];
            e++;
            while (e<=19) {
               err=err | byte[e]<<(8*(e-12));
               e++;
            }
            json["Flags= "]= QString::number(sw) + "(Error, Data[7:0] gives error code. ) Error code: " + QString::number(err);
            switch (err) {
            case 1:
                json[" (Illegel sync pattern)"];
                break;
            case 2:
                json[" (Illegal stop)  "];
                break;
            case 3:
                json[" (Illegel sync pattern)  "];
                break;
            case 32:
                json[" (Output fifo was full and 1 or more packets were lost) "];
                break;
            default:
                json[" (*RESERVED*) "];
                break;
            }
            break;}
        default:{
            json["Flags= "]= QString::number(sw) + "(*RESERVED*) ";
            break;}
        }
        break;
    }
    case 6:{
        json["Device ID= "]= QString::number(device_ID) + "";
        switch (flags) {
        case 0:
            json["Flags= "]=QString::number(flags)+" Normal size packe";
            break;
        case 1:
            json["Flags= "]=QString::number(flags)+" Shrinked packet(length is less that it should be)";
            break;
        default:
            json["Flags= "]=QString::number(flags)+" *RESERVED*";
            break;
        }
        json["Data lenght= "]=QString::number(data_lenght)+"";


        json["HB0= "]=QString::number(HB0)+"";
        json["HB1= "]=QString::number(HB1)+"";
        json["HB2= "]=QString::number(HB2)+"";
        json["HB3= "]=QString::number(Data_4)+"";

        int b;
        int pb=0,p;
        int db=0,d;

        for (b=16;b<=data_lenght+16;b++){

            for (p=0;p<=3;p++){
                if (b<=data_lenght+16){
                json["PB"]=QString::number(pb)+" = "+QString::number(byte[b])+"";

                pb++;
                b++;}

            };

            for(d=0;d<=15;d++){
                if (b<=data_lenght+16){
                json["DB"]=QString::number(db)+" = "+ QString::number(byte[b])+"";
                db++;
                b++;}
            };
            b=b-1;
        };


        break;
    }
    case 7:{
        json["Device ID= "]= QString::number(device_ID) + "";
        json["Stream ID= "]=QString::number(flags&0x03)+"";
        json["Data lenght= "]=QString::number(data_lenght)+"(Should be 24)";
        for (int k=12;k<=data_lenght+12;k++){
            json["data"]=QString::number(byte[k])+"";
        };
        break;
    }
    case 8:{
        json["Device ID= "]= QString::number(device_ID) + "";
        json["Stream ID= "]=QString::number(flags&0x03)+ "";
        json["Data lenght= "]=QString::number(data_lenght)+"(Should be 3)";
        long vb_id = byte[12];
        long mvid = byte[13];
        long maud = byte[14];
        json["VB-ID= "]= QString::number(vb_id)+ "";
        json["Mvid= "]= QString::number(mvid)+ "";
        json["Maud= "]= QString::number(maud)+ "";
        break;
    }
    default:{
        json["Device ID= "]= QString::number(device_ID) + "";
        json["Flags= "]= QString::number(flags)+" ";
        json["Data lenght= "]=QString::number(data_lenght)+"";
        for (int k=12;k<=data_lenght+12;k++){
            json["data"]=QString::number(byte[k])+"";
        };
        break;}
    }
    json["TIMESTAMP[31:0] = "]= QString::number(TIMESTAMP);
    json["TIMESTAMP[64:32]  = "]= QString::number(TIMESTAMP2);
    json["packet_ID"]=arr_type[packet_ID];

    QJsonDocument saveDoc(json);
            saveFile.write(saveDoc.toJson());
            saveFile.close();

            return NO_ERRORS;
}
