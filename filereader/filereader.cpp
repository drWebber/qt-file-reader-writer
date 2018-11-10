#include "filereader.h"
#include <qdebug.h>

FileReader::FileReader(const QString &fileName)
{
    file = new QFile(fileName);
}

FileReader::~FileReader()
{
    delete file;
}

QString FileReader::read()
{
    file->open(QIODevice::ReadOnly);
    in = new QTextStream(file);
    in->setCodec("UTF-8");

    QString text = QString::fromLocal8Bit(in->readAll().toLocal8Bit());

    delete in;
    file->close();

    return text;
}

QStringList FileReader::read(const QString &separator)
{
    return read().split(separator);
}

void FileReader::write(const QString &text, QIODevice::OpenModeFlag flags,
                       const QString &separator)
{
    file->open(flags);
    in = new QTextStream(file);
    in->setCodec("UTF-8");
    *in << text << separator;

    in->flush();
    delete in;
    file->close();
}
