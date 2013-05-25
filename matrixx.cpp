#include "matrixx.hpp"

matrixx::matrixx(const QList<QStringList>& wordsList)
{    
    matrix_init(createWords(wordsList), wordsList.size());
    matrix_fill(wordsList);
    matrix_comput();
    matrix_prepare_to_mul_and_mul();
    matrix_test_print();
}

matrixx::~matrixx()
{
    gsl_matrix_free(A);
    gsl_matrix_free(V);
    gsl_matrix_free(AxSxV);
    gsl_vector_free(S);
    gsl_vector_free(work);
}

void matrixx::matrix_init(const int &maxI, const int &maxJ)
{
    A = gsl_matrix_alloc(maxI, maxJ);
    V = gsl_matrix_alloc(maxJ, maxJ);
    S = gsl_vector_alloc(maxJ);
    work = gsl_vector_alloc(maxJ);

    gsl_matrix_set_all(A, 0);
    gsl_matrix_set_all(V, 0);
    gsl_vector_set_all(S, 0);
    gsl_vector_set_all(work, 0);
}

void matrixx::matrix_fill(const QList<QStringList> &wordsList)
{
    for(size_t i = 0; i < A->size1; ++ i)
    {
        if(wordsList.size() == i)
            break;
        for(size_t j = 0; j < A->size2; ++ j)
        {
            if(words[i] == wordsList[j][i])
            {
                gsl_matrix_set(A, i, j, (gsl_matrix_get(A, i, j) + 1));
            }
        }
    }
}

int matrixx::createWords(const QList<QStringList> &wordsList)
{
    const int maxI = wordsList.size() - 1;
    int maxJ;
    for(int i = 0; i < maxI; ++ i)
    {
        maxJ = wordsList[i].size();
        for(int j = 0; j < maxJ; ++ j)
        {
            if(!words.contains((wordsList[i])[j]))
            {
                words.append((wordsList[i])[j]);
            }

        }
    }
    return words.size();
}

void matrixx::matrix_comput()
{
    gsl_linalg_SV_decomp(A, V, S, work);
}

void matrixx::matrix_prepare_to_mul_and_mul()
{
    const size_t maxI = A->size1;
    const size_t maxJ = _MATRIX_J;

    gsl_matrix *AxS = gsl_matrix_alloc(maxI, maxJ);
    gsl_matrix *Am = gsl_matrix_alloc(maxI, maxJ);
    gsl_matrix *Sm = gsl_matrix_alloc(_MATRIX_J, _MATRIX_J);
    gsl_matrix *Vm = gsl_matrix_alloc(_MATRIX_J, _MATRIX_J); // j el-t ==> text count

    gsl_matrix_set_all(Am, 0);
    gsl_matrix_set_all(Sm, 0);
    gsl_matrix_set_all(Vm, 0);

    AxSxV = gsl_matrix_alloc(maxI, Vm->size1);

    for(size_t i = 0; i < Am->size1; ++ i)
    {
        for(size_t j = 0; j < Am->size2; ++ j)
        {
            gsl_matrix_set(Am, i , j, gsl_matrix_get(A, i, j));
        }
    }

    for(size_t i = 0; i < Sm->size1; ++ i)
    {
        gsl_matrix_set(Sm, i, i, gsl_vector_get(S, i));
    }

    for(size_t i = 0; i < Vm->size1; ++ i)
    {
        for(size_t j = 0; j < Vm->size2; ++ j)
        {
            gsl_matrix_set(Vm, i , j, gsl_matrix_get(V, i , j));
        }
    }


    matrix_mul(AxS, Am, Sm);
    matrix_mul(AxSxV, AxS, Vm);

    gsl_matrix_free(Am);
    gsl_matrix_free(Sm);
    gsl_matrix_free(Vm);
    gsl_matrix_free(AxS);
}

void matrixx::matrix_mul(gsl_matrix *result, const gsl_matrix *A, const gsl_matrix *B)
{
    double data;
    size_t jR = 0;
    for(size_t iA = 0; iA < A->size1; ++ iA)
    {
        for(size_t jA = 0; jA < A->size2; ++ jA)
        {
            data = 0;
            for(size_t iB = 0; iB < B->size1; ++ iB)
            {
                data += gsl_matrix_get(A, iA, jA) * gsl_matrix_get(B, iB, jA);
            }
            gsl_matrix_set(result, iA, jR ++, data);
        }
        jR = 0;
    }
}

void matrixx::matrix_test_print() const
{
    QFile *outFile = new QFile("../stemming_svd/matrix_test_print");
    outFile->open(QIODevice::Text | QIODevice::Truncate | QIODevice::WriteOnly);
    if(outFile->isOpen())
    {
        QTextStream outTextStream(outFile);
        outTextStream.setFieldWidth(13);
        for(size_t i = 0; i < AxSxV->size1; ++ i)
        {
            outTextStream << words[i];
            for(size_t j = 0; j < AxSxV->size2; ++ j)
            {
                outTextStream << gsl_matrix_get(AxSxV, i, j);
            }
            outTextStream << '\n';
        }

        outFile->close();
        delete outFile;
    }
    else
    {
        qDebug() << "function : \"matrix_test_print\" : out file not open";
    }
}
