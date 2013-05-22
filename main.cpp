#include <QCoreApplication>
#include <QTextCodec>
#include "text_to_svd.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);            
    QTextCodec::setCodecForLocale((QTextCodec::codecForName("System")));

    QString str = "{ response :[1803,{ id :43127, from_id :-10933209, to_id :-10933209, date :1369155716, text : А вы готовы к новому XBox? http:\/\/www.xbox.com\/en-US\/hub\/reveal , attachment :{ type : photo , photo :{ pid :303236127, aid :-7, owner_id :-10933209, user_id :100, src : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a17\/PJOovzMD9rA.jpg , src_big : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a18\/GJ10eBqcwkI.jpg , src_small : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a16\/K_CQG4gpz94.jpg , src_xbig : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a19\/H4yzrKE7wRc.jpg , src_xxbig : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a1a\/2NfPtCiMJGM.jpg , width :1072, height :635, text :  , created :1369155716, post_id :43127, access_key : f0c673c2ea9504e3de }}, attachments :[{ type : photo , photo :{ pid :303236127, aid :-7, owner_id :-10933209, user_id :100, src : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a17\/PJOovzMD9rA.jpg , src_big : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a18\/GJ10eBqcwkI.jpg , src_small : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a16\/K_CQG4gpz94.jpg , src_xbig : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a19\/H4yzrKE7wRc.jpg , src_xxbig : http:\/\/cs7010.vk.me\/c540106\/v540106646\/a1a\/2NfPtCiMJGM.jpg , width :1072, height :635, text :  , created :1369155716, post_id :43127, access_key : f0c673c2ea9504e3de }},{ type : link , link :{ url : http:\/\/www.xbox.com\/en-US\/hub\/reveal , title : Xbox, A New Generation Revealed - Xbox.com , description : Watch it live May 21, 10am PDT on Xbox Live, Xbox.com or Spike TV , image_src : http:\/\/cs320420.vk.me\/v320420704\/5e7\/cWHuN3pXcfw.jpg }}], comments :{ count :37}, likes :{ count :19}, reposts :{ count :7}}]}";
    text_to_svd tx_svd(str);

    return a.exec();
}
