#ifndef AWSRESTREQUEST_H
#define AWSRESTREQUEST_H

#include <QByteArray>
#include <QObject>
#include <QString>

class AwsRestRequest : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString endpoint READ endpoint WRITE setEndpoint NOTIFY endpointChanged)
    Q_PROPERTY(QString AWSECommerceService READ awsECommerceService WRITE setAwsECommerceService NOTIFY awsECommerceServiceChanged)
    Q_PROPERTY(QString AWSAccessKeyId READ awsAccessKeyId WRITE setAwsAccessKeyId NOTIFY awsAccessKeyIdChanged)
    Q_PROPERTY(QString AWSSecretKey READ awsSecretKey WRITE setAwsSecretKey NOTIFY awsSecretKeyChanged)
    Q_PROPERTY(QString operation READ operation WRITE setOperation NOTIFY operationChanged)
public:
    explicit AwsRestRequest(QObject *parent = 0);

    QString endpoint() const;
    void setEndpoint(QString const & endpoint);
    QString awsECommerceService() const;
    void setAwsECommerceService(QString const &awsEcommerceService);
    QString awsAccessKeyId() const;
    void setAwsAccessKeyId(QString const &awsAccessKeyId);
    QString operation() const;
    void setOperation(QString const & operation);
    QString awsSecretKey() const;
    void setAwsSecretKey(QString const &awsSecretKey);

signals:
    void endpointChanged(QString newEndpoint);
    void awsECommerceServiceChanged(QString newAwsECommerceService);
    void awsAccessKeyIdChanged(QString newAwsAccessKeyId);
    void operationChanged(QString newOperation);
    void awsSecretKeyChanged(QString newAwsSecretKey);

protected:
    void generateHmacSignature();

private slots:

private:
    QByteArray m_hmacSig;
    QString m_endpoint;
    QString m_operation;
    QString m_awsECommerceService;
    QString m_awsAccessKeyId;
    QString m_awsSecretKey;

};

#endif // AWSRESTREQUEST_H
