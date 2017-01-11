#include "awsrestrequest.h"

#include <QDateTime>
#include <QDebug>
#include <QList>
#include <QMessageAuthenticationCode>
#include <QMetaObject>
#include <QMetaProperty>
#include <QPair>
#include <QTextStream>
#include <QUrl>
#include <QUrlQuery>

static bool pairLessThan(QPair<QString, QString> const &p1, QPair<QString, QString> const &p2)
{
    QString str1 = p1.first + "=" + p1.second;
    QString str2 = p2.first + "=" + p2.second;
    return str1 < str2;
}

AwsRestRequest::AwsRestRequest(QObject *parent)
    :   QObject(parent)
    ,   m_validate(false)
{
    setService(" AWSECommerceService");
}

QString AwsRestRequest::endpoint() const
{
    return m_endpoint;
}

void AwsRestRequest::setEndpoint(const QString &endpoint)
{
    if (m_endpoint != endpoint)
    {
        m_endpoint = endpoint;
        emit endpointChanged(m_endpoint);
    }
}

QString AwsRestRequest::awsAccessKeyId() const
{
    return m_awsAccessKeyId;
}

void AwsRestRequest::setAwsAccessKeyId(const QString &awsAccessKeyId)
{
    if (m_awsAccessKeyId != awsAccessKeyId)
    {
        m_awsAccessKeyId = awsAccessKeyId;
        emit awsAccessKeyIdChanged(m_awsAccessKeyId);
    }
}

QString AwsRestRequest::operation() const
{
    return m_operation;
}

void AwsRestRequest::setOperation(const QString &operation)
{
    if (m_operation != operation)
    {
        m_operation = operation;
        emit operationChanged(m_operation);
    }
}

QString AwsRestRequest::awsSecretKey() const
{
    return m_awsSecretKey;
}

void AwsRestRequest::setAwsSecretKey(const QString &awsSecretKey)
{
    if (m_awsSecretKey != awsSecretKey)
    {
        m_awsSecretKey = awsSecretKey;
        emit awsSecretKeyChanged(m_awsSecretKey);
    }
}

QString AwsRestRequest::version() const
{
    return m_version;
}

void AwsRestRequest::setVersion(const QString &version)
{
    if (m_version != version)
    {
        m_version = version;
        emit versionChanged(m_version);
    }
}

QString AwsRestRequest::key() const
{
    return m_key;
}

void AwsRestRequest::setKey(const QString &key)
{
    if (m_key != key)
    {
        m_key = key;
        emit keyChanged(m_key);
    }
}

bool AwsRestRequest::validRequest()
{
    bool validOperation = false;
    if (m_associateTag.isEmpty())
        return false;
    if (m_awsAccessKeyId.isEmpty())
        return false;
    if (!m_merchantId.isEmpty())
        if (m_merchantId != "Amazon")
            return false;
    if (m_operation.isEmpty())
        return false;
    else if (m_operation == "ItemSearch")
        validOperation = true;
    else if (m_operation == "BrowseNodeLookup")
        validOperation = true;
    else if (m_operation == "ItemLookup")
        validOperation = true;
    else if (m_operation == "SimilarityLookup")
        validOperation = true;
    else if (m_operation == "CartAdd")
        validOperation = true;
    else if (m_operation == "CartClear")
        validOperation = true;
    else if (m_operation == "CartCreate")
        validOperation = true;
    else if (m_operation == "CartGet")
        validOperation = true;
    else if (m_operation == "CartModify")
        validOperation = true;
    return validOperation;
}

QString AwsRestRequest::generateHmacSignature()
{
    QUrl url(m_endpoint);
    QList< QPair< QString, QString> > params;
    QUrlQuery queryItems;
    const QMetaObject *metaobject = this->metaObject();
    int count = metaobject->propertyCount();
    for (int i = 0; i < count; ++i)
    {
        QMetaProperty metaproperty = metaobject->property(i);
        QString name = metaproperty.name();
        QVariant value;
        if (name == "objectName")
            continue;
        value = this->property(name.toLatin1().constData());
        if (value.isNull() || !value.isValid())
            continue;
        QPair<QString, QString> pair;
        pair.first = name;
        pair.second = value.toString();
        params.append(pair);
    }
    QPair<QString, QString> timestmp;
    timestmp.first = "Timestamp";
    QDateTime dt = QDateTime::currentDateTime();
    QString strdt = dt.toString(Qt::ISODate);
    timestmp.second = strdt;
    params.append(timestmp);
    queryItems.setQueryItems(params);
    qSort(params.begin(), params.end(), pairLessThan);
    QString cmd = "GET\nwebservices.amazon.com\n/onca/xml\n";
    QList< QPair< QString, QString> >::iterator it;
    for (it = params.begin(); it != params.end(); ++it)
    {
        cmd += it->first;
        cmd += "=";
        cmd += it->second;
        cmd += "&";
    }
    cmd = cmd.left(cmd.size() - 1);
    qDebug() << cmd;
    QMessageAuthenticationCode code(QCryptographicHash::Sha256);
    code.setKey(m_key.toLatin1());
    code.addData(cmd.toLatin1());
    queryItems.addQueryItem("Signature", code.result().toBase64(QByteArray::Base64UrlEncoding));
    url.setQuery(queryItems);
    qDebug() << url.toString();
    return code.result().toBase64(QByteArray::Base64UrlEncoding);
}
