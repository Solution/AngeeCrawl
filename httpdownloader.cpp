#include "httpdownloader.h"

HttpDownloader::HttpDownloader(QObject *parent):
    QObject(parent),
    manager(new QNetworkAccessManager(this))
{
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
}


void HttpDownloader::download(QUrl fileUrl)
{
    processRequest(fileUrl);
}


void HttpDownloader::download(QString fileUrl)
{
    QUrl url(fileUrl);
    processRequest(url);
}


void HttpDownloader::processRequest(QUrl fileUrl)
{
    QNetworkRequest request(fileUrl);
    request.setRawHeader("User-Agent", "Angee crawler 1.0");

    manager->get(request);

    // sad o'hack
    QEventLoop eventLoop;
    connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();
}


void HttpDownloader::requestFinished(QNetworkReply *reply)
{
    qDebug() << "downloaded";
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(requestError(QNetworkReply::NetworkError)));
    QString data(reply->readAll());

    qDebug() << data.size();

    emit fileDownloaded(data);
}


void HttpDownloader::requestError(QNetworkReply::NetworkError error)
{
    qDebug() << "There is some error";
    //todo
}
