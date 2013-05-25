#include <QCoreApplication>
#include <QTextCodec>
#include "text_to_svd.hpp"
#include "matrixx.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);            
    QTextCodec::setCodecForLocale((QTextCodec::codecForName("System")));

    QString str = "{ response :[1803,{ id :43127, from_id :-10933209, to_id :-10933209, date :1369155716, text : А вы готовы к новому XBox? http:\/\/www.xbox.com\/en-US\/hub\/reveal , attachment :{ type : photo , photo :{ pid :303236127, aid :-7, owner_id :-10933209, user_id :100, src : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a17\/PJOovzMD9rA.jpg , src_big : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a18\/GJ10eBqcwkI.jpg , src_small : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a16\/K_CQG4gpz94.jpg , src_xbig : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a19\/H4yzrKE7wRc.jpg , src_xxbig : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a1a\/2NfPtCiMJGM.jpg , width :1072, height :635, text :  , created :1369155716, post_id :43127, access_key : f0c673c2ea9504e3de }}, attachments :[{ type : photo , photo :{ pid :303236127, aid :-7, owner_id :-10933209, user_id :100, src : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a17\/PJOovzMD9rA.jpg , src_big : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a18\/GJ10eBqcwkI.jpg , src_small : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a16\/K_CQG4gpz94.jpg , src_xbig : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a19\/H4yzrKE7wRc.jpg , src_xxbig : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a1a\/2NfPtCiMJGM.jpg , width :1072, height :635, text :  , created :1369155716, post_id :43127, access_key : f0c673c2ea9504e3de }},{ type : link , link :{ url : http:\/\/www.xbox.com\/en-US\/hub\/reveal , title : Xbox, A New Generation Revealed - Xbox.com , description : Watch it live May 21, 10am PDT on Xbox Live, Xbox.com or Spike TV , image_src : http:\/\/cs320420.vk.me\/v320420704\/5e7\/cWHuN3pXcfw.jpg }}], comments :{ count :37}, likes :{ count :19}, reposts :{ count :7}}]}";

    QString str1 = "Прелесть сингулярного разложения состоит в том, что оно выделяет ключевые составляющие матрицы, позволяя игнорировать шумы. Согласно простым правилам произведения матриц, видно, что столбцы и строки соответствующие меньшим сингулярным значениям дают наименьший вклад в итоговое произведение. Например, мы можем отбросить последние столбцы матрицы U и последние строки матрицы V^t, оставив только первые 2. Важно, что при этом гарантируется, оптимальность полученного произведения. Разложение такого вида называют двумерным сингулярным разложением";

    QString str2 = "Для примера я выбрал несколько заголовков с различных новостей. Они выбраны не совсем случайно, дело в том, что для случайной выборки потребовался бы очень большой объем данных, что сильно затруднило бы дальнейшее изложение. Итак, было выбрано несколько заголовков.";

    QString str3 = "Предположим, перед вами стоит задача написать алгоритм, который сможет отличать новости о звездах эстрады от новостей по экономике. Первое, что приходит в голову, это выбрать слова которые встречаются исключительно в статьях каждого вида и использовать их для классификации. Очевидная проблема такого подхода: как перечислить все возможные слова и что делать в случае когда в статье есть слова из нескольких классов. Дополнительную сложность представляют омонимы. Т.е. слова имеющие множество значений. Например, слово банки в одном контексте может означать стеклянные сосуды а в другом контексте это могут быть финансовые институты.";

//    text_to_svd tx_svd(str);

    text_to_svd tx_svd1(str1);
//    text_to_svd tx_svd2(str2);
//    text_to_svd tx_svd3(str3);

//    QList<QStringList> listt;
//    listt.clear();
//    listt += tx_svd1.get_words_list();
//    listt += tx_svd2.get_words_list();
//    listt += tx_svd3.get_words_list();

//    matrixx mat(listt);

    qDebug () << "\nEND.";

    return a.exec();
}
