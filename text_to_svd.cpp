#include "text_to_svd.hpp"

#include <cstdlib>
#include <ctype.h>

text_to_svd::text_to_svd(QString &inputData)
{
    remove_stopSymbols(inputData);
    printWords();
    stemmer();
    printWords();
}

const QStringList &text_to_svd::get_words_list()
{
    return words;
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
            words.removeAll(inpStr);
        }
        inpFile->close();
        delete inpFile;
    }
    else
        qDebug() << "File : \"" << _STOP_SYMBOLS_FPATH << "\" not open.";
}

void text_to_svd::stemmer()
{
    const char *language = "rus";
    const char *charnec = "UTF_8";
    struct sb_stemmer *stemmer = sb_stemmer_new(language, charnec);
//    stemm(stemmer);
    stemm_c(stemmer);
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
        const sb_symbol *stemmed = sb_stemmer_stem(stemmer, b, (words[i].size() - 1));
        words[i] = (char*)stemmed;
        delete b;
    }
}

void text_to_svd::stemm_c(sb_stemmer *stemmer)
{
#define _INC 10
    const int words_size = words.size();
    for(int i = 0; i < words_size - 1; ++ i)
    {
        sb_symbol *b = (sb_symbol*)malloc(_INC * sizeof(sb_symbol) * words_size);
        for(int j = 0; j < words[i].size(); ++ j)
        {
            b[j] = words[i].toStdString().c_str()[j];
        }
        int xx = sizeof(sb_symbol);
//        strcpy(b, words[i].toStdString());

        const sb_symbol *stemmed = sb_stemmer_stem(stemmer, b, words[i].size() * sizeof(sb_symbol));
        words[i] = (char*)stemmed;
        free(b);
    }
}

void text_to_svd::printWords() const
{
    QFile *fl = new QFile("../stemming_svd/words_temp");
    fl->open(QIODevice::Text | QIODevice::Append | QIODevice::WriteOnly);
    QTextStream streamm(fl);
    for(int i = 0; i < words.size(); ++ i)
    {
        streamm << words[i] << '\n';
        qDebug() << words[i];
    }
    fl->close();
    delete fl;
}
