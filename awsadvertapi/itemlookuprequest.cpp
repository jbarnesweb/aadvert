#include "itemlookuprequest.h"

const QString ItemLookupRequest::DEFAULT_CONDITION("New");
const QString ItemLookupRequest::DEFAULT_ID_TYPE("ASIN");
const QString ItemLookupRequest::DEFAULT_RESPONSE_GROUP("Small");
const QString ItemLookupRequest::DEFAULT_SEARCH_INDEX("None");
const QString ItemLookupRequest::DEFAULT_VARIATION_PAGE("All");

ItemLookupRequest::ItemLookupRequest(QObject *parent)
    :   AwsRestRequest(parent)
    ,   m_includeReviewsSummary(true)
    ,   m_relatedItemPage(0)
    ,   m_truncateReviewsAt(1000)
    ,   m_condition(DEFAULT_CONDITION)
    ,   m_idType(DEFAULT_ID_TYPE)
    ,   m_responseGroup(DEFAULT_RESPONSE_GROUP)
    ,   m_searchIndex(DEFAULT_SEARCH_INDEX)
    ,   m_variationPage(DEFAULT_VARIATION_PAGE)
{

}

QString ItemLookupRequest::condition() const
{
    return m_condition.toString();
}

void ItemLookupRequest::setCondition(const QString &condition)
{
    if (m_condition.toString() != condition)
    {
        m_condition = condition;
        emit conditionChanged(m_condition.toString());
    }
}

QString ItemLookupRequest::idType() const
{
    return m_idType.toString();
}

void ItemLookupRequest::setIdType(const QString &idType)
{
    if (m_idType.toString() != idType)
    {
        m_idType = idType;
        emit idTypeChanged(m_idType.toString());
    }
}

bool ItemLookupRequest::includeReviewsSummary() const
{
    return m_includeReviewsSummary.toBool();
}

void ItemLookupRequest::setIncludeReviewsSummary(bool includeReviewsSummary)
{
    if (m_includeReviewsSummary.toBool() != includeReviewsSummary)
    {
        m_includeReviewsSummary = includeReviewsSummary;
        emit includeReviewsSummaryChanged(m_includeReviewsSummary.toBool());
    }
}

QString ItemLookupRequest::relationshipType() const
{
    return m_relationshipType.toString();
}

void ItemLookupRequest::setRelationshipType(const QString &relationshipType)
{
    if (m_relationshipType.toString() != relationshipType)
    {
        m_relationshipType = relationshipType;
        emit relationshipTypeChanged(m_relationshipType.toString());
    }
}

QString ItemLookupRequest::responseGroup() const
{
    return m_responseGroup.toString();
}

void ItemLookupRequest::setResponseGroup(const QString &responseGroup)
{
    if (m_responseGroup.toString() != responseGroup)
    {
        m_responseGroup = responseGroup;
        emit responseGroupChanged(m_responseGroup.toString());
    }
}

QString ItemLookupRequest::searchIndex() const
{
    return m_searchIndex.toString();
}

void ItemLookupRequest::setSearchIndex(const QString &searchIndex)
{
    if (m_searchIndex.toString() != searchIndex)
    {
        m_searchIndex = searchIndex;
        emit searchIndexChanged(m_searchIndex.toString());
    }
}

int ItemLookupRequest::truncateReviewsAt() const
{
    return m_truncateReviewsAt.toInt();
}

void ItemLookupRequest::setTruncateReviewsAt(int truncateReviewsAt)
{
    if (m_truncateReviewsAt != truncateReviewsAt)
    {
        m_truncateReviewsAt = truncateReviewsAt;
        emit truncateReviewsAtChanged(m_truncateReviewsAt.toInt());
    }
}

QString ItemLookupRequest::variationPage() const
{
    return m_variationPage.toString();
}

void ItemLookupRequest::setVariationPage(const QString &variationPage)
{
    if (m_variationPage.toString() != variationPage)
    {
        m_variationPage = variationPage;
        emit variationPageChanged(m_variationPage.toString());
    }
}

bool ItemLookupRequest::validRequest()
{
}
