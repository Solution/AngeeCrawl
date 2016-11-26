#include "angeecrawlapplication.h"

AngeeCrawlApplication::AngeeCrawlApplication(int argc, char *argv[]):
    QCoreApplication(argc, argv)
{
    initiliazeApplication();
}


AngeeCrawlApplication::AngeeCrawlApplication(int argc, char *argv[], QSettings *applicationSettings):
    QCoreApplication(argc, argv),
    applicationSettings(applicationSettings)
{
    initiliazeApplication();
}


void AngeeCrawlApplication::initiliazeApplication()
{
    setApplicationName(APPLICATION_NAME);
    setApplicationVersion(APPLICATION_VERSION);
}


int AngeeCrawlApplication::run()
{
    qDebug() << "Application run";
    qDebug() << applicationSettings->value("numberOfWOrkingThreads").toString();

    return 0;
}
