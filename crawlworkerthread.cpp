#include "crawlworkerthread.h"

CrawlWorkerThread::CrawlWorkerThread():
    downloader(0)
{
}


void CrawlWorkerThread::setUrlToCrawl(QUrl url)
{
    urlToCrawl = url;
}


void CrawlWorkerThread::run()
{
    if (downloader == NULL) {
        qDebug() << "initialize downloader";
        downloader = new HttpDownloader(this);
        connect(downloader, SIGNAL(fileDownloaded(QString)), this, SLOT(downloaded(QString)));
    }

    qDebug() << urlToCrawl.toString();
    if (urlToCrawl.isEmpty()) {
        emit abort();
    }

    qDebug() << "thread running";
    downloader->download(urlToCrawl);

    //emit finished();
}


void CrawlWorkerThread::downloaded(QString data)
{
    emit finished();
    qDebug() << "Received something " << data.size();
}
