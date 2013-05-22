#ifndef TEXT_TO_SVD_HPP
#define TEXT_TO_SVD_HPP

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QRegExp>
#include <QStringList>

#include "include/libstemmer.h"

#define _STOP_SYMBOLS_FPATH "../stemming_svd/stop_symbols"

class text_to_svd
{
public:
    text_to_svd(QString &inputData);
private :
    void remove_stopSymbols(QString &inputData);
    void stemmer();
    void stemm(struct sb_stemmer *stemmer);
    void printWords()const;
    QStringList words;
};

#endif // TEXT_TO_SVD_HPP
