#ifndef CRAWLWORKERTHREAD_H
#define CRAWLWORKERTHREAD_H

#include <QObject>
#include <QThread>
#include <QUrl>

#include "httpdownloader.h"
#include "page.h"


class CrawlWorkerThread : public QThread
{

    Q_OBJECT

public:
    CrawlWorkerThread();

    void setUrlToCrawl(QUrl url);
    void run();

protected slots:
    void downloaded(QString data);

signals:
    void pageReady(Page page);
    void queueItemReady(QUrl url);

private:
    QUrl urlToCrawl;
    HttpDownloader *downloader;

};

#endif // CRAWLWORKERTHREAD_H
