#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

#ifndef ANGEECRAWLAPPLICATION_H
#define ANGEECRAWLAPPLICATION_H

#define APPLICATION_NAME "Angee crawl application"
#define APPLICATION_VERSION "1.0"


class AngeeCrawlApplication : public QCoreApplication
{

public:
    AngeeCrawlApplication(int argc, char *argv[]);
    AngeeCrawlApplication(int argc, char *argv[], QSettings *applicationSettings);

    int run();

private:
    QSettings *applicationSettings;
    void initiliazeApplication();

};

#endif // ANGEECRAWLAPPLICATION_H
