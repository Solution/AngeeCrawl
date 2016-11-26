#include <QSettings>
#include <QDebug>
#include <QThread>

#include "angeecrawlapplication.h"

#define SETTINGS_THREAD_NS "numberOfWOrkingThreads"
#define DEFAULT_NUMBER_OF_THREADS 4


int main(int argc, char *argv[])
{
    QSettings *settings = new QSettings("CrawlAngee", "Crawler");
    if (settings->value(SETTINGS_THREAD_NS).isNull()) {
        settings->setValue(SETTINGS_THREAD_NS, DEFAULT_NUMBER_OF_THREADS);
    }

    AngeeCrawlApplication *app = new AngeeCrawlApplication(argc, argv, settings);

    return app->run();
}

