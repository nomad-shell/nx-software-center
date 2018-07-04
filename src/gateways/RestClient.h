//
// Created by alexis on 7/2/18.
//

#ifndef NX_SOFTWARE_CENTER_EXPLORER_H
#define NX_SOFTWARE_CENTER_EXPLORER_H

#include <QList>
#include <QObject>
#include <QString>
#include <QVariantMap>
#include <QNetworkReply>

class ApplicationsSearchRequest;
class RestClient : public QObject {
Q_OBJECT
    Q_PROPERTY(bool isBusy READ isBusy NOTIFY isBusyChanged)

    bool busy;
    QString api;
    QNetworkAccessManager *networkAccessManager;
public:
    explicit RestClient(QString url, QObject* parent = nullptr);
    ApplicationsSearchRequest* buildSearchRequest(const QString& query = "", const QString& category = "");
    void getApplication(const QString &id);
    bool isBusy() const;

signals:
    void isBusyChanged(bool busy);
    void failure(QString errorMessage);
    void searchCompleted(QList<QVariantMap> apps);
    void getApplicationCompleted(QVariantMap app);

protected slots:
    void handleSearchRequestResults(QNetworkReply *reply);
    void handleGetApplicationResult(QNetworkReply *reply);

protected:
    void setBusy(bool busy);
    void trySetBusy();
    QUrl buildSearchQueryUrl(const QString& query, const QString& category) const;
    QUrl buildGetApplicationUrl(const QString& id) const;
};

class RestClientBusy : public std::runtime_error {
    explicit RestClientBusy(const std::string& __arg = "Another request is being processed.");
};

#endif //NX_SOFTWARE_CENTER_EXPLORER_H
