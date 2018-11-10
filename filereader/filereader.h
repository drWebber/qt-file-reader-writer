#ifndef FILEREADER_H
#define FILEREADER_H

#include <qstring.h>
#include <qfile.h>
#include <qtextstream.h>


class FileReader
{
private:
    QFile *file;
    QTextStream *in;
public:
    FileReader(const QString &fileName);
    ~FileReader();

    QString read();
    QStringList read(const QString &separator);

    void write(const QString &text,
               QIODevice::OpenModeFlag flags = QIODevice::Append,
               const QString &separator = "\r\n");
};

#endif // FILEREADER_H
