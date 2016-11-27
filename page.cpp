#include "page.h"

Page::Page()
{

}


Page::Page(QUrl url, QString urlKeyHash):
    url(url),
    urlKeyHash(urlKeyHash)
{

}


const QUrl Page::getUrl()
{
    const QUrl constUrl(url);

    return constUrl;
}


const QString Page::getUrlKeyHash()
{
    const QString constUrlKeyHash(urlKeyHash);

    return constUrlKeyHash;
}


void Page::setContentHash(QString contentHash)
{
    this->contentHash = contentHash;
}


const QString Page::getContentHash()
{
    const QString constContentHash(contentHash);

    return constContentHash;
}


void Page::setRawContent(QString rawContent)
{
    this->rawContent = rawContent;
}


const QString Page::getRawContent()
{
    const QString constRawContent(rawContent);

    return constRawContent;
}

