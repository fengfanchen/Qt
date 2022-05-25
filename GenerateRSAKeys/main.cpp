#include <QCoreApplication>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int ret = 0;
    RSA *r = nullptr;
    BIGNUM *bne = nullptr;
    BIO *bp_public = nullptr;
    BIO *bp_private = nullptr;
    int bits = 2048;
    unsigned long e = RSA_F4;

    //generate rsa key
    bne = BN_new();
    ret = BN_set_word(bne, e);
    if(!ret){

        qDebug() << "BN_set_word() error";
        BIO_free_all(bp_public);
        BIO_free_all(bp_private);
        RSA_free(r);
        BN_free(bne);
        return 0;
    }

    r = RSA_new();
    ret = RSA_generate_key_ex(r, bits, bne, nullptr);
    if(!ret){

        qDebug() << "RSA_generate_key() error";
        BIO_free_all(bp_public);
        BIO_free_all(bp_private);
        RSA_free(r);
        BN_free(bne);
        return 0;
    }

    //save public key
    bp_public = BIO_new_file("public.pem", "w+");
    ret = PEM_write_bio_RSAPublicKey(bp_public, r);
    if(!ret){

        qDebug() << "PEM_write_bio_RSAPublicKey() error";
        BIO_free_all(bp_public);
        BIO_free_all(bp_private);
        RSA_free(r);
        BN_free(bne);
        return 0;
    }

    //save private key
    bp_private = BIO_new_file("private.pem", "w+");
    ret = PEM_write_bio_RSAPrivateKey(bp_private, r, nullptr, nullptr, 0, nullptr, nullptr);
    if(!ret){

        qDebug() << "PEM_write_RSAPrivateKey() error";
        BIO_free_all(bp_public);
        BIO_free_all(bp_private);
        RSA_free(r);
        BN_free(bne);
        return 0;
    }

    //free
    BIO_free_all(bp_public);
    BIO_free_all(bp_private);
    RSA_free(r);
    BN_free(bne);
    qDebug() << "success";

    return a.exec();
}

