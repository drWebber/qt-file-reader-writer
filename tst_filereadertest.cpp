#include <QtTest>

#include "filereader/filereader.h"


class FileReaderTest : public QObject
{
    Q_OBJECT
private:
public:
    FileReaderTest();
    ~FileReaderTest();

private slots:
    void testReading();
    void testReadingAsQStringList();
    void testWriting();
};

FileReaderTest::FileReaderTest()
{
}

FileReaderTest::~FileReaderTest()
{
}

void FileReaderTest::testReading()
{
    FileReader fr("test.txt");
    QString text = fr.read();
    QCOMPARE(text.size(), 43);
    QVERIFY(text == "hello\r\nheading\r\nline 3\r\nline 4\r\nend of file");
}

void FileReaderTest::testReadingAsQStringList()
{
    FileReader fr("test.txt");
    QStringList list = QStringList() << "hello" << "heading" << "line 3"
                                     << "line 4" << "end of file";
    QCOMPARE(list, fr.read("\r\n"));
}

void FileReaderTest::testWriting()
{
    FileReader fr("output.txt");
    fr.write("hello world", QIODevice::NewOnly, "");
    QCOMPARE("hello world", fr.read());
    QFile("output.txt").remove();
}

QTEST_APPLESS_MAIN(FileReaderTest)

#include "tst_filereadertest.moc"
