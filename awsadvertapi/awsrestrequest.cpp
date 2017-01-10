#include "awsrestrequest.h"

#include <QMetaObject>
#include <QMetaProperty>
#include <QPair>
#include <QUrl>
#include <QUrlQuery>
#include <openssl/hmac.h>

static bool pairLessThan(QPair<QString, QString> const &p1, QPair<QString, QString> const &p2)
{
    return p1.first < p2.first;
}

AwsRestRequest::AwsRestRequest(QObject *parent) : QObject(parent)
{

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

QString AwsRestRequest::awsECommerceService() const
{
    return m_awsECommerceService;
}

void AwsRestRequest::setAwsECommerceService(const QString &awsEcommerceService)
{
    if (m_awsECommerceService != awsEcommerceService)
    {
        m_awsECommerceService = awsEcommerceService;
        emit awsECommerceServiceChanged(m_awsECommerceService);
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

void AwsRestRequest::generateHmacSignature()
{
    QUrl url(m_endpoint);
    QUrlQuery query;
    const QMetaObject *metaobject = this->metaObject();
    int count = metaobject->propertyCount();
    for (int i = 0; i < count; ++i)
    {
        QMetaProperty metaproperty = metaobject->property(i);
        const char *name = metaproperty.name();
        QVariant value = this->property(name);
        query.addQueryItem(name, value.toString());
    }
    QList< QPair< QString, QString> > params = query.queryItems();
    qSort(params.begin(), params.end(), pairLessThan);
}
