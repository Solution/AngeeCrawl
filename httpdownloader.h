#ifndef HTTPDOWNLOADER_H
#define HTTPDOWNLOADER_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QEventLoop>


class HttpDownloader : public QObject
{

    Q_OBJECT

public:
    explicit HttpDownloader(QObject *parent = 0);

    void download(QUrl fileUrl);
    void download(QString fileUrl);

signals:
    void fileDownloaded(QString data);
    void downloadFailed();

protected slots:
    void requestFinished(QNetworkReply* reply);
    void requestError(QNetworkReply::NetworkError error);

protected:
    void processRequest(QUrl fileUrl);

private:
    QNetworkAccessManager *manager;

};

#endif // HTTPDOWNLOADER_H
