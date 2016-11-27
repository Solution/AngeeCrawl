#ifndef PAGE_H
#define PAGE_H


#include <QString>
#include <QUrl>


class Page
{

public:
    Page();
    Page(QUrl url, QString urlKeyHash);

    const QUrl getUrl();
    const QString getUrlKeyHash();
    void setContentHash(QString contentHash);
    const QString getContentHash();
    void setRawContent(QString rawContent);
    const QString getRawContent();

private:
    QUrl url;
    QString urlKeyHash;
    QString contentHash;
    QString rawContent;

};

#endif // PAGE_H
