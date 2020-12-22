#ifndef CATEGORIESMODEL_H
#define CATEGORIESMODEL_H

#include <QObject>

#ifdef STATIC_MAUIKIT
#include "fmh.h"
#include "mauilist.h"
#else
#include <MauiKit/fmh.h>
#include <MauiKit/mauilist.h>
#endif

#include "ResponseDTO/category.h"

class Store;
class CategoriesModel : public MauiList
{
    Q_OBJECT
    Q_PROPERTY(Category * category READ category WRITE setCategory NOTIFY categoryChanged)

public:
    CategoriesModel(QObject * parent = nullptr);

    // QQmlParserStatus interface
    void componentComplete() override final;

    // MauiList interface
    const FMH::MODEL_LIST &items() const override final;

    Category * category() const;

private:
    FMH::MODEL_LIST m_list;
    QHash<QString, Category *> m_categoryMap; //id,app
    Store *m_store;

    Category * m_category;

    void setList();

public slots:
    Category *baseCategory();
    Category *featureCategory();
    Category *audioCategory();
    Category *videoCategory();
    Category *educationCategory();
    Category *graphicsCategory();
    Category *gamesCategory();

    Category *getCategory(const QString &id);

    void setCategory(Category * category);
    void clear();

signals:
    void categoryChanged();
};

#endif // CATEGORIESMODEL_H
