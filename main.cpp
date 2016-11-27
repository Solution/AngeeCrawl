#include <QCoreApplication>
#include <QObject>
#include <QTimer>
#include <QSettings>
#include <QDebug>

#include "angeecrawlapplication.h"
#include "appdefaults.h"


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    app.setApplicationName(APPLICATION_NAME);
    app.setApplicationVersion(APPLICATION_VERSION);

    QSettings *settings = new QSettings("CrawlAngee", "Crawler");
    if (settings->value(SETTINGS_THREAD_NS).isNull()) {
        settings->setValue(SETTINGS_THREAD_NS, DEFAULT_NUMBER_OF_THREADS);
    }

    QString def("https://www.meetangee.com");
    if (argc == 1 && def.isEmpty()) {
        qDebug() << "Please specify url on input";

        return 0;
    }

    AngeeCrawlApplication crawlerTask(settings);
    QObject::connect(&crawlerTask, SIGNAL(finished()), &app, SLOT(quit()));

    QUrl url(def);
    crawlerTask.appendToQueue(url);

    QTimer::singleShot(10, &crawlerTask, SLOT(run()));

    return app.exec();
}

