#ifndef ANGEECRAWLAPPLICATION_H
#define ANGEECRAWLAPPLICATION_H

#include <QObject>
#include <QSettings>
#include <QDebug>
#include <QElapsedTimer>
#include <QMap>
#include <QQueue>

#include "appdefaults.h"
#include "httpdownloader.h"
#include "crawlworkerthread.h"
#include "page.h"


class AngeeCrawlApplication : public QObject
{

    Q_OBJECT

public:
    AngeeCrawlApplication(QObject *parent);
    AngeeCrawlApplication(QSettings *applicationSettings);
    ~AngeeCrawlApplication();


signals:
    void finished();

public slots:
    void run();
    //void fileDownloaded(QString);

    void appendToQueue(QUrl url);
    void appendPage(Page page);

private:
    QSettings *applicationSettings;
    void initiliazeApplication();

    QQueue<QUrl> pagesQueue;
    QMap<QString, Page> pages;

    CrawlWorkerThread *workerThreads;
};

#endif // ANGEECRAWLAPPLICATION_H
