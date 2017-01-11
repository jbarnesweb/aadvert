#include <QCoreApplication>

#include "awsrestrequest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AwsRestRequest req;
    req.setAwsAccessKeyId("AKIAIOSFODNN7EXAMPLE");
    req.setService("ItemLookup");
    req.setEndpoint("https://www.amazon.com/onca/xml");
    req.setAwsSecretKey("1234567890");
    req.setOperation("Item");
    req.setVersion("2013-08-13");

    req.generateHmacSignature();

    return a.exec();
}
