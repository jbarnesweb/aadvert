#ifndef ITEMLOOKUPREQUEST_H
#define ITEMLOOKUPREQUEST_H

#include "awsrestrequest.h"

#include <QVariant>

class ItemLookupRequest : public AwsRestRequest
{
    Q_OBJECT
    Q_PROPERTY(QString Condition READ condition WRITE setCondition NOTIFY conditionChanged)
    Q_PROPERTY(QString IdType READ idType WRITE setIdType NOTIFY idTypeChanged)
    Q_PROPERTY(bool IncludeReviewsSummary READ includeReviewsSummary WRITE setIncludeReviewsSummary NOTIFY includeReviewsSummaryChanged)
    Q_PROPERTY(QString ItemId READ itemId WRITE setItemId NOTIFY itemIdChanged)
    Q_PROPERTY(int RelatedItemPage READ relatedItemPage WRITE setRelatedItemPage NOTIFY relatedItemPageChanged)
    Q_PROPERTY(QString RelationshipType READ relationshipType WRITE setRelationshipType NOTIFY relationshipTypeChanged)
    Q_PROPERTY(QString ResponseGroup READ responseGroup WRITE setResponseGroup NOTIFY responseGroupChanged)
    Q_PROPERTY(QString SearchIndex READ searchIndex WRITE setSearchIndex NOTIFY searchIndexChanged)
    Q_PROPERTY(int TruncateReviewsAt READ truncateReviewsAt WRITE setTruncateReviewsAt NOTIFY truncateReviewsAtChanged)
    Q_PROPERTY(QString VariationPage READ variationPage WRITE setVariationPage NOTIFY variationPageChanged)
public:
    static const QString DEFAULT_CONDITION;
    static const QString DEFAULT_ID_TYPE;
    static const QString DEFAULT_RESPONSE_GROUP;
    static const QString DEFAULT_SEARCH_INDEX;
    static const QString DEFAULT_VARIATION_PAGE;

    ItemLookupRequest(QObject *parent = NULL);

    QString condition() const;
    void setCondition(QString const & condition);
    QString idType() const;
    void setIdType(QString const & idType);
    bool includeReviewsSummary() const;
    void setIncludeReviewsSummary(bool includeReviewsSummary);
    QString relationshipType() const;
    void setRelationshipType(QString const &relationshipType);
    QString responseGroup() const;
    void setResponseGroup(QString const &responseGroup);
    QString searchIndex() const;
    void setSearchIndex(QString const & searchIndex);
    int truncateReviewsAt() const;
    void setTruncateReviewsAt(int truncateReviewsAt);
    QString variationPage() const;
    void setVariationPage(QString const & variationPage);

signals:
    void conditionChanged(QString newCondition);
    void idTypeChanged(QString newIdType);
    void includeReviewsSummaryChanged(bool newIncludeReviewsSummary);
    void itemIdChanged(QString newItemId);
    void relatedItemPageChanged(int newRelatedItemPage);
    void relationshipTypeChanged(QString newRelationshipType);
    void responseGroupChanged(QString newResponseGroup);
    void searchIndexChanged(QString newSearchIndex);
    void truncateReviewsAtChanged(int newTruncateReviewsAt);
    void variationPageChanged(QString newVariationPage);

protected:
    virtual bool validRequest();

private:
    QVariant m_includeReviewsSummary;
    QVariant m_relatedItemPage;
    QVariant m_truncateReviewsAt;
    QVariant m_condition;
    QVariant m_idType;
    QVariant m_itemId;
    QVariant m_relationshipType;
    QVariant m_responseGroup;
    QVariant m_searchIndex;
    QVariant m_variationPage;
};

#endif // ITEMLOOKUPREQUEST_H
