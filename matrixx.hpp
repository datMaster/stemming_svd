#ifndef MATRIXX_HPP
#define MATRIXX_HPP

#include <gsl/gsl_linalg.h>
#include <QList>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>

// for computing
#define _MATRIX_J 3

class matrixx
{
public:
    matrixx(const QList<QStringList>&wordsList);
    ~matrixx();
private:
    void matrix_init(const int &maxI, const int &maxJ);
    void matrix_fill(const QList<QStringList>&wordsList);
    int createWords(const QList<QStringList>& wordsList);
    void matrix_comput();
    void matrix_prepare_to_mul_and_mul();
    void matrix_mul(gsl_matrix *result, const gsl_matrix *A, const gsl_matrix *B);
    void matrix_test_print()const;
    gsl_matrix *A, *V, *AxSxV;
    gsl_vector *S, *work;
    QStringList words;
};

#endif // MATRIXX_HPP
