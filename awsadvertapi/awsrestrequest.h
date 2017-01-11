#ifndef AWSRESTREQUEST_H
#define AWSRESTREQUEST_H

#include <QByteArray>
#include <QObject>
#include <QString>

class AwsRestRequest : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString AssociateTag READ associateTag WRITE setAssociateTag NOTIFY associateTagChanged)
    Q_PROPERTY(QString AWSAccessKeyId READ awsAccessKeyId WRITE setAwsAccessKeyId NOTIFY awsAccessKeyIdChanged)
    Q_PROPERTY(QString ContentType READ contentType WRITE setContentType NOTIFY contentTypeChanged)
    Q_PROPERTY(QString MerchantId READ merchantId WRITE setMerchantId NOTIFY merchantIdChanged)
    Q_PROPERTY(QString Operation READ operation WRITE setOperation NOTIFY operationChanged)
    Q_PROPERTY(QString Service READ service WRITE setService NOTIFY serviceChanged)
    Q_PROPERTY(bool Validate READ validate WRITE setValidate NOTIFY validateChanged)
    Q_PROPERTY(QString Version READ version WRITE setVersion NOTIFY versionChanged)
    Q_PROPERTY(QString XMLEscaping READ xmlEscaping WRITE setXmlEscaping NOTIFY xmlEscapingChanged)
public:
    explicit AwsRestRequest(QObject *parent = 0);
    QString generateHmacSignature();

    QString associateTag() const;
    void setAssociateTag(QString const & associateTag);
    QString awsAccessKeyId() const;
    void setAwsAccessKeyId(QString const &awsAccessKeyId);
    QString awsSecretKey() const;
    void setAwsSecretKey(QString const &awsSecretKey);
    QString contentType() const;
    void setContentType(QString const & contentType);
    QString endpoint() const;
    void setEndpoint(QString const & endpoint);
    QString merchantId() const;
    void setMerchantId(QString const &merchantId);
    QString operation() const;
    void setOperation(QString const & operation);
    QString service() const;
    void setService(QString const &service);
    QString version() const;
    void setVersion(QString const & version);
    QString key() const;
    void setKey(QString const & key);

signals:
    void associateTagChanged(QString newAssociateTag);
    void awsAccessKeyIdChanged(QString newAwsAccessKeyId);
    void contentTypeChanged(QString newContentType);
    void endpointChanged(QString newEndpoint);
    void merchantIdChanged(QString newMerchantId);
    void operationChanged(QString newOperation);
    void awsSecretKeyChanged(QString newAwsSecretKey);
    void versionChanged(QString newVersion);
    void keyChanged(QString newKey);

protected:
    virtual bool validRequest();

private slots:

private:
    bool m_validate;
    QByteArray m_hmacSig;
    QString m_associateTag;
    QString m_awsAccessKeyId;
    QString m_awsSecretKey;
    QString m_contentType;
    QString m_endpoint;
    QString m_merchantId;
    QString m_operation;
    QString m_version;
    QString m_key;
};

#endif // AWSRESTREQUEST_H
