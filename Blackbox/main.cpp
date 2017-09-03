#include "startup.h"
#include "zijian.h"
#include "xuzhi.h"
#include "bidui.h"
#include "kaoshi.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load(":/qt_zh_CN.qm");
    a.installTranslator(&translator);
    startup s;
    zijian z;
    xuzhi x;
    bidui b;
    kaoshi k;
    s.show();

    QObject::connect(&s,SIGNAL(zshow()),&z,SLOT(receiveshow()));
    QObject::connect(&s,SIGNAL(xshow()),&x,SLOT(receiveshow()));
    QObject::connect(&z,SIGNAL(xshow()),&x,SLOT(receiveshow()));
    QObject::connect(&x,SIGNAL(bshow()),&b,SLOT(receiveshow()));
    QObject::connect(&b,SIGNAL(kshow()),&k,SLOT(receiveshow()));
    QObject::connect(&k,SIGNAL(xshow()),&x,SLOT(receiveshow()));

    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));

    return a.exec();
}
