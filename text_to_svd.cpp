#include "text_to_svd.hpp"

text_to_svd::text_to_svd(QString &inputData)
{
    remove_stopSymbols(inputData);
    printWords();
    stemmer();
    printWords();
}

void text_to_svd::remove_stopSymbols(QString &inputData)
{
    inputData = inputData.toLower();
    inputData.remove(QRegExp("[^а-я\\s]"));

    inputData.remove(QRegExp("\\s{2,}"));
    words = inputData.split(' ');

    QFile *inpFile = new QFile(_STOP_SYMBOLS_FPATH);
    inpFile->open(QIODevice::Text | QIODevice::ReadOnly);
    if(inpFile->isOpen())
    {
        QTextStream inputStream(inpFile);
        QString inpStr;
        while(!inputStream.atEnd())
        {
            inpStr = inputStream.readLine();
            words.removeOne(inpStr);
        }
        inpFile->close();
        delete inpFile;
    }
    else
        qDebug() << "File : \"" << _STOP_SYMBOLS_FPATH << "\" not open.";
}

void text_to_svd::stemmer()
{
    const char *language = "rus",
         *charnec = "UTF_8";
    struct sb_stemmer *stemmer = sb_stemmer_new(language, charnec);
    stemm(stemmer);
    sb_stemmer_delete(stemmer);
}

void text_to_svd::stemm(struct sb_stemmer *stemmer)
{
    for(int i = 0; i < words.size(); ++ i)
    {
        sb_symbol *b = new sb_symbol[words[i].size()];
        for(int j = 0; j < words[i].size(); ++ j)
        {
            b[j] = (words[i]).toStdString().c_str()[j];
        }
        const sb_symbol *stemmed = sb_stemmer_stem(stemmer, b, words[i].size());
        words[i] = (char*)stemmed;
        delete b;
    }
}

void text_to_svd::printWords() const
{
    for(int i = 0; i < words.size(); ++ i)
    {
        qDebug() << words[i];
    }
}
