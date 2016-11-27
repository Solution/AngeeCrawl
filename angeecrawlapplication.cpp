#include "angeecrawlapplication.h"

AngeeCrawlApplication::AngeeCrawlApplication(QObject *parent = 0):
    QObject(parent)
{
}


AngeeCrawlApplication::AngeeCrawlApplication(QSettings *applicationSettings):
    applicationSettings(applicationSettings)
{
}


void AngeeCrawlApplication::run()
{
    QElapsedTimer timer;
    timer.start();

    qDebug() << "Crawl started";

    const int numberOfWorkingThreads = applicationSettings->value(SETTINGS_THREAD_NS).toInt();
    workerThreads = new CrawlWorkerThread[numberOfWorkingThreads];

    for (int i = 0; i < numberOfWorkingThreads; i++) {
        connect(&workerThreads[i], SIGNAL(queueItemReady(QUrl)), this, SLOT(appendToQueue(QUrl)));
        connect(&workerThreads[i], SIGNAL(pageReady(Page)), this, SLOT(appendPage(Page)));
        connect(&workerThreads[i], SIGNAL(finished()), &workerThreads[i], SLOT(deleteLater()));
    }

    qDebug() << "Preparing " << numberOfWorkingThreads << " threads";

    while(!pagesQueue.isEmpty()) {

        for (int i = 0; i < numberOfWorkingThreads; i++) {

            if (!workerThreads[i].isRunning()) {
                QString queueItem(pagesQueue.dequeue().toString());

                qDebug() << "Crawling page: " << queueItem << "in thread " << i;

                workerThreads[i].setUrlToCrawl(queueItem);
                workerThreads[i].start();
                workerThreads[i].wait(2000);

                break;
            }

        }

    }

    qDebug() << "Application run time: " << timer.elapsed() << "ms";

    emit finished();
}


void AngeeCrawlApplication::appendToQueue(QUrl url)
{
    if (!pages.keys().contains(url.toString())) {
        pagesQueue.enqueue(url);
    }
}


void AngeeCrawlApplication::appendPage(Page page)
{
    QString pageKey(page.getUrl().toString());

    if (!pages.keys().contains(pageKey)) {
        pages.insert(pageKey, page);
    }
}


AngeeCrawlApplication::~AngeeCrawlApplication()
{
    delete applicationSettings;
    delete[] workerThreads;
}
